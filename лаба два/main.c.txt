#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)
#include <stdio.h>

#define MAXLINE 1024

int main(void)
{
	char ORIG[MAXLINE]; //исходный массив
	char COPY[MAXLINE]; //результирующий 

	char *ORIG_PTR = ORIG; //указатель на нулевой элемент исходного массива
	char *COPY_PTR = COPY; //указатель на начало результирующего массива

	FILE* fpin = fopen("C:\\Users\\HP\\source\\repos\\file.txt", "rt"); // открыть файл для чтения
	FILE* fpout = fopen("C:\\Users\\HP\\source\\repos\\result.txt", "wt"); // открыть файл для записи

	if (fpin == NULL)
	{
		printf("error opening file input\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	if (fpout == NULL)
	{
		printf("error opening file output\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	while (!feof(fpin)) // цикл до конца файла
	{
		ORIG_PTR = fgets(ORIG, MAXLINE, fpin); // получаем новую строку и ставим на нее указатель
		if (ORIG_PTR == NULL)
		{
			break; // файл исчерпан
		}

		while (*ORIG_PTR != '\0') //пока указатель на элемент исходного массива не равен /0 
		{
			if (*ORIG_PTR == 'm') //если указатель на эл массива равен m, то
			{
				*COPY_PTR++ = 'M'; //присваиваем указателю на эл результирующего массива M и рассматриваем указатель на след эл результ массива
			}
			else
			{
				*COPY_PTR++ = *ORIG_PTR; //иначе присваиваем значение элемента исх массива результирующему и рассм след эл
			}
			*ORIG_PTR++; //рассм след эл
		}
		*COPY_PTR = '\0'; //вставляем /0
	}
	fputs(COPY, fpout); //вывод
	fclose(fpin); // закрыть входной файлло
	fclose(fpout); // закрыть выходной файл

	return 0;
}
