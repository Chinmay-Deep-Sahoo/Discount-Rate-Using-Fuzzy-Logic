#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;

//function declarations
float find_mu(int start, int end, int I);   //to find the membership function
void update_m1(map<string, float>& map, int I);  
void update_m2(map<string, float>& map, int I);
void update_m3(map<string, float>& map, int I);
float calc_discount(vector<float>& weights, vector<float>& y_value);
void display_discout(float discount);

//main function
int main() {
    //Taking Inputs
    float I1, I2, I3;
    cout << "What is the number of sales per week for the product? (0-200):"; cin >> I1;
    cout << "How large is the stock of product? (0-500):"; cin >> I2;
    cout << "How long has the product been in the warehouse? (0-24mo):"; cin >> I3;

    //Normalizing Inputs
    if (I1 > 200) I1 = 200; //sales greater than 200 is taken as 'high' sale with mu=1;
    if (I2 > 500) I2 = 500; //stock greater than 500 is taken as 'bulk' with mu=1;
    if (I3 > 24) I3 = 24;   //product older than 24 mon is taken as 'very old' with mu=1;

    //map data structure to store membership value for each linguistic term
    map<string, float> m1, m2, m3; 
    update_m1(m1, I1);
    update_m2(m2, I2);
    update_m3(m3, I3);

    I1 = 200 - I1;  //normalizing I1
    //different linguistic terms I1, I2 and I3
    string lings1[] = { "VLOW","LOW","MID","HIGH" };  //Very LOW, LOW, MIDdle, HIGH
    string lings2[] = { "HF","SM","MID","BK" };  //HandFul, SMall, MIDdl    e, BulK
    string lings3[] = { "NEW","OLD","VOLD" };  //NEW, OLD, Very OLD

    //calculating weights for each input combination to produce different outputs
    vector<float> weights; //to store weights
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                weights.push_back(m1[lings1[i]] * m2[lings2[j]] * m3[lings3[k]]);
            }
        }
    }

    //higher the coefficient higher the effect of that linguistic term in increasing output (discount)    
    float coeff1[] = { 1,2,3,5 };  //storing coefficients for each linguistic term of I1
    float coeff2[] = { 1,3,5,7 };  //storing coefficients for each linguistic term of I2
    float coeff3[] = { 1,3,5 };    //storing coefficients for each linguistic term of I3

    //calculating y_value for each combination
    vector<float> y_value;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                y_value.push_back(coeff1[i] * I1 + coeff2[j] * I2 + coeff3[k] * I3);
            }
        }
    }

    //Now calculating the final discount % based on weights and and y-value's.
    float discount = calc_discount(weights, y_value);

    //prints the dicount value beautifully
    display_discout(discount);

    return 0;
}

void update_m1(map<string, float>& m, int I) {
    if (I > 0 && I <= 20) {
        m["VLOW"] = find_mu(20, 0, I);
        m["LOW"] = find_mu(0, 20, I);
    }
    else if (I <= 100) {
        m["MID"] = find_mu(20, 100, I);
        m["LOW"] = find_mu(100, 20, I);
    }
    else/* if (I >100 && I<infinity)*/ {
        m["HIGH"] = find_mu(100, 200, I);
        m["MID"] = find_mu(200, 100, I);
    }
}

void update_m2(map<string, float>& m, int I) {
    if (I > 0 && I <= 20) {
        m["HF"] = find_mu(20, 0, I);  //HF=HandFul
        m["SM"] = find_mu(0, 20, I);  //SM=SMall
    }
    else if (I <= 250) {
        m["MID"] = find_mu(20, 250, I);
        m["SM"] = find_mu(250, 20, I);
    }
    else /*if (I > 250 && I<infinity)*/ {
        m["MID"] = find_mu(250, 500, I);
        m["BK"] = find_mu(500, 250, I);  //BK=BulK
    }
}

void update_m3(map<string, float>& m, int I) {
    if (I > 0 && I <= 6) {
        m["OLD"] = find_mu(0, 6, I);
        m["NEW"] = find_mu(6, 0, I);
    }
    else /*if (I > 6 && I<infinity)*/ {
        m["VOLD"] = find_mu(6, 24, I);
        m["OLD"] = find_mu(24, 6, I);
    }
}

float find_mu(int s, int e, int I) {
    //calculates membership value
    float temp = (I - s);
    temp = temp / (e - s);
    return temp;
}

float calc_discount(vector<float>& weights, vector<float>& y_value) {
    //this function calculates y-value (as in book) and then normalizes this y-value between 0 and 60
    float result = 0;
    float weights_sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        result += (weights[i] * y_value[i]);
        weights_sum += weights[i];
    }
    result = (result / weights_sum);
    //cout << "raw result: " << result << endl;
    //the value of result is raw, we now need to normalize this value between 0 and 60;
    //min and max value of result (i.e. 0 and 2970 respectively) represents min and max discount possible;
    result = (result - 0) * 60;
    result = result / 2970;
    return result;
}

void display_discout(float discount) {
    //This function displays discount% to the user based on the its value.
    if (discount < 20) {
        cout << "\n\n\nSince the product is doing quite good or has the potential to do good in the market, "
            << "discount on the product is LOW.\nDiscount:  " << discount << "%" << endl;
    }
    else if (discount < 35) {
        cout << "\n\n\nBased on the market value of the product, it has MID range discount of "
            << discount << "%" << endl;
    }
    else if (discount < 45) {
        cout << "\n\n\nThe Product is doing average, therefore discount for the product is 'HIGH'. "
            << "\nDiscount: " << discount << "%" << endl;
    }
    else
        cout << "\n\n\nThe product is expected to fail in the market and thus it has 'HEAVY' discount to offer\n"
        << "Discount: " << discount << "%" << endl;

}