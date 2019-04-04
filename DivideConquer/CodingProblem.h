#pragma once
#include <vector>
#include <algorithm>

// pow with 0(logn)
int power(int x, int raiseTo)
{
	int temp;
	if (raiseTo == 0)
		return 1;
	temp = power(x, raiseTo / 2);
	if (raiseTo % 2 == 0)
		return temp * temp;
	else
		return x * temp * temp;
}

// pow wot O(n)
int powerRecrusive(int x, int RaiseTo)
{
	if (RaiseTo == 0)
		return 1;
	else
		return x * powerRecrusive(x, RaiseTo - 1);
}


// closest point
struct Point
{
	int x;
	int y;
};

float distance(Point &p1, Point &p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y)
	);
}

float bruteForceCloseUtil(std::vector<Point> &points, int left, int right)
{
	float min = std::numeric_limits<float>::max();
	for (int i = left; i < right; ++i)
	{
		for (int j = i + 1; j < right; ++j)
		{
			float dist = distance(points[i], points[j]);
			if (dist < min)
				min = dist;
		}
	}
	return min;
}

float stripClosest(std::vector<Point> &stripPoints, float distanceMin)
{
	float min = distanceMin;
	int length = stripPoints.size();
	std::sort(stripPoints.begin(), stripPoints.end(), [](Point a, Point b) {
		return a.y < b.y;
	});

	for (int i = 0; i < length; ++i)
	{
		for (int j = i + 1; j < length && (stripPoints[j].y - stripPoints[i].y) < min; ++j)
		{
			float dist = distance(stripPoints[i], stripPoints[j]);
			if (dist < min)
				min = dist;
		}
			
	}
		

	return min;
}

float closeUtil(std::vector<Point> &points, int left, int right)
{
	int length = right - left;
	if (length <= 3)
		return bruteForceCloseUtil(points, left, right);

	int mid = right / 2;
	Point midPoint = points[mid];

	float distanceLeft = closeUtil(points, left, mid);
	float distanceRight = closeUtil(points, mid, right);

	float distanceMin = std::min(distanceLeft, distanceRight);

	std::vector<Point> strip;
	for (int i = 0; i < right; i++)
	{
		if (abs(points[i].x - midPoint.x) < distanceMin)
			strip.push_back(points[i]);
	}
		

	float stripClosestDistance = stripClosest(strip, distanceMin);
	return std::min(distanceMin, stripClosestDistance);
}

float closest(std::vector<Point> points)
{
	std::sort(points.begin(), points.end(), [](Point a, Point b) {
		return a.x < b.x;
	});

	return closeUtil(points, 0, points.size());
}

