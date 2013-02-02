#define TIMER_START \
typedef std::chrono::system_clock clock; \
typedef std::chrono::nanoseconds nano;	 \
clock::time_point t0 = clock::now();

#define TIMER_END \
clock::time_point t1 = clock::now(); \
cout << "\ntime " \
<< std::chrono::duration_cast<nano>(t1 - t0).count() \
<< endl;
