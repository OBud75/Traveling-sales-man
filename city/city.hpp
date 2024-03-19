#pragma once
// Class representing a city with its coordinates
class City
{
private:
    int id;      // Unique identifier for the city
    double x, y; // Coordinates of the city

public:
    // Constructor to initialize the city with given id and coordinates
    City(int id, double x, double y);

    // Getter method to retrieve the city's id
    int getId() const;

    // Getter method to retrieve the x-coordinate of the city
    double getX() const;

    // Getter method to retrieve the y-coordinate of the city
    double getY() const;

    // Method to calculate the Euclidean distance between this city and another city
    double distanceTo(const City &other) const;
};