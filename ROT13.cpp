/*ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".
*/


#include<iostream>
#include<string>
#include<numeric>
#include<string_view>
#include<cstring>

int Nadji(const char* lista, size_t velicina, char a){
	for(int i = 0; i < velicina; i++){if(lista[i] == a){return (int)i;}}
	return -1;
}


std::string rot13(std::string msg)
{
  char mABC[26] {};
  char vABC[26] {};
  
  int index;
  
  std::iota(std::begin(mABC), std::end(mABC), 'a');
  std::iota(std::begin(vABC), std::end(vABC), 'A');

  for(int i = 0; i < msg.length(); i++){
	  if(islower(msg[i])){
		index = Nadji(mABC, sizeof(mABC), msg[i]);
		if(index>14){msg[i] = mABC[index -13];}
		else{msg[i] = mABC[index + 13];}
	  }
	  else{
		index = Nadji(vABC, sizeof(vABC), msg[i]);
		if(index>14){msg[i] = vABC[index-13];}
		else{msg[i] = vABC[index + 13];}
	  }
 	}
  return msg;
}

int main(){
	std::string Unos;
	std::cout<<"=====Fuke ROT-13 Enkripter====="<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<"Unesi rijec koju hoces da enkriptujes: ";
	getline(std::cin,Unos);
	std::cout<<""<<std::endl;
	std::cout<<"==================="<<std::endl;
	std::cout<<"Unos: "<<Unos<<std::endl;
	std::cout<<"Nakon enkripcije: "<<rot13(Unos)<<std::endl;
	return 0;
}
