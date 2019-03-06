	;WSKAZNIKI LUB INTY
	;rdi - wskaznik na bitmape 
	;rsi - wysokosc bitmapy kopiujemy do r8
	;rdx - szerokosc bitmapy kopiujemy do r9
	;rcx - maksymalna ilosc iteracji
	;r8 -  
	;r9 -
	
	;FLOATY LUB DOUBLE
	;xmm0 - czesc rzeczywista parametru c
	;xmm1 - czesc urojona parametru c
	;xmm2 - wspolrzedna x srodka ukladu
	;xmm3 - wspolrzedna y srodka ukladu
	;xmm4 - wielkosc przyblizenia
	;xmm5
	;xmm6
	;xmm7

section .text
global julia

julia:
	push rbp
	mov rbp, rsp

poli:

	mov	r8,rsi		;kopiujemy wysokosc obrazka do r8
	mov	r9,rdx		;kopiujemy szerokosc obrazka do r9
  	
	mov	r10,0		;r10 bedzie wskazywalo na aktualny mumer wiersza pikseli
	mov	r11,0		;r11 bedzie wskazywalo na aktualny numer kolumny pikseli

loop_y:
	cmp	r8,r10		;porownujemy wysokosc obrazka z aktualnym numerem wiersza
	je	end		;jezeli sa rowne to konczymy, bo juz przejrzelismy wszystkie piksele

loop_x: cmp	r9,r11		;porownujemy szerokosc obrazka z 
	je	end_of_loop_x	;jezeli sa rowne to konczymy ta petle i zwiekszamy numer wiersza

	;licze parametry danego piksela w moim wykresie zespolonym
	;najpierw y	
	mov	r12,400
	cvtsi2ss xmm7,r12	;w xmm7 jest 400
	
	sub	r12,r10		;w r12 jest 400 minus 'aktualny numer numer wiersza pikseli'   
	cvtsi2ss xmm6,r12	;wartosc r12 konwertujemy na double

	addss	xmm6,xmm3	;przesuwamy o tyle ile jest oddalony od srodka ukladu wspolrzednych na osi y

	divss	xmm6,xmm7
	mov	r12,3		;do xmm7 chcemy zapisac 1.5
	cvtsi2ss xmm7,r12
	mov	r12,2
	cvtsi2ss xmm8,r12
	divss	xmm7,xmm8	;w xmm7 jest 1.5

	mulss	xmm7,xmm4	;zwiekszamy zoom

	mulss	xmm6,xmm7	;w xmm6 jest wspolrzedna urojona punktu
		
	;teraz x
	;mov	r13,400
	;mov	r12,r11
	;cvtsi2ss xmm8,r13
	;sub	r12,r13
	;cvtsi2ss xmm7,r12
	
	mov	r12,400
	cvtsi2ss xmm8,r12
	sub	r12,r11
	cvtsi2ss xmm7,r12	

	addss	xmm7,xmm2	;przesuwamy o tyle ile jest oddalony od srodka ukladu wspolrzednych na osi x

	divss	xmm7,xmm8
	mov	r12,3
	cvtsi2ss xmm8,r12
	mov	r12,2
	cvtsi2ss xmm9,r12
	divss	xmm8,xmm9
	
	mulss	xmm8,xmm4	;zwiekszamy zoom	
	
	mulss	xmm7,xmm8	;w xmm7 jest wspolrzedna rzeczywista punktu

	;teraz robie while w ktorym sprawdzam czy jest wiezien czy uciekinier
	;xmm0 - czesc rzeczywista wspolczynnika c
	;xxm1 - czesc urojona wspolczynnika c
	;xmm8 - czesc rzeczywista lizby z
	;xmm9 - czesc urojona liczby z
	mov	r13,rcx		;maksymalna ilosc iteracji
	mov	r12,0		;licznik iteracji
	movss	xmm8,xmm7	;czesc rzeczywista obliczona wyzej
	movss	xmm9,xmm6	;czesc urojona obliczona wyzej

tata:

do_while:
	;teraz trzeba policzyc czesc rzeczywista nowej liczby z
	movss	xmm10,xmm8	;uzyjemy tego przy liczeniu nowej czesci urojonej
	movss	xmm11,xmm9
	mulss	xmm8,xmm8	;zR*zR
	mulss	xmm11,xmm11	;zU*zU
	subss	xmm8,xmm11	;zR*zR - zU*zU
	addss	xmm8,xmm0	;zR*zR - zU*zU + cR

	;teraz trzeba policzyc czesc urojona nowej liczby z
	mov r14,2
	cvtsi2ss xmm11,r14
	mulss	xmm9,xmm11	;2*zU
	mulss	xmm9,xmm10	;2*zU*zR
	addss	xmm9,xmm1	;2*zU*zR+cU

	add	r12,1		;zwiekszamy licznik iteracji
	cmp	r12,r13		;porownujemy aktulany licznik z maksymalna iloscia iteracju
	je	fugutive
	
	;tutaj jeszcze warunek ze kwadrat modulu mniejszy niz 4
	movss	xmm10,xmm8	;czesc rzeczywista nowego z w xmm10
	movss	xmm11,xmm9	;czesc urojona nowego z w xmm11
	;mov	r14,4
	;cvtsi2ss xmm12,r14	;konwertujemy liczbe 4 do zmiennoprzecinkowych zeby moc ja porownac z kwadratem modulu
	mulss	xmm10,xmm10	;zR*zR
	mulss	xmm11,xmm11	;zU*zU
	addss	xmm10,xmm11	;zR*zR+zU*zU
	
	mov	r14,1000000
	cvtsi2ss xmm12,r14
	mulss	xmm10,xmm12	;przesuwamy przecinek zeby bez zbyt duzej straty zamienic na int i porownac
	cvtss2si r14,xmm10

	mov	r15,4000000
	

show:

	cmp	r14,r15	;porownujemy kwadrat modulu i 4
	jg	fugutive

	jmp	do_while	;wracamy na poczatek petli do_while
		

next_x:
	add	r11,1		;zwiekszamy numer kolumny w ktorej bedziemy aktualnie pracowac
	jmp	loop_x


;punkt jest wiezniem wiec nalezy do zbioru julii (malujemy go na 255,0,0)
;prisoner:
;	mov	r14,r10		;kopiujemy numer wiersza
;	mov	r15,rdi		;ustawiamy poczatek bitmapy
;	shl	r14,3		;wysokosc bitmapy *8 bo 64 bitowe
;	add	r15,r14		;przesuwamy sie do wiersza
;	mov	rbx,[r15]
;;
;	mov	r14,r11
;;	add	r14,r11
;	add	r14,r11		;w tym momencie r14 = 3*r11
;	add	rbx,r14		;przesuwamy sie do kolumny
;	mov	rax,r12		
;	mov	[rbx],rax	;malujemy pierwsza skaldowa koloru
;	add	rbx,1
;	mov	rax,0
;;	mov	[rbx],rax	;malujemy pierwsza skaldowa koloru
;	add	rbx,1
;	mov	rax,0	
;	mov	[rbx],rax	;malujemy pierwsza skaldowa koloru
;
;	jmp	next_x


;punkt jest uciekinierem weic nie nalezy do zbioru julii( malujemy go na 0,0,255)
fugutive:

po:
	mov	r14,r10		;kopiujemy numer wiersza
	mov	r15,rdi		;ustawiamy poczatek bitmapy
	shl	r14,3		;wysokosc bitmapy *8 bo 64 bitowe
	add	r15,r14		;przesuwamy sie do wiersza
	mov	rbx,[r15]

	mov	r14,r11
	add	r14,r11
	add	r14,r11		;w tym momencie r14 = 3*r11
	add	rbx,r14		;przesuwamy sie do kolumny
	mov	rax,0		
	mov	[rbx],rax	;malujemy pierwsza skaldowa koloru
	add	rbx,1
	mov	rax,0
	mov	[rbx],rax	;malujemy pierwsza skaldowa koloru
	add	rbx,1
	mov	rax,r12	
	mov	[rbx],rax	;malujemy pierwsza skaldowa koloru

after:

	jmp	next_x

end_of_loop_x:
	add 	r10,1		;zwiekszamy numer wiersza w ktorym bedziemy aktualnie pracowac
	mov	r11,0
	jmp	loop_y




end:
	mov rsp, rbp
	pop rbp
	ret
