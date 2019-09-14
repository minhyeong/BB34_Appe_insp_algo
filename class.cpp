
#include "BB34_Appe_insp_algo.hpp"

// ファイル読み込み

using namespace cv;


const std::string file_number[5] = { "01","06","07","08","12" };
std::string input_FILE = "sozai/input/alcon" + file_number[4] + "/input.csv";


// コンストラクタ
BB34_Appe_insp_algo::BB34_Appe_insp_algo(int threshold) {
	THRESHOLD = threshold;
	std::cout << "Threshold : " << THRESHOLD << std::endl;
}

BB34_Appe_insp_algo::BB34_Appe_insp_algo() {
	THRESHOLD = 0;
	std::cout << "Threshold : Automatic Setting" << std::endl;
}


// csvファイルの取得
void BB34_Appe_insp_algo::input_csv() {
	std::ifstream ifs(input_FILE);
	std::string str;

	if (!ifs) {
		std::cerr << "ERROR::Failed to acquire the File." << std::endl;
		exit(-1);
	}
	
	int i = 0;
	while (getline(ifs, str)) {
		data[i++] = str;
	}
	input_img_name_set(data[0], atoi(data[1].c_str()));
}

// データセット
void BB34_Appe_insp_algo::input_img_name_set(std::string data_name, int z_num) { // 枚数, alcon名, 

	for (int i = 0; i < z_num; i++) {

		char img_number[5];
		sprintf_s(img_number, "%04d", i);
		std::string str = img_number;

		std::string IMG_NAME = "./sozai/input/" + data_name + "/" + data_name + "_input_" + str + ".tif";
		img_name.push_back(IMG_NAME);
	}
}

// 二値化
void BB34_Appe_insp_algo::labeling() {
	// 画像インポート

	//int width = atoi(data[2].c_str());
	//int height = atoi(data[3].c_str());


	for (auto v : img_name) {

		// グレースケール
		Mat input_img = imread(v, IMREAD_GRAYSCALE);
		Mat out_img;
			

		if (THRESHOLD == 0)
			threshold(input_img, out_img, THRESHOLD, 255, THRESH_BINARY | THRESH_OTSU);
		else 
			threshold(input_img, out_img, THRESHOLD, 255, THRESH_BINARY);


		std::string str = replace_input_label(v);
		imwrite(str, out_img); // 保存
	}

	std::cout << "Finished." << std::endl;
	
}

// 文字列置換 input -> output
std::string BB34_Appe_insp_algo::replace_input_label(std::string str) {
	std::string target = "input";
	std::string replacement = "label";
	if (!target.empty()) {
		std::string::size_type pos = 0;
		while ((pos = str.find(target, pos)) != std::string::npos) {
			str.replace(pos, target.length(), replacement);
			pos += replacement.length();
		}
	}
	return str;
}
