# include <stdio.h>
# include <string.h>
# include <ctype.h>
int ret[100];
int pos=0;
int sc=0;
void nfa(int st,int p,char *s)
{    int i,sp,fs[15],fsc=0;
	sp=st;pos=p;sc=st;	
    for(int j=0;s[j]!=0;j++)
	{if(isalpha(s[j]))
	    {ret[pos++]=sp;
		ret[pos++]=s[j];
		ret[pos++]=++sc;
		}
	if(s[j]=='.')
		{sp=sc;

		}
	if(s[j]=='|')
		{sp=st;
		 fs[fsc++]=sc;}
	if(s[j]=='*')
		{ret[pos++]=sc;
		 ret[pos++]=s[j-1];
		 ret[pos++]=sc;
		 sp++;
		
		 }
	 if (s[j]=='(')
		{char ps[50];
		 int i=0,flag=1;
		 j++;
		   while(flag!=0)
			{ps[i++]=s[j];
			 if (s[j]=='(')
				flag++;
			 if (s[j]==')')
				flag--;
			 j++;}
			 ps[--i]='\0';
			 nfa(sc,pos,ps);
			 j--;
		}
	
	}
	sc++;
	  for(i=0;i<fsc-1;i++)
		 {ret[pos++]=fs[i];
		  ret[pos++]=238;
		  ret[pos++]=sc;
		 }
	
}
int main()
{    int i;
	char *inp="a.(b+c)";
	
	nfa(1,0,inp);
	printf("\nstate  input  state\n");
	for(i=0;i<pos;i=i+3)
		 printf("%d     --%c-->      %d\n",ret[i],ret[i+1],ret[i+2]);
	printf("\n");
	
    return 0;
}