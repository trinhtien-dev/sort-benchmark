## I. Thông tin nhóm
* **Môn học:** Cấu trúc dữ liệu và Giải thuật
* **Thời gian học:** Thứ 6 (12h40 - 16h10)
* **Họ và tên, MSSV thành viên:**
 * Trịnh Văn Tiến - 25120447
 * Phạm Đức Toàn - 25120449
 * Mạc Chí Thiện – 25120440

---

## II. Các hàm phụ

### 1. Hàm writeRaw()
* Mục tiêu của hàm này là dùng hàm `fwrite()` của thư viện C chuẩn để ghi trực tiếp toàn bộ dữ liệu của một chuỗi string ra stdout.

### 2. Hàm base26(num, width)
* Mục tiêu của hàm là chuyển một số nguyên không dấu thành một chuỗi ký tự với độ dài cố định là width, biểu diễn dưới hệ cơ số 26.

---

## III. Phân tích test case

### A. Integer Sort

**1. Hàm genInt1()**
* **Ý tưởng:** Tạo mảng đan xen liên tục giữa các giá trị cực đại và cực tiểu của kiểu số nguyên để kiểm tra trực tiếp giới hạn của Quick Sort và Radix Sort.
* **Đối với Quick Sort:** Sự đan xen dữ liệu liên tục khiến CPU dự đoán sai điều kiện rẽ nhánh trong các vòng lặp phân hoạch, làm hệ thống xóa và nạp lại bộ đệm lệnh dẫn đến lỗi TLE.
* **Đối với Radix Sort:** Là test case đánh giá tính chính xác thao tác xử lý số âm bằng phép đảo bit dấu giúp kiểm tra thuật toán có phát sinh lỗi logic hoặc lỗi tràn số.

**2. Hàm genInt2()**
* **Ý tưởng:** Tạo mảng có cấu trúc tăng dần rồi giảm dần làm vô hiệu hóa Quick Sort cơ bản, đặc biệt là kỹ thuật chọn chốt median-of-3. Cấu trúc dữ liệu này "đánh lừa" thuật toán, khiến pivot rơi vào giá trị xấu nhất và quá trình phân hoạch bị mất cân bằng làm độ phức tạp thời gian suy biến lên O(n^2), lỗi Stack Overflow hoặc TLE.

**3. Hàm genInt3()**
* **Ý tưởng:** Tạo ra test case với dải giá trị giảm dần đi từ số dương sang số âm.
* **Đối với Insertion Sort:** Là trường hợp xấu của Insertion Sort (thường được gọi ra khi mảng con có kích thước <=15 trong các hàm Intro Sort). Thuật toán phải thực hiện số phép hoán vị tối đa, ép độ phức tạp lên O(n^2).
* **Đối với Radix Sort:** Mốc số 0 là hạn chế của thao tác bit. Nếu Radix Sort tách mảng ra xử lý số dương riêng, số âm riêng, thì vị trí của mốc số 0 rất dễ gán sai index mảng dẫn đến việc mất số 0 hoặc đảo lộn thứ tự khi ghép mảng lại.

**4. Hàm genInt4()**
* **Ý tưởng:** Tạo ra test case với các phần tử được sinh ngẫu nhiên nhưng nằm rải rác trên dải giá trị của số nguyên 32-bit có dấu, từ `INT_MIN` đến `INT_MAX`.
* **Đối với Counting Sort:** Khi cài đặt thuật toán, ta sẽ cấp phát một mảng phụ có số lượng phần tử là max – min. Nếu làm vậy, chương trình sẽ cố gắng cấp một mảng có kích thước hơn 4 tỷ phần tử làm tràn RAM và báo lỗi MLE hoặc RE.
* **Đối với Radix Sort:** Trong thao tác xử lý số âm, với test case như trên buộc code phải ép sang kiểu unsgined int và đảo bit dấu. Nếu code thiếu bước này hoặc xử lý sai thì số âm sẽ phân loại thành số dương cực lớn do tràn số gây ra lỗi WA hoặc RE.

**5. Hàm genInt5()**
* **Ý tưởng:** Tạo một mảng gần như sắp xếp tăng dần nhưng đặt phần tử lớn nhất ở đầu và nhỏ nhất ở cuối khai thác điểm yếu của Intro Sort vì khi Quick Sort phân hoạch mảng xuống kích thước đủ nhỏ và nhường quyền xử lý cho Insertion Sort, hai phần tử ngoại lai sẽ bị kẹt lại trong các mảng con làm Insertion Sort buộc phải dịch chuyển chúng xuyên suốt chiều dài mảng, sinh ra một lượng lớn các phép gán vô ích.

### B. Lexicographic Sort

**1. Hàm genStrlexi1()**
* **Ý tưởng:** Dữ liệu giảm dần hoàn toàn, chuỗi rất dài và giống nhau ở 96 ký tự đầu.
* **Với Quick Sort:** Trật tự giảm dần là một trong những trường hợp xấu nhất vì chọn pivot không tốt, mảng sẽ phân chia mất cân bằng, suy biến độ phức tạp thành O(n^2) gây TLE hoặc Stack Overflow.
* **Với Merge Sort/Quick Sort:** Vì các ký tự giống nhau ở đầu quá dài, mỗi phép so sánh chuỗi không còn là O(1) mà buộc CPU quét qua gần hết chiều dài chuỗi O(L). Điều này làm chi phí so sánh tăng, làm cài đặt thời gian không tối ưu.

**2. Hàm genStrlexi2()**
* **Ý tưởng:** Các chuỗi gần như giống nhau (chứa toàn ký tự 'm', kết thúc là 'z' hoặc 'x').
* **Với Quick Sort:** Nếu bộ phân hoạch không đẩy đều các phần tử bằng pivot về hai phía, mảng con sẽ lệch dẫn đến trường hợp xấu O(n^2) và TLE.
* **Với Radix/Counting Sort:** Kiểm tra khả năng phân phối vào các "bucket". Việc dữ liệu đổ dồn vào 1-2 bucket cố định sẽ kiểm tra cấu trúc lưu trữ có bị quá tải bộ nhớ hay xử lý chậm.

**3. Hàm genStrlexi3()**
* **Ý tưởng:** Tất cả các chuỗi giống nhau tuyệt đối.
* **Với Quick Sort:** Phép thử chí mạng cho các mã nguồn không xử lý phân hoạch 3 phần. CPU sẽ phân hoạch sai lầm, đẩy đệ quy lên tối đa gây Stack Overflow hoặc TLE.
* **Với Radix Sort:** Thuật toán MSD phải đệ quy sâu đến tận ký tự cuối mới nhận diện được 2 chuỗi bằng nhau. Nếu code thiếu điều kiện dừng sớm, chương trình sẽ lặp vô hạn hoặc đệ quy quá sâu gây sập.

**4. Hàm genStrlexi4()**
* **Ý tưởng:** Tạo ra dải dữ liệu tăng dần gần như hoàn hảo
* **Với Quick Sort:** Tương tự mảng giảm dần, đây là nhược điểm lớn nhất khiến thuật toán suy biến về O(n^2) nếu chọn phần tử đầu làm pivot.
* **Với Intro Sort:** Kiểm tra cơ chế tự động chuyển đổi và kiểm tra xem bộ chuyển đổi thuật toán trong Intro Sort có hoạt động đúng thời điểm hay không. Khi phát hiện Quick Sort suy biến, Intro Sort phải tự động chuyển sang Heap Sort để kéo độ phức tạp về O(nlogn), giúp chương trình thoát khỏi lỗi TLE.

**5. Hàm genStrlexi5()**
* **Ý tưởng:** Tiền tố giống nhau ('aaccccc...') nhưng hậu tố giảm dần ('zzzz' xuống 'zzzy').
* **Với Radix Sort:** Thuật toán kiểu LSD quét từ phải qua trái vì các phần tử bị đảo lộn ở phần đuôi do đang giảm dần và giống nhau ở phần đầu, thuật toán phải dựa hoàn toàn vào tính ổn định và cài đặt không chuẩn, kết quả cuối cùng sẽ sai.
* **Với tối ưu hóa bộ đệm:** Chuỗi dài kết hợp tiền tố giống nhau làm CPU nhảy bộ nhớ liên tục để xét ký tự cuối, tăng tỷ lệ Cache Miss và kéo dài thời gian chạy.

### C. Length-aware Lexicographic Sort

**1. Hàm genStrlenlexi1()**
* **Ý tưởng:** Test case có cấu trúc giảm dần, chuỗi có cùng độ dài, giống nhau ở ký tự đầu, chỉ khác nhau ở một vài ký tự cuối.
* **Đối với Quick Sort:** Là trường hợp xấu nhất vì nếu thuật toán chọn pivot là phần tử đầu hoặc cuối mảng thì mỗi lần partition sẽ tạo ra một mảng con có kích thước n - 1 và một mảng rỗng làm độ phức tạp thời gian suy biến thành O(n^2) gây lỗi TLE hoặc Stack Overflow.
* **Đối với Comparator của bài C:** Do phần lớn prefix giống nhau, CPU phải quét gần toàn bộ chiều dài chuỗi mới tìm được ký tự khác nhau ở cuối làm tăng chi phí compare từ gần O(1) lên O(L).

**2. Hàm genStrlenlexi2()**
* **Ý tưởng:** Tạo ra nhiều nhóm chuỗi có độ dài xen kẽ liên tục giữa ngắn và dài.
* **Đối với Comparator length-aware:** Phải kiểm tra độ dài chuỗi trước, sau đó mới compare lexicographic nếu hai chuỗi cùng độ dài. Input có độ dài thay đổi liên tục, CPU branch predictor rất khó dự đoán hướng thực thi tiếp theo của câu lệnh điều kiện.
* **Đối với CPU Branch Prediction:** `if(a.length() != b.length())` liên tục thay đổi giữa đúng và sai khiến CPU thường xuyên branch misprediction khi dự đoán sai, CPU phải flush pipeline và nạp lại instruction cache, làm runtime thực tế tăng.

**3. Hàm genStrlenlexi3()**
* **Ý tưởng:** Tạo test case mà tất cả các chuỗi đều giống nhau hoàn toàn.
* **Đối với Quick Sort:** Cực kỳ nguy hiểm đối với Quick Sort không cài đặt partition 3 chiều vì các phần tử đều bằng pivot nên partition bị mất cân bằng làm thuật toán suy biến về O(n^2) gây TLE hoặc Stack Overflow.
* **Đối với Comparator String:** Comparator phải quét toàn bộ chuỗi mới xác định được hai chuỗi bằng nhau khiến mỗi phép compare có chi phí O(L).
* **Đối với MSD Radix Sort:** Chuỗi giống nhau, toàn bộ phần tử sẽ liên tục rơi vào cùng một bucket ở mọi mức đệ quy và code không có điều kiện dừng tối ưu, thuật toán sẽ đệ quy sâu đến ký tự cuối gây RE hoặc TLE.

**4. Hàm genStrlenlexi4()**
* **Ý tưởng:** Tạo ra các chuỗi có prefix rất dài giống nhau nhưng suffix lại giảm dần theo thứ tự từ điển.
* **Đối với Comparator length-aware và Quick Sort:** Vì prefix của các chuỗi giống nhau gần như hoàn toàn nên comparator buộc phải quét rất sâu mới tìm được ký tự khác nhau ở cuối làm tăng chi phí compare.
* **Đối với Quick Sort:** Các block dữ liệu giảm dần sẽ phá heuristic chọn pivot kiểu median-of-three hoặc pivot sampling khi pivot chọn vào vị trí xấu khiến partition bị lệch và giảm hiệu năng.
* **Đối với Merge Sort:** Số lần compare lớn và mỗi compare đều cực kỳ đắt do phải scan gần hết chuỗi.

**5. Hàm genStrlenlexi5()**
* **Ý tưởng:** Tạo dữ liệu có prefix dài giống nhau nhưng suffix zig-zag liên tục.
* **Đối với Comparator String:** Phần đầu chuỗi giống nhau nên comparator phải quét gần hết chuỗi mới tới phần suffix khác nhau làm tăng thời gian compare.
* **Đối với Quick Sort:** Zig-zag pattern phá hỏng các heuristic chọn pivot như median-of-three hoặc adaptive pivot sampling. Pivot bị chọn vào vị trí xấu khiến partition mất cân bằng.
* **Đối với Adaptive Sort:** Thuật toán adaptive cố gắng nhận diện dữ liệu “gần sorted” để tối ưu nhưng zig-zag pattern khiến dữ liệu vừa không random vừa không gần sorted làm thuật toán mất khả năng tối ưu.
* **Đối với Cache Locality:** Comparator phải liên tục truy xuất các ký tự nằm sâu ở cuối và nhảy nhiều vùng nhớ khác nhau làm tăng Cache Miss và kéo dài thời gian.

---

## IV. Phân tích 2 lần chạy

### A. Integer Sort

* **Lần chạy 1:** Chọn Merge Sort vì độ phức tạp thời gian luôn định ở O(nlogn), tránh rủi ro suy biến O(n^2) của Quick Sort hay hiện tượng Cache Miss của Radix Sort. Chấp nhận đánh đổi O(n) bộ nhớ phụ để tối ưu tốc độ và sự ổn định.
* **Lần chạy 2:** Vượt qua giới hạn O(nlogn) bằng cách chuyển sang Radix/Counting Sort để đạt độ phức tạp O(n) cùng với các kỹ thuật:
* **Tối ưu I/O:** Khắc phục độ trễ của thư viện chuẩn bằng bộ đệm tĩnh 2MB kết hợp `fread()`/`fwrite()`. Tự cài đặt readInt/writeInt để dịch trực tiếp mã ASCII sang số nguyên.
* **Tối ưu trình biên dịch:** `#pragma GCC optimize("O3,unroll-loops")` dùng để tháo dỡ vòng lặp, giảm độ trễ rẽ nhánh CPU. Dùng `#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")` tận dụng tập lệnh x86 nâng cao (đặc biệt là BMI/BMI2) nhằm tăng tốc các thao tác bit.
* **Cải tiến Radix Sort:** Nâng hệ cơ số lên 2^11 (base 2048), giảm từ 4 vòng lặp xuống 3 (11-11-10 bit), tiết kiệm 25% chi phí ghi mảng. Xử lý mảng chứa số âm bằng cách lật bit dấu để đưa về dải số không dấu trước sắp xếp, sau đó lật lại để khôi phục.

### B. Lexicographic Sort

* **Lần chạy 1: Quick Sort ngẫu nhiên**
  * Lý do tốt nhất ở lần 1: Độ phức tạp trung bình O(nlogn). Kỹ thuật sử dụng tư chia để trị chọn pivot ngẫu nhiên triệt tiêu rủi ro rơi vào trường hợp xấu nhất tốt hơn so với Bubble Sort, Selection Sort hay Insertion Sort.
* **Lần chạy 2: Multikey Quick Sort**
  * **Tối ưu Thuật toán:** Dùng Multikey Quick Sort kết hợp với tối ưu nhập xuất, thay vì so sánh toàn bộ chuỗi nhiều lần, chỉ xét từng ký tự (vị trí d), chia dữ liệu thành 3 nhóm (<, =, > pivot). Thuật toán chỉ xét tiếp ký tự d+1 với nhóm bằng pivot, giúp loại bỏ việc so sánh lại các tiền tố trùng lặp.
  * **Tối ưu Nhập/Xuất:** Dùng `fread()` để đọc dữ liệu vào buffer lớn và `fwrite()` để ghi kết quả ra output, thay vì dùng cin/cout liên tục. Các hàm đọc số, đọc chuỗi, ghi số và ghi chuỗi được tự cài đặt để giảm overhead của thư viện chuẩn.
  * **Tối ưu Mã nguồn:** Kết hợp Insertion Sort cho các mảng con nhỏ làm giảm chi phí đệ quy. Khai báo `#pragma GCC optimize("O3,unroll-loops")` để ép trình biên dịch tối ưu hóa vòng lặp không xác định.

### C. Length-aware Lexicographic Sort

* **Lần chạy 1:** Chọn Quick Sort kết hợp Hoare Partition và Random Pivot.
  * Quick Sort có độ phức tạp trung bình O(nlogn), không cần cấp phát thêm bộ nhớ phụ. Khi sắp xếp chuỗi theo độ dài và thứ tự, nó cho tốc độ tốt vì số lượng phép swap và truy cập bộ nhớ thấp.
  * Hoare Partition có ít phép swap và giảm số lần ghi dữ liệu vào bộ nhớ. Random Pivot chọn ngẫu nhiên một phần tử làm pivot nhằm hạn chế trường hợp xấu nhất O(n^2) khi input gần như có thứ tự.
  * Hàm so sánh chuỗi được tối ưu vì ưu tiên so sánh độ dài chuỗi và tiến hành so sánh từng ký tự khi hai chuỗi có cùng độ dài làm giảm số phép so sánh ký tự.
* **Lần chạy 2:** Chọn Introsort (lai giữa Quick Sort, Heap Sort và Insertion Sort) kết hợp với nhiều kỹ thuật tối ưu:
  * Dùng `fread()` để đọc dữ liệu vào buffer lớn và `fwrite()` để ghi kết quả ra output, thay vì dùng cin/cout liên tục. Các hàm đọc số, đọc chuỗi, ghi số và ghi chuỗi được tự cài đặt để giảm overhead của thư viện chuẩn.
  * Lệnh `#pragma GCC optimize("O3,unroll-loops")` bật mức tối ưu hóa mạnh nhất của GCC với “O3” cho phép compiler tối ưu biểu thức và vòng lặp, còn “unroll-loops” giúp giảm chi phí rẽ nhánh trong pipeline của CPU.
  * Không swap trực tiếp chuỗi mà sắp xếp thông qua mảng chỉ số `idx[]` vì swap hai số nguyên sẽ nhanh hơn copy cả chuỗi làm giảm lượng truy cập bộ nhớ, tăng hiệu quả cache của CPU.
  * Hàm `cmp_less()` tối ưu bằng cách so sánh độ dài chuỗi trước rồi mới so sánh từ điển nếu cần thiết giúp giảm số lần duyệt ký tự.
  * Dùng bộ sinh số ngẫu nhiên Xorshift thay cho `rand()` vì tốc độ nhanh hơn và phù hợp cho việc chọn pivot ngẫu nhiên.
  * Việc áp dụng kỹ thuật 3-way partitioning để chia dữ liệu thành ba vùng giúp giảm số lần đệ quy không cần thiết khi có nhiều chuỗi trùng nhau.
