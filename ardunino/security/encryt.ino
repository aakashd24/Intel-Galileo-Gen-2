void encrypt(int dec)
{

const  byte sBox4[] = {
				0xc,0x5,0x6,0xb,
				0x9,0x0,0xa,0xd,
				0x3,0xe,0xf,0x8,
				0x4,0x7,0x1,0x2
						};

 unsigned int i=8,l=0;
 unsigned int w=8;
 unsigned int P,C,n;
 unsigned int j,k,enc=0;
 
//input
byte x[]	={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
//byte a[]	={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte key[]	={0xa9,0x07,0x63,0x44,0x25,0x36,0x47,0x28};


   while(dec>0)
      {
	   x[i]=dec%2;
	   i++;
	   dec=dec/2;
      }

P=w/2;
C=(1+P)-P;

   if (w%2==0)
	{
	while(w!=1)
	{ w/=2;
	  n++;
	}
	}

do
	{
		i--;
		x[i] = sBox4[x[i]>>4]<<4 | sBox4[x[i] & 0xF];
	}
	while(i>0);



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
for(i=0;i<n;i++){
for(i=0;i<8;i++)
{
x[i]=x[i]+key[i];
}}

Serial.println("encrypt");
for(i=0;i<8;i++)
{
Serial.println(x[i]);
}
  
//return x;

}  

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  int voltage = sensorValue * (5/ 1023);
  // print out the value you read:
  encrypt(voltage);
}

