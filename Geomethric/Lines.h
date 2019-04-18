#pragma once
#include <iostream>
#include <algorithm>

enum orientation
{
	COLINEAR,
	CLOCK_WISE,
	COUNTERCLOCK_WISE
};

struct Point
{
	int x;
	int y;
};

struct Lines
{
	Point p;
	Point q;
};


orientation getOrientation(Point p, Point q, Point r)
{
	int result = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (result == 0)
		return COLINEAR;
	else if (result > 0)
		return CLOCK_WISE;
	else
		return COUNTERCLOCK_WISE;
}


bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
		q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
		return true;

	return false;
}

bool doIntersect(Lines line_1, Lines line_2)
{
	orientation o1 = getOrientation(line_1.p, line_1.q, line_2.p);
	orientation o2 = getOrientation(line_1.p, line_1.q, line_2.q);
	orientation o3 = getOrientation(line_2.p, line_2.q, line_1.p);
	orientation o4 = getOrientation(line_2.p, line_2.q, line_1.q);

	if (o1 != o2 && o3 != o4)
		return true;

	if (o1 == COLINEAR && onSegment(line_1.p, line_2.p, line_1.q)) 
		return true;

	if (o2 == COLINEAR && onSegment(line_1.p, line_2.q, line_1.q))
		return true;

	if (o3 == COLINEAR && onSegment(line_2.p, line_1.p, line_2.q)) 
		return true;

	if (o4 == COLINEAR && onSegment(line_2.p, line_1.q, line_2.q)) 
		return true;

	return false;
}



int segmentUnionLength(const std::vector<std::pair<int, int>> &seg)
{
	int n = seg.size();

	std::vector<std::pair<int, bool>> points(n * 2);
	for (int i = 0; i < n; i++)
	{
		points[i * 2] = std::make_pair(seg[i].first, false);
		points[i * 2 + 1] = std::make_pair(seg[i].second, true);
	}

	sort(points.begin(), points.end());

	int result = 0;
	int Counter = 0;
	for (unsigned i = 0; i < n * 2; i++)
	{
		if (Counter)
			result += (points[i].first - points[i - 1].first);

		(points[i].second) ? Counter-- : Counter++;
	}
	return result;
}

