#include <iostream>
#include "utils.h"

int main() {
    char cmd[128];
	inst_t token;

	while (1) {
		printf("Commands : ");
		if (scanf("%128s", cmd) <= 0)
			return 0;
		token = inst_to_enum(cmd);
		printf("%d\n", (int)token);
	}
}