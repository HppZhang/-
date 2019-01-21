//#include <iostream>
#include <vector>
#include "Agrothm.h"
using std::vector;
using std::cout;
int main()
{
    vector<vector<int > > x = {{2,2}};
    vector<int > y = {3, 3};
    x.push_back(y);
    x.push_back(y);
    x.pop_back();
    cout << y;
    cout<<x<<std::endl;
    double b_ini=0;
    vector<double > w_ini={0, 0};
    Agrothm test ({},1,b_ini,w_ini,1.0,1);
    vector<vector<double >> input_data_set = {{3,3},{4,3},{1,1},{5,5}};
    vector<int > y1 ={1,1,-1,1};
    test.train(input_data_set,y1);
    vector<double > test_data= {0,0};
    int y2 =-1;
    int predict_value = test.API(test_data);
    cout<<"test_real_label"<<y2<<" "<<"test_predict_label"<<predict_value<<endl;
    return 0;
}
