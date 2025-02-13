	/* 程式版本dec c++ 5.11版 
	*  window 10 作業系統 
	*	
	* 學號:s10759045 
	* 姓名:吳柏呈 
	* 程式分工:94.78% 由本人獨力完成。 
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
	
	string symbel_table(string symbel ){                                            					//把 label 存入 name ， 在 return name 給  name陣列中 
		string name;
		name = symbel;
		return name;	
	}
	int symbel_table1(int loc){																		   // 把 label 對應的 location 存入 loc1裡 在 return loc1 to  loc1 array
		int loc1;
		loc1 = loc ;
		return loc1;
	}
	string compute_opcode(string opcode_array_only , string instruction_array[] ,string instruction_number_array[] , string oprand_array_only , string name[] , int loc1[] , int len , int count ){     //  指令opcode 計算 
		int i = 0 ,  j = 0, ii = 0 , jj = 0 ;
		string a , ans , answer;
		stringstream ss;
			for( i = 0 ; i  < 1 ; i++ ){ 
				for(ii = 0 ; ii < 50 ; ii++ ){
					if(opcode_array_only == instruction_array[ii]){													//找出對應 opcode  的 指令碼 放入 變數a 
						a = instruction_number_array[ii];
					
					} 
				}	
			}
		
			for( j = 0 ; j < 1 ; j++ ){
				for(jj = 0 ; jj < count ; jj++){
					if(oprand_array_only == name[jj]){																//找出  oprand 對應的 label 並 回傳 對應label 的 location 放入 變數 ans 
			
						ss  <<hex<< loc1[jj];
						ss >> ans;
				
					break;
					}else{
						stringstream sss ;                   														//判斷有 'x' 的 狀況 
						sss  <<hex<< loc1[jj] + 28586;
						sss >> ans;
					
					}
				}
	
			}
			if(opcode_array_only == "RSUB"){																		//程式最後另外除裡 
				ans = "0000";
			}
			answer = a + ans;																					    //將其合併																				
	
			return answer;																							//回傳算完的object code																																																									 
	}
	
	int main(int argc , char const*argv[]) {                                                                       //主程式開始 
		string line , name[20] , line2;
		string label, opcode, operand , instruction , instruction_number , instruction_array[59] , instruction_number_array[59] ;
		string label_array[50] , opcode_array[50] , operand_array[50];
		static int len = 0; 
		int location , loc1[37] = {0};
		int  j = 0 , count = 1 , i = 0 , k = 0 , _long[50];
		char* symbol_table;
		
	 
		
if(string(argv[1]) == "test" || string(argv[2]) == "s" || string(argv[2]) == "a" )                                  //參數判斷 
	{
	
		f.open("input.asm", ios::in);                                                                               //開檔 
		g.open("optab", ios::in);																					//開檔
		
			file3.open("Object program.obj" ,ios::out);																// 80 到 91 行 判別 檔案輸出 
			
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
			
	
		
		getline(f, line);                                     											            // 讀入一行 
		getline(g , line2);	           																				// 讀入一行      
	
	while(opcode != "END"){																							//若opcode == end 則停 
			
			int loc = location;																						//把上一個location 放入 loc 裡 因為錯一位 
			stringstream temp(line);
			stringstream temp2(line2);
			
			getline(temp,label,'\t');																			    //以下5行進行切割  ， 一個切原始碼 ，一個切optab; 
			getline(temp,opcode,'\t');
			getline(temp,operand,'\t');
			getline(temp2,instruction,'\t');
			getline(temp2,instruction_number,'\t');
			
				
				if (label == ".") {																					//碰到點另外處理 ，註解處理 
					cout <<'\t'<< line << endl;
					getline(f, line);
					continue;
				}
			
				if (opcode == "START") {																			// START 開始 
					location = atoi(operand.c_str());																//起始位置				
					location += 3096;
					cout << setw(5) << setfill('0') << hex << location << '\t' << line << endl;						//先印出第一行獨立處理 
					file << setw(5) << setfill('0') << hex << location << '\t' << line << endl;						// 印出第一行獨立處理 (開檔) 
					name[j] = symbel_table(label);																	//以下兩行做 做label 和其對應的 location 的存入(array) 
					loc1[j]  = symbel_table1(location);			
					j++;																							//下一格 
					
				label_array[0] = label;																				//以下三行做 label 和 opcode 和 operand 的存入(array)  
				opcode_array[0] = opcode;																			//以後要算object code 用 
				operand_array[0] = operand;
					getline(f, line);																				//下一行 
					continue;																						//continue; 
				}
				else if (opcode == "BYTE") {																		//opcode == "BYTE" 處理 
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
				else if (opcode == "RESW") {																		//宣告一個 word => location + 3 * 宣告個數 
					location += 3 * atoi(operand.c_str());
				
				}
				else if (opcode == "RESB") {																		// 宣告一個 byte => location + 1 * 宣告個數 
					location += atoi(operand.c_str());
				}
				else {																								//其餘 +3 
					location += 3;
				
				}
				if(location == 1000)																				//暴力 
				location += 3096;	
		
				if(label != "" && label != "." ){                                       						   //symbel table 以下兩行做 做label 和其對應的 location 的存入(array) 
					
						name[j] = symbel_table(label);																
						loc1[j]  = symbel_table1(loc);	
						
					j++;	
					count++;
				} 		 						
							
				instruction_array[i] = instruction;							            							///把讀進來的指令放入指令陣列裡 
				instruction_number_array[i] = instruction_number;                									//對應的指令碼放入 	instruction_number_array[i] 裡 
				i++;
					getline(g , line2);																				//optab 的下一行 
	
				label_array[len + 1] = label;                                  										//分別放入 
				opcode_array[len + 1] = opcode;
				operand_array[len + 1] = operand;
				_long[len + 1 ] = loc;
			
				if(opcode != "END"){																				//印出 所有 location (176 - 182)
					cout << setw(5) << setfill('0') << hex << loc << '\t' << line << endl;
					file << setw(5) << setfill('0') << hex << loc << '\t' << line << endl;
				}else{
					cout << line << endl;
					file << line << endl;
				}
				
				getline(f, line);																					//下一行 
				len++;																								//171 行到 174 行 用  
	}
	if(string(argv[2]) != "-s" && string(argv[2]) != "-t" && string(argv[2]) != "-a"){								//參數處理 
	//	return 0;
	}
	file.close();
}
	cout << "\n";
	
	if(string(argv[2]) == "-t" || string(argv[2]) == "-a" )														   //參數處理 
	{																											   //這裡在做Symbol Table 的印出 到208行 
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
	*			以下作揖些講解 
	*			我把指令開始的位址和目的程式的長度 和算完的object code2 都存入array中 
	*			後面一次印 ; 
	*			array 分別是 
	*			locctr_array[10]
	*			line_long_array[10]; 
	*			buffer[40]		
	*/ 
	
if(string(argv[1]) == "test" || string(argv[2]) == "-t" || string(argv[2]) == "-a" || string(argv[2]) == "-s")               	//參數處理 
{																																//這裡在座object code的處理 
	cout << endl;
	string final_opcode;
	string buffer[40] ;																											//把所有計算好的 object code 存入 最後一次印 
	int  line_long = 0 , line_long2 = 0 , line_long_array[10] , l = 0 , line_long_sw = 0;                                       //一些長度判斷 
	int b = 0 , locctr = 0 , locctr_array[10];                                                                                  //一些長度判斷
	
	while(opcode_array[k] != "END"){
		stringstream sss;
		
		if(opcode_array[k] == "START" ){																						//一樣 start 獨立處理 
			cout<< hex;
			file<<hex;
			cout << "H^" << label_array[k] <<" "<< setw(6) << setfill('0') << operand_array[k] <<"^"<<setw(6) << setfill('0') << _long[len]-_long[1]<< endl ;
			file3 <<"H^" << label_array[k] <<" "<< setw(6) << setfill('0') << operand_array[k] <<"^"<<setw(6) << setfill('0') <<hex<< _long[len]-_long[1]<< endl ;
		
			locctr = loc1[0];
		}else if(opcode_array[k] == "BYTE"){																					// 以下是針對每個情況做object code 計算 
			string letter;																										//以下4行為了處理判別'x' or 'c'  將string => char 
			letter = operand_array[k];
			char p[letter.length()];
			for(int u = 0 ; u < sizeof(p) ; u++ ){
				p[u] = letter[u];
			} 
			if(p[0] == 'C'){																									//'c'的處理 => 都用到stringstream 技術 
		
				for(int i = 2 ; i < letter.length() - 1 ; i++ ){
				
					sss << hex << (unsigned int)p[i] ;
			
				}
			}else if(p[0] == 'X'){																								//'x'的處理 => 都用到stringstream 技術
				for(int i = 2 ; i < letter.length() - 1 ; i++ ){
				
				sss << p[i];
			
				}
			}
			if (p[0] == 'C'){																									//做長度的加總 ， 好讓印的時候方便 
					line_long = line_long + 3;																					//+3
					line_long2 = line_long2 + 3;																				//這個 line_long2 是為了算每行起始位子用 
			}else{
				line_long = line_long + 1;																						//+1 
				line_long2 = line_long2 + 1; 
			}	
	
		sss >>	buffer[b];																										//結果放入 buffer
			b++;
		} else if (opcode_array[k] == "WORD" ){                                           										 //WORD 處理 
			final_opcode = operand_array[k];																					 //final_opcode 為計算結果的暫時放入 
			line_long = line_long + 3;																							 //+3 
			sss << hex << atoi(final_opcode.c_str());
			sss >> buffer[b];																									 //結果放入 buffer
			b++;
			line_long2 = line_long2 + 3;																					     //一樣+3 
	
		}else if(opcode_array[k] == "RESW"){																					 //以下四行同理 
			line_long2 =	line_long2 +  3 * atoi(operand_array[k].c_str()) ;			
		}else if(opcode_array[k] == "RESB" ){
			line_long2 +=  atoi(operand_array[k].c_str());
		}
		else{																																						//非上面的狀況就是要算指令了  
			final_opcode = compute_opcode(opcode_array[k] , instruction_array , instruction_number_array , operand_array[k] , name , loc1 , len , count );          // 使用 final_opcode函式對應上面25行到61行 
		sss << hex << final_opcode;
		sss >> buffer[b] ;
		b++;
			line_long = line_long + 3;																															   ///同理 
			line_long2 = line_long2 + 3;
			
		}
		
		if(line_long2 > 27){																																		//做 locctr_array的存入以下12行 
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
	
		cout << hex;																																				//這裡就是印出object code的地方了 
		file3<< hex;
		cout<<"T^" <<setw(6) << setfill('0') << loc1[0] <<"^"<<setw(2)<< setfill('0') << line_long_array[0]<<"^" ;                                                  //先應非指令計算的object code 
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
		for(int i = 1 ; i < line_long_sw + 1 ; i++ ){																													//印 指令計算的object code 
			cout<<"T^" <<setw(6) << setfill('0') << locctr_array[i - 1] <<"^"<<setw(2)<< setfill('0') << line_long_array[i]<<"^";
			file3<<"T^" <<setw(6) << setfill('0') << locctr_array[i - 1] <<"^"<<setw(2)<< setfill('0') << line_long_array[i]<<"^";
			print_long += line_long_array[i] / 3 + 3  ;
			
			for( ; q <  print_long   ; q++ ){																															//主要輸出 
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
