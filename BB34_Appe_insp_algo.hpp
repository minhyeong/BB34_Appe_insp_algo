#ifndef __BB34_Appe_insp_algo__
#define __BB34_Appe_insp_algo__

#include <opencv2/imgproc/types_c.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <vector>
#include <fstream>

class BB34_Appe_insp_algo {

public:
	BB34_Appe_insp_algo(); // コンストラクタ
	BB34_Appe_insp_algo(int); // コンストラクタ

	void input_csv(); // csvファイルを取得
	void labeling(); // 二値化させて保存する


private:
	int THRESHOLD; // 閾値
	std::string data[4]; // data_name, z_num, x_width(px), y_height(px)
	std::vector<std::string> img_name;

	void input_img_name_set(std::string, int); // ファイル名を取得
	std::string replace_input_label(std::string); // 保存ようのファイル名の文字列置換
};

#endif // __BB34_Appe_insp_algo__