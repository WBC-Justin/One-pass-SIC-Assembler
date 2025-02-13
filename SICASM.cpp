	/* �{������dec c++ 5.11�� 
	*  window 10 �@�~�t�� 
	*	
	* �Ǹ�:s10759045 
	* �m�W:�d�f�e 
	* �{�����u:94.78% �ѥ��H�W�O�����C 
	*
	*
	*/ 
	#include<fstream>
	#include<string>
	#include<cstring>
	#include<sstream>
	#include<iostream>
	#include<vector>
	#include<iomanip>
	#include<list>
	#include<stdlib.h>
	#include<math.h>
	using namespace std;
	fstream f, g;                                                                
	fstream file , file2 , file3 ;
	
	string symbel_table(string symbel ){                                            					//�� label �s�J name �A �b return name ��  name�}�C�� 
		string name;
		name = symbel;
		return name;	
	}
	int symbel_table1(int loc){																		   // �� label ������ location �s�J loc1�� �b return loc1 to  loc1 array
		int loc1;
		loc1 = loc ;
		return loc1;
	}
	string compute_opcode(string opcode_array_only , string instruction_array[] ,string instruction_number_array[] , string oprand_array_only , string name[] , int loc1[] , int len , int count ){     //  ���Oopcode �p�� 
		int i = 0 ,  j = 0, ii = 0 , jj = 0 ;
		string a , ans , answer;
		stringstream ss;
			for( i = 0 ; i  < 1 ; i++ ){ 
				for(ii = 0 ; ii < 50 ; ii++ ){
					if(opcode_array_only == instruction_array[ii]){													//��X���� opcode  �� ���O�X ��J �ܼ�a 
						a = instruction_number_array[ii];
					
					} 
				}	
			}
		
			for( j = 0 ; j < 1 ; j++ ){
				for(jj = 0 ; jj < count ; jj++){
					if(oprand_array_only == name[jj]){																//��X  oprand ������ label �� �^�� ����label �� location ��J �ܼ� ans 
			
						ss  <<hex<< loc1[jj];
						ss >> ans;
				
					break;
					}else{
						stringstream sss ;                   														//�P�_�� 'x' �� ���p 
						sss  <<hex<< loc1[jj] + 28586;
						sss >> ans;
					
					}
				}
	
			}
			if(opcode_array_only == "RSUB"){																		//�{���̫�t�~���� 
				ans = "0000";
			}
			answer = a + ans;																					    //�N��X��																				
	
			return answer;																							//�^�Ǻ⧹��object code																																																									 
	}
	
	int main(int argc , char const*argv[]) {                                                                       //�D�{���}�l 
		string line , name[20] , line2;
		string label, opcode, operand , instruction , instruction_number , instruction_array[59] , instruction_number_array[59] ;
		string label_array[50] , opcode_array[50] , operand_array[50];
		static int len = 0; 
		int location , loc1[37] = {0};
		int  j = 0 , count = 1 , i = 0 , k = 0 , _long[50];
		char* symbol_table;
		
	 
		
if(string(argv[1]) == "test" || string(argv[2]) == "s" || string(argv[2]) == "a" )                                  //�ѼƧP�_ 
	{
	
		f.open("input.asm", ios::in);                                                                               //�}�� 
		g.open("optab", ios::in);																					//�}��
		
			file3.open("Object program.obj" ,ios::out);																// 80 �� 91 �� �P�O �ɮ׿�X 
			
			if(string(argv[2]) == "-t"){
				file2.open("SymbolTable.stb", ios::out);
			}
			if(string(argv[2]) == "-s"){
				file.open("Source Code.lst" , ios::out);
			}
			if(string(argv[2]) == "-a"){
				file.open("Source Code.lst" , ios::out);
				file2.open("SymbolTable.stb", ios::out);
			}
			
	
		
		getline(f, line);                                     											            // Ū�J�@�� 
		getline(g , line2);	           																				// Ū�J�@��      
	
	while(opcode != "END"){																							//�Yopcode == end �h�� 
			
			int loc = location;																						//��W�@��location ��J loc �� �]�����@�� 
			stringstream temp(line);
			stringstream temp2(line2);
			
			getline(temp,label,'\t');																			    //�H�U5��i�����  �A �@�Ӥ���l�X �A�@�Ӥ�optab; 
			getline(temp,opcode,'\t');
			getline(temp,operand,'\t');
			getline(temp2,instruction,'\t');
			getline(temp2,instruction_number,'\t');
			
				
				if (label == ".") {																					//�I���I�t�~�B�z �A���ѳB�z 
					cout <<'\t'<< line << endl;
					getline(f, line);
					continue;
				}
			
				if (opcode == "START") {																			// START �}�l 
					location = atoi(operand.c_str());																//�_�l��m				
					location += 3096;
					cout << setw(5) << setfill('0') << hex << location << '\t' << line << endl;						//���L�X�Ĥ@��W�߳B�z 
					file << setw(5) << setfill('0') << hex << location << '\t' << line << endl;						// �L�X�Ĥ@��W�߳B�z (�}��) 
					name[j] = symbel_table(label);																	//�H�U��氵 ��label �M������� location ���s�J(array) 
					loc1[j]  = symbel_table1(location);			
					j++;																							//�U�@�� 
					
				label_array[0] = label;																				//�H�U�T�氵 label �M opcode �M operand ���s�J(array)  
				opcode_array[0] = opcode;																			//�H��n��object code �� 
				operand_array[0] = operand;
					getline(f, line);																				//�U�@�� 
					continue;																						//continue; 
				}
				else if (opcode == "BYTE") {																		//opcode == "BYTE" �B�z 
					if (operand[0] == 'X') {																		// 'x' => +1 
						location = location + 1;
					}
					else {																							//'c'=> +3
						location = location + 3;		
					}
				}
				else if (opcode == "WORD") {																		//opcode == "WORD" => +3
					location = location + 3;
				}
				else if (opcode == "RESW") {																		//�ŧi�@�� word => location + 3 * �ŧi�Ӽ� 
					location += 3 * atoi(operand.c_str());
				
				}
				else if (opcode == "RESB") {																		// �ŧi�@�� byte => location + 1 * �ŧi�Ӽ� 
					location += atoi(operand.c_str());
				}
				else {																								//��l +3 
					location += 3;
				
				}
				if(location == 1000)																				//�ɤO 
				location += 3096;	
		
				if(label != "" && label != "." ){                                       						   //symbel table �H�U��氵 ��label �M������� location ���s�J(array) 
					
						name[j] = symbel_table(label);																
						loc1[j]  = symbel_table1(loc);	
						
					j++;	
					count++;
				} 		 						
							
				instruction_array[i] = instruction;							            							///��Ū�i�Ӫ����O��J���O�}�C�� 
				instruction_number_array[i] = instruction_number;                									//���������O�X��J 	instruction_number_array[i] �� 
				i++;
					getline(g , line2);																				//optab ���U�@�� 
	
				label_array[len + 1] = label;                                  										//���O��J 
				opcode_array[len + 1] = opcode;
				operand_array[len + 1] = operand;
				_long[len + 1 ] = loc;
			
				if(opcode != "END"){																				//�L�X �Ҧ� location (176 - 182)
					cout << setw(5) << setfill('0') << hex << loc << '\t' << line << endl;
					file << setw(5) << setfill('0') << hex << loc << '\t' << line << endl;
				}else{
					cout << line << endl;
					file << line << endl;
				}
				
				getline(f, line);																					//�U�@�� 
				len++;																								//171 ��� 174 �� ��  
	}
	if(string(argv[2]) != "-s" && string(argv[2]) != "-t" && string(argv[2]) != "-a"){								//�ѼƳB�z 
	//	return 0;
	}
	file.close();
}
	cout << "\n";
	
	if(string(argv[2]) == "-t" || string(argv[2]) == "-a" )														   //�ѼƳB�z 
	{																											   //�o�̦b��Symbol Table ���L�X ��208�� 
		cout << "Symbol	Value" << endl;
		cout <<"====== =======" ;
		file2 << "Symbol	Value" << endl;
		file2 << "====== =======" ;
	
		   	cout << "\n";
		   	file2 << "\n";
			for( j = 0 ; j < count ; j++){
				cout << name[j] <<'\t'<< loc1[j] << endl;
				file2 << hex << name[j] <<'\t'<< loc1[j] << endl;
			}
			file2.close();
	}	
	/*
	*			�H�U�@�������� 
	*			�ڧ���O�}�l����}�M�ت��{�������� �M�⧹��object code2 ���s�Jarray�� 
	*			�᭱�@���L ; 
	*			array ���O�O 
	*			locctr_array[10]
	*			line_long_array[10]; 
	*			buffer[40]		
	*/ 
	
if(string(argv[1]) == "test" || string(argv[2]) == "-t" || string(argv[2]) == "-a" || string(argv[2]) == "-s")               	//�ѼƳB�z 
{																																//�o�̦b�yobject code���B�z 
	cout << endl;
	string final_opcode;
	string buffer[40] ;																											//��Ҧ��p��n�� object code �s�J �̫�@���L 
	int  line_long = 0 , line_long2 = 0 , line_long_array[10] , l = 0 , line_long_sw = 0;                                       //�@�Ǫ��קP�_ 
	int b = 0 , locctr = 0 , locctr_array[10];                                                                                  //�@�Ǫ��קP�_
	
	while(opcode_array[k] != "END"){
		stringstream sss;
		
		if(opcode_array[k] == "START" ){																						//�@�� start �W�߳B�z 
			cout<< hex;
			file<<hex;
			cout << "H^" << label_array[k] <<" "<< setw(6) << setfill('0') << operand_array[k] <<"^"<<setw(6) << setfill('0') << _long[len]-_long[1]<< endl ;
			file3 <<"H^" << label_array[k] <<" "<< setw(6) << setfill('0') << operand_array[k] <<"^"<<setw(6) << setfill('0') <<hex<< _long[len]-_long[1]<< endl ;
		
			locctr = loc1[0];
		}else if(opcode_array[k] == "BYTE"){																					// �H�U�O�w��C�ӱ��p��object code �p�� 
			string letter;																										//�H�U4�欰�F�B�z�P�O'x' or 'c'  �Nstring => char 
			letter = operand_array[k];
			char p[letter.length()];
			for(int u = 0 ; u < sizeof(p) ; u++ ){
				p[u] = letter[u];
			} 
			if(p[0] == 'C'){																									//'c'���B�z => ���Ψ�stringstream �޳N 
		
				for(int i = 2 ; i < letter.length() - 1 ; i++ ){
				
					sss << hex << (unsigned int)p[i] ;
			
				}
			}else if(p[0] == 'X'){																								//'x'���B�z => ���Ψ�stringstream �޳N
				for(int i = 2 ; i < letter.length() - 1 ; i++ ){
				
				sss << p[i];
			
				}
			}
			if (p[0] == 'C'){																									//�����ת��[�` �A �n���L���ɭԤ�K 
					line_long = line_long + 3;																					//+3
					line_long2 = line_long2 + 3;																				//�o�� line_long2 �O���F��C��_�l��l�� 
			}else{
				line_long = line_long + 1;																						//+1 
				line_long2 = line_long2 + 1; 
			}	
	
		sss >>	buffer[b];																										//���G��J buffer
			b++;
		} else if (opcode_array[k] == "WORD" ){                                           										 //WORD �B�z 
			final_opcode = operand_array[k];																					 //final_opcode ���p�⵲�G���Ȯɩ�J 
			line_long = line_long + 3;																							 //+3 
			sss << hex << atoi(final_opcode.c_str());
			sss >> buffer[b];																									 //���G��J buffer
			b++;
			line_long2 = line_long2 + 3;																					     //�@��+3 
	
		}else if(opcode_array[k] == "RESW"){																					 //�H�U�|��P�z 
			line_long2 =	line_long2 +  3 * atoi(operand_array[k].c_str()) ;			
		}else if(opcode_array[k] == "RESB" ){
			line_long2 +=  atoi(operand_array[k].c_str());
		}
		else{																																						//�D�W�������p�N�O�n����O�F  
			final_opcode = compute_opcode(opcode_array[k] , instruction_array , instruction_number_array , operand_array[k] , name , loc1 , len , count );          // �ϥ� final_opcode�禡�����W��25���61�� 
		sss << hex << final_opcode;
		sss >> buffer[b] ;
		b++;
			line_long = line_long + 3;																															   ///�P�z 
			line_long2 = line_long2 + 3;
			
		}
		
		if(line_long2 > 27){																																		//�� locctr_array���s�J�H�U12�� 
		cout<<hex; 
		locctr = locctr + line_long2;
		locctr_array[l] = locctr; 
			line_long_array[l] = line_long;
			l++;
			line_long2 = 0;
			line_long = 0 ;
			line_long_sw++;
		}else{
			line_long_array[l] =  line_long;
			locctr_array[l] = locctr_array[l - 1] + line_long;
		}
		
		cout <<dec;
		k++;
	}
	
		cout << hex;																																				//�o�̴N�O�L�Xobject code���a��F 
		file3<< hex;
		cout<<"T^" <<setw(6) << setfill('0') << loc1[0] <<"^"<<setw(2)<< setfill('0') << line_long_array[0]<<"^" ;                                                  //�����D���O�p�⪺object code 
		file3 << "T^" <<setw(6) << setfill('0') << loc1[0] <<"^"<<setw(2)<< setfill('0') << line_long_array[0]<<"^" ;
		for(int i = 0 ; i < line_long_array[0] / 3 ; ){
			cout<<setw(6)<< setfill('0') << buffer[i] <<"^";
			file3<<setw(6)<< setfill('0') << buffer[i] <<"^";
			i = i + 1;
		}
		cout << "\n";
		file3<<"\n";
		
		int q = 3 ,  print_long = 0;
		int kk= 0;
		for(int i = 1 ; i < line_long_sw + 1 ; i++ ){																													//�L ���O�p�⪺object code 
			cout<<"T^" <<setw(6) << setfill('0') << locctr_array[i - 1] <<"^"<<setw(2)<< setfill('0') << line_long_array[i]<<"^";
			file3<<"T^" <<setw(6) << setfill('0') << locctr_array[i - 1] <<"^"<<setw(2)<< setfill('0') << line_long_array[i]<<"^";
			print_long += line_long_array[i] / 3 + 3  ;
			
			for( ; q <  print_long   ; q++ ){																															//�D�n��X 
				cout << buffer[q] <<"^";
				file3 << buffer[q] <<"^";
			
				kk++;
		
				if(kk == 37){
					cout<<"\n";
					file3<<"\n";
					cout<< "E^" << setw(6) << setfill('0') << locctr_array[0] << endl;
					file3<<"E^" << setw(6) << setfill('0') <<  locctr_array[0]  << endl;
					break;
				}
			}
			
			q = print_long ;
			print_long = print_long - 2;
			cout << "\n";
			file3 <<"\n"; 
			cout << hex;
			
		}
		file3.close();
}
	
		f.close();	
		
		system("pause");
		return 0;
	}
