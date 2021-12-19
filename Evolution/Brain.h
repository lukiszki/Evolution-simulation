#pragma once

class Brain
{
	static constexpr int  inp_size = 6;
	static constexpr int  hl_size = 5;
	static constexpr int  out_size = 5;



private:
//INPUT: POS(x,y), surrounding(north,east,south,west)

	//Hidden layers
	float z1[hl_size];
	float a1[hl_size];

//OUTPUT: stay, go_up, go_right, go_down, go_left
	float z2[out_size];
	float a2[out_size];

//WEIGHTS
	float W1[inp_size* hl_size];
	float W2[out_size * hl_size];
//BIASES
	float b1[hl_size];
	float b2[out_size];

public:

	void initialize_params();

	void feed_forward(float input[]);

	int GetAction(float input[]);
	
};

