#include <stdio.h>
#include <math.h>
#include "cv.h"
#include "highgui.h"

int mSetTest(double c_re, double c_im)
{
	int num = 0;
	int multTimes = 0;
	double z1 = 0;
	double z2 = 0;
	double z1Tmp, z2Tmp;
	double mod = 0;
	//scanf("%lf", &c_re);
	//scanf("%lf", &c_im);
	while (num<200) {
		num++;
		z1Tmp = (z1*z1 - z2*z2) + c_re;
		z2Tmp = (2 * z1*z2) + c_im;
		z1 = z1Tmp;
		z2 = z2Tmp;
		multTimes++;
		mod = sqrt(z1*z1 + z2*z2);
		if (mod>2)return num;
	}
	return 0;
}

int main() {
	/*printf("Tomato\n");
	double c1 = 1.3;
	double c2 = 0.4;
	printf("%d", mSetTest(c1, c2));
	scanf("%lf", &c1);*/

	IplImage *pImg =
		cvCreateImage(cvSize(400, 400), 8, 3);
	for (int x = 0; x<399; x++) {
		for (int y = 0; y<399; y++) {
			double xPos = ((double)x - 200) / 100;
			double yPos = ((double)y - 200) / 100;
			//printf("x:%d, y:%d, num:%d\n", xPos, yPos, num);
			if (mSetTest(xPos, yPos) ==0)
			{
				cvSet2D(pImg, y, x, cvScalar(0, 0, 0, 0));
			}
			else
			{
				cvSet2D(pImg, y, x, cvScalar(255, 255, 255, 0));
			}
		}
	}
	cvNamedWindow(/*name of the window*/"mandelbrot", 1);
	cvShowImage("mandbrot", pImg);





	cvWaitKey(/*delay*/0);

	cvDestroyWindow("mandlbrot");
	cvRelease(&pImg);

	return 0;
}
