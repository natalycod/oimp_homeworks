#include <iostream>

template <typename T>
class IntegrationMethod {
public:
    virtual double Integrate(T f, double L, double R, int k) {}
};

template <typename T>
class RectangleRule : public IntegrationMethod<T> {
public:
    double Integrate(T f, double L, double R, int k) override {
        double len = (R - L) / k;
        double res = 0;
        for (int i = 0; i < k; ++i) {
            double x_now = L + i * len;
            double y_now = f(x_now + len / 2);
            res += y_now * len;
        }
        return res;
    }
};

template <typename T>
class TrapezoidalRule : public IntegrationMethod<T> {
public:
    double Integrate(T f, double L, double R, int k) override {
        double len = (R - L) / k;
        double res = 0;
        for (int i = 0; i < k; i++) {
            double x_now = L + i * len;
            double y_now = (f(x_now) + f(x_now + len)) / 2;
            res += y_now * len;
        }
        return res;
    }
};
