#include<stdio.h>

// fnctions declaration
int getLRU(int time[], int n);
 
int main() {
    // variables declarations
    int counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;

    // setting the given values
    int frames_count=3;
    int pages_count=11;
    int frames[frames_count]; 
    
    printf("Given reference string: ");
    int pages[] = {3, 2, 1, 3, 4, 1, 6, 2, 4, 1, 6};
    for(i = 0; i < pages_count; ++i){   // setting all the nos
        printf("%d, ", pages[i]);
    }
    
    // setting all pages in each frames as -1
    for(i = 0; i < frames_count; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < pages_count; ++i){
            flag1 = flag2 = 0;
        
            for(j = 0; j < frames_count; ++j){
            if(frames[j] == pages[i]){
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;
            break;
        }
    }
    
     if(flag1 == 0){
        for(j = 0; j < frames_count; ++j){
                if(frames[j] == -1){
                counter++;
                faults++;
                frames[j] = pages[i];
                time[j] = counter;
                flag2 = 1;
                break;
            }
        }
    }
    
        if(flag2 == 0){
        pos = getLRU(time, frames_count);
        counter++;
        faults++;
        frames[pos] = pages[i];
        time[pos] = counter;
    }
    
}
printf("\nTotal Page Faults = %d \n\n", faults);
    
    return 0;
}

// func's defs
int getLRU(int time[], int n){
        int i, minimum = time[0], pos = 0;
    
        for(i = 1; i < n; ++i){
            if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}