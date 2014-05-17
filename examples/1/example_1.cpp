#include <Halide.h>
#include <iostream>

int main(int argc, char **argv)
{
  typedef float PixelType;

  int width = 1000;
  int height = 1000;

  // Define the imaging pipeline to be evaluated
  Halide::Var x, y;
  Halide::Func paraboloid;
  paraboloid( x, y ) = Halide::cast< PixelType >( x * x + y * y );

  // Realize the image executing the pipeline
  Halide::Image< PixelType > output = paraboloid.realize( width, height );

  // Check for the expected output
  for( int j = 0; j < output.height(); j++ )
  {
    for(int i = 0; i < output.width(); i++ )
    {
      PixelType expectedValue( static_cast< PixelType >( i * i + j * j ) );
      if( output(i,j) != expectedValue )
      {
        std::cout << "Something went wrong!" << std::endl;
        std::cout << "Pixel " << i << "," << j << " was supposed to be " << expectedValue
                  << ", but instead it is " << output( i, j ) << std::endl;
        return EXIT_FAILURE;
      }
    }
  }

  std::cout << "Success!"<< std::endl;
  return EXIT_SUCCESS;
}
