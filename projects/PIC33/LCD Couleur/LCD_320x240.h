//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&					Titre 		: 	Afficheur LCD						&&&
//&&&					Fichier 	:   LCD_320x240.h						&&&
//&&&					Description : 	prototypes des Fonctions LCD		&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&					Auteur 		: 	Dr Pierre BLACHÉ					&&&
//&&&					Date 		: 	Octobre 2010						&&&
//&&&					Version 	:	1.0									&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&				Fichiers Requis	:	LCD_320x240.c						&&&
//&&&									LCD_320x240.h						&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void LCD_Init(void);

void LCD_Adresse(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

void LCD_Write(unsigned int Cmd, unsigned int Data);

void LCD_Write_Cmd(unsigned int Cmd);

void LCD_Write_Color(unsigned char H,unsigned char L);

void LCD_Write_Data(unsigned int Cmd);

void LCD_Draw_FillRectangle(unsigned int color);

void showzifustr(unsigned int x, unsigned int y, unsigned char *str, unsigned int dcolor, unsigned int bgcolor);

void showzifu(unsigned int x, unsigned int y, unsigned char value, unsigned int dcolor, unsigned int bgcolor);

