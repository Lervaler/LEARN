#include <iostream>
#include <vector>
#include <string>
#include <cstring>


template <class T>
void sort_template(T array[], int n)
{
    T t;
    int cnt;
    for(int i = 0; i < n; ++i)
    {
  //      cnt = 0;
        for(int j = i+1; j < n; ++j)
        {
            if(array[i] > array[j])
            {
                std::swap(array[i], array[j]);
      //          cnt++;
            }
        }
 //       if(cnt == 0) {break;}
    }
        return;
}



// пузырек
std::vector<int> sorting (std::vector<int>& vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = i+1; j < vec.size(); ++j)
        if(vec[i] > vec[j])
        {
            std::swap(vec[i], vec[j]);
        }
    }
    return vec;
}

void sorting_mas (int mas[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = i+1; j < size; ++j)
        {
            if(mas[i] > mas[j])
            {
                std::swap(mas[i], mas[j]);
            }
        }
    }
}


// вставкаками

std::vector<int> sort_vst(std::vector<int>& vec)
{
    for(int i = 1; i < vec.size(); ++i)
    {
        for(int j = i; j > 0 && vec[j -1] > vec[j]; --j)
        {
            std::swap(vec[j-1], vec[j]);
        }
    }
    return vec;
}


// реверс строки

void reverse (std::string& str)
{
    for(char i = 0; i < str.size()/2; ++i)
    {
        std::swap(str[i], str[str.size() - i -1]);
    }
}

void reverse_1(char* str)
{
    char size = strlen(str);
    for(char i = 0; i < size/2; ++i)
    {
//        std::swap(str[i], str[size - i -1]);

        char temp = str[i];
        str[i] = str[size - i -1];
        str[size - i -1] = temp;
    }

}



int main()
{
   int mas[] = {3, 1, 5, 2, 6, 7};


    sorting_mas(mas,6);
    for(int i = 0; i < 6; ++i)
    {
        std::cout<< mas[i] <<" ";
    }
//    std::string str = "hello world";
//    reverse(str);
//    std::cout << str << std::endl;

//    char mas[12] = "hello world";

//    reverse_1(mas);
//    std::cout << mas << std::endl;

//    std::vector<int> vec = {9, 8, 7, 1, 2, 5, 6, 3, 4};


//    std::vector<int> n_vec = sort_vst(vec);

//    for(const auto elem: n_vec)
//    {
//        std::cout << elem <<" " << std::endl;
//    }


//   // поиск бинарный
//   int key = 3;
//   int l = 0;
//   int r = vec.size();
//   int mid = 0;
//   bool flag = false;
//   while(l <=r && flag != true)
//   {
//       mid = (l+r)/2;
//       if(vec[mid] == key)
//           flag = true;
//       if(vec[mid] > key)
//           r = mid -1;
//       else l = mid +1;
//   }
//   std::cout<< "number "<< mid << std::endl;

    return 0;
}
