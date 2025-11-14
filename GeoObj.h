#pragma once

#include <variant>
#include <math.h>
#include <iostream>

class Coord
{
public:
    Coord(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}
    double x() const { return x_; }
    double y() const { return y_; }
    void setX(double x) { x_ = x; }
    void setY(double y) { y_ = y; }

    void draw() const
    {
        std::cout << "Drawing point at (" << x_ << ", " << y_ << ")\n";
    }

private:
    double x_;
    double y_;
};

auto &operator<<(std::ostream &os, const Coord &c)
{
    os << "(" << c.x() << ", " << c.y() << ")";
    return os;
}

class Circle
{
public:
    Circle(Coord center = Coord(), double radius = 1.0)
        : center_(center), radius_(radius)
    {
    }
    double area() const
    {
        return M_PI * radius_ * radius_;
    }

    double circumference() const
    {
        return M_2_PI * radius_;
    }

    void draw() const
    {
        // std::cout << "Drawing circle at (" << center_.x() << ", " << center_.y() << ") with radius " << radius_ << "\n";
        std::cout << "Drawing circle at " << center_ << " with radius " << radius_ << "\n";
    }

private:
    Coord center_;
    double radius_;
};

class Rectangle
{
public:
    Rectangle(Coord topLeft = Coord(), double width = 1.0, double height = 1.0)
        : topLeft_(topLeft), width_(width), height_(height)
    {
    }
    double area() const
    {
        return width_ * height_;
    }
    double perimeter() const
    {
        return 2 * (width_ + height_);
    }

    void draw() const
    {
        //        std::cout << "Drawing rectangle at (" << topLeft_.x() << ", " << topLeft_.y() << ") with width " << width_ << " and height " << height_ << "\n";
        std::cout << "Drawing rectangle at " << topLeft_ << " with width " << width_ << " and height " << height_ << "\n";
    }

private:
    Coord topLeft_;
    double width_;
    double height_;
};

//
using GeoObj = std::variant<Circle, Rectangle>;

template <class T, typename Var>
concept alternative_c = requires(const Var &var) {
    []<typename... Args>
        requires(std::same_as<T, Args> || ...)
    (const std::variant<Args...> &) {}(var);
};

template <typename T>
concept is_geoobj = alternative_c<T, GeoObj>;

//
