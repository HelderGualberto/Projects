
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
/*
	This example code multiply a matrix by a constant.
	The data is read from a csv file, and converted into a vector of vectors of floatpoints
	The constant and file path are passed in program argumments
	The second param is the number to multiply the matrix
*/

/*
	Namespaces sao metodos utilizados para evitar conflitos de nomes em projetos.
	Funcionam como escopos que separam metodos e atributos dentro de um projeto (nao sao classes).
*/
using namespace std;

namespace file_operators {

	const char *name = "file operators";

	int value = 50;

	void count_file_rows_cols(char * file_path, int *rows, int *cols){
		ifstream in_file(file_path);

		string line;
		int rcount = 0;
		int ccount = 0;

		while(!in_file.eof()){
			getline(in_file,line);

			if(rcount == 0){
				string temp="";
				stringstream ss(line);
				while(!getline(ss, temp, ',').eof()){
					ccount++;
				}
			}
			rcount++;
		}
		
		*rows = rcount-1;
		*cols = ccount+1;

		in_file.close();
	}

	string* read_csv_file(char * file_path, int fsize){

		//use +1 to insert end of file
		string *data = new string[fsize+1];

		ifstream in_file(file_path);
		
		int i=0;
		while(!getline(in_file, data[i++]).eof());
		// ++i or i++ ?

		return data;
	}

	void save_cvs_file(vector<vector<float>>matrix){
		string output_file = "output.csv";

		ofstream output(output_file);

		for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[i].size();j++){
				output << matrix[i][j];
				if(j < matrix[i].size()-1){
					output << ",";
				}
			}
			output << "\n";
		}
		output.close();
	}

}


//Parse string and covert to float array
vector<vector<float>> parse_and_convert_matrix(string* data, int rows, int cols){
	
	vector<vector<float>> matrix; 	
	string temp;

	for (int i=0;i<rows;i++){
		stringstream ss(data[i]);
		vector<float>vtmp;
		for(int j=0;j<cols;j++){
			getline(ss, temp, ',');
			vtmp.push_back(stof(temp));
		}
		matrix.push_back(vtmp);
	}
	
	return matrix;
}

void scalar_product(vector<vector<float>> &matrix, float scalar){
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			matrix[i][j] *= scalar;
		}
	}
}

void print_matrix(vector<vector<float>> matrix){
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(int argv, char* argc[]){

	cout << "Example program in c++" << endl;

	if(argv < 2){
		cout << "ERROR! Wrong parameters\n" << "usage: ./basic <string path_to_file> <float multiplier_value>\n";
		return -1;
	}

	char* file_path = argc[1];
	
	float multiplier = stof(argc[2]);

	string* data;
	
	int rows;
	int cols;
	vector<vector<float>> matrix;

    cout << "Scalar: " << multiplier << endl;

	cout << file_operators::name << endl;

	//Exemplo de variaveis em namespaces
	cout << file_operators::value << endl;
	file_operators::value = 120;
	cout << file_operators::value << endl;


	//Operacoes com arquivos
	file_operators::count_file_rows_cols(file_path, &rows, &cols);
	data = file_operators::read_csv_file(file_path, rows);

	cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;	

	matrix = parse_and_convert_matrix(data,rows,cols);

	cout << "Input matrix: " << endl;
	print_matrix(matrix);

	scalar_product(matrix, multiplier);

	cout << "Output matrix: " << endl;
	print_matrix(matrix);

	file_operators::save_cvs_file(matrix);

	delete[] data;
	
	//Evitar problemas com acesso de memoria invalido
	data = NULL;

	//Teste com data
	cout << data << endl;

	return 0;
}


