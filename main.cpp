/*
 * main.cpp
 *
 *  Created on: 28 Feb 2012
 *      Author: pwollaston
 */

#include "main.h"
#include "signage.h"

int main(int argc, char* argv[])
{
	srand(time(NULL)); /* Randomise Time Seed */
	Signage signage;
	signage.Init("Digital Signage", 1920, 1080, 32, false);

	while (signage.Running())
	{
		signage.HandleEvents(&signage);
		signage.Update();
		signage.Draw();
	}

	/* Cleanup Engine */
	signage.Clean();

	printf("OrbitalDigitalSignage has cleanly exited.\n");

	return 0;
}
