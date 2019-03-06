	#Projekt 1 ARKO - MIPS
	#zadanie nr 16
	#Algorytm flood-fill na obrazku BMP 
	
	.globl main
	.data
	
size:		.space 4	#rozmiar calego pliku w bajtach
width:		.space 4	#szerokosc obrazu w pikselach
height:		.space 4	#wysokosc obrazu w pikselach
offset:		.space 4	#poczatkowy adres bitow w tablicy pikseli
temp:		.space 4	#zmienna do przechowywanie danych tymczasowych
table_of_pixels:.space 4	#zmienna do przechowywania adresu na poczatek tablicy pikseli
padding:	.space 4	#zmienna do przechowywania ilosci bajtów paddingowych

begin_x:	.space 4	#zmienna do przechowywania wspolrzednej x poczatku wypelniania
begin_y:	.space 4	#zmienna do przechowywania wspolrzednej y poczatku wypelniania
x1:		.space 4	#wspolrzedna poczatku segmentu
count_x1:	.space 4	#licznik szukania lewego konca segmentu	#wartosci przechowywane
count_y1:	.space 4	#wspolrzedna poczatku segmentu		#w tych zmiennych
len:		.space 4	#dlugosc segmentu w pikselach		#umieszczamy na stosie
x2:		.space 4	#wspolrzedna prawego konca segmentu
count_x2:	.space 4	#licznik prawego konca segmentu

return_adress:	.space 4	#zapisujemy
return_adress1:	.space 4	#tutaj
return_adress2:	.space 4	#adresy powrotow
return_adress3: .space 4	#z procedur

return_f_s:	.space 4	#zapisujemy tutaj wartosc zwracana przez funkcje find_segment

temp_1:		.space 4	#do przechowywania
temp_2:		.space 4	#tymczasowych
temp_3:		.space 4	#wartosci

x_from_stack:	.space 4	#w tych zmiennych
y_from_stack:	.space 4	# zapisujemy to
len_from_stack:	.space 4	#co sciagamy ze stosu

x_to_search_segment:	.space 4	#w tych zmiennych zapisujemy 
y_to_search_segment:	.space 4	#wartosci, ktorych uzyjemy
len_to_search_segment:	.space 4	#w funkcji search_segment

adress_of_allocated_memory_for_bitmap: .space 4 #przechowujemy tu t1
stack_counter:	.space 4	#licznik elementow na stosie

###############################################################################################################################

	#komunikaty do wypisywania

text_start:	 .asciiz	"Projekt1 ARKO. Algorytm flood-fill na obrazku BMP.\n"
text_end:	 .asciiz "\nProgram zakonczyl dzialanie.\n"
text_error:	 .asciiz	"Blad otwarcia pliku.\n"
text_error_begin_x1:.asciiz "Podano zbyt mala wspolrzedna x poczatku wypelniania. Koncze dzialanie programu.\n"
text_error_begin_x2:.asciiz "Podano zbyt duza wspolrzedna x poczatku wypelniania. Koncze dzialanie programu.\n"
text_error_begin_y1:.asciiz "Podano zbyt mala wspolrzedna y poczatku wypelniania. Koncze dzialanie programu.\n"
text_error_begin_y2:.asciiz "Podano zlyt duza wspolrzedna y poczatku wypelniania. Koncze dzialanie programu.\n"
text_begin_x:	 .asciiz "\nPodaj wspolrzedna x poczatku wypelniania powodziowego.\n"
text_begin_y:	 .asciiz "Podaj wspolrzedna y poczatku wypelnienia powodziowego.\n"
black_pixel:	 .asciiz "Piksel na wspolrzednych poczatkowych jest koloru czarnego, wiec koncze dzialanie programu.\n"
stack__overflow: .asciiz "Stos jest pelny wiec nie mozemy dodawac wiecej elementow. Koniec programu. Przykro mi.\n"
empty__stack:	 .asciiz "Stos jest pusty:.Nie mozemy nic sciagnac. Koniec programu.\n"
black_continue:	 .asciiz "Segment zaczyna sie od bajtu czarnego. Nic nie robimy.\n"

################################################################################################################################

##########################################################################
##########################################################################
									##
#rozne nazwy plikow wejsciowych i wyjsciowych				##
#w zaleznosci od tego na ktorym pliku chcemy pracowac			##
#to go odkomentowujemy a pozostale zakomentowujemy			##
									##
#name_input:	.asciiz	"/home/wojciech/empty.bmp"			##
#name_output:	.asciiz	"/home/wojciech/empty_ff.bmp"			##
									##
#name_input:	.asciiz	"/home/wojciech/kwadrat80.bmp"			##
#name_output:	.asciiz	"/home/wojciech/kwadrat80_ff.bmp"		##
									##
#name_input:	.asciiz	"/home/wojciech/linux_attempt.bmp"		##
#name_output:	.asciiz	"/home/wojciech/linux_attempt_ff.bmp"		##
									##
#name_input:	.asciiz	"/home/wojciech/paski.bmp"			##
#name_output:	.asciiz	"/home/wojciech/paski_ff.bmp"			##
									##
#name_input:	.asciiz	"/home/wojciech/wywijas.bmp"			##
#name_output:	.asciiz	"/home/wojciech/wywijas_ff.bmp"			##
									##
name_input:	.asciiz	"/home/wojciech/s.bmp"				##
name_output:	.asciiz	"/home/wojciech/s_ff.bmp"			##
									##
#name_input:	.asciiz	"/home/wojciech/open.bmp"			##
#name_output:	.asciiz	"/home/wojciech/open_ff.bmp"			##
									##
##########################################################################
##########################################################################

	.text		

main:	la	$a0,text_start	#wypisujemy tekst powitalny
	li	$v0,4		
	syscall
	
load_file:	#wczytujemy z pliku
	la	$a0, name_input
	li	$a1,0		#ustawiamy falge na 0, aby moc czytac z pliku
	li	$a2,0		#ustawiamy mode na 0
	li	$v0,13		# etykieta 13 umozliwia nam otwarcie pliku
	syscall
	
	move	$t0,$v0		# w t0 umieszczamy deskryptor pliku
	bltz	$t0, error_opening	#jesli plik nie zostal poprawnie otwarty, to wtedy v0 jest ustawiane na ujemna liczbe
	
	move	$a0,$t0		#w a0 umieszczamy deskryptor pliku
	la	$a1,temp	#w zmiennej size zapisujemy tymczasowo identyfikacje pliku wpostaci napisu "BM"
	li	$a2,2		#identyfikacja pliku jest zapisana na 2 bajtach
	la	$v0,14		#wczytujemy z pliku
	syscall
	
	#move	$a0,$t0		#w a0 umieszczamy deskryptor pliku (tutaj to chyba nie potrzebne bo z poprzedniej operacji jest to co trzeba)
	la	$a1,size	#w zmiennej size zapisujemy rozmiar pliku w bajtach
	li	$a2,4		#informacja o rozmiarze jest zapisana na 2 bajtach
	la	$v0,14		#wczytujemy z pliku
	syscall
		
	lw	$t7,size	#w t7 zapisujemy rozmiar pliku
	
	move	$a0,$t7		#do a0 kopiujemy rozmiar pliku, zeby wiedziec ile bajtow pamieci mamy do zaalokowania
	li	$v0,9		#alokacja pamieci na bitmape
	syscall
	
	move	$t1, $v0	# rejestrze t1 umieszczamy adres zaalokowanej pamieci na bitmape
	sw	$t1,adress_of_allocated_memory_for_bitmap
	
	move	$a0,$t0		#w a0 umieszczamy deskryptor pliku
	la	$a1, temp	#w zmiennej temp zapisujemy tymczasowo zarezerwowane bajty
	li	$a2,4		#sa 4 takie bajty
	li	$v0,14		#wczytujemy z pliku
	syscall
	
	#move	$a0,$t0		#w a0 umieszczamy deskryptor pliku (tutaj to chyba nie potrzebne bo z poprzedniej operacji jest to co trzeba)
	la	$a1, offset	#w zmiennej offset zapisujemy poczatkowy adres bitow w tablicy pikseli
	li	$a2,4		#offset jest na 4 bajtach
	li	$v0,14		#wczytujemy z pliku
	syscall
	
	#move	$a0,$t0		#w a0 umieszczamy deskryptor pliku (tutaj to chyba nie potrzebne bo z poprzedniej operacji jest to co trzeba)
	la	$a1, temp	#zapisujemy tymczasowo wielkosc naglowka informacyjnego
	li	$a2,4		#ta wielkosc jest na 4 bajtach
	li	$v0,14		#wczytujemy z pliku
	syscall
	
	#move	$a0,$t0		#w a0 umieszczamy deskryptor pliku (tutaj to chyba nie potrzebne bo z poprzedniej operacji jest to co trzeba)
	la	$a1, width	#w zmiennej width zapisujemy szerokosc obrazu w pikselach
	li	$a2,4		#szerokosc jest na 4 bajtach
	li	$v0,14		#wczytujemy z pliku
	syscall
	
	lw	$t2,width	#do t2 przenosimy szerokosc obrazu
	
	#move	$a0,$t0		#w a0 umieszczamy deskryptor pliku (tutaj to chyba nie potrzebne bo z poprzedniej operacji jest to co trzeba)
	la	$a1,height	#w zmiennej height zapisujemy wysokosc obrazu w pikselach
	li	$a2,4		#wysokosc jest na 4 bajtach
	li	$v0,14		#wczytujemy z pliku
	syscall
	
	lw	$t3,height	#do t3 przenosimy wysokosc pliku w pikselach
	
	# t0 -> deskryptor pliku
	# t1 -> adres pamieci zaalokowanej na plik
	# t2 -> szerokosc obrazu
	# t3 -> wysokosc obrazu
	# t7 -> rozmiar pliku
	
	#move	$a0,$t0		#w a0 umieszczamy deskryptor pliku (tutaj to chyba nie potrzebne bo z poprzedniej operacji jest to co trzeba)
	li	$v0,16		# zamykamy plik
	syscall			# zamykamy plik, aby wskaznik odczytu ustawil sie na poczatek
##################################################################################################################################################################	
	
copy_from_file_to_memory:	#kopiujemy caly plik do pamieci
	la	$a0,name_input	#otwieramy plik o nazwie zapisanej w zmiennej name_imput
 	li	$a1,0		#flaga ustawiona na 0, aby moc otworzyc plik
   	li	$a2,1		#opcja ustawiona na 0
   	li	$v0,13		#13 oznacza otwieranie pliku
   	syscall
   	
   	move	$t0,$v0		#do t0 przenosimy deskryptor pliku
   	
   	bltz	$t0,error_opening	#jesli nie udalo sie otworzyc pliku (deskryptor jest wtedy mniejszy niz 0) konczymy program
   	
   	move	$a0,$t0		#w a0 umieszczamy deskryptor pliku
   	la	$a1,($t1)	#dane z pliku wczytujemy do zaalokowanej pamieci, ktorej adres zostal wczesniej zapisany w t1
   	la	$a2,($t7)	#z pliku wczytujemy tyle bajt�w ile wynosi rozmiar calego pliku (zostal on wczesniej zapisany w t7)
   	li	$v0,14		#14 oznacza wczytywanie danych z pliku
   	syscall
   	
   	move $s7,$v0
   	
   	#move	$a0,$t0		#w a0 umieszczamy deskryptor pliku (tutaj to chyba nie potrzebne bo z poprzedniej operacji jest to co trzeba)
	li	$v0,16		# zamykamy plik
	syscall			# zamykamy plik, bo juz wszystko co chcielismy wczytalismy z niego
	
	lw	$t9,offset	# w t9 ustawiamy wskaznik na adres poczatku tablicy pikseli
	addu	$t9,$t9,$t1	# w t9 jest teraz wskaznik poczatku tablicy przesuniety
				# poczatek bliku bmp jest w t1 i przesuwamy go o offset
	sw	$t9,table_of_pixels	#do zmiennej table_of_pixels kopiujemy adres poczatku tablicy pikseli	
	
	lw	$t7,size
	
	move	$a0,$t7		#do a0 kopiujemy rozmiar pliku, bo chce zeby na stosie mogło byc maksymalnie (width*height*3) elementow
	li	$v0,9		#alokacja pamieci na stos
	syscall
	
	move	$t8,$v0		#w t8 będzie wskaznik stosu
	
	# t0 -> deskryptor pliku
	# t1 -> wskaznik na pocatek tablicy w ktorej jest wczytany cały plik
	# t2 -> szerokosc obrazu
	# t3 -> wysokosc obrazu
	# t7 -> rozmiar pliku
   	# t9 -> adres poczatku tablicy pikseli 
   			
##########################################################################################################################################################

check_padding:
 	mul	$t6,$t2,3	# w t6 zapisujemy szerokosc pliku w bajtach. 24-bitowy format pliku bmp oznacza, że każdy piksel jest zapisywany na trzech bajtach
   	andi	$t6,$t6,3	# w t6 zapisujemy reszte z dzielenia (3* (szerokosc [w pikselach])) przez 4,  3*szerokosc to liczba bajtow w wierszu bez paddingu
   				#liczba bajtow musi byc podzielna przez 4, wiec jesli 3*szerokosc nie jest, to ta podzielnosc jest otrzymywana przez dodanie przez
   				#plik przy zapisie odpowiedniej liczby bajtow paddingowych
   				
   	beq	$t6,0,rest_0	#jest 0 bajtow paddingowych, czyli nie brakuje bajtow paddingowych	
   	beq	$t6,1,rest_1	#jest 1 bajt paddingowy, czyli brakuje 3 bajtow paddingowych
   	beq	$t6,2,rest_2	#sa 2 bajty paddingowe, czyli brakuje 2 bajtow paddingowych
   	beq	$t6,3,rest_3	#sa 3 bajty paddingowe, czyli brakuje 1 bajtu paddingowego

rest_0:
	li	$t6,0	#brakuje 0 bajtow paddingowych, bo ilosc bajtow w linijce jest podzielna przez 4
	sw  	$t6,padding
	b	main_part_of_the_program
	
rest_1:
	li	$t6,3	#brakuje 3 bajtow paddingowych
	sw  	$t6,padding
	b	main_part_of_the_program
	
rest_2:
	li	$t6,2	#brakuje 2 bajtow paddingowych
	sw	$t6,padding
	b	main_part_of_the_program

rest_3:
	li	$t6,1	#brakuje 1 bajta paddingowego
	sw	$t6,padding
	b	main_part_of_the_program

#####################################################################################################################################################################
#####################################################################################################################################################################
#####################################################################################################################################################################

#GLOWNA FUNKCJA PROGRAMU		
		
main_part_of_the_program:
	lw	$s0,padding

	la	$a0,text_begin_x	#wypisujemy tekst informujacy uzytkownika co ma zrobic
	li	$v0,4
	syscall
	
	li	$v0,5	#wczytujemy wspolrzedna x od ktorej zaczniemy algorytm wypelniania powodziowego
	syscall
	move	$t4,$v0
	sw	$t4,begin_x	#w begin_x zapisujemy wspolrzedna x punktu od ktorego zaczynamy algorytm
	
	la	$a0,text_begin_y	#wypisujemy tekst informujacy uzytkownika co ma zrobic
	li	$v0,4
	syscall
	
	li	$v0,5	#wczytujemy wspolrzedna y od ktorej zaczniemy algorytm wypelniania powodziowego
	syscall
	move	$t5,$v0
	sw	$t5,begin_y	#w begin_x zapisujemy wspolrzedna y punktu od ktorego zaczynamy algorytm

#########################################################################################################################################

flood_fill:
	lw	$t3,height
	li	$t1,0	#w trakcie dzialania programu bedzie to licznik elementow ktore znajduja sie na stosie	
					
	jal	go_to_point	#idziemy do punktu, z ktorego zaczynamy wypelnianie
	jal	find_segment	#dla wyznaczonego wyzej punktu znajdujemy segment do pomalowania
	jal	push_on_stack
	
stack_check:
	jal	pop_from_stack	#ze stosu pobieramy wartosci x,y,len
	jal	paint_segment
	
y_minus_minus:	#wywolujemy funkcje search_segment(x,y-1,len)
	lw	$t4,x_from_stack	#zapisujemy wartosci
	lw	$t5,y_from_stack	#zdjete ze stosu
	lw	$s5,len_from_stack	#
	
	ble	$t5,1,y_plus_plus	#sprawdzamy dla y pod
	addiu	$t5,$t5,-1
	sw	$t4,x_to_search_segment
	sw	$t5 y_to_search_segment
	sw	$s5,len_to_search_segment
	jal	search_segment
	
y_plus_plus:	#wywolujemy funkcje search_segment(x,y+1,len)
	lw	$t4,x_from_stack	#zapisujemy wartosci
	lw	$t5,y_from_stack	#zdjete ze stosu
	lw	$s5,len_from_stack	#	
	
	bge	$t5,$t3,jump_loop	#sprawdzamy dla y nad
	addiu	$t5,$t5,1
	sw	$t4,x_to_search_segment
	sw	$t5 y_to_search_segment
	sw	$s5,len_to_search_segment
	jal	search_segment

jump_loop:				#funkcja zakonczy dzialanie gdy nie bedzie juz nic do pobrania ze stosu, bo wtedy 
	j	stack_check		#zostanie wywolany komunikat o pustym stosie i przejscie do zapisywania pliku

#####################################################################################################################################################################
#####################################################################################################################################################################
#####################################################################################################################################################################

#FUNKCJE POMOCNICZE

go_to_point:	#w tej funkcji niezmienne sa $t4 oraz $t5
	sw	$t2,temp_1	#chce zeby wartosci w tych rejestrach nie byly tracone
	sw	$t3,temp_2	#
	lw	$t2,width
	lw	$t3,height
	lw	$t9,table_of_pixels	#wskaznik t9 umieszczam z powrotem na poczatku tablicy pikseli, zeby nie bylo przesuniec
	
	#ponizsze operacje zapewniaja nam to, że nie bedziemy pracowali na pikselu, ktorego nie ma na obrazku
	ble	$t4,0,error_beginning_x1	#jesli podana przez nas wspolrzedna x jest mniejsza niz 0, to blad i konczymy program
	ble	$t5,0,error_beginning_y1	#jesli podana przez nas wspolrzedna y jest mniejsza niz 0, to blad i konczymy program
	bgt	$t4,$t2,error_beginning_x2	#jesli podana przez nas wspolrzedna x jest wieksza niz szerokosc obrazu, to blad i konczymy program
	bgt	$t5,$t3,error_beginning_y2	#jesli podana przez nas wspolrzedna y jest wieksza niz wysokosc obrazu, to blad i konczymy program
	
	li	$s6,1	#licznik tego na ktorej pozycji x jestesmy	
	li	$s7,1	#licznki tego na ktorej pozycji y jestesmy
	sw	$ra,return_adress
	
find_point:		#przechodze do miejsca od ktorego zaczyna sie algorytm flood-fill	
	beq	$s6,$t4,check_y		

back:	jal	next_pixel
	bgt	$s6,$t2,next_line
	j	find_point

check_y:	#sprawdzam czy jak x jest dobre, to czy y tez jest dobre
	bne	$s7,$t5,back	#jak x i y sa dobre to konczymy szukanie
	j	go_to_point_end

next_pixel:	#przechodzimy do nastepnego piksela
	addiu	$t9,$t9,3	#kazdy piksel jest zapisywany na trzech bajtach
	addiu	$s6,$s6,1	#zwiekszamy licznik pozycji x
	jr	$ra		#wracamy tam gdzie wywolalismy ta funkcje
	
next_line:
	addu	$t9,$t9,$t6
	li	$s6,1		#jesli przechodzimy do kolejnej linijki, to wtedy licznik x jest ustawiany na pierwsza pozycje w nowej linijce
	addiu	$s7,$s7,1	#jesli przechodzimy do kolejnej linijki, to wtedy licznik y jest zwiekszany o 1
	j	find_point	#wracamy do funkcji szukajacej porzadanej pozycji

go_to_point_end:
	lw	$t2,temp_1	#chce, żeby te rejestry mogly byc swobodnie uzywane w innych funkcjach
	lw	$t3,temp_2	#bez obawy o strate ich zawartosci

	lw	$ra,return_adress
	jr	$ra	#wracamy do miejsca z ktorego wywolalismy funkcje 
				
########################################################################################################################################

search_segment:	#przed wejsciem do tej funkcji musimy zdejmujemy wartosci ze stosu i zapisujemy 
	sw	$ra,return_adress2
	
	lw	$t4,x_to_search_segment
	lw	$t5,y_to_search_segment
	lw	$s5,len_to_search_segment

	jal	go_to_point #idziemy do punktu od ktorego zaczynamy przeszukiwanie segmentu
	
	addu	$s7,$t4,$s5	#x2=x1+len-1 oznaczenia z internetu
	addiu	$s7,$s7,-1	#w s7 jest zapisywana dlugosc segmentu do sprawdzani
	
loop_s:	bgt	$t4,$s7,end_loop_s
	jal	load_pixel	#wczytujemy kolor piksela na pozycji x1,y1
	
	#sprawdzamy czy kolor piksela jest taki jak ten ktorym wypelniamy (zakladam, ze zawsze wypelniam kolorem o wspolrzednych 100,100,100)
	bne	$s0,1,next_s	#100
	bne	$s1,1,next_s	#100
	bne	$s2,254,next_s	#100
	addiu	$t4,$t4,2	#przesuwamy sie o dwie pozycje w prawo (licznik)
	addiu	$t9,$t9,6	#przesuwamy sie o dwa piskele dalej 6 = 2 * 3bajty
	
	j	loop_s		#kontynuujemy petle jezeli na obecnej pozycji byl piksel, ktorym wypelniamy
	
next_s:	jal	load_pixel	#wczytujemy kolor piksela
	bne	$s0,0,find_and_push	#sprawdzamy czy kolor piksela jest taki jak obramowki 	
	bne	$s1,0,find_and_push	#(zakladam, ze obramowka jest czarna,
	bne	$s2,0,find_and_push	#czyli ma wspolrzedne 0,0,0)
	addiu	$t4,$t4,1	#przesuwamy sie o jedna pozycje
	addiu	$t9,$t9,3	#przesuwamy sie na kolejny piksel
		
	j	loop_s		#kontynuujemy petle jezeli na obecnej pozycji byl piksel, ktorym wypelniamy
	
find_and_push:
	jal	find_segment	#szukamy segmentu dla danego punktu
	lw	$t9,return_f_s	#zapisujemy adres piksela, ktory zwrocilismy z funkcji find_segment
	
	addiu	$t4,$t4,1	#musimy dodac jeden, bo chcemy zeby indeks zgadzal sie z adresem piksela, a w funkcji find_segment na koneic adres wskazuje na piskel o nastepnym indeksie	
	lw	$s0,count_x1
	j	loop_s
	
end_loop_s:
	lw	$ra,return_adress2
	jr	$ra
	
###################################################################################################################################################################	
	
find_segment:	
	sw	$ra,return_adress1
	lw	$t2,width
	lw	$t3,height

	sw	$t9,x2	#ustawiamy koniec segmentu w punkcie startowym
	sw	$t4,count_x2	
	
	jal	load_pixel	#sprawdzamy czy piksel wejsciowy jest czarny
	bne	$s0,0,loop2	#jak tak, to wychodzimy z tej funkcji
	bne	$s1,0,loop2
	bne	$s2,0,loop2
	
	b	first_black_end	#jezeli na pierwszym wczytanym bajcie byl czarny piksel, to konczymy dzialanie programu
	
loop2:	addiu	$t9,$t9,-3	#przesuwamy sie w lewo o jeden piksel
	addiu	$t4,$t4,-1	#cofamy licznik pozycji x
	jal	load_pixel
	
	beq	$t4,0,p		#jesli doszlismy do krawedzi obrazka to wychodzimy z petli
	bne	$s0,0,loop2	#czarny kolor ma wszystkie wspolrzedne rowne 0
	bne	$s1,0,loop2
	bne	$s2,0,loop2
	
p:	addiu	$t9,$t9,3	#wracamy o jedna piksel w prawo, tak zebysmy byli na pierwszym pikselu do pomalowania
	addiu	$t4,$t4,1
	sw	$t9,x1		#ustawiamy lewy koniec segmentu w x1
	sw	$t4,count_x1
	
	lw	$t9,x2		#do t9 z powrotem ladujemy pozycje na ktorej byl punkt od ktorego zaczelismy szukac
	lw	$t4,count_x2	#do s6 z powrotem ladujemy licznik pozycji
	
	addiu	$t2,$t2,1	#powiekszamy szerokosc o 1, aby zamalowac caly obrazek
loop3:	addiu	$t9,$t9,3	#przesuwamy sie w prawo o jeden piksel
	addiu	$t4,$t4,1	#przesuwamy do przodu licznik pozycji x
	jal	load_pixel	
		
	beq 	$t4,$t2,r	#jesli doszlismy do krawedzi obrazka, to wychodzimy z petli	
	bne	$s0,0,loop3	#czarny kolor ma wszystkie wspolrzedne rowne 0
	bne	$s1,0,loop3
	bne	$s2,0,loop3
	
r:	sw 	$t9,x2		#ustawiamy pierwszy piksel za prawym koncem segmentu
	sw	$t4,count_x2	
	sw	$t5,count_y1		#zapisujemy wspolrzedna y na ktorej sie przemieszczalismy
	lw	$t0,count_x1
	subu	$t0,$t4,$t0
	sw	$t0,len		#zapisujemy dlugosc segmentu	
	
end_f_s:addiu	$t0,$t9,3	#w t0 zapisujemy pierwszy piksel na którym może się zacząć segment, jest to wartosc ktora zwracamy z tej funkcji
	sw	$t0,return_f_s
	jal	push_on_stack	#na stosie umieszczamy wartosci count_x1, count_y1, len
	lw	$ra,return_adress1
	jr	$ra

###########################################################################################################################################################

push_on_stack:	#do tej funkcji wchodzimy majac wartosci ktore chcemy zapisac w zmiennych: count_x1,count_y1,len
	lw	$t7,size	#rozmiar pamieci na stos jest taki sam jak rozmiar pamieci na obrazek
	bge	$t1,$t7,stack_overflow	#jezeli chcemy cos dodac do pelnego stosu, to blad i koniec programu
	
	#umieszczamy wartsoci na stosie
	lw	$t7,count_x1
	addiu	$t8,$t8,1	#przesuwamy wskaznik stosu zeby wskazywal na dodany element
	sb	$t7,($t8)	#zapisujemy wspolrzedna x poczatku segmentu na stosie
	
	lw	$t7,count_y1	
	addiu	$t8,$t8,1	#przesuwamy wskaznik stosu zeby wskazywal na dodany element
	sb	$t7,($t8)	#zapisujemy wspolrzedna y poczatku segmentu na stosie
	
	lw	$t7,len
	addiu	$t8,$t8,1	#przesuwamy wskaznik stosu zeby wskazywal na dodany element
	sb	$t7,($t8)	#zapisujemy dlugosc segmentu na stosie	
				
	addiu	$t1,$t1,3	#dodalismy 3 elementy, wiec zwiekszamy licznik elementow na stosie
	jr	$ra
	
###########################################################################################################################################################

pop_from_stack:
	beq	$t1,0,empty_stack
	
	lbu	$t7,($t8)		#odczytujemy wartosc ze stosu 
	sw	$t7,len_from_stack	#odczytana wartosc zapisujemy do zmiennej len_from_stack okreslajaca dlugosc segmentu do przetwarzania w funkcji search segment
	addiu	$t8,$t8,-1		#przesuwamy wskaznik stosu na poprzednia pozycje
	
	lbu	$t7,($t8)		#odczytujemy wartosc ze stosu 
	sw	$t7,y_from_stack	#odczytana wartosc zapisujemy do zmiennej y_from_stack okreslajaca wspolrzedna y kolejengo segmentu do przerabiania
	addiu	$t8,$t8,-1		#przesuwamy wskaznik stosu na poprzednia pozycje
	
	lbu	$t7,($t8)		#odczytujemy wartosc ze stosu 
	sw	$t7,x_from_stack	#odczytana wartosc zapisujemy do zmiennej x_from_stack okreslajaca wspolrzedna x kolejnego segmentu do przerabiania
	addiu	$t8,$t8,-1		#przesuwamy wskaznik stosu na poprzednia pozycje
	
	addiu	$t1,$t1,-3	#zdjelismy 3 elementy ze stosu, wiec zmniejszamy licznik elementow na stosie
	
	jr	$ra
	
##########################################################################################################################################################

paint_segment:	#do tej funkcji wchodzimy po zdjeciu danych ze stosu
	sw	$ra,return_adress3	#bedziemy w tej procedurze zmieniac wartosc tego rejestru przy wywolywaniu innych procedur
	sw	$t4,temp_1	#nie chce zeby te rejestry
	sw	$t5,temp_2	#tracily swoja pierwotna wartosc
	sw	$s5,temp_3	#w trakcie dzialania funkcji
	
	li	$s4,0	#licznik tego ile punktow chcemy pomalowac -> s4
	
	lw	$s5,len_from_stack	#ustawiam dlugosc segmentu do malowania
	lw	$t4,x_from_stack	#ladujemy zmienna x, ktora bedzie potem uzyta w funkcji go_to_point
	lw	$t5,y_from_stack	#ladujemy zmienna y, ktora bedzie potem uzyta w funkcji go_to_point
	
	jal	go_to_point	#pobieramy punkt, z którego zaczynamy wypelnienie segmentu
			
loop:	jal	load_pixel
	jal	paint_pixel
	addiu	$t4,$t4,1	#po zakonczeniu petli mamy w t4 wspolrzedna x ostatniego piksela z segmentu
	addiu	$s4,$s4,1
	addiu	$t9,$t9,3	#ta operacja sprawia ze idziemy na kolejny piksel, wiec malujemy piksele lezace kolo siebie(zakladam ze idziemy przez jeden wiersz)
	bne	$s4,$s5,loop
	
	sw	$t4,temp_1	#nie chce zeby te rejestry
	sw	$t5,temp_2	#tracily swoja pierwotna wartosc
	sw	$s5,temp_3	#w trakcie dzialania funkcji
	
	lw	$ra,return_adress3	#ladujemy adres powrotu z tej procedury
	jr	$ra
	
##########################################################################################################################################################		

paint_pixel:	#malujemy pixel na kolor o wspolrzednych 0,0,255, czyli czerwony
	li	$s0,1	#B	#100
	li	$s1,1	#G	#100
	li	$s2,254	#R	#100
	
	sb	$s0,($t9)	#pierwsza wspolrzedna koloru
	addi	$t9,$t9,1
	sb	$s1,($t9)	#druga wspolrzedna koloru
	addi	$t9,$t9,1
	sb	$s2,($t9)	#trzecia wspolrzedna koloru
	subiu	$t9,$t9,2	#cofamy sie zeby t9 wskazywal na pierwszy bajt danego piksela
	
	jr	$ra		#wracamy do miejsca z ktorego wywolalismy ta funkcje

###########################################################################################################################################################

load_pixel:	#przed wejsciem do tej funkcji w t9 musi byc pierwszy bajt na ktorym jest zapisany dany piksel
	lbu	$s0,($t9)	#pierwsza wspolrzedna koloru
	addiu	$t9,$t9,1
	lbu	$s1,($t9)	#druga wspolrzedna koloru
	addiu	$t9,$t9,1
	lbu	$s2,($t9)	#trzecia wspolrzedna koloru
	subiu	$t9,$t9,2	#cofamy sie zeby $t9 wskazywalo na pierwszy bajt daengo piksela
	
	jr	$ra		#wracamy do miejsca z ktorego wywolalismy ta funkcje
	
###########################################################################################################################################################

empty_stack:
	la	$a0,empty__stack
	li	$v0,4
	syscall
		
###########################################################################################################################################################
			
save_file:	#zapisujemy do pliku zmodyfikowany obraz
	la	$a0,name_output	#do a0 ladujemy nazw� pliku, do ktorego chcemy zapisa�
	li	$a1,1		#flaga ustaawiona na 1 umo�liwia zapisywanie do pliku
	li	$a2,0		#opcja ustawiona na 0
	li	$v0,13		#13 oznacza, �e otwieramy plik, do kt�ego b�dziemy zapisywali
	syscall
	move	$t0,$v0 	# do t0 przenosimy deskryptor pliku, do kt�rego chcemy zapisa�
	lw	$t7,size	# do t7 �adujemy rozmiar pliku, ktory modyfikowali�my
	lw	$t1,adress_of_allocated_memory_for_bitmap #do t1 ladujemy adres zaalokowanej pamieci na bitmape
	
	bltz	$t0,error_opening	#jesli plik, do ktoego chcemy zapisac nie zostal poprawnie otwarty, to konczymy dzialanie programu
	
	move	$a0,$t0		# ponownie przenosimy deskryptor (chyba niekonieczne
	la	$a1,($t1)	# dane pobieramy stamtad, gdzie je pierwotnie zapisalismy po pobraniu z pliku wejsciowego (czyli z t1)
	la	$a2,($t7)	# chcemy zapisa� tyle bajt�w ile wynosi rozmiar (został on zapisany w t7)
	li	$v0, 15		#15 oznacza, �e zapisujemy do pliku
	syscall
	
	j	close_file	#pomijamy wypisanie komunikatu o bledzie		
	
############################################################################################################################################################
	
error_opening:
	la	$a0, text_error
	li	$v0,4
	syscall
	j 	exit
	
############################################################################################################################################################	
	
error_beginning_x1:
	la	$a0, text_error_begin_x1
	li	$v0,4
	syscall
	j	exit
	
error_beginning_x2:
	la	$a0, text_error_begin_x2
	li	$v0,4
	syscall
	j	exit	
	
error_beginning_y1:
	la	$a0, text_error_begin_y1
	li	$v0,4
	syscall
	j	exit	
	
error_beginning_y2:
	la	$a0, text_error_begin_y2
	li	$v0,4
	syscall
	j	exit
		
###########################################################################################################################################################
	
close_file:
	move	$a0,$t0 	# do a0 przenosimy deskryptor pliku
	li	$v0,16		# etykieta 16 oznacza zamykanie pliku
	syscall
	
	la	$a0, text_end	#wypisujemy napis ko�cowy
	li	$v0,4
	syscall
	
	j	exit
	
###########################################################################################################################################################

stack_overflow:
	la	$a0,stack__overflow
	li	$v0,4
	syscall
	
	j	exit
	
###########################################################################################################################################################	
	
first_black_end:
	la	$a0,black_pixel
	li	$v0,4
	syscall
	
###########################################################################################################################################################	
	
exit:	li	$v0,10		#zakonczenie dzialania programu
	syscall
	
##########################################################################################################################################################