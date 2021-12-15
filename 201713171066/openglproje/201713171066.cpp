#include <GL/glut.h>

float xKupgotur = -1.5f, yKupgotur = 0.0f, zKupgotur = -7.0f;  //Küpün x,y,z deki başlangıç konumları
float xPiramitgotur = 2.0f, yPiramitgotur = 0.0f, zPiramitgotur = -7.0f; //Piramitin x,y,z deki başlangıç konumları

GLfloat aciPiramit = 0.0f; // Pramitin dönme açısı (GLfloat-->GL'in kendi float'ı )
//float aciPiramit=0.0;
GLfloat aciKup = 0.0f; // Kübün dönme açısı
int t_yenileme = 20; // milisaniye cinsinden yenileme aralığı
/* Kendi OpenGL Grafik ayarlarımızı yapalım */
void Ayarlar() {
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f); 
	glClearDepth(1.0f); 
	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LEQUAL); 

	glShadeModel(GL_SMOOTH); 
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}

void CizimFonksiyonu()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW); 
	// piramit için 4 üçgen lazım
	glLoadIdentity(); 

	glTranslatef(xPiramitgotur, yPiramitgotur, zPiramitgotur);  // Piramiti ötelemek için 
	glRotatef(aciPiramit, 1.0f, 1.0f, 0.0f);


	



	glBegin(GL_TRIANGLES); // piramit için 4 üçgen lazım
	 // Ön
	glColor3f(1.0f, 0.0f, 0.0f); // Kırmızı
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); // Yeşil
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); // Mavi
	glVertex3f(1.0f, -1.0f, 1.0f);

	// sağ
	glColor3f(1.0f, 0.0f, 0.0f); // Kırmızı
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f); // Mavi
	glVertex3f(1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f); // yeşil
	glVertex3f(1.0f, -1.0f, -1.0f);
	// arka
	glColor3f(1.0f, 0.0f, 0.0f); // Kırmızı
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); // Yeşil
	glVertex3f(1.0f, -1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); // Mavi
	glVertex3f(-1.0f, -1.0f, -1.0f);
	// sol
	glColor3f(1.0f, 0.0f, 0.0f); // Kırmızı
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f); // Mavi
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glColor3f(0.0f, 1.0f, 0.0f); // Yeşil
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd(); // Piramit çizimi bitti
	// Kenarları Farklı renklerde olan renkli küp yapalım
	glLoadIdentity(); // Orjinal Duruma dönülür (Reset) (Reset model-view matrix)
	glTranslatef(xKupgotur, yKupgotur, zKupgotur); // Küpü ötelemek için
	glRotatef(aciKup, 1.0f, 0.0f, 0.0f); // Rotate (1,0,0)-axis (x-ekseni etrafında dönüş)





	glBegin(GL_QUADS); // Küp için 6 kare-yüz lazım

					   // üst yüz (y = 1.0f)
	// köşeleri saat yönünün tersine sıralayacağız
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f); // pembe
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	// Alt yüz (y = -1.0f)
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f); // Turuncu
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Ön yüz (z = 1.0f)
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f); // Mavi
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Arka yüz (z = -1.0f)
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f); // SArı
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);


	// sol yüz (x = -1.0f)
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); // Kırmızı
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// sağ yüz (x = 1.0f)
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f); // Yeşil
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd(); // Renkli küp çiziminin sonu
	//glflush(); -->Yetmez, glutSwapBuffers()lazım
	glutSwapBuffers(); /*Çerçeveyi çizdikten sonra Ön ve arka tamponlar değişir. Burada, biri
	gösterilen diğeri gizlenen, çift tampon modunda pencere kullanıyoruz. Bu durumda OpenGL
	komutlarının görüntülenmesi daima gizli tampon içine yapılır. glutSwapBuffers(), çağrıldığında,
	tamponları değiştokuş ederek çizileni pencere içinde görüntüler. Tercih edilmesinin nedeni,
	çerçeve içeriğinin satır satır oluşumunu insan gözünden saklamasıdır*/
	aciPiramit += 1.0f;
	aciKup -= 0.2f;
}
void zamanlayici(int value) {
	glutPostRedisplay(); //CizimFonksiyonu()'nun yaptığı işlem sonrası güncelleme için
	glutTimerFunc(t_yenileme, zamanlayici, 0); // next timer call milliseconds later
}
/*pencerenin en boy oranını için: */
void GorunumAyari(GLsizei x, GLsizei y) //x:genişlik, y:yükseklik
{ // "GLsizei"(negatif olmayan tamsayı demektir. int width; diyebilirdik)
 // Yeni pencerenin en boy oranını hesaplama
	if (y == 0) y = 1; // 0'a bölümden korunmak için
	GLfloat oran = (GLfloat)x / (GLfloat)y; //float oran; diyebilirdik
	/* Genellikle pencere genişliği ile aynıdır. Eğer viewport genişlik / yükseklik oranı
	projeksiyondakinden farklı ise nesneler olduklarından farklı biçimde görünebilirler*/
	glViewport(0, 0, x, y);
	// en boy oranını görünüm penceresiyle eşleşecek şekilde ayarlama:
	glMatrixMode(GL_PROJECTION); // projeksiyon (izdüşüm) matrisi
	//izdüşüm görünümüne ayarlamak için
	glLoadIdentity(); // Orjinal Duruma dönülür (Reset)
	// Perspectif projeksiyon yapar--> gluPerspective (theta, aspect, dnear, dfar)
	gluPerspective(45.0f, oran, 1.0f, 20.0f);
	//Bu fonksiyondaki theta perspektifin yaptığı dönüş açısını,
	//aspect en / boy oranını,
	//dnear ve dfar ise sırasıyla yakın ve uzak perspektif panellerine olan uzaklığı

		//0-180 arası olacak.Nesneye ne kadar yakınsak o kadar dar açı olmalı,
		//ne kadar uzaksak o kadar geniş açı olmalı
		//(float)en/(float)boy --> tam ekran yapıldığında bozulmasın diye
		//1.0 kameranın modele(çokgene) en yakın olabileceği yer
		//20.0 kameranın modele(çokgene) en uzak olabileceği yer
}



void Kupgotursag(void)//Küpü sağa ilerletmek için fonksiyon
{
	glLoadIdentity();//koordinat sistemimiz

	xKupgotur += 0.1;
}
void Kupgotursol(void)//Küpü sola geriletmek için fonksiyon
{
	glLoadIdentity();
	xKupgotur -= 0.1;
}
void Kupgoturyuk(void)//Küpü yukarı götürmek için fonksiyon
{
	glLoadIdentity();
	yKupgotur += 0.1;
}
void Kupgoturas(void)//Küpü aşağı götürmek için fonksiyon
{
	glLoadIdentity();
	yKupgotur -= 0.1;
}
void Kupgoturil(void)//Küpü ilerletmek için fonksiyon
{
	glLoadIdentity();
	zKupgotur -= 0.1;
}
void Kupgoturger(void)//Küpü geriletmek için fonksiyon
{
	glLoadIdentity();
	zKupgotur += 0.1;
}
void Piramitgotursag(void)  //Piramiti sağa ilerletmek içn fonksiyon
{
	glLoadIdentity();//koordinat sistemimiz

	xPiramitgotur += 0.1;
}
void Piramitgotursol(void) //Piramiti sola geriletmek içn fonksiyon
{
	glLoadIdentity();
	xPiramitgotur -= 0.1;
}
void Piramitgoturyuk(void) //Piramiti yukarı götürmek içn fonksiyon
{
	glLoadIdentity();
	yPiramitgotur += 0.1;
}
void Piramitgoturas(void) //Piramiti aşağı götürmek içn fonksiyon
{
	glLoadIdentity();
	yPiramitgotur -= 0.1;
}
void Piramitgoturil(void)//Piramiti ileri götürmek içn fonksiyon
{
	glLoadIdentity();
	zPiramitgotur -= 0.1;
}
void Piramitgoturger(void)//Piramiti geri götürmek içn fonksiyon
{
	glLoadIdentity();
	zPiramitgotur += 0.1;
}


void klavye(int dugme, int x, int y)
{//yalnız özel işlev tuşlarını kullanabiliriz-->F1,Insert, ok tuşları gibi
	switch (dugme)
	{   //Hangi özel tuş seçildiğinde hangi fonksiyonun çalışacağını belirliyoruz.
	case GLUT_KEY_LEFT:Kupgotursol(); break;
	case GLUT_KEY_RIGHT:Kupgotursag(); break;
	case GLUT_KEY_UP:Kupgoturyuk(); break;
	case GLUT_KEY_DOWN:Kupgoturas(); break;
	case GLUT_KEY_PAGE_UP:Kupgoturil(); break;
	case GLUT_KEY_PAGE_DOWN:Kupgoturger(); break;
	}
	glutPostRedisplay();//hareket(işlem) sonrasıgüncelleme için
}

void klavye(unsigned char dugme, int x, int y)
{//yalnız karakter tuşlarını kullanabiliriz
	//Hangi karakter tuşu seçildiğinde hangi fonksiyonun çalışacağını belirliyoruz.
	switch (dugme)
	{
	case 'a':Piramitgotursag(); break;
	case'd':Piramitgotursol(); break;
	case 'w':Piramitgoturyuk(); break;
	case 's':Piramitgoturas(); break;
	case'+':Piramitgoturil(); break;
	case'-':Piramitgoturger(); break;
	}
	glutPostRedisplay();//hareket(işlem) sonrasıgüncelleme için
}

/* GLUT, main()den başlayarak bir konsol uygulaması olarak çalışır */
int main(int argc, char** argv) {
	glutInit(&argc, argv); // GLUT'u başlat
	glutInitDisplayMode(GLUT_DOUBLE); // çift tampon kullanma
	glutInitWindowPosition(50, 50); //pencere başlangıç noktası
	glutInitWindowSize(800, 600); // Pencere genişlik ve yükseklik ayarlayalım
	glutCreateWindow("3-Boyutlu Sekiller"); //pencere başlığı
	glutDisplayFunc(CizimFonksiyonu); // kendisine parametre olarak gönderilen CizimFonksiyonufonksiyonu çağırır ve çizimi yapar
	glutReshapeFunc(GorunumAyari); // Eğer pencere yeniden boyutlandırılırsa yeni genişlik ve yükseklik değerleri atanır.
	Ayarlar(); // Kendi OpenGL Ayarlarımız
	glutTimerFunc(0, zamanlayici, 0); // zamanlayıcı çağrımı
	glutSpecialFunc(klavye);
	glutKeyboardFunc(klavye);
	glutMainLoop(); // çizimi döngüye sokar.


	return 0;
}




