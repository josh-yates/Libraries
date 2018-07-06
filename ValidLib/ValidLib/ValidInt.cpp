#include "ValidInt.h"

bool valid::isInt(const std::string InputString, std::string& ErrMessage) {
	//Auto remove spaces
	std::stringstream eolStream(InputString);
	char BuffPeek;
	while ((BuffPeek = static_cast<char>(eolStream.peek())) == ' ') {
		eolStream.ignore(1, '\n');
	}
	//Auto remove eol, if present, then put it back on
	std::string DumpString;
	std::getline(eolStream, DumpString);
	//Put dumpstring and eol character in eolstream
	std::stringstream(DumpString + '\n').swap(eolStream);
	double TestDouble;
	eolStream >> TestDouble;
	if (eolStream.fail()) {
		eolStream.ignore(std::numeric_limits < std::streamsize>::max(), '\n');	//WARNING: if using windows.h, #define NOMINMAX
		ErrMessage = "Input contained non-numeric characters";
		return false;
	}
	//check if anything followed the number
	else if ((BuffPeek = static_cast<char>(eolStream.peek())) != '\n') {
		eolStream.ignore(std::numeric_limits < std::streamsize>::max(), '\n');	//WARNING: if using windows.h, #define NOMINMAX
		ErrMessage = "Input contained non-numeric characters";
		return false;
	}
	else {
		//split double into int and fraction parts
		double intPart, fractPart;
		fractPart = modf(TestDouble, &intPart);
		if (fractPart == 0.0) {
			return true;
		}
		else {
			ErrMessage = "Input not integer";
			return false;
		}
	}
}

bool valid::intInRange(const int InputInt, const int MinVal, const int MaxVal) {
	if (InputInt > MaxVal || InputInt < MinVal) {
		return false;
	}
	else {
		return true;
	}
}