
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Header.h"
#include "Pixel.h"
using namespace std;

//Function declarations.
Header ReadFile(ifstream& current_file, vector<Pixel>& current_image_pixels);
Header ReadHeaderOnly(ifstream& current_file);
void ReadLineOnly(ifstream& current_file, vector<Pixel>& current_image_pixels, short width);
void WriteFile(Header header_data, vector<Pixel>& image_pixel_data, ofstream& current_file);
void ReverseVector(vector<Pixel>& image_pixel_data);
void operator-=(vector<Pixel>& lhs, const vector<Pixel>& rhs);
void operator*=(vector<Pixel>& lhs, const vector<Pixel>& rhs);
bool ComparePixels(vector<Pixel>& program_output, vector<Pixel>& example_output);

int main()
{
	//Tasks seperated into multiple loops to segment variables and processes.
	int task_manager = 1;
	
	// Task 1
	while (task_manager == 1)
	{
		// Data input.
		ifstream layer1_file("input/layer1.tga", ios_base::binary);
		vector<Pixel> layer1_pixels;
		ifstream pattern1_file("input/pattern1.tga", ios_base::binary);
		vector<Pixel> pattern1_pixels;
		// Use of && based on info from Zybooks Table 5.5.2: Logical operators.
		if (layer1_file.is_open() && pattern1_file.is_open())
		{
			Header layer1_header = ReadFile(layer1_file, layer1_pixels);
			Header pattern1_header = ReadFile(pattern1_file, pattern1_pixels);
			// Task completion.
			layer1_pixels *= pattern1_pixels;
			// Data output.
			ofstream part1_file("output/part1.tga", ios_base::binary);
			WriteFile(layer1_header, layer1_pixels, part1_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 1 completed." << endl;
		task_manager = 2;
	}

	// Task 2
	while (task_manager == 2)
	{
		// Data input.
		ifstream car_file("input/car.tga", ios_base::binary);
		vector<Pixel> car_pixels;
		ifstream layer2_file("input/layer2.tga", ios_base::binary);
		vector<Pixel> layer2_pixels;
		if (car_file.is_open() && layer2_file.is_open())
		{
			Header car_header = ReadFile(car_file, car_pixels);
			Header layer2_header = ReadFile(layer2_file, layer2_pixels);
			// Task completion.
			car_pixels -= layer2_pixels;
			// Data output.
			ofstream part2_file("output/part2.tga", ios_base::binary);
			WriteFile(car_header, car_pixels, part2_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 2 completed." << endl;
		task_manager = 3;
	}

	// Task 3
	while (task_manager == 3)
	{
		// Data input.
		ifstream pattern2_file("input/pattern2.tga", ios_base::binary);
		vector<Pixel> pattern2_pixels;
		ifstream layer1_file("input/layer1.tga", ios_base::binary);
		vector<Pixel> layer1_pixels;
		ifstream text_file("input/text.tga", ios_base::binary);
		vector<Pixel> text_pixels;
		if (pattern2_file.is_open() && layer1_file.is_open() && text_file.is_open())
		{
			Header pattern2_header = ReadFile(pattern2_file, pattern2_pixels);
			Header layer1_header = ReadFile(layer1_file, layer1_pixels);
			Header text_header = ReadFile(text_file, text_pixels);
			// Task completion.
			layer1_pixels *= pattern2_pixels;
			for (int i = 0; i < text_pixels.size(); ++i)
			{
				text_pixels[i]._blue = 255 - text_pixels[i]._blue;
				layer1_pixels[i]._blue = 255 - layer1_pixels[i]._blue;
				text_pixels[i]._green = 255 - text_pixels[i]._green;
				layer1_pixels[i]._green = 255 - layer1_pixels[i]._green;
				text_pixels[i]._red = 255 - text_pixels[i]._red;
				layer1_pixels[i]._red = 255 - layer1_pixels[i]._red;
				
			}
			text_pixels *= layer1_pixels;
			for (int i = 0; i < text_pixels.size(); ++i)
			{
				text_pixels[i]._blue = 255 - text_pixels[i]._blue;
				text_pixels[i]._green = 255 - text_pixels[i]._green;
				text_pixels[i]._red = 255 - text_pixels[i]._red;
			}

			// Data output.
			ofstream part3_file("output/part3.tga", ios_base::binary);
			WriteFile(text_header, text_pixels, part3_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 3 completed." << endl;
		task_manager = 4;
	}

	// Task 4
	while (task_manager == 4)
	{
		// Data input.
		ifstream layer2_file("input/layer2.tga", ios_base::binary);
		vector<Pixel> layer2_pixels;
		ifstream circles_file("input/circles.tga", ios_base::binary);
		vector<Pixel> circles_pixels;
		ifstream pattern2_file("input/pattern2.tga", ios_base::binary);
		vector<Pixel> pattern2_pixels;
		// Use of && based on info from Zybooks Table 5.5.2: Logical operators.
		if (layer2_file.is_open() && circles_file.is_open() && pattern2_file.is_open())
		{
			Header layer2_header = ReadFile(layer2_file, layer2_pixels);
			Header circles_header = ReadFile(circles_file, circles_pixels);
			Header pattern2_header = ReadFile(pattern2_file, pattern2_pixels);
			// Task completion.
			layer2_pixels *= circles_pixels;
			layer2_pixels -= pattern2_pixels;
			// Data output.
			ofstream part4_file("output/part4.tga", ios_base::binary);
			WriteFile(layer2_header, layer2_pixels, part4_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 4 completed." << endl;
		task_manager = 5;
	}

	// Task 5
	while (task_manager == 5)
	{
		// Data input.
		ifstream layer1_file("input/layer1.tga", ios_base::binary);
		vector<Pixel> layer1_pixels;
		ifstream pattern1_file("input/pattern1.tga", ios_base::binary);
		vector<Pixel> pattern1_pixels;
		if (layer1_file.is_open() && pattern1_file.is_open())
		{
			Header layer1_header = ReadFile(layer1_file, layer1_pixels);
			Header pattern1_header = ReadFile(pattern1_file, pattern1_pixels);
			// Task completion.
			for (int i = 0; i < layer1_pixels.size(); ++i)
			{
				int background_grey = pattern1_pixels[i]._blue + pattern1_pixels[i]._green + pattern1_pixels[i]._red;
				if (background_grey < 382)
				{
					float blue = ((float)layer1_pixels[i]._blue * (float)pattern1_pixels[i]._blue) / 255;
					float green = ((float)layer1_pixels[i]._green * (float)pattern1_pixels[i]._green) / 255;
					float red = ((float)layer1_pixels[i]._red * (float)pattern1_pixels[i]._red) / 255;

					if (blue >= 127.5)
					{
						layer1_pixels[i]._blue = 255;
					}
					else
					{
						layer1_pixels[i]._blue = (2 * blue) + 0.5f;
					}
					if (green >= 127.5)
					{
						layer1_pixels[i]._green = 255;
					}
					else
					{
						layer1_pixels[i]._green = (2 * green) + 0.5f;
					}
					if (red >= 127.5)
					{
						layer1_pixels[i]._red = 255;
					}
					else
					{
						layer1_pixels[i]._red = (2 * red) + 0.5f;
					}
				}
				else
				{
					float A_blue = (float)layer1_pixels[i]._blue / 255;
					float A_green = (float)layer1_pixels[i]._green / 255;
					float A_red = (float)layer1_pixels[i]._red / 255;
					float B_blue = (float)pattern1_pixels[i]._blue / 255;
					float B_green = (float)pattern1_pixels[i]._green / 255;
					float B_red = (float)pattern1_pixels[i]._red / 255;

					float C_blue = 1 - 2 * (1 - A_blue) * (1 - B_blue);
					float C_green = 1 - 2 * (1 - A_green) * (1 - B_green);
					float C_red = 1 - 2 * (1 - A_red) * (1 - B_red);

					layer1_pixels[i]._blue = (C_blue * 255) + 0.5f;
					layer1_pixels[i]._green = (C_green * 255) + 0.5f;
					layer1_pixels[i]._red = (C_red * 255) + 0.5f;

				}
			}
			// Data output.
			ofstream part5_file("output/part5.tga", ios_base::binary);
			WriteFile(layer1_header, layer1_pixels, part5_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 5 completed." << endl;
		task_manager = 6;
	}

	// Task 6
	while (task_manager == 6)
	{
		// Data input.
		ifstream car_file("input/car.tga", ios_base::binary);
		vector<Pixel> car_pixels;
		if (car_file.is_open())
		{
			Header car_header = ReadFile(car_file, car_pixels);
			// Task completion.
			for (int i = 0; i < car_pixels.size(); ++i)
				if (car_pixels[i]._green >= 55)
					car_pixels[i]._green = 255;
				else
				{
					car_pixels[i]._green += 200;
				}
			// Data output.
			ofstream part6_file("output/part6.tga", ios_base::binary);
			WriteFile(car_header, car_pixels, part6_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 6 completed." << endl;
		task_manager = 7;
	}

	// Task 7 
	while (task_manager == 7)
	{
		// Data input.
		ifstream car_file("input/car.tga", ios_base::binary);
		vector<Pixel> car_pixels;
		if (car_file.is_open())
		{
			Header car_header = ReadFile(car_file, car_pixels);
			// Task completion.
			for (int i = 0; i < car_pixels.size(); ++i)
			{
				if (car_pixels[i]._red >= 64)
					car_pixels[i]._red = 255;
				else
				{
					car_pixels[i]._red *= 4;
				}
				car_pixels[i]._blue = 0;
			}
			// Data output.
			ofstream part7_file("output/part7.tga", ios_base::binary);
			WriteFile(car_header, car_pixels, part7_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 7 completed." << endl;
		task_manager = 8;
	}

	// Task 8 
	while (task_manager == 8)
	{
		// Data input.
		ifstream car_file("input/car.tga", ios_base::binary);
		vector<Pixel> car_pixels;
		if (car_file.is_open())
		{
			Header car_header = ReadFile(car_file, car_pixels);
			// Task completion.
			vector<Pixel> blue_pixels;
			vector<Pixel> green_pixels;
			vector<Pixel> red_pixels;
			for (int i = 0; i < car_pixels.size(); ++i)
			{
				Pixel blue_pixel(car_pixels[i]._blue, car_pixels[i]._blue, car_pixels[i]._blue);
				blue_pixels.push_back(blue_pixel);
				Pixel green_pixel(car_pixels[i]._green, car_pixels[i]._green, car_pixels[i]._green);
				green_pixels.push_back(green_pixel);
				Pixel red_pixel(car_pixels[i]._red, car_pixels[i]._red, car_pixels[i]._red);
				red_pixels.push_back(red_pixel);
			}
			// Data output.
			ofstream part8_b_file("output/part8_b.tga", ios_base::binary);
			WriteFile(car_header, blue_pixels, part8_b_file);
			ofstream part8_g_file("output/part8_g.tga", ios_base::binary);
			WriteFile(car_header, green_pixels, part8_g_file);
			ofstream part8_r_file("output/part8_r.tga", ios_base::binary);
			WriteFile(car_header, red_pixels, part8_r_file);

		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 8 completed." << endl;
		task_manager = 9;
	}

	// Task 9 
	while (task_manager == 9)
	{
		// Data input.
		ifstream layer_blue_file("input/layer_blue.tga", ios_base::binary);
		ifstream layer_green_file("input/layer_green.tga", ios_base::binary);
		ifstream layer_red_file("input/layer_red.tga", ios_base::binary);
		
		vector<Pixel> blue_pixels;
		vector<Pixel> green_pixels;
		vector<Pixel> red_pixels;
		vector<Pixel> combined_pixels;
		if (layer_blue_file.is_open() && layer_green_file.is_open() && layer_red_file.is_open())
		{
			Header blue_header = ReadFile(layer_blue_file, blue_pixels);
			Header green_header = ReadFile(layer_green_file, green_pixels);
			Header red_header = ReadFile(layer_red_file, red_pixels);
			// Task completion.
			for (int i = 0; i < blue_pixels.size(); ++i)
			{
				Pixel current_pixel(blue_pixels[i]._blue, green_pixels[i]._green, red_pixels[i]._red);
				combined_pixels.push_back(current_pixel);
			}
			// Data output.
			ofstream part9_file("output/part9.tga", ios_base::binary);
			WriteFile(blue_header, combined_pixels, part9_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 9 completed." << endl;
		task_manager = 10;
	}

	// Task 10 
	while (task_manager == 10)
	{
		// Data input.
		ifstream text2_file("input/text2.tga", ios_base::binary);
		vector<Pixel> text2_pixels;
		if (text2_file.is_open())
		{
			Header car_header = ReadFile(text2_file, text2_pixels);
			// Task completion.
			ReverseVector(text2_pixels);
			// Data output.
			ofstream part10_file("output/part10.tga", ios_base::binary);
			WriteFile(car_header, text2_pixels, part10_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Part 10 completed." << endl;
		task_manager = 11;
	}

	// Extra Credit task 
	while (task_manager == 11)
	{
		//Data input.
		ifstream car_file("input/car.tga", ios_base::binary);
		ifstream circles_file("input/circles.tga", ios_base::binary);
		ifstream text_file("input/text.tga", ios_base::binary);
		ifstream pattern1_file("input/pattern1.tga", ios_base::binary);
		vector<Pixel> combined_pixels;

		if (car_file.is_open() && circles_file.is_open() && text_file.is_open() && pattern1_file.is_open())
		{
			Header car_header = ReadHeaderOnly(car_file);
			Header circles_header = ReadHeaderOnly(circles_file);
			Header text_header = ReadHeaderOnly(text_file);
			Header pattern1_header = ReadHeaderOnly(pattern1_file);

			// Task completion.
			
			
			for (int i = 0; i < car_header._height; ++i)
			{
				ReadLineOnly(text_file, combined_pixels, car_header._width);
				ReadLineOnly(pattern1_file, combined_pixels, car_header._width);

			}
			for (int i = 0; i < car_header._height; ++i)
			{
				ReadLineOnly(car_file, combined_pixels, car_header._width);
				ReadLineOnly(circles_file, combined_pixels, car_header._width);

			}

			short width = car_header._width + circles_header._width;
			short height = car_header._height + text_header._height;
			car_header._width = width;
			car_header._height = height;

			// Data output.
			ofstream extra_credit_file("output/extracredit.tga", ios_base::binary);
			WriteFile(car_header, combined_pixels, extra_credit_file);
		}
		else
		{
			cout << "Error! File not open!" << endl;
		}
		cout << "Extra credit completed." << endl;
		task_manager = 999;
	}
	
	// Tests for output
	while (task_manager == 12)
	{
		// Task 1
		ifstream part1_file("output/part1.tga", ios_base::binary);
		vector<Pixel> part1_pixels;
		ifstream example1_file("examples/EXAMPLE_part1.tga", ios_base::binary);
		vector<Pixel> example1_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part1_header = ReadFile(part1_file, part1_pixels);
			Header example1_header = ReadFile(example1_file, example1_pixels);

			if (ComparePixels(part1_pixels, example1_pixels))
				cout << "Test #1...... Passed!" << endl;
			else
				cout << "Test #1...... Failed!" << endl;
		}
		else
			cout << "Test #1: Error! File not open." << endl;

		// Task 2
		ifstream part2_file("output/part2.tga", ios_base::binary);
		vector<Pixel> part2_pixels;
		ifstream example2_file("examples/EXAMPLE_part2.tga", ios_base::binary);
		vector<Pixel> example2_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part2_header = ReadFile(part2_file, part1_pixels);
			Header example2_header = ReadFile(example2_file, example1_pixels);

			if (ComparePixels(part2_pixels, example2_pixels))
				cout << "Test #2...... Passed!" << endl;
			else
				cout << "Test #2...... Failed!" << endl;
		}
		else
			cout << "Test #2: Error! File not open." << endl;

		// Task 3
		ifstream part3_file("output/part3.tga", ios_base::binary);
		vector<Pixel> part3_pixels;
		ifstream example3_file("examples/EXAMPLE_part3.tga", ios_base::binary);
		vector<Pixel> example3_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part3_header = ReadFile(part3_file, part3_pixels);
			Header example3_header = ReadFile(example3_file, example3_pixels);

			if (ComparePixels(part3_pixels, example3_pixels))
				cout << "Test #3...... Passed!" << endl;
			else
				cout << "Test #3...... Failed!" << endl;
		}
		else
			cout << "Test #3: Error! File not open." << endl;

		// Task 4
		ifstream part4_file("output/part4.tga", ios_base::binary);
		vector<Pixel> part4_pixels;
		ifstream example4_file("examples/EXAMPLE_part4.tga", ios_base::binary);
		vector<Pixel> example4_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part4_header = ReadFile(part4_file, part4_pixels);
			Header example4_header = ReadFile(example4_file, example4_pixels);

			if (ComparePixels(part4_pixels, example4_pixels))
				cout << "Test #4...... Passed!" << endl;
			else
				cout << "Test #4...... Failed!" << endl;
		}
		else
			cout << "Test #4: Error! File not open." << endl;

		// Task 5
		ifstream part5_file("output/part5.tga", ios_base::binary);
		vector<Pixel> part5_pixels;
		ifstream example5_file("examples/EXAMPLE_part5.tga", ios_base::binary);
		vector<Pixel> example5_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part5_header = ReadFile(part5_file, part5_pixels);
			Header example5_header = ReadFile(example5_file, example5_pixels);

			if (ComparePixels(part5_pixels, example5_pixels))
				cout << "Test #5...... Passed!" << endl;
			else
				cout << "Test #5...... Failed!" << endl;
		}
		else
			cout << "Test #5: Error! File not open." << endl;

		// Task 6
		ifstream part6_file("output/part6.tga", ios_base::binary);
		vector<Pixel> part6_pixels;
		ifstream example6_file("examples/EXAMPLE_part6.tga", ios_base::binary);
		vector<Pixel> example6_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part6_header = ReadFile(part6_file, part6_pixels);
			Header example6_header = ReadFile(example6_file, example6_pixels);

			if (ComparePixels(part6_pixels, example6_pixels))
				cout << "Test #6...... Passed!" << endl;
			else
				cout << "Test #6...... Failed!" << endl;
		}
		else
			cout << "Test #6: Error! File not open." << endl;

		// Task 7
		ifstream part7_file("output/part7.tga", ios_base::binary);
		vector<Pixel> part7_pixels;
		ifstream example7_file("examples/EXAMPLE_part7.tga", ios_base::binary);
		vector<Pixel> example7_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part7_header = ReadFile(part7_file, part7_pixels);
			Header example7_header = ReadFile(example7_file, example7_pixels);

			if (ComparePixels(part7_pixels, example7_pixels))
				cout << "Test #7...... Passed!" << endl;
			else
				cout << "Test #7...... Failed!" << endl;
		}
		else
			cout << "Test #7: Error! File not open." << endl;

		// Task 8_b
		ifstream part8_b_file("output/part8_b.tga", ios_base::binary);
		vector<Pixel> part8_b_pixels;
		ifstream example8_b_file("examples/EXAMPLE_part8_b.tga", ios_base::binary);
		vector<Pixel> example8_b_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part8_b_header = ReadFile(part8_b_file, part8_b_pixels);
			Header example8_b_header = ReadFile(example8_b_file, example8_b_pixels);

			if (ComparePixels(part8_b_pixels, example8_b_pixels))
				cout << "Test #8_b...... Passed!" << endl;
			else
				cout << "Test #8_b...... Failed!" << endl;
		}
		else
			cout << "Test #8_b: Error! File not open." << endl;


		// Task 8_g
		ifstream part8_g_file("output/part8_g.tga", ios_base::binary);
		vector<Pixel> part8_g_pixels;
		ifstream example8_g_file("examples/EXAMPLE_part8_g.tga", ios_base::binary);
		vector<Pixel> example8_g_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part8_g_header = ReadFile(part8_g_file, part8_g_pixels);
			Header example8_g_header = ReadFile(example8_g_file, example8_g_pixels);

			if (ComparePixels(part8_g_pixels, example8_g_pixels))
				cout << "Test #8_g...... Passed!" << endl;
			else
				cout << "Test #8_g...... Failed!" << endl;
		}
		else
			cout << "Test #8_g: Error! File not open." << endl;

		// Task 8_r
		ifstream part8_r_file("output/part8_r.tga", ios_base::binary);
		vector<Pixel> part8_r_pixels;
		ifstream example8_r_file("examples/EXAMPLE_part8_r.tga", ios_base::binary);
		vector<Pixel> example8_r_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part8_r_header = ReadFile(part8_r_file, part8_r_pixels);
			Header example8_r_header = ReadFile(example8_r_file, example8_r_pixels);

			if (ComparePixels(part8_r_pixels, example8_r_pixels))
				cout << "Test #8_r...... Passed!" << endl;
			else
				cout << "Test #8_r...... Failed!" << endl;
		}
		else
			cout << "Test #8_r: Error! File not open." << endl;

		// Task 9
		ifstream part9_file("output/part9.tga", ios_base::binary);
		vector<Pixel> part9_pixels;
		ifstream example9_file("examples/EXAMPLE_part9.tga", ios_base::binary);
		vector<Pixel> example9_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part9_header = ReadFile(part9_file, part9_pixels);
			Header example9_header = ReadFile(example9_file, example9_pixels);

			if (ComparePixels(part9_pixels, example9_pixels))
				cout << "Test #9...... Passed!" << endl;
			else
				cout << "Test #9...... Failed!" << endl;
		}
		else
			cout << "Test #9: Error! File not open." << endl;

		// Task 10
		ifstream part10_file("output/part10.tga", ios_base::binary);
		vector<Pixel> part10_pixels;
		ifstream example10_file("examples/EXAMPLE_part10.tga", ios_base::binary);
		vector<Pixel> example10_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header part10_header = ReadFile(part10_file, part10_pixels);
			Header example10_header = ReadFile(example10_file, example10_pixels);

			if (ComparePixels(part10_pixels, example10_pixels))
				cout << "Test #10...... Passed!" << endl;
			else
				cout << "Test #10...... Failed!" << endl;
		}
		else
			cout << "Test #10: Error! File not open." << endl;

		// Extra credit task
		ifstream extracredit_file("output/extracredit.tga", ios_base::binary);
		vector<Pixel> extracredit_pixels;
		ifstream example_extracredit_file("examples/EXAMPLE_extracredit.tga", ios_base::binary);
		vector<Pixel> example_extracredit_pixels;
		if (part1_file.is_open() && example1_file.is_open())
		{
			Header extracredit_header = ReadFile(extracredit_file, extracredit_pixels);
			Header example_extracredit_header = ReadFile(example_extracredit_file, example_extracredit_pixels);

			if (ComparePixels(extracredit_pixels, example_extracredit_pixels))
				cout << "Test #_extracredit...... Passed!" << endl;
			else
				cout << "Test #_extracredit...... Failed!" << endl;
		}
		else
			cout << "Test #_extracredit: Error! File not open." << endl;

		task_manager = 999;
	}
}


Header ReadFile(ifstream& current_file, vector<Pixel>& current_image_pixels)
{
	// Declarations
	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	// Reads header.
	current_file.read(&idLength, sizeof(idLength));
	current_file.read(&colorMapType, sizeof(colorMapType));
	current_file.read(&dataTypeCode, sizeof(dataTypeCode));
	current_file.read(reinterpret_cast<char*>(&colorMapOrigin), sizeof(colorMapOrigin));
	current_file.read(reinterpret_cast<char*>(&colorMapLength), sizeof(colorMapLength));
	current_file.read(&colorMapDepth, sizeof(colorMapDepth));
	current_file.read(reinterpret_cast<char*>(&xOrigin), sizeof(xOrigin));
	current_file.read(reinterpret_cast<char*>(&yOrigin), sizeof(yOrigin));
	current_file.read(reinterpret_cast<char*>(&width), sizeof(width));
	current_file.read(reinterpret_cast<char*>(&height), sizeof(height));
	current_file.read(&bitsPerPixel, sizeof(bitsPerPixel));
	current_file.read(&imageDescriptor, sizeof(imageDescriptor));

	Header headerObject(idLength, colorMapType, dataTypeCode, colorMapOrigin, colorMapLength, colorMapDepth, xOrigin, yOrigin, width, height, bitsPerPixel, imageDescriptor);
	
	// Reads image information
	for (int i = 0; i < (headerObject._height * headerObject._width); ++i)
	{
		unsigned char blue;
		unsigned char green;
		unsigned char red;
		current_file.read(reinterpret_cast<char*>(&blue), sizeof(blue));
		current_file.read(reinterpret_cast<char*>(&green), sizeof(green));
		current_file.read(reinterpret_cast<char*>(&red), sizeof(red));
		Pixel current_pixel(blue, green, red);
		current_image_pixels.push_back(current_pixel);
	}

	return headerObject;
}

Header ReadHeaderOnly(ifstream& current_file)
{
	// Variable declarations.
	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	// Reads header only
	current_file.read(&idLength, sizeof(idLength));
	current_file.read(&colorMapType, sizeof(colorMapType));
	current_file.read(&dataTypeCode, sizeof(dataTypeCode));
	current_file.read(reinterpret_cast<char*>(&colorMapOrigin), sizeof(colorMapOrigin));
	current_file.read(reinterpret_cast<char*>(&colorMapLength), sizeof(colorMapLength));
	current_file.read(&colorMapDepth, sizeof(colorMapDepth));
	current_file.read(reinterpret_cast<char*>(&xOrigin), sizeof(xOrigin));
	current_file.read(reinterpret_cast<char*>(&yOrigin), sizeof(yOrigin));
	current_file.read(reinterpret_cast<char*>(&width), sizeof(width));
	current_file.read(reinterpret_cast<char*>(&height), sizeof(height));
	current_file.read(&bitsPerPixel, sizeof(bitsPerPixel));
	current_file.read(&imageDescriptor, sizeof(imageDescriptor));

	Header headerObject(idLength, colorMapType, dataTypeCode, colorMapOrigin, colorMapLength, colorMapDepth, xOrigin, yOrigin, width, height, bitsPerPixel, imageDescriptor);

	return headerObject;
}
void ReadLineOnly(ifstream& current_file, vector<Pixel>& current_image_pixels, short width) 
{
	// Stops after reading one line of pixels.
	for (int i = 0; i < width; ++i)
	{
		unsigned char blue;
		unsigned char green;
		unsigned char red;
		current_file.read(reinterpret_cast<char*>(&blue), sizeof(blue));
		current_file.read(reinterpret_cast<char*>(&green), sizeof(green));
		current_file.read(reinterpret_cast<char*>(&red), sizeof(red));
		Pixel current_pixel(blue, green, red);
		current_image_pixels.push_back(current_pixel);
	}
}

void WriteFile(Header header_data, vector<Pixel>& image_pixel_data, ofstream& current_file)
{
	// Writes the header data.
	current_file.write(&header_data._idLength, sizeof(header_data._idLength));
	current_file.write(&header_data._colorMapType, sizeof(header_data._colorMapType));
	current_file.write(&header_data._dataTypeCode, sizeof(header_data._dataTypeCode));
	current_file.write(reinterpret_cast<char*>(&header_data._colorMapOrigin), sizeof(header_data._colorMapOrigin));
	current_file.write(reinterpret_cast<char*>(&header_data._colorMapLength), sizeof(header_data._colorMapLength));
	current_file.write(&header_data._colorMapDepth, sizeof(header_data._colorMapDepth));
	current_file.write(reinterpret_cast<char*>(&header_data._xOrigin), sizeof(header_data._xOrigin));
	current_file.write(reinterpret_cast<char*>(&header_data._yOrigin), sizeof(header_data._yOrigin));
	current_file.write(reinterpret_cast<char*>(&header_data._width), sizeof(header_data._width));
	current_file.write(reinterpret_cast<char*>(&header_data._height), sizeof(header_data._height));
	current_file.write(&header_data._bitsPerPixel, sizeof(header_data._bitsPerPixel));
	current_file.write(&header_data._imageDescriptor, sizeof(header_data._imageDescriptor));

	// Writes the image data.
	for (int i = 0; i < image_pixel_data.size(); ++i)
	{
		current_file.write(reinterpret_cast<char*>(&image_pixel_data[i]._blue), sizeof(image_pixel_data[i]._blue));
		current_file.write(reinterpret_cast<char*>(&image_pixel_data[i]._green), sizeof(image_pixel_data[i]._green));
		current_file.write(reinterpret_cast<char*>(&image_pixel_data[i]._red), sizeof(image_pixel_data[i]._red));
	}
}

void ReverseVector(vector<Pixel>& image_pixel_data)
{
	vector<Pixel> reversed_vector;
	for (int i = image_pixel_data.size() - 1; i >= 0; --i)
	{
		reversed_vector.push_back(image_pixel_data[i]);
	}
	image_pixel_data = reversed_vector;
}

void operator-=(vector<Pixel>& lhs, const vector<Pixel>& rhs)
{
	// subtracts individual color values.
	for (int i = 0; i < lhs.size(); ++i)
	{
		if (lhs[i]._blue <= rhs[i]._blue)
		{
			lhs[i]._blue = 0;
		}
		else
		{
			lhs[i]._blue -= rhs[i]._blue;
		}
		if (lhs[i]._green <= rhs[i]._green)
		{
			lhs[i]._green = 0;
		}
		else
		{
			lhs[i]._green -= rhs[i]._green;
		}
		if (lhs[i]._red <= rhs[i]._red)
		{
			lhs[i]._red = 0;
		}
		else
		{
			lhs[i]._red -= rhs[i]._red;
		}
	}
}
void operator*=(vector<Pixel>& lhs, const vector<Pixel>& rhs)
{
	for (int i = 0; i < lhs.size(); ++i)
	{
		// Process for correcting rounding during conversion taken from project 2 overview. Credit to instruct.
		lhs[i]._blue = ((float)lhs[i]._blue * (float)rhs[i]._blue) / 255 + 0.5f;
		lhs[i]._green = ((float)lhs[i]._green * (float)rhs[i]._green) / 255 + 0.5f;
		lhs[i]._red = ((float)lhs[i]._red * (float)rhs[i]._red) / 255 + 0.5f;
	}
}

bool ComparePixels(vector<Pixel>& program_output, vector<Pixel>& example_output)
{
	// Checks for consistent sizes.
	if (program_output.size() == example_output.size())
	{
		// Checks for consistent rbg values.
		for (int i = 0; i < program_output.size(); ++i)
		{
			if (program_output[i]._blue != example_output[i]._blue)
			{
				cout << "Green - Actual: " << (int)program_output[i]._green << " " << "Expected: " << (int)example_output[i]._green << endl;
				cout << "Blue - Actual: " << (int)program_output[i]._blue << " " << "Expected: " << (int)example_output[i]._blue << endl;
				cout << "Red - Actual: " << (int)program_output[i]._red << " " << "Expected: " << (int)example_output[i]._red << endl;
				return false;
			}

			if (program_output[i]._red != example_output[i]._red)
			{
				cout << "Green - Actual: " << (int)program_output[i]._green << " " << "Expected: " << (int)example_output[i]._green << endl;
				cout << "Blue - Actual: " << (int)program_output[i]._blue << " " << "Expected: " << (int)example_output[i]._blue << endl;
				cout << "Red - Actual: " << (int)program_output[i]._red << " " << "Expected: " << (int)example_output[i]._red << endl;
				return false;
			}
			if (program_output[i]._green != example_output[i]._green)
			{
				cout << "Green - Actual: " << (int)program_output[i]._green << " " << "Expected: " << (int)example_output[i]._green << endl;
				cout << "Blue - Actual: " << (int)program_output[i]._blue << " " << "Expected: " << (int)example_output[i]._blue << endl;
				cout << "Red - Actual: " << (int)program_output[i]._red << " " << "Expected: " << (int)example_output[i]._red << endl;
				return false;
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}