/*
=> Derleme:

Linux: gcc example-00.c libmlx_linux.a -lXext -lX11 -lm -lz
Macos: gcc example-00.c libmlx_macos.a -framework OpenGL -framework AppKit

*/

# include "mlx.h"
# include <stdio.h>
# include <unistd.h>

int main(void)
{
	/* ==> mlx_init() Fonksiyonu <==

	Minilibx kütüphanesini başlatır ve void bir pointer döndürür. Dönen void pointerı
	neredeyse kütüphanenin tüm fonksıyonlara parametre olarak yolluyoruz.

	*/
	void *mlx_ptr = mlx_init();




	/* ==> mlx_new_window() Fonsiyonu <==

	Siyah içi boş bir pencere oluşturur. Parametre olarak mlx_ptr, pencerenin genişliği için int width,
	yüksekliği için int height ve son olarak pencere adı alır(const char bir dizi olarak)
	Daha sonra fonksiyon bize void bir win_ptr pointer döndürür. mlx_ptr gibi hemen hemen kütüphanenin tüm fonksiyonlara
	parametre olarak yolluyoruz.

	*/
	void *win_ptr = mlx_new_window(mlx_ptr, 64*17, 64*3, "Deneme");




	/* ==> mlx_xpm_file_to_image() Fonksiyonu <==

	xmp uzantılı resimleri okur ve bir pointer döndürür (dönen pointeri ekrana basması için mlx_put_image_to_window() fonksiyona parametre olarak yollucağız)
	Parametre olarak mlx_ptr, xpm dosyasının konumu ve iki tane değeri verilmemiş int adresi veriyoruz. Eğer okuyamazsa null döndürür. Resimler genellikle png veya jpg
	olur xpm çevirmek için bu siteyi kullanabilirsiniz: https://convertio.co/tr/png-xpm/

	*/
	int     width;
	int     height;

	void *img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./wall.xpm", &width, &height);

    void *coin_img=mlx_xpm_file_to_image(mlx_ptr, "./coin.xpm",&width, &height);
   // void *exit_img=mlx_xpm_file_to_image(mlx_ptr, "./exit.xpm", &width, &height);
//   void *player_img=mlx_xpm_file_to_image(mlx_ptr, "./player.xpm", &width, &height);
    void *bg_img=mlx_xpm_file_to_image(mlx_ptr,"./background.xpm", &width, &height);


	if (img_ptr == NULL)
	{
		printf ("Xpm dosyası verilen konumda bulunamadı");
		return (1);
	}




	/* ==> mlx_put_image_to_window() Fonsiyonu <==

	Resimlerı ekrana basmamıza yarar. Parametre olarak mlx_ptr, win_ptr, img_ptr ve resmin pencerenin hangi konuma basılacagını belirtmek için
	bir x y kordınatı alır örnek olarak : (0, 0) noktası verelim

	*/
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, bg_img, 0,1*16);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, exit_img, 0,2*16);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, player_img, 0,3*16);
	mlx_put_image_to_window(mlx_ptr, win_ptr, coin_img, 0, (4*16));

	/* ==> mlx_loop Fonksiyonu <==

	Pencerenin açık kalmasını sağlar. Parametre olarak mlx_ptr alır.

	*/
	mlx_loop(mlx_ptr);

	return (0);
}
