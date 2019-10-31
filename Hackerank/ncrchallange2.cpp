#include<iostream>
#include<string.h>
using namespace std;
int reverse(int data){
	int rev = 0;
	while(data > 0){
		rev = rev * 10 + data % 10 ;
		data = data / 10;	
	}
	return rev;
}
int main(){
	int revmonth,n = 0;
	char input[10];
	cout<<"Enter Day between 1 - 60 and month between 1 to 30 in format DD:MM"<<endl;
	cin>>input;
	int month = ((int)input[3] - 48) * 10 + (int)input[4] - 48;
	int date = ((int)input[0] - 48) * 10 + (int)input[1] - 48;
	
	b:
	for(int i = month ; i <= 30 ; i++){
		revmonth = reverse(i);
		for(int j = date ; i <= 60 ; j++){
			if( j == revmonth){
				n++;
				goto a;
			}
		}
		date = 1;
	}
	if(n == 0){
		month = 1;
		goto b;
	}
	a:

	cout<<revmonth<<endl;
	return 0 ;
}