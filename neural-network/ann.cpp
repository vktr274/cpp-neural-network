#include "ann.h"

#include <algorithm>
#include <random>
#include <cmath>

namespace ann {
	Neuron::Neuron(double_t weight_) :
		weight(weight_) {
	
	}

	double_t Neuron::relu(double_t input) {
		return std::max(0.0, input);
	}

	double_t Neuron::output(std::vector<double_t>& inputs) {
		for (auto& input : inputs) {

		}
	}

	Layer::Layer(size_t numberOfNeurons_) : numberOfNeurons(numberOfNeurons_) {
		std::normal_distribution<double_t> weights(0.0, std::sqrt(2.0));
		std::default_random_engine weightGenerator;

		for (size_t i = 0; i < numberOfNeurons; i++) {
			double_t weight = weights(weightGenerator);
			neurons.push_back(Neuron(weight));
		}

		bias = weights(weightGenerator);
	}
}