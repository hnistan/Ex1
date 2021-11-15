#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
//typedef struct matrix matrix;

struct matrix
{
    string name;
    vector<vector<string>> row;
};

void Menu ()
{
    cout
    << "To add matrix [add matrix] \n"
    << "To determine the diameter of the matrix [is_diagonal] \n"
    << "To detect the high triangularity of the matrix [is_upper_triangular] \n"
    << "To detect the low triangularity of the matrix [is_lower_triangular] \n"
    << "To detect whether the matrix is low-triangular or high-triangular [is_triangular] \n"
    << "To determine the identity of the matrix [is_identity] \n"
    << "To detect the symmetry of the matrix [is_normal_symmetric] \n"
    << "To detect the antisymmetry of the matrix [is_skew_symmetric] \n"
    << "To identify the type of matrix symmetry [is_symmetric] \n"
    << "To show matrix [show] \n"
    << "To change [change] \n"
    << "To exit [exit] \n";
    cout << "Enter a command : ";
}

template <typename T>

struct matrix addMatrix()
{
    struct matrix mat;
    int rowsCount, colsCount;
    cin >> mat.name;
    cin >> rowsCount;

    //testing input
    char test = cin.peek();

    if (isspace(test))
    {
        cin.ignore(1);
        test = cin.peek();
    }
    
    //if array is not squared
    if (isdigit(test))
    {
        cin >> colsCount;
    }
    else
        colsCount = rowsCount;

    if (rowsCount <= 0 || colsCount <= 0)
    {
        mat.name = "error";
        cout << "sizes must be positive" << endl;
        return mat;
    }

    //testing input
    test = cin.peek();
    if (isspace(test))
    {
        cin.ignore(1);
        test = cin.peek();
    }
    //if array is declared
    if (test == '[')
    {
        string declaration;
        unsigned index = 0; //index of dec

        cin.ignore(1);
        getline(cin, declaration, ']');
        cout << "dec: " << declaration << endl;
        vector <T> members;
        //------------------------------------------- collecting members
        while (index < declaration.size())
        {
            //creating number...
            string member;
            for (; index < declaration.size(); index++)
            {
                // cout << "checking---> " << declaration[index] << endl;
                if (isdigit(declaration[index]) || isalpha(declaration[index]) || declaration[index] == '.' || declaration[index] == '-')
                {
                    member += declaration[index];
                }
                if (!isdigit(declaration[index + 1]) && declaration[index + 1] != '.' && !isalpha(declaration[index + 1]))
                {
                    index++;
                    break;
                }
            }
            //if found a number
            if (!member.empty())
            {
                cout << "member: " << member << endl;
                members.push_back(member);
            }
        }

        //-------------------------------------- creating vectors
        //creating rows
        unsigned k = 0;
        for (int i = 0; i < rowsCount; i++)
        {
            vector <T> col;
            //creating columns
            for (int j = 0; j < colsCount; j++) //colsCount + , + []
            {
                if (k < members.size())
                    col.push_back(members[k++]);
            }

            //if cols are wrong
            if (col.size() != colsCount)
            {
                mat.name = "error";
                cout << "cols are entered wrong" << endl;
                return mat;
            }
            mat.row.push_back(col);
        } //loop

        //if rows are wrong
        if (mat.row.size() != rowsCount)
        {
            mat.name = "error";
            cout << "rows are entered wrong" << endl;
            return mat;
        }
    }


    //if size are wrong
    else if (isdigit(test))
    {
        mat.name = "error";
        cout << "sizes are entered wrong" << endl;
        return mat;
    }
    return mat;
}

void print_all(vector <matrix> mats)
{
    for (matrix mat : mats)
    {
        cout << "-----------------------------------------\n";
        cout << "name: " << mat.name << "\n\n";
        for (auto col : mat.row)
        {
            for (auto num : col)
            {
                cout << num << '\t';
            }
            puts("");
        }
    }
    cout << "-----------------------------------------\n";
}

bool Square(vector <matrix> mats, string name)
{
    int index = 0;
    for (matrix mat : mats)
    {
        if (mat.name == name)
        {
            for (auto col : mat.row)
            {
                for (auto num : col)
                {
                    index++;                           //Number of matrix cells          
                }
            }
        }
    } 

    int temp = sqrt(index);  

    if (temp * temp == index)                         
    {
        return true;
    }
    else
        return false;
}

bool IsDiagonal(vector <matrix> mats, string name)
{
    int index = 0;
    int i = 0;
    int j = 0;
    int number;

    if (Square(mats, name))                          
    {
        for (matrix mat : mats)
        {
            if (mat.name == name)
            {
                for (auto col : mat.row)
                {
                    for (auto num : col)
                    {
                        number = stoi(num);                      //Convert string to number
                        if (i != j && number != 0)     
                        {
                            return false;
                        }
                        j++;
                    }
                    j = 0;
                    i++;
                }
            }
        } 
        return true;
    } 
    //if the matrix was not square
    else
    {
        cout << "The matrix must be square to be diagonal" << endl;
        return false;
    }   
    return false;
}

bool IsUpperTriangular (vector <matrix> mats, string name)
{
    int index = 0;
    int i = 0;
    int j = 0;
    int number;

    if (Square(mats, name))                        
    {
        for (matrix mat : mats)
        {
            if (mat.name == name)
            {
                for (auto col : mat.row)
                {
                    for (auto num : col)
                    {
                        number = stoi(num);                      //Convert string to number
                        if (i > j && number != 0)     
                        {
                            return false;
                        }
                        j++;
                    }
                    j = 0;
                    i++;
                }
            }
        } 
        return true;
    } 
    //if the matrix was not square
    else
    {
        cout << "The matrix must be square to be Upper Triangular" << endl;
        return false;
    }   
    return false;
}

bool IsLowerTriangular (vector <matrix> mats, string name)
{
    int index = 0;
    int i = 0;
    int j = 0;
    int number;

    if (Square(mats, name))                         
    {
        for (matrix mat : mats)
        {
            if (mat.name == name)
            {
               for (auto col : mat.row)
                {
                    for (auto num : col)
                    {
                        number = stoi(num);                      //Convert string to number
                        if (j > i && number != 0)     
                        {
                            return false;
                        }
                        j++;
                    }
                    j = 0;
                    i++;
                }
            }
        }     
        return true;                                     
    } 
    //if the matrix was not square
    else
    {
        cout << "The matrix must be square to be Lower Triangular" << endl;
        return false;
    }   
    return false;
}

void IsTriangular(vector <matrix> mats, string name)
{
    if (IsUpperTriangular(mats, name) && IsLowerTriangular(mats, name))
    {
        cout << "Upper Triangular And Lower Triangular" << endl;
        return;
    }

    else if (IsUpperTriangular(mats, name))
    {
        cout << "Upper Triangula" << endl;
    }
    
    else if (IsLowerTriangular(mats, name))
    {
        cout << "Lower Triangular" << endl;
    }

    else if (!IsLowerTriangular(mats, name) && !IsUpperTriangular(mats, name))
    {
        cout << "None" << endl;
    }
}

bool IsIdentity(vector <matrix> mats, string name)
{
    int i = 0;
    int j = 0;
    int number;

    if (IsDiagonal(mats, name))
    {
        for (matrix mat : mats)
        {
            if (mat.name == name)
            {
                
                for (auto col : mat.row)
                {
                    for (auto num : col)
                    {
                        number = stoi (num);                              //Convert string to number
                        if (i == j && number != 1)
                        {
                            return false;
                        }
                        j++;  
                    }
                    j = 0;
                    i++;
                }
            }
        } 
        return true;
    }
    //if the matrix was not square
    else
    {
        cout << "The matrix must be diagonal to be identity" << endl;
    }
    return false;
}

bool IsNormalSymmetric(vector <matrix> mats, string name)
{
    int number;

    if (Square(mats, name))
    {
        for (matrix mat : mats)
        {
            if (mat.name == name)
            {
                for (size_t i = 0; i < (mat.row).size(); i++)
                {
                    for (size_t j = 0; j < mat.row[i].size(); j++)
                    {
                        if (mat.row[i][j] != mat.row[j][i])
                        {
                            return false;
                        }
                        
                    }
                    
                }
                
            }
        } 
        return true;
    }
    
    //if the matrix was not square
    else
    {
        cout << "The matrix must be square to be Normal Symmetric" << endl;
    }
    return false;
}

bool IsSkewSymmetric(vector <matrix> mats, string name)
{
    int number1;
    int number2;

    if (Square(mats, name))
    {
        for (matrix mat : mats)
        {
            if (mat.name == name)
            {
                for (size_t i = 0; i < (mat.row).size(); i++)
                {
                    for (size_t j = 0; j < mat.row[i].size(); j++)
                    {
                        number1 = stoi (mat.row[j][i]);
                        number2 = stoi (mat.row[i][j]);

                        if (number1 != -1 * number2 && i != j)
                        {
                            return false;
                        }
                        
                    }
                    
                }
                
            }
        } 
        return true;
    }
    
    //if the matrix was not square
    else
    {
        cout << "The matrix must be square to be Normal Symmetric" << endl;
    }
    return false;
}

void IsSymmetric (vector <matrix> mats, string name)
{
    if (IsSkewSymmetric(mats, name))
    {
        cout << "Skew Symmetric" << endl;
    }
    
    else if (IsNormalSymmetric(mats, name))
    {
        cout << "Normal Symmetric" << endl;
    }

    else if (!IsNormalSymmetric(mats, name) && !IsSkewSymmetric(mats, name))
    {
        cout << "None" << endl;
    }
}

void Show (vector <matrix> mats, string name)
{
    for (matrix mat : mats)
    {
        if (mat.name == name)
        {
            for (size_t i = 0; i < mat.row.size(); i++)
            {
                for (size_t j = 0; j < mat.row[i].size(); j++)
                {
                    cout << mat.row[i][j] << "\t";
                }
                puts("");
            } 
        }   
    }
}

void Change (vector <matrix> mats)
{
    string name;
    string temp;
    int rowsCount, colsCount;
    
    cin >> name;
    cin >> rowsCount >> colsCount >> temp;

    for (matrix mat : mats)
    {
        if (mat.name == name)
        {
            mats.erase(mats.begin());
            mat.row[rowsCount][colsCount] = temp;
        }
    }
    Show(mats, name);
}

int main()
{
    vector <matrix> mats;
    char ch;
    string command;
    system("clear");
    Menu();
    while (command != "exit")
    {
        
        getline(cin, command);

        if (command == "add matrix")
        {
            matrix temp = addMatrix<string>();
            if (temp.name != "error")
            mats.push_back(temp);
            //print all matrixes
            print_all(mats);
            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }
        if (command == "is_diagonal")
        {
            matrix mat;
            string name;
            cout << "Enter a name : ";
            cin >> name ;
            system("clear");
            if (IsDiagonal(mats , name))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            
            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }

        if (command == "is_upper_triangular")
        {
            matrix mat;
            string name;
            cout << "Enter a name : ";
            cin >> name ;
            system("clear");
            if (IsUpperTriangular(mats, name))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }
        if (command == "is_lower_triangular")
        {
            matrix mat;
            string name;
            cout << "Enter a name : ";
            cin >> name ;
            system("clear");
            if (IsLowerTriangular(mats , name))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        } 
        if (command == "is_triangular")
        {
            matrix mat;
            string name;
            cout << "Enter a name : ";
            cin >> name ;
            system("clear");

            IsTriangular(mats, name);

            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }
        if (command == "is_identity")
        {
            matrix mat;
            string name;
            cout << "Enter a name : ";
            cin >> name ;
            system("clear");

            if (IsIdentity(mats, name))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }
        if (command == "is_skew_symmetric")
        {
            matrix mat;
            string name;
            cout << "Enter a name : ";
            cin >> name ;
            system("clear");

            if (IsSkewSymmetric(mats, name))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }

        if (command == "is_symmetric")
        {
            matrix mat;
            string name;
            cout << "Enter a name : ";
            cin >> name ;
            system("clear");

            IsSymmetric(mats, name);

            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }

        if (command == "show")
        {
            matrix mat;
            string name;
            cout << "Enter a name : ";
            cin >> name ;
            system("clear");

            Show(mats, name);

            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }      

        if (command == "change")
        {
            matrix mat;

            Change(mats);
            //system ("clear");

            cout << "Press the [m] key to return to the menu, press other key to exit : ";
            cin >> ch;
            if (ch == 'm')
            {
                system("clear");
                Menu();
                continue;
            }
            else
            {
                break;
            }
        }        
    }
}

