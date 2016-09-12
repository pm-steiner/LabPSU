/* 
* Linearizer.h
*
* Author: tom
*/

#include <stdint.h>

#ifndef __LINEARIZER_H__
#define __LINEARIZER_H__

/*
The Linearizer is used to linearize the output of a DAC or ADC using a table of measured
values.
To calibrate the output of a DAC we need to adjust the codes used to take into 
account any non-linearities in either the DAC or the system being driven by it.
A simple way of doing this is to store a series of measure points and to linearly
interpolate between those points. The points are a series of float values and 
their corresponding ADC/DAC codes. 

When converting a value to a code or vice versa the class will search for a point
in the table greater than the value in question and then will use the gradient
calculated between that point and the next one to convert to a code/value.
*/
class Linearizer
{
public:
    struct Point
    {		
        uint16_t	code;
        float		value;		
    };
    
    static const struct Point ZERO_POINT;
    
    Linearizer(const Point *points, int numPoints,uint16_t min=0,uint16_t max=0xffff);
    
    /*
    Calculates the code for the value provided by using
    the table of points provided in the constructor.
    */
    const uint16_t valueToCode(const float value) const;
    
    /*
    Calculates the value given the code provided by using
    the table of points provided in the constructor
    */
    const float codeToValue(const uint16_t code) const;
    
protected:

    /*
    Calculates the code by interpolating using the points provided.
    Uses point1 and point2 to calculat the gradient and then extrapolates
    using this gradient from the basepoint provided.
    */
    uint16_t interpolateCode( 
        const Point&	point1, 
        const Point&	point2, 
        const Point&	basePoint,
        const float		value  ) const;

    /*
    Calculates the code by interpolating using the points provided.
    Uses point1 and point2 to calculate the gradient and then extrapolates
    using this gradient from the basepoint provided.
    */
    float interpolateValue(
        const Point&	point1, 
        const Point&	point2, 
        const Point&	basePoint,
        const uint16_t	code ) const;
        
    const Point	*m_points;
    int			m_numPoints;
    uint16_t    m_min;
    uint16_t    m_max;
};

#endif //__LINEARIZER_H__
