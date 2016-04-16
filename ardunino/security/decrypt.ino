void decrypt(unsigned int y[])
{

const byte invsBox4[] = {
				0x5,0xe,0xf,0x8,
				0xc,0x1,0x2,0xd,
				0xb,0x4,0x6,0x3,
				0x0,0x7,0x9,0xa
		                };
 unsigned int i=0,l=1;
 unsigned int w=8;
 unsigned int P,C,n;
 unsigned int j,k,decry=0;
 

unsigned int x[]	={373,211,303,265,234,258,275,244};
unsigned int key[]	={0xa9,0x07,0x63,0x44,0x25,0x36,0x47,0x28};

/*P=w/2;
C=(1+P)-P;

   if (w%2==0)
	{
	while(w!=1)
	{ w/=2;
	  n++;
	}
	}*/
P=4;
C=1;
n=3;

for(i=0;i<n;i++){
for(i=0;i<8;i++)
{
x[i]=x[i]-key[i];
}                }

i=0;	
do
		{
			x[i] = invsBox4[x[i]>>4]<<4 | invsBox4[x[i] & 0xF];
			i++;
		}
		while(i<=7);


for(i=0;i<n;i++)
{

  for(j=0;j<P;j++)
      {
	for(k=0;k<C;k++)
	{
	x[(2*P*k)+j]    =x[(2*P*k)+j]^x[(2*P*k)+j+P];
	x[(2*P*k)+j+P]	=x[(2*P*k)+j]^x[(2*P*k)+j+P];
	x[(2*P*k)+j]	=x[(2*P*k)+j]^x[(2*P*k)+j+P];
	}
      }
    P/=2;
    C*=2;
}

printf("decrypt array\n");
for(i=0;i<8;i++)
{
printf ("%d\n",x[i]);
}


for(i=0;i<8;i++)
{
decry=decry + y[i]*l;
l=l*2;
}


Serial.println(decry);

//return decry;
}




int i=0,k;
//int * p;
int output;
unsigned int a[8];

//p=&a[i];
void setup() {
 
  Serial.begin(9600);
 
}

void loop()
{
  
    while (Serial.available()==0); 
  
   {      a[i]= Serial.read()-'0'; 
        
        Serial.print(a[i]);
        i++;
     }
    
    
   if(i>=8)
    {
    
    Serial.println("DECRYPT:");
    decrypt(a);
    //Serial.println(output);
        i=0;
        
        for(k=0;k<8;k++)
        {
          //Serial.write(a[k]);
          delay(100);
          a[k]=0;
        }
    }
  
  

}



