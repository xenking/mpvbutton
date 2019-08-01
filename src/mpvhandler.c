#include <stdio.h>
#include <string.h>
#include <windows.h>

char *str_replace(char *orig, char *rep, char *with) {
    char *result;
    char *ins;
    char *tmp;
    int len_rep;
    int len_with;
    int len_front;
    int count;

    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; 
    if (!with)
        with = "";
    len_with = strlen(with);

    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    ins = strstr(orig, rep);
    len_front = ins - orig;
    tmp = strncpy(tmp, orig, len_front) + len_front;
    tmp = strcpy(tmp, with) + len_with;
    orig += len_front + len_rep; 
    strcpy(tmp, orig);
    return result;
}

int WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	if (lpCmdLine == NULL)
		return -1;
	char *str = str_replace(lpCmdLine, "://", " ");
	if (str == NULL){
		return -1;
	}
	if(strstr(str,"--")){
		char *str1 = str_replace(str,"--", " --");
		if(str1 != NULL)
			str = str1;
	}
	
	printf("%s", str);
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};
	si.cb = sizeof(si);
	CreateProcessA(NULL, str, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	return 0;
}
