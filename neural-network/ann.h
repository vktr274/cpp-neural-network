#pragma once

#include <vector>

namespace ann {
	class Layer {
		size_t numberOfNeurons;
		std::vector<Neuron> neurons;
		double_t bias;
	public:
		Layer(size_t);
	};

	class Neuron {
		double_t weight;
	public:
		Neuron(double_t);
		double_t relu(double_t);
		double_t output(std::vector<double_t>&);
	};
}