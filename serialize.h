string serialize(char & in[][])
{
	return FlattenVar(in);
}

void deserialize(string in, char & out[][])
{
	UnflattenVar(in, out);
}

string createHeader(int x_dim, int y_dim, int chunk_size)
{
	return StrCat("#", NumToStr(x_dim), ",", NumToStr(y_dim), ",", NumToStr(chunk_size));
}

string createFinMessage()
{
	return "FIN";
}

void parseHeader(string header, int & x_dim, int & y_dim, int & chunk_size)
{
	string cleaned = SubStr(header, 1, StrLen(header));
	int separator = Pos(",", cleaned);
	x_dim = atoi(SubStr(cleaned, 0, separator));
	string current = SubStr(cleaned, separator + 1, StrLen(cleaned));
	separator = Pos(",", current);
	y_dim = atoi(SubStr(current, 0, separator));
	current = SubStr(current, separator + 1, StrLen(current));
	chunk_size = atoi(current);
}