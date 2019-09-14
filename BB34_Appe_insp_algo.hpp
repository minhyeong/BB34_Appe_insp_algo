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
	BB34_Appe_insp_algo(); // �R���X�g���N�^
	BB34_Appe_insp_algo(int); // �R���X�g���N�^

	void input_csv(); // csv�t�@�C�����擾
	void labeling(); // ��l�������ĕۑ�����


private:
	int THRESHOLD; // 臒l
	std::string data[4]; // data_name, z_num, x_width(px), y_height(px)
	std::vector<std::string> img_name;

	void input_img_name_set(std::string, int); // �t�@�C�������擾
	std::string replace_input_label(std::string); // �ۑ��悤�̃t�@�C�����̕�����u��
};

#endif // __BB34_Appe_insp_algo__