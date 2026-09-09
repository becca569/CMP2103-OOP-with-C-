// A dataframe is a structure that stores data in rows and columns. Forexample;
// ind      ELE     COMP    BIO
// 1        100     120     80
// 2        130     140     90
// 3        110     150     100
// 4        100     105     95

// Calculate the mean, sum and median for each row.
// Display the final output in a table.

#include <array>
#include <iomanip>
#include <iostream>
#include <algorithm>

int main()
{
	const std::array<std::array<int, 3>, 4> scores{{
		{100, 120, 80}, {130, 140, 90}, {110, 150, 100}, {100, 105, 95}
	}};

	std::cout << "Ind\tSum\tMean\tMedian\n";

	for (std::size_t index = 0; index < scores.size(); ++index) {
		const auto& row = scores[index];
		const int sum = row[0] + row[1] + row[2];
		const double mean = sum / static_cast<double>(row.size());
		const int median = sum - std::min({row[0], row[1], row[2]})
			- std::max({row[0], row[1], row[2]});

		std::cout << index + 1 << '\t'
				  << sum << '\t'
				  << std::fixed << std::setprecision(2) << mean << '\t'
				  << median << '\n';
	}

	return 0;
}

