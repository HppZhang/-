//
// Created by zhp on 19-1-20.
//

#ifndef GANZHIJI_AGROTHM_H
#define GANZHIJI_AGROTHM_H
#include <numeric>
#include <iostream>
#include <vector>
#include <cstdlib>
using std::vector;
using std::endl;
using std::cout;
int sign(double x);
class Agrothm
{
private:
    vector<double > x;
    int y;
    int y_real;
    vector<double > w;
    double  b;
    double learn_rate;
public:
    Agrothm(vector<double > a2={}, int b2=0, double b_ini={}, vector<double > w_ini={{}}, double learn=1.0, int y_real_ini={}):x(a2),y(b2),w(w_ini),b(b_ini),learn_rate(learn),y_real(y_real_ini){}
    Agrothm(Agrothm& x_input);
    Agrothm& operator=(Agrothm & n1);
    vector<double > show_x() const {return x;}
    int show_y() const  {return y;}
    vector<double > show_w() const {return w;}
    double show_b() const {return b;}
    int show_y_real() const {return sign(y_real);}
    double show_learn_rate() const {return learn_rate;}
    int model(vector<double > x1);
    void update_y_real(vector<double > x1);
    void update_w(vector<double >x1, int y1);
    void update_b(int y1);
    void update(vector<double > x1, int y1);
    int flag();
    void to_set_learn_rate(double learn);
    void update_input(vector<double > input);
    void update_landmark(int landmark);
    void train(vector<vector<double >> input_data_set, vector<int >y1);
    int API(vector<double >input)
    {
        update_y_real(input);
        return show_y_real();
    }
};


vector<int > operator*(vector<int > x, vector<int > y);
vector<double > operator*(vector<double > x, vector<double > y);
vector<double > operator*(double x, vector<double > y);
vector<double > operator+(vector<double > x, vector<double > y);
std::ostream& operator<<(std::ostream&os, vector<int >& x);
std::ostream& operator<<(std::ostream&os, vector<vector<int >>& x);
std::ostream& operator<<(std::ostream&os, vector<vector<double >>& x);
std::ostream& operator<<(std::ostream&os, vector<double >& x);
vector<int > operator+(const vector<int >& x, const int& y);
vector<double > operator+(const vector<double >& x, const double& y);

#endif //GANZHIJI_AGROTHM_H
