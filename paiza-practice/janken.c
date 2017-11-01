#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int win(int a,int b);

int main(void)
{
	int i;
	/*1行目から勝負数と指の本数を取得*/
	printf("勝負数と出したい指の本数を入力してください\n");
	char str[2000];
	fgets(str,sizeof(str),stdin);
	str[strlen(str)-1]='\0';
	int battle,finger;
	char *tmp;
	tmp=strtok(str," ");
	battle=atoi(tmp);
	tmp=strtok(NULL," ");
	finger=atoi(tmp);
	
	/*2行目から相手の出すG,C,Pの数を取得*/
	printf("相手の出す手をG,C,Pで入力してください\n");
	fgets(str,sizeof(str),stdin);
	str[strlen(str)-1]='\0';
	int Goo=0,Cyoki=0,Pa=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='G')
		{
			Goo++;
		}
		else if(str[i]=='C')
		{
			Cyoki++;
		}
		else if(str[i]=='P')
		{
			Pa++;
		}
	}
	
	/*1行目の情報からパーが最大になるような手の組み合わせを考える*/
	int G=0,C=0,P=0;
	while(finger>=5)
	{
		finger=finger-5;
		P++;
	}
	if(finger==1)
	{
		P--;
		C=3;
	}
	else if(finger==2)
	{
		C=1;
	}
	else if(finger==3)
	{
		P--;
		C=4;
	}
	else if(finger==4)
	{
		C==2;
	}
	G=battle-C-P;

	/*勝利数を確認*/
	int count;
	count=win(G,Cyoki)+win(C,Pa)+win(P,Goo);

	/*2パー->5チョキに変換して再度勝利数を計算。グーがマイナスで終了*/
	int tp;
	while(G>2 && P>1)
	{
		P=P-2;
		C=C+5;
		G=G-3;
		tp=win(G,Cyoki)+win(C,Pa)+win(P,Goo);
		if(tp>count)
		{
			count=tp;
		}
	}
	printf("あなたは最大%d回勝利できます\n",count);
}

int win(int a,int b)
{
	if(a>=b)
	{
		return b;
	}
	else
	{
		return a;
	}
}	
