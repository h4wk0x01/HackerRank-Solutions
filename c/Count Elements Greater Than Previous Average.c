int countResponseTimeRegressions(int responseTimes_count, int* responseTimes) {
    int answer = 0;
    for (int i = 1; i < responseTimes_count; i++ ) {
        long long sum = 0;
        long long average = 0;
        int j = 0;
        for (j = 0; j < i; j++) {
            sum += responseTimes[j];
        }
        average = sum / (j);
        if(responseTimes[i] > average ){
            answer += 1;
        }
    }
    return answer;
}
