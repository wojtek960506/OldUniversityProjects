#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SOIL.h>

#include <iostream>

#include "WZ_ShaderProgram.h"
#include "WZ_Camera.h"
#include "WZ_VerticesAndIndices.h"

using namespace std;

//deklaracje funkcji
void key_callback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mode);
void mouse_callback(GLFWwindow* window, GLdouble xpos, GLdouble ypos);
void scroll_callback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset);
void processInput(GLFWwindow *window);
GLuint loadTexture(const GLchar* fname);
void increaseCameraAccuracyWhileMovingWithKeyboard();
void doAnimation();

// rozmiary ekranu
const GLuint WIDTH = 1200;
const GLuint HEIGHT = 800;

//kamera
Camera camera = Camera();

//wspolrzedne srodka ekranu
GLfloat lastX = WIDTH / 2;
GLfloat lastY = HEIGHT / 2;

GLboolean firstMouse = true; //poczatkowy stan myszy

//zapewnia dzialanie na roznych maszynach
float deltaTime = 0.0f;
float lastFrame = 0.0f;

//natezenie swiatla
GLfloat ambient = 1.0f;

//const glm::vec3 AMBIENT = glm::vec3(0.99f, 0.99f, 0.99f);

//poczatkowy widok

const glm::vec3 START_POSITION = glm::vec3(-1.0f, -6.0f, -10.0f);
const GLfloat START_ANGLE = -60.0f;

//ustawienia animacji
const GLfloat START_DELAY = 2.0f;
const GLfloat DELAY_BETWEEN_SEQUENCES = 0.5f;
const GLfloat UNSCREW_DEALY = 0.5f;
const GLfloat MOVING_SPEED = 0.025;	//przysuwanie i odsuwanie klucza
const GLfloat ROTATING_SPEED = 4.0f;
const GLfloat GOING_DOWN_SPEED = 0.0025f;
const GLfloat WRENCH_POSITION_BEFORE_MOVING = -2.0f;

//stale do animacji
GLfloat wrenchPositionZ = WRENCH_POSITION_BEFORE_MOVING;
GLfloat startTime = (GLfloat)glfwGetTime();
GLfloat currentTime = 0;
GLfloat onceAgain = 1000.0f; //zeby sie nie zaczelo za szybko
GLboolean goDown = false;
GLboolean goBack = false;
GLboolean doRotate = false;
GLfloat angle = 0.0f;
GLfloat positionY = 0.0f;

int main()
{
	//inicjujemy okno
	if (glfwInit() != GL_TRUE)
	{
		cout << "GLFW initialization failed" << endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); //nie mozna zmieniac rozmiaru okna

	try {
		
		//tworzymy obiekt w ktorym przechowujemy informacje o oknie
		GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
		if (window == nullptr)
			throw exception("GLFW window not created");																										//
		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, key_callback);	//ta funkcja ustala nam sposob zamkniecia programu
		glfwSetCursorPosCallback(window, mouse_callback);	//w funkcji mouse_callback definiuje zachowanie myszki
		glfwSetScrollCallback(window, scroll_callback); //w funkcji scroll_callback definiujemy zoom																							//
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //uruchomiona obsluga myszki																										//
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw exception("GLEW Initialization failed");
		glViewport(0, 0, WIDTH, HEIGHT);
		glEnable(GL_DEPTH_TEST); //bedziemy uzywali z-bufora	
		//----------------------------------------------------------------------------------------------------------//

		//tworzenie i kompilacja shadera
		ShaderProgram cubeShader = ShaderProgram("WZ_VertexShader.vert", "WZ_FragmentShader.frag");
		ShaderProgram wrenchShader = ShaderProgram("WZ_VertexShader.vert", "WZ_FragmentShader.frag");
		ShaderProgram screwShader = ShaderProgram("WZ_VertexShader.vert", "WZ_FragmentShader.frag");
		ShaderProgram grassShader = ShaderProgram("WZ_VertexShader.vert", "WZ_FragmentShader.frag");

		//tworzymy obiekty do przechowywania wierzcholkow wszystkich obiektow
		//szescian
		GLuint cubeVBO;
		GLuint cubeVAO;
		GLuint cubeEBO; //
		glGenVertexArrays(1, &cubeVAO); //1 to ilosc buforow ktore definiujemy 
		glGenBuffers(1, &cubeVBO);
		glGenBuffers(1, &cubeEBO); //
		glBindVertexArray(cubeVAO); //
		glBindBuffer(GL_ARRAY_BUFFER,cubeVBO); //teraz do tablicy buforow dolaczamy nasz bufor wierzcholkow
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);	//
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW); //
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		//trawa
		GLuint grassVBO;
		GLuint grassVAO;
		GLuint grassEBO;
		glGenVertexArrays(1, &grassVAO);
		glGenBuffers(1, &grassVBO);
		glGenBuffers(1, &grassEBO);
		glBindVertexArray(grassVAO);
		glBindBuffer(GL_ARRAY_BUFFER, grassVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(grassVertices), grassVertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, grassEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(grassIndices), grassIndices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		
		//klucz
		GLuint wrenchVBO;
		GLuint wrenchVAO;
		GLuint wrenchEBO;
		glGenVertexArrays(1, &wrenchVAO);
		glGenBuffers(1, &wrenchVBO);
		glGenBuffers(1, &wrenchEBO);
		glBindVertexArray(wrenchVAO);
		glBindBuffer(GL_ARRAY_BUFFER, wrenchVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(wrenchVertices), wrenchVertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, wrenchEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(wrenchIndices), wrenchIndices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		//sruba
		GLuint screwVBO;
		GLuint screwVAO;
		GLuint screwEBO;
		glGenVertexArrays(1, &screwVAO);
		glGenBuffers(1, &screwVBO);
		glGenBuffers(1, &screwEBO);
		glBindVertexArray(screwVAO);
		glBindBuffer(GL_ARRAY_BUFFER, screwVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(screwVertices), screwVertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, screwEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(screwIndices), screwIndices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		//ladujemy tekstury 
		GLuint cubeTexture = loadTexture("container2.png");
		GLuint grassTexture = loadTexture("grass.JPG");
		GLuint wrenchTexture = loadTexture("wrench.jpg");
		GLuint screwTexture = loadTexture("screw.png");

		//konfiguracja shaderow
		cubeShader.use();
		cubeShader.setInt("texture1", 0);
		wrenchShader.use();
		wrenchShader.setInt("texture1", 1);
		grassShader.use();
		grassShader.setInt("texture1", 2);
		screwShader.use();
		screwShader.setInt("texture1", 3);

		//glowna petla programu. Czeka az wywolamy zamkniecie okna
		while (!glfwWindowShouldClose(window))
		{
			increaseCameraAccuracyWhileMovingWithKeyboard();			//zwieksza dokladnosc przesuwania kamery klawiatura
			processInput(window); //sprawdzamy czy zostal wcisniety ESC
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	//za kazdym obiegiem petli odswiezamy to co jest wyswietlane
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			//tu jest ustawiony kolor ekranu

			//przykrecanie i odkrecanie sruby
			doAnimation();

			//ustawiamy macierze projekcji i widoku (one sa wszystkie takie same dla naszych obiektow)
			glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
			glm::mat4 view = camera.getViewMatrix();

			glm::mat4 modelCube;
			glm::mat4 modelWrench;
			glm::mat4 modelScrew;
			glm::mat4 modelGrass;

			//SZESCIAN
			cubeShader.use();
			cubeShader.setMat4("projection", projection);
			cubeShader.setMat4("view", view);
			modelCube = glm::translate(modelCube, START_POSITION);
			modelCube = glm::rotate(modelCube, glm::radians(START_ANGLE), glm::vec3(0.0f, 1.0f, 0.0f));
			modelCube = glm::translate(modelCube, glm::vec3(0.0f, 1.5f, 0.0f));
			modelCube = glm::scale(modelCube, glm::vec3(4.0f, 4.0f, 4.0f));
			cubeShader.setMat4("model", modelCube);
			cubeShader.setVec3("ambient", glm::vec3(ambient, ambient, ambient));
			//rysujemy szescian
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, cubeTexture);
			glBindVertexArray(cubeVAO);
			glDrawElements(GL_TRIANGLES, VERTICES_IN_CUBE, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
			
			//KLUCZ
			wrenchShader.use();
			wrenchShader.setMat4("projection", projection);
			wrenchShader.setMat4("view", view);
			modelWrench = glm::translate(modelWrench, START_POSITION);
			modelWrench = glm::rotate(modelWrench, glm::radians(START_ANGLE), glm::vec3(0.0f, 1.0f, 0.0f));
			modelWrench = glm::translate(modelWrench, glm::vec3(0.0f, 4.6f-positionY, wrenchPositionZ));
			modelWrench = glm::rotate(modelWrench, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
			modelWrench = glm::scale(modelWrench, glm::vec3(0.1f, 0.1f, 0.1f));
			modelWrench = glm::translate(modelWrench, glm::vec3(0.0f, 0.0f, -7.5f)); //to ustawia nam wokol ktorego punktu sie obiekt kreci
			wrenchShader.setMat4("model", modelWrench);
			wrenchShader.setVec3("ambient", glm::vec3(ambient, ambient, ambient));
			//rysujemy klucz
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, wrenchTexture);
			glBindVertexArray(wrenchVAO);
			glDrawElements(GL_TRIANGLES, VERTICES_IN_WRENCH, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
			
			//SRUBA
			screwShader.use();
			screwShader.setMat4("projection", projection);
			screwShader.setMat4("view", view);
			modelScrew = glm::translate(modelScrew, START_POSITION);
			modelScrew = glm::rotate(modelScrew, glm::radians(START_ANGLE), glm::vec3(0.0f, 1.0f, 0.0f));
			modelScrew = glm::translate(modelScrew, glm::vec3(0.0f, 4.6f-positionY, 0.0f));	//to ustawia nam przesuniecie obiektu
			modelScrew = glm::rotate(modelScrew, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
			modelScrew = glm::scale(modelScrew, glm::vec3(0.1f, 0.1f, 0.1f));
			modelScrew = glm::translate(modelScrew, glm::vec3(0.0f, -0.1f, -4.5f)); //to ustawia nam wokol ktorego punktu sie obiekt kreci
			screwShader.setMat4("model", modelScrew);
			screwShader.setVec3("ambient", glm::vec3(ambient, ambient, ambient));
			//rysujemy srube
			glActiveTexture(GL_TEXTURE3);
			glBindTexture(GL_TEXTURE_2D, screwTexture);
			glBindVertexArray(screwVAO);
			glDrawElements(GL_TRIANGLES, VERTICES_IN_SCREW, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			//TRAWA
			grassShader.use();
			grassShader.setMat4("projection", projection);
			grassShader.setMat4("view",view);
			modelGrass = glm::translate(modelGrass, START_POSITION);
			modelGrass = glm::rotate(modelGrass, glm::radians(START_ANGLE), glm::vec3(0.0f, 1.0f, 0.0f));
			modelGrass = glm::translate(modelGrass, glm::vec3(0.0f, -0.5f, 0.0f));
			grassShader.setMat4("model", modelGrass);
			grassShader.setVec3("ambient", glm::vec3(ambient, ambient, ambient));
			//rysujemy trawe
			glActiveTexture(GL_TEXTURE2);
			glBindTexture(GL_TEXTURE_2D, grassTexture);
			glBindVertexArray(grassVAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			glfwSwapBuffers(window); //czyszczenie bufora kolorow
			glfwPollEvents();	//sprawdza czy cos sie zadzialo
		}

		//usuwamy wszystkie bufory, bo juz nie beda nam potrzebne
		glDeleteVertexArrays(1, &cubeVAO);
		glDeleteVertexArrays(1, &grassVAO);
		glDeleteVertexArrays(1, &wrenchVAO);
		glDeleteVertexArrays(1, &screwVAO);
		glDeleteBuffers(1, &grassEBO);
		glDeleteBuffers(1, &grassVBO);
		glDeleteBuffers(1, &wrenchEBO);
		glDeleteBuffers(1, &wrenchVBO);
		glDeleteBuffers(1, &screwEBO);
		glDeleteBuffers(1, &screwVBO);
		glDeleteBuffers(1, &cubeEBO);
		glDeleteBuffers(1, &cubeVBO);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	//system("pause");
	glfwTerminate();
	return 0;
}

/*---------------------FUNKCJE----------------------*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


//obsluga myszy
void mouse_callback(GLFWwindow* window, GLdouble xpos, GLdouble ypos) {

	if (firstMouse) { //zapewniamy, ze pierwsze najechanie myszka na ekran nie powoduje dziwnego przeskoku ekranu
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;	//sprawdzamy przesuniecie myszki i zapamietujemy ostatnia pozycje
	GLfloat yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	camera.processMouseMovement(xoffset, yoffset);
}

//obsluga zoomu 
void scroll_callback(GLFWwindow* window, GLdouble xoffset, GLdouble yoffset)
{
	camera.processMouseScroll(yoffset);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	//ruchy kamery
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.processKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.processKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.processKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.processKeyboard(RIGHT, deltaTime);

	//intensywnosc swiatla
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
		ambient += 0.005f;
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		ambient -= 0.005f;

	if (ambient > 1.0f)
		ambient = 1.0f;
	if (ambient < 0.0f)
		ambient = 0.0f;
}

//ladowanie tekstury
GLuint loadTexture(const GLchar* fname)	//przekazujemy ktory unit tekstury aktywujemy i nazwe pliku z ktorego pobieramy wzor
{
	//generujemy bufor tekstury i przypisujemy mu Id
	GLuint texture;
	glGenTextures(1, &texture);
	
	GLint width, height;	//szerokosc i wysokosc tekstury

	unsigned char* image = SOIL_load_image(fname, &width, &height, 0, SOIL_LOAD_RGB); //ladujemy obrazek
	if (image == nullptr)
		throw exception("Failed to load texture file");

	glBindTexture(GL_TEXTURE_2D, texture); //dolaczamy teksture i specyfikujemy, ze jest to tekstura 2D
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image); //specyfikujemy ze wygenerujemy teksture na juz
	//dolaczonym obiecie 2D ; specyfikujemy poziom mipmap ; format zapisu ; szerokosc i wysokosc, ktore wczesniej ustalilismy ; zawsze 0 ; format
	//dostarczonego obrazka ; typ danych w dostarczonym obrazku ; wlasciwy obrazek do tekstury, ktory odczytalismy

	//ustawiamy to jak sie zachowuje tekstura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D); //generujemy wszystkie wymagane mipmapy dla danej tekstury
	SOIL_free_image_data(image);	//czyscimy pamiec, bo juz nam nie potrzebna
	glBindTexture(GL_TEXTURE_2D, 0);	//odpinamy teksture
	return texture;
}

void increaseCameraAccuracyWhileMovingWithKeyboard() {

	GLfloat currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

}

void doAnimation() {
	//dojezdzamy do klucza
	if (glfwGetTime() - startTime > START_DELAY || glfwGetTime() - onceAgain > DELAY_BETWEEN_SEQUENCES) {
		if (wrenchPositionZ < 0 && !goBack)
			wrenchPositionZ += MOVING_SPEED;
		if (wrenchPositionZ > 0) {
			wrenchPositionZ = 0;
			doRotate = true;
			goDown = true;
			goBack = true;
		}
	}

	//przykrecamy
	if (doRotate && goDown) { //krecimy
		angle += ROTATING_SPEED;
		positionY += GOING_DOWN_SPEED;
		if (positionY > 0.8f) {
			goDown = false;
			positionY = 0.8f;
			currentTime = (GLfloat)glfwGetTime();
		}
	}

	//odkrecamy
	if (doRotate && !goDown) {
		if (glfwGetTime() - currentTime > UNSCREW_DEALY) {
			angle -= ROTATING_SPEED;
			positionY -= GOING_DOWN_SPEED;
			if (positionY < 0.0f) {
				goDown = true;
				doRotate = false;
				positionY = 0.0f;
			}
		}
	}

	//cofamy sie 
	if (!doRotate && goDown) {
		if (wrenchPositionZ > WRENCH_POSITION_BEFORE_MOVING && goBack)
			wrenchPositionZ -= MOVING_SPEED;
		if (wrenchPositionZ < WRENCH_POSITION_BEFORE_MOVING) {
			wrenchPositionZ = WRENCH_POSITION_BEFORE_MOVING;
			goBack = false;
			onceAgain = (GLfloat)glfwGetTime();
			startTime = 1000.0f; //zeby poczekalo
		}
	}
}

/*------------------KONIEC FUNKCJI----------------------------*/