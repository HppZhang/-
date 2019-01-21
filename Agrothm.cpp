//
// Created by zhp on 19-1-20.
//

#include "Agrothm.h"
void Agrothm::train(vector<vector<double >> input_data_set, vector<int >y1)
{
    while (true)
    {
        int num=0;
        for (int i = 0; i < input_data_set.size(); i++)
        {
            update_input(input_data_set[i]);
            update_landmark(y1[i]);
            update_y_real(input_data_set[i]);
            update(input_data_set[i], y1[i]);
            if (flag())
            {
                //cout<<"success";
                num+=1;
            }
        }
        if (num==input_data_set.size())
        {
            cout<<"success"<<endl;
            break;
        }
    }
    for (int j = 0; j < input_data_set.size(); j++)
    {
        update_input(input_data_set[j]);
        update_landmark(y1[j]);
        update_y_real(input_data_set[j]);
        int label = show_y_real();
        cout<<"real_label"<<y1[j]<<" "<<"predict_label"<<label<<endl;
    }
}

Agrothm::Agrothm(Agrothm &x_input)
{
    this->x = x_input.x;
    this->y = x_input.y;
    this->w = x_input.w;
    this->b = x_input.b;
    this->learn_rate = x_input.learn_rate;
    this->y_real = x_input.y_real;
}
Agrothm& Agrothm::operator=(Agrothm &n1)
{
    this->x = n1.x;
    this->y = n1.y;
    this->w = n1.w;
    this->b = n1.b;
    this->learn_rate = n1.learn_rate;
    this->y_real = n1.y_real;
    return *this;
}

int Agrothm::model(vector<double> x1)
{
    int  result;
    if (w.size()!=x1.size())
    {
        cout<<"please make sure the size of x and w is equal";
        abort();
    }
    //int total = accumulate(x.begin(), x.end(),0);
    //int result = accumulate(result.begin(), result.end(), 0);
    vector<double > inter_vec = w*x1;
    double inter = accumulate(inter_vec.begin(),inter_vec.end(),0);
    result = inter+b;
    return result;
}
void Agrothm::update_y_real(vector<double > x1)
{
    y_real =  model(x1);
}
void Agrothm::update_w(vector<double >x1, int y1)
{
    w = w+learn_rate*y1*x1;
}
void Agrothm::update_b(int y1)
{

    b = b+learn_rate*y1;
}
void Agrothm::update(vector<double > x1, int y1)
{
    if (y_real*y<=0)
    {
        update_w(x1, y1);
        update_b(y1);
    }
}
int Agrothm::flag()
{
    if (y_real*y>0)
    {
        return true;
    }
    else
        return false;
}
void Agrothm::to_set_learn_rate(double learn)
{
    learn_rate = learn;
}
void Agrothm::update_input(vector<double> input)
{
    x=input;
}
void Agrothm::update_landmark(int landmark)
{
    y=landmark;
}
//全局重载<<
std::ostream& operator<<(std::ostream&os, vector<int >& x)
{
    os<<"(";
    for (int i =0; i<x.size(); i++)
    {
        if (i != (x.size()-1))
        {
            os<<x[i]<<",";
        }
        else
        {
            os<<x[i];
        }
    }
    os<<")"<<std::endl;
    return os;
}

std::ostream& operator<<(std::ostream&os, vector<vector<int >>& x)
{
    os<<"(";
    for (int j=0;j<x.size();j++)
    {
        os<<"(";
        for (int i =0; i<x[j].size(); i++)
        {
            if (i != (x[j].size()-1))
            {
                os<<x[j][i]<<",";
            }
            else
            {
                os<<x[j][i];
            }
        }
        os<<")";
    }
    os<<")";

    return os;
}
std::ostream& operator<<(std::ostream&os, vector<vector<double >>& x)
{
    os<<"(";
    for (int j=0;j<x.size();j++)
    {
        os<<"(";
        for (int i =0; i<x[j].size(); i++)
        {
            if (i != (x[j].size()-1))
            {
                os<<x[j][i]<<",";
            }
            else
            {
                os<<x[j][i];
            }
        }
        os<<")";
    }
    os<<")";

    return os;
}
std::ostream& operator<<(std::ostream&os, vector<double >& x)
{
    os<<"(";
    for (int i =0; i<x.size(); i++)
    {
        if (i != (x.size()-1))
        {
            os<<x[i]<<",";
        }
        else
        {
            os<<x[i];
        }
    }
    os<<")"<<std::endl;
    return os;
}
//点乘
vector<int > operator*(const vector<int > x, const vector<int > y)
{
    if (x.size()!=y.size())
    {
        cout<<"please ensure the size of x and y is qeual"<<endl;
        std::abort();
    }
    vector<int > result;
    for (int num=0; num<x.size(); num++)
    {
        result.push_back(x[num]*y[num]);
    }
    return result;
}

vector<double > operator*(const vector<double > x, const vector<double > y)
{
    if(x.size() != y.size())
    {
        cout<<"please ensure the size of x and y is equal"<<endl;
        std::abort();
    }
    vector<double > result = x;
    for (int i = 0; i <result.size() ; i++)
    {
        result[i] *= y[i];
    }
    return result;
}
vector<double > operator*(double x, vector<double > y)
{
    vector<double >result(y.size(),x);
    return result*y;
}
//加法重载
vector<int > operator+(const vector<int >& x, const int& y)
{
    vector<int > result(x.size(),y);
    for (int i = 0; i < x.size(); ++i)
    {
        result[i] += x[i];
    }
    return result;
}
vector<double > operator+(const vector<double >& x, const double& y)
{
    vector<double > result(x.size(),y);
    for (int i = 0; i < x.size(); ++i)
    {
        result[i] += x[i];
    }
    return result;
}
vector<double > operator+(vector<double > x, vector<double > y)
{
    if (x.size()!=y.size())
    {
        cout<<"please make sure the size of x and y is equal";
        abort();
    }
    for (int i = 0; i <x.size(); i++)
    {
        x[i] = x[i]+y[i];
    }
    return x;
}
//常用函数
int sign(double x)
{
    if (x>=0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}