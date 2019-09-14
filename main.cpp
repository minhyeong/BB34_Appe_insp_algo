
// main.cpp  imamura

#include "BB34_Appe_insp_algo.hpp"

using namespace cv;

int main() {

	//BB34_Appe_insp_algo test(160);
	BB34_Appe_insp_algo test;

	test.input_csv();
	test.labeling();

	return 0;
}