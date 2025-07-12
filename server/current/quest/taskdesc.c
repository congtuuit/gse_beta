#include <ansi.h>
#include <task.h>
#include <music.h>

mapping mpTaskDesc = ([2:([
							 // Tân Thủ
							 TID_NEWBIE_01:
								 ([3:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm" HIR " Tìm Chủ Tiệm Giáp Trụ" BLK ".\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ Tiệm Vũ Khí kêu ta tới Tìm Chủ Tiệm Giáp Trụ bàn công việc, Đi thẳng theo con đường này hướng lên trên là có thể tìm được Tìm Chủ Tiệm Giáp Trụ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    60 điểm Kinh nghiệm \n" 
 BLK "    10 điểm Tiềm năng \n" 
 BLK "    800 lượng\n" 
 BLK "    Thảo Hài",
									   6:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Chủ Dịch Trạm.\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ Tiệm Y Dược thật đúng là một lương y, hắn nhờ ta tới Chủ Dịch Trạm hỏi thăm người bệnh, đi sớm về sớm.\n" BLK "Phần thưởng nhiệm vụ:80 điểm Kinh nghiệm ,Chính Khí Tán x10",
									   7:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem thư giao cho Chủ Tiệm Tạp Hoá.\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hôm nay có bồ câu đưa thư tới Chủ Dịch Trạm gửi cho Chủ Tiệm Tạp Hoá, nhưng hắn không thể đi xa, nên nhờ ta giao lá thư cho Chủ Tiệm Tạp Hoá.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 100 điểm, 200 lượng",
									   9:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem cái xẻng giao cho Ngưu Nhị.\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mấy ngày trước Ngưu Nhị đã cho Chủ Tiệm Sửa Sửa mượn cái Xẻng, hắn nhờ ta đem cái Xẻng giao cho Ngưu Nhị .\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 80 điểm,Tiềm năng 5 điểm",
									  10:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem tiền thưởng của Ngưu Nhị giao cho Vệ Đội Trưởng.\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ Đội Trưởng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngưu Nhị không may bị thổ phỉ cướp, Vệ Đội Trưởng nghe tin liền xông vào hang ổ bắt trọn đám thổ phí trả lại tiền cho Ngưu Nhị.\n" 
 BLK "    Ta phải đem tiền thưởng này đến " HIR "Vệ Đội Trưởng" BLK ".Hắn ở ngay tại" HIR " phía Nam của Thôn" BLK ", đứng gần Lão Thôn Trưởng.\n" BLK "Phần thưởng nhiệm vụ:160 điểm Kinh nghiệm \n" 
 BLK "          10 điểm Tiềm năng ",
									  11:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem sách dạy đánh cờ của Ngưu Nhị giao cho Sứ Giả Môn Phái.\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngưu Nhị săn thú, tập võ, hắn muốn tìm một Sư Phụ, nếu ta đem Sách dạy đánh cờ của Ngưu Nhị giao cho Sứ Giả Môn Phái có thể giúp hắn tìm được Sư Phụ?\n" BLK "Phần thưởng nhiệm vụ:100 điểm Kinh nghiệm ,50 điểm Tiềm năng ",
									  12:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Lão Thôn Trưởng.\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lão Thôn Trưởng gần đây dường như đang có chuyện không ổn, ta đi tìm hắn xem có thể giúp được gì không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    200 điểm Kinh nghiệm \n" 
 BLK "    10 điểm Tiềm năng ",
									  13:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm" HIR " Thần Tiên Gia Gia" BLK ".\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thần Tiên Gia Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ Đội Trưởng nói Thần Tiên Gia Gia muốn tìm hắn, bảo ta đi gặp Thần Tiên Gia Gia hỏi rõ tình hình.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :250\n" 
 BLK "    Tiềm năng :30\n" 
 BLK "    Ngân lượng :5000",
									  17:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Trí Tuệ Lão Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nếu ta có chuyện gì không ổn có thể đến gặp Trí Tuệ Lão Nhân hỏi vài chuyện.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 280 điểm,1500 lượng",
									  18:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi U Cốc tìm Thủ Trạc bị mất, giao cho Chủ Tửu Lâu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chiếc Thủ Trạc được mẫu thân tặng cho nay đã bị mất cho chiến loạn, ta phải đi U Cốc một chuyến tìm lại giúp hắn!\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 250 điểm,Tiềm năng 20 điểm,Bố Mão",
									  23:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 10" BLK " đi tìm Tiễn Lão Cửu ở Sở Quốc đem chiến thư giao cho hắn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tiễn Lão Cửu Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sứ Giả Môn Phái và Tiễn Lão Cửu của Sở Quốc đã nhiều năm ân ân oán oán, nay ta đem thư khiêu chiến này giao cho Tiễn Lão Cửu để kết thúc ân oán này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :300 điểm\n" 
 BLK "    Tiềm năng :35 điểm\n" 
 BLK "    Ngân lượng :1000",
									  24:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tìm Chủ Tửu Lâu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quản Khố bị chứng bệnh đau đầu rất khó chịu, nên hắn bảo ta đi tìm Chủ Tửu Lâu bàn về chuyện Cỏ Linh Chi giúp trị bệnh đau đầu, nếu có điều kiện gì cứ đáp ứng.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 150 Tiềm năng 20",
									  26:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Cỏ Linh Chi giao cho Quản Khố\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đem Cỏ Linh Chi giao cho Quản Khố để trị bệnh đau đầu, nếu Quản Khố hài lòng có thể tặng lại hậu lễ!\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 600 Tiềm năng 70 Ngân lượng 2000 Hành Quân Tán x5",
									  27:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp Lão Thôn Trưởng hỏi thăm Trí Tuệ Lão Nhân về chứng bệnh Nan Y\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây dân chúng bị mắc một loại bệnh Nan Y, Chủ Tiệm Y Dược cố gắng hết sức cũng không trị được bệnh này nên bào ta đi tìm Trí Tuệ Lão Nhân hỏi xem cách trị bệnh.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 150 Tiềm năng 20",
									  29:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Thuốc Giải giao cho Lão Thôn Trưởng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trí Tuệ Lão Nhân bảo ta đem thuốc giải giao cho Lão Thôn Trưởng, còn dặn dò trong 2 ngày dân chúng không được múc nước giếng để uống, ông ta nghi ngờ có người hạ độc vào nước giếng, phải cẩn thận đề phòng.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 600 Tiềm năng 70 Ngân lượng 2000 Hành Quân Tán x5",
									  33:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem vật phẩm giao cho Lưu Đại Thúc ở ngoài Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ Tiệm Tạp Hoá bảo ta đưa vật phẩm trong rương giao cho Lưu Đại Thúc.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 250 Ngân lượng 20",
									  34:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem thư giao cho" HIR " Khổng Lão Đầu ở Thanh Khê\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Khổng Lão Đầu ở Thanh Khê\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Cô độc, nhất định cô độc.\n" 
 BLK "    Chủ Tiệm Sửa Chửa nhiều năm không gặp người bạn cũ, nên nhờ ta đưa thư tới Khổng Lão Đầu ở Thanh Khê.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 200\n" 
 BLK "          Tiềm năng 30\n" 
 BLK "          Ngân lượng 1000",
									  35:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được Mạnh Đại Bá ở U Cốc, đem chuyện của Chủ Tửu Lâu nói cho hắn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mạnh Đại Bá ở U Cốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây khách của Chủ Tửu Lâu bỗng dưng nhiều hơn so với lúc thường, thực phẩm không đủ làm cho khách ăn, nên nhờ ta đến Mạnh Đại Bạ bắt cá ngon cho nàng.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm 350\n" 
 BLK "          Tiềm năng 20",
									 102:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Chủ Tiệm Giáp Trụ bàn việc làm ăn\n" BLK "Người hoàn thành nhiệm vụ:\n" 
 BLK "    Chủ Tiệm Giáp Trụ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Giúp Chủ Tiệm Vũ Khí bàn chuyện làm ăn với Chủ Tiệm Giáp Trụ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :120 điểm\n" 
 BLK "    Tiềm năng :20 điểm\n" 
 BLK "    Ngân lượng :500\n" 
 BLK "    Vật phẩm :新手 Y Phục\n",
									 105:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Chủ Dịch Trạm\n" BLK "Người hoàn thành nhiệm vụ:\n" 
 BLK "    Chủ Dịch Trạm\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ Tiệm Y Dược thật đúng là một lương y, hắn nhờ ta tới Chủ Dịch Trạm hỏi thăm người bệnh, đi sớm về sớm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :290 điểm\n" 
 BLK "    Tiềm năng :20 điểm\n" 
 BLK "    Ngân lượng :500\n",
									 106:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem thư giao cho Chủ Tiệm Tạp Hoá\n" BLK "Người hoàn thành nhiệm vụ:\n" 
 BLK "    Chủ Tiệm Tạp Hoá\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ Dịch Trạm nhận được 1 phong thư gửi cho Chủ Tiệm Tạp Hoá nên nhờ ta đem đến cho Chủ Tiệm Tạp Hoá.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :290 điểm\n" 
 BLK "    Tiềm năng :20 điểm\n" 
 BLK "    Ngân lượng :200\n" 
 BLK "    Vật phẩm :普通鉴定镜\n",
									 109:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp Vệ Đội Trưởng hỏi Công Đức Lão Nhân về chứng bệnh Nan Y\n" BLK "Người hoàn thành nhiệm vụ:\n" 
 BLK "    Công Đức Lão Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây dân chúng bị mắc một loại bệnh Nan Y, Vệ Đội Trưởng nhờ ta đến hỏi thăm Công Đức Lão Nhân để tìm ra thuốc giải bệnh này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :350 điểm\n" 
 BLK "    Tiềm năng :20 điểm\n" 
 BLK "    Ngân lượng :500\n",
									 111:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Thuốc Giải giao cho Vệ Đội Trưởng\n" BLK "Người hoàn thành nhiệm vụ:\n" 
 BLK "    Vệ Đội Trưởng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Công Đức Lão Nhân bảo ta đem thuốc giải này giao cho Vệ Đội Trưởng, còn dặn dò dân chúng trong 2 ngày không được uống nước giếng, hắn nghi có người bỏ độc vào nước giếng, phải đề phòng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :600 điểm\n" 
 BLK "    Tiềm năng :25 điểm\n" 
 BLK "    Ngân lượng :2000\n" 
 BLK "    Vật phẩm :新手 Hài\n",
									 113:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được Thôn Dân, thảo luận về Cỏ Linh Chi\n" BLK "Người hoàn thành nhiệm vụ:\n" 
 BLK "    Thôn Dân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quản Khố vì bị chứng bệnh đau đầu khó chịu nên nhờ ta đi tìm Thôn Dân mua Cỏ Linh Chi, nếu hắn có điều kiện gì cứ đáp ứng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :650 điểm\n" 
 BLK "    Tiềm năng :20 điểm\n" 
 BLK "    Ngân lượng :500\n",
									 114:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi" HIR " Ba Khâu bắt 1 con" BLK " Kiến Đen, báo cho Thôn Dân, thảo luận về Cỏ Linh Chi\n" BLK "Người hoàn thành nhiệm vụ:\n" 
 BLK "    Thôn Dân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thôn Dân sai ta đi bắt 1 con Kiến Đen, như thế hắn có thể cho ta Cỏ Linh Chi, trước khi đi bắt nhớ mua Dây Càn Khôn ở Chủ Tiệm Tạp Hoá.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :550 điểm\n" 
 BLK "    Tiềm năng :30 điểm\n" 
 BLK "    Vật phẩm :Cỏ linh chi草\n",
									 115:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Cỏ Linh Chi giao cho Quản Khố\n" BLK "Người hoàn thành nhiệm vụ:\n" 
 BLK "    Quản Khố\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta phải đem Cỏ Linh Chi giao cho Quản Khố để chửa bệnh đau đầu của ông ta!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :280 điểm\n" 
 BLK "    Tiềm năng :40 điểm\n" 
 BLK "    Ngân lượng :1000\n" 
 BLK "    Vật phẩm :新手帽子\n",
]),
							   TID_ZHOUGUO:
								   ([1:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Vương Bộ Đầu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vương Bộ Đầu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trước đó vài ngày bức tường ngục bị phá, một vài tên đã lợi dụng đào tẩu, ta phải đi tìm hắn xem có hỗ trợ được gì không!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    250 điểm Kinh nghiệm \n" 
 BLK "    30 điểm Tiềm năng ",
										2:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tìm Uất Trí Lão Tiêu Đầu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Uất Trí Lão Tiêu Đầu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta phải đi tìm Lão Uất Trí Lão Tiêu Đầu hỏi xem tình hình.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    250 điểm Kinh nghiệm \n" 
 BLK "    30 điểm Tiềm năng ",
										3:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tìm Sư Gia đối thoại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sư Gia Chu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi tìm Sư Gia nói chuyện hỏi rõ tình hình.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    1200 điểm Kinh nghiệm \n" 
 BLK "    60 điểm Tiềm năng ",
										9:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Tiểu Mộc Dũng giao cho Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đem Tiểu Mộc Dũng giao cho Triệu Quốc Bá Tánh Ngô Cơ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :200500 điểm\n" 
 BLK "    Tiềm năng :2255 điểm\n" 
 BLK "    Ngân lượng :200500",
									   10:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tìm Lý Ẩn Sĩ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Ẩn Sĩ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lý Ẩn Sĩ mai danh ẩn tích đã lâu, nay ta phải đi tìm ông ấy để chế tạo Tù Và, nghe Thần Tiên Gia Gia nói rằng Lý Ẩn Sĩ đang ở Hải Tân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :3000 điểm\n" 
 BLK "    Tiềm năng :100 điểm\n" 
 BLK "    Ngân lượng :2500",
									   13:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Đại Vương của nước mình gia nhập\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau khi tìm thấy Tù Và, Lý Ẩn Sĩ nói với ta phải nhờ Công Tượng của Triều Đình mới có thể chế tạo Tù Và Đế Vương, nên ta phải đi tìm Đại Vương nhờ sự giúp đỡ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :3000 điểm\n" 
 BLK "     Tiềm năng :100 điểm\n" 
 BLK "    Ngân lượng :2500",
									   14:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Đại Vương lấy Tù Và Đế Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Công Tượng nói chế tạo Tù Và Đế Vương tốn rất nhiều công sức, sau 24 giờ nữa ta có thể tới Đại Vương lấy Tù Và Đế Vương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :3000 điểm\n" 
 BLK "    Tiềm năng :100 điểm\n" 
 BLK "    Ngân lượng :2500",
									   16:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tìm Sư Gia đối thoại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sư Gia Từ Phúc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi tìm Sư Gia Từ Phúc đối thoại vài vấn đề, ta phải đi ngay thôy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm  300\n" 
 BLK "    Tiềm năng  35\n" 
 BLK "    Ngân lượng  500",
									   17:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tìm được Uất Trí Lão Tiêu Đầu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Uất Trí Lão Tiêu Đầu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta phải đi tìm Lão Uất Trí Lão Tiêu Đầu hỏi xem tình hình.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm  300\n" 
 BLK "    Tiềm năng  35\n" 
 BLK "    Ngân lượng  500",
									   18:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Tả Khâu Minh hỏi về Phong Yêu Kính\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tả Khâu Minh\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây rộ lên chuyện Phong Yêu Kính cất giữ nhiều bảo vật quý hiếm, nên ta phải tới gặp Tả Khâu Minh hỏi chuyện.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm  300\n" 
 BLK "    Tiềm năng  35\n" 
 BLK "    Ngân lượng  500",
									   19:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Chu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Vương Cơ Duyên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chu Vương hiện nay đang mở một hệ thống Bảo Hiếm, ta phải đi hỏi chút xem sao.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm  300\n" 
 BLK "    Tiềm năng  35\n" 
 BLK "    Ngân lượng  500",
									   22:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi lời nhắn đến Sở Quản Gia\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chu Vương vì nhớ tới người bạn cũ, nên sai ta đi hoi thăm sức khoẻ của Sở Quản Gia.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm  600\n" 
 BLK "    Tiềm năng  35\n" 
 BLK "    Ngân lượng  1000",
]),
								// Chu Quốc
								TID_CHUGUO:
									([9:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Ở Động Đinh Hồ tìm được" HIR " Trang Tân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trang Tân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tìm được Trang Tân nhờ hắn giúp đỡ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :500 điểm\n" 
 BLK "    Tiềm năng :10 điểm",
										11:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 3 cái Phiến Vũ Mao giao cho " HIR "Chủ Tửu Lâu Sở Quốc Vu Lăng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tửu Lâu Sở Quốc Vu Lăng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau khi mất trí nhớ hắn lại mất đi 3 Phiến Vũ Mao, hy vọng sau khi ta tìm lại được 3 Phiến Vũ Mao có thể giúp hắn hồi phục trí nhớ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1800 điểm\n" 
 BLK "    Tiềm năng :30 điểm\n" 
 BLK "    Ngân lượng :1500",
										12:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được Thôi Đại Quan, và giao cho hắn Phiến Vũ Mao \n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thôi Đại Quan Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nay ta đem 3 Phiến Vũ Mao này giao cho hắn, hy vọng hắn có thể hồi phục lại trí nhớ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :4000 điểm\n" 
 BLK "    Tiềm năng :50 điểm\n" 
 BLK "    Ngân lượng :2800",
										14:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đánh bại Vu Sơn Linh Tinh sau đó báo cho" HIR " Sở Quốc Bá Tánh Hàn Nhượng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quốc Bá Tánh Hàn Nhượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    " HIR "Vu Sơn Tinh Linh " BLK "đang tác oai tác quái, ta phải đi thu thập hắn để ổn định lòng dân, từ Bà Dương Hồ hay Đại Biệt Sơn đều có thể đi tới Vu Sơn.\n" BLK "Phần thưởng nhiệm vụ:\n" BLK "   Kinh nghiệm :2300 điểm\n" BLK "   Tiềm năng :80 điểm\n" BLK "   Ngân lượng :1600",
										15:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tìm Hổi Bảo Rương và giao cho" HIR " Sở Quốc Thủ Vệ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quốc Thủ Vệ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta phải đi tới Địa Giới Đầm Lầy lấy Hồi Bảo Rương rồi giao cho Sở Quốc Thủ Vệ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2200 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1700\n",
										16:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giết chết Vô Danh Dã Quỷ sau đó tới" HIR " Chủ Tiệm Giáp Trụ Sở Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Giáp Trụ Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta phải đi tiêu diệt yêu quái, cho dù không có thù lao ta vẫn sẽ cố gắng hết sức mà hoàn thành nhiệm vụ!\n" BLK "Phần thưởng nhiệm vụ:\n" BLK "Hiện tại phải tới" HIR " Ranh Giới Đầm Lầy" BLK " tiêu diệt Lệ Quỷ!\n" 
 BLK "    Kinh nghiệm :2400 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1800\n" 
 BLK "    Vật phẩm :30 cấp Nón",
										17:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Thuỷ Quái rồi báo cho" HIR " Lê Lão Hán\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lê Lão Hán ở Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tiêu diệt Thuỷ Quái ở Bà Dương Hồ, ta phải đi giúp dân trừ hại.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2500 điểm\n" 
 BLK "    Tiềm năng :90 điểm\n" 
 BLK "    Ngân lượng :1800",
										18:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Chiếu Thế Bảo Thạch giao cho " HIR "Quản Khố Sở Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản Khố Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta phải đi tới sườn núi Vu Sơn tìm về Chiếu Thế Bảo Thạch giao cho Quản Khố Sở Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2500 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1700",
										19:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Giấy Nợ giao cho " HIR "Dân Cờ Bạc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân Cờ Bạc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói Giấy Nợ ở tại Đại Biệt Sơn, ta phải giúp hắn tìm về!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2500 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1900\n",
										20:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giết Mê Hồn Tinh Linh sau đó báo cho " HIR "Sở Quốc Công Tượng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quốc Công Tượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Đại Biệt Sơn tiêu diệt Mê Hồn Tinh Linh để trừ hại cho dân chúng!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2600 điểm\n" 
 BLK "    Tiềm năng :90 điểm\n" 
 BLK "    Ngân lượng :2000\n",
										21:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Dạ Quỷ sau đó báo cho " HIR "Sở Quốc Thương Nhân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quốc Thương Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Đại Biệt Sơn tiêu diệt Dạ Quỷ, ta phải đi trừ hại cho dân chúng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2500 điểm\n" 
 BLK "    Tiềm năng :90 điểm\n" 
 BLK "    Ngân lượng :2000\n",
										22:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm về Hoa Mộc Thần Bút giao cho" HIR " Sở Quốc Bá Tánh Hàn Nhượng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quốc Bá Tánh Hàn Nhượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói Cửu Đại Cốc ở Đại Biệt Sơn có một cây thần bút có năng lực thần kỳ, ta phải đi tìm giúp hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2600 điểm\n" 
 BLK "    Tiềm năng :100 điểm\n" 
 BLK "    Ngân lượng :1900",
										23:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giáo huấn Ác Bá Trương Đại Thăng sau đó báo cho " HIR "Chủ Tửu Lâu Sở Quốc Vu Lăng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tửu Lâu Sở Quốc Vu Lăng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Bà Dương Hồ giáo huấn tên Ác Bá, ta phái đi trừ hại cho dân chúng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2700 điểm\n" 
 BLK "    Tiềm năng :100 điểm\n" 
 BLK "    Ngân lượng :2000\n" 
 BLK "    Vật phẩm :30 cấp Yêu Đới",
										24:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giết bọn buôn người" HIR " Triệu Tiểu Tam" BLK " sau đó báo cho " HIR "Sở Quốc Thủ Vệ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quốc Thủ Vệ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Bà Dương Hồ tiêu diệt bọn buôn người, ta phải đi trừ hại cho dân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2600\n" 
 BLK "    Tiềm năng :100\n" 
 BLK "    Ngân lượng :2000",
										25:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được" HIR " Long Ngọc Châu" BLK " giao cho " HIR "Nội Chính Quan Sở Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội Chính Quan Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Đại Biệt Sơn tìm lại Ngọc Long Châu bị mất, ta phải đi ngay!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2600 điểm\n" 
 BLK "    Tiềm năng :100 điểm\n" 
 BLK "    Ngân lượng :2100\n",
										26:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR " Chồn Tinh" BLK " rồi báo cho " HIR "Chủ Tiệm Giáp Trụ Sở Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Giáp Trụ Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Bà Dương Hồ tiêu diệt Chồn Tinh, ta phải đi ngay trừ hại cho dân dúng!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2600 điểm\n" 
 BLK "    Tiềm năng :90 điểm\n" 
 BLK "    Ngân lượng :2200 điểm\n" 
 BLK "    Vật phẩm :40 cấp Sắc Hài\n",
										27:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR " Cốt Ma Tinh " BLK " rồi báo cho " HIR "Quản Khố Sở Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản Khố Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Vu Sơn tiêu diệt Cốt Ma Tinh, ta phải đi ngay trừ hại cho dân chúng!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2700 điểm\n" 
 BLK "    Tiềm năng :110 điểm\n" 
 BLK "    Ngân lượng :2000\n",
										28:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR " Quỷ Tinh Quái" BLK " rồi báo cho " HIR "Chủ Tiệm Sửa Chửa Sở Quốc" BLK "汇报\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Sửa Chửa Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Vu Sơn tiêu diệt Quỷ Tinh Quái, ta phải đi ngay trừ hại cho dân chúng!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2800 điểm\n" 
 BLK "    Tiềm năng :110 điểm\n" 
 BLK "    Ngân lượng :2000\n" 
 BLK "    Vật phẩm :30 cấp Y Phục",
										31:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Trà Hoa Lài cùng Tuyết Thuỷ giao cho " HIR "Tề Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đem trà Hoa Lài cùng Tuyết Thuỷ giao cho Tề Vương, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :63000 điểm\n" 
 BLK "    Tiềm năng :860 điểm\n" 
 BLK "    Ngân lượng :63000\n" 
 BLK "    Vật phẩm :Tàng Bảo Đồ 1",
										32:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được Lưu Đầu ở Sở Quốc, bàn về chuyện di sản\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lưu Đầu ở Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nhìn ta có khả năng đi tới Tầng 3 của Khốn Ma Trận, ta phải đi gặp Lưu Đầu ở Sở Quốc bàn về chuyện di sản.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :31000 điểm\n" 
 BLK "    Tiềm năng :605 điểm\n" 
 BLK "    Ngân lượng :30000",
										38:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay Sở Quốc Thủ Vệ giáo huấn " HIR "Lương Thiểu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quốc Thủ Vệ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Đại Biệt Sơn giáo huấn Lương Thiểu thay cho Sở Quốc Thủ Vệ, ta phải đi ngay!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :71000 điểm\n" 
 BLK "    Tiềm năng :930 điểm\n" 
 BLK "    Ngân lượng :60000",
										42:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi cấp 10" BLK " tìm được Đại Vương Mãn ở ngoài thành\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Vương Mãn ở ngoài thành Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" BLK "   Đi tìm Đại Vương Mãn ở ngoài thành bàn bạc về chuyện mua lại châu bấu.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :300 điểm\n" 
 BLK "    Tiềm năng :30 điểm\n" 
 BLK "    Ngân lượng :1000",
										43:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi cấp 15" BLK " chuyển lời của Sở Quốc Thủ Vệ đến Hàn Tổng Quản\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" BLK "   Chuyển lời của Sở Quốc Thủ Vệ đến Hàn Tổng Quản, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :600 điểm\n" 
 BLK "    Tiềm năng :35 điểm\n" 
 BLK "    Ngân lượng :1200",
										44:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi cấp 35" BLK " chuyển lời của Sở Quốc Thủ Vệ đến Tề Quốc Sử Tiết Trâu Diễn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Quốc Sử Tiết Trâu Diễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chuyển lời của Sở Quốc Thủ Vệ đến Tề Quốc Sử Tiết Trâu Diễn, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2500 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :2000",
										45:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi cấp 95" BLK " tìm Thôi Đại Quan ở Nguỵ Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thôi Đại Quan Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi tìm Thôi Đại Quan ở Nguỵ Quốc giúp Sở Quốc Thủ Vệ, ta phải đi ngay!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :35000 điểm\n" 
 BLK "    Tiềm năng :600 điểm\n" 
 BLK "    Ngân lượng :30000",
										46:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi cấp 10" BLK " chuyển lời của Sở Vương đến Triệu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Triệu Quốc chuyển lời của Sở Vương tới Triệu Vương, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :50000 điểm\n" 
 BLK "    Tiềm năng :620 điểm\n" 
 BLK "    Ngân lượng :48000",
]),
								// Hàn Quốc
								TID_HANGUO:
									([1:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Phi Tặc Tằng Tử Dụng rồi báo cho " HIR "Hàn Quốc tài chính quan Hàn Phi\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc tài chính quan Hàn Phi\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phi Tặc Tằng Tử Dụng thừa cơ Hàn Quốc phòng ngự ko nghiêm, đánh cắp rương Hoàng Lượng. Theo tin tức, tên đạo tặc này từng trốn ở " HIR "Phía Đông Hàm Cốc Quan" BLK ", ngươi chạy ra" HIR "Phía đông Hào Hàm Cổ Đạo" BLK ". Ngươi hay mau đi tìm và tiêu diệt hắn lấy Rương Hoàng Lượng đem về giao cho " HIR "Hàn Phi" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1200 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1200",
										 2:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp " HIR "Hàn Quốc Nội Chính Quan Thân Bất Hại" BLK " giết phản đồ Ngô Tư\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    	Ngô Tư từng là quan chức triều đình, nhưng vì tư lợi hắn lấy đi vài món đồ, thừa dịp hắn trống tới Bờ Vô Định Hà gần Sườn Núi, Thân Bất Hại nhờ ngươi đi giết hắn dùm rồi báo về cho ổng 1 tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1100 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1300",
										 3:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Chứng Cứ Phạm Tội giao cho Hàn Quốc Ngự Sử\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Ngự Sử\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngự sử đang điều tra đại án và cần chứng cứ thất lạc tại " HIR "Vô Định Hà" BLK " chứng cứ này rất quan trọng, hãy tìm về giao cho " HIR "Hàn Quốc Ngự Sử" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1200 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1500",
										 4:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Ngọc Long Tình giao cho " HIR "Hàn Quốc Sử Tiết Niếp Chính\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Sử Tiết Niếp Chính\n" BLK "Miêu tả nhiệm vụ\n" 
 BLK "    Ngọc quý của Niếp Chính bị rớt ở " HIR "Dương Sơn Đạo Thủ Dương Sơn" BLK " vật phẩm tên là" HIR "Ngọc Long Tình" BLK " hãy tìm về giao cho " HIR "Hàn Quốc Sử Tiết Niếp Chính" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1400 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1200",
										 6:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp " HIR "Hàn Quốc Hộ Tịch Quan" BLK " tìm Phong Thư về\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Hộ Tịch Quan\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lúc đi du ngoan vô tình làm rơi Phong Thư ở " HIR "Thanh Long Đàn Vô Định Hà" BLK ". Đây là thư quan trọng mong ngươi có thể giúp ta tìm về.\n" BLK "Phần thưởng nhiệm vụ:\n" BLK "Kinh nghiệm :1100 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1200",
										 7:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Quần áo màu nhiệm, giao cho " HIR "Hàn Quốc Chủ Tiệm Giáp Phục Bản Trí Tẩu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Chủ Tiệm Giáp Phục Bản Trí Tẩu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói " HIR "Vô Định Hà hướng Tướng Quân Mộ" BLK " đã xuất hiện 1 món Quần áo màu nhiệm, ngươi hãy giúp chủ tiệm y phục tìm nó!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1500 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1300",
										 8:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm về Chuỗi Hạt Phỉ Thúy giao cho " HIR "Hàn Quốc Bá Tánh Tử Thẳng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Bá Tánh Tử Thẳng\n" BLK "Miêu tả nhiệm vụ:\n" BLK "  Nghe nói một bá tánh ở Hàn Quốc bị mất chuỗi ngọc đẹp ở " HIR "Vô Định Hà hướng Bạch Hổ Đàn" BLK " hãy mau đi tìm dùm họ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1600\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1200",
										 9:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10 Vò Rượu Đế giao cho " HIR "Hàn Quốc Công Tượng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Công Tượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Công tượng đang cần rượu để uống, nghe nói " HIR "Chủ Tiệm Rượu" BLK " có bán. Hãy mau giúp ổng đi mua.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1600 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1500",
										10:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay " HIR "Hàn Quốc Công Tượng" BLK " tìm Phật Long Châu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Công Tượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói Công Tượng bị mất Phật Long quý báu ở " HIR "Thúy Hoa Sơn hướng Hoa Sơn Đạo" BLK " hãy tìm về giao cho hắn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1800 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1500",
										11:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Mã Tặc Phùng Đại Long rồi báo cho " HIR "Hàn Quốc Bá Tánh Tử Thắng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Bá Tánh Tử Thắng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói tên cướp đang lộng hành ở " HIR "Hổ Lao Quan" BLK ", ngươi hãy mau đi tiêu diệt hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1800 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1600",
										12:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt phạm nhân Mã Tam Đao rồi báo cho " HIR "Hàn Quốc Quản Ngục Quan" BLK " biết\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Quản Ngục Quan\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hãy mau đi tiêu diệt phạm nhân, hắn đang ở " HIR "Thúy Hoa Sơn hướng Hoa Sơn Đạo" BLK " sau đó hãy báo cho Quản Ngục Quan biết.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1900 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1600\n" 
 BLK "    Vật phẩm :Yêu Đới Hoàng Kim cấp 20",
										13:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt ác quan Mã Tam rồi báo cho " HIR "Hàn Quốc Công Tượng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Công Tượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tên ác quan đang lộng hành tại " HIR "Vô Định Hà hướng Hồ Tâm Đảo" BLK " hãy mau tiêu diệt hắn để trừ hại cho dân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2000 điểm\n" 
 BLK "    Tiềm năng :90 điểm\n" 
 BLK "    Ngân lượng :1800",
										14:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giết trọng phạm Hứa Hoành Đao rồi báo cho " HIR "Hàn Quốc Quản Ngục Quan\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Quản Ngục Quan\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tội phạm sắp bị chém Hứa Hoành Đao đang ở " HIR "Hổ Lao Quan" BLK " trốn chạy. Hãy mau giết hắn để trừ họa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2100 điểm\n" 
 BLK "    Tiềm năng :90 điểm\n" 
 BLK "    Ngân lượng :1600",
										15:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Điều Binh Phù giao cho " HIR "Hàn Quốc Đại Tướng Quân Hàn Cử\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Đại Tướng Quân Hàn Cử\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "     Lần trước ở " HIR "Thủ Dương Sơn hướng Tụ hiền Pha" BLK " thao túng quân đội, không may làm rơi binh phù, hãy mau giúp tướng quân tìm lại.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2200 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1500",
										16:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hàn Quốc Tài Chính Quan Hàn Phi yêu cầu đi theo hướng Bản Đồ Kho Báu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Tài Chính Quan Hàn Phi\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Có tin đồn từ xưa chỗ Linh Cốc Động có Kho Báu, nhưng đến đó cần Bản Đồ Kho Báu từ tay Hàn Phi, hãy tới chỗ hắn và đi theo Bản Đồ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :31000 điểm\n" 
 BLK "    Tiềm năng :480 điểm\n" 
 BLK "    Ngân lượng :30000",
										17:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR " Kiếp Đạo Lý Tam" BLK " rồi báo cho Hàn Quốc Tài Chính Quan Hàn Phi biết\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Tài Chính Quan Hàn Phi\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hàn Quốc Tài Chính Quan Hàn Phi bị cướp và uy hiếp, nay nhờ ngươi đi Linh Cốc Động hướng Tây Bắc tiêu diệt tên trộm này giúp Hàn Phi.\n" BLK "Phần Thưởng:\n" 
 BLK "    Kinh nghiệm :30000 điểm\n" 
 BLK "    Tiềm năng :490 điểm\n" 
 BLK "    Ngân lượng :32000",
										18:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tới Hàn Tổng Quản hỏi rõ nội dung Bản Đồ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Theo tin tức Hàn Quốc Tài Chính Quan Hàn Phi cho biết thì mảnh bản đồ con lại đc Đại Vương đưa cho Hàn Tổng Quản rồi, hãy đi nói chuyện với Hàn Tổng Quản để hỏi tin tức.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :32000 điểm\n" 
 BLK "    Tiềm năng :500 điểm\n" 
 BLK "    Ngân lượng :31000\n",
										20:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Thúy Ngọc Chi Tình về giao cho Hàn Tổng Quản\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngày xưa Hàn Tổng Quản đi dò xét làm rơi Thúy Ngọc Chi Tình, ngươi hãy đi " HIR "Linh Cốc Động Tầng 2" BLK " đem bảo bối trở về. Dựa theo Tàng Bảo Đồ để tìm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :33000 điểm\n" 
 BLK "    Tiềm năng :500 điểm\n" 
 BLK "    Ngân lượng :33000\n",
										21:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Thỉnh Mệnh Hàm giao cho Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dạo gần đây âm khí nơi Linh Cốc Động tràn trề, hãy giao Mệnh Hàm cho Hàn Quốc Nội Chính Quan Thân Bất Hại để hắn đưa cho Đại Vương giải quyết vấn đề này ngay!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :35000 điểm\n" 
 BLK "    Tiềm năng :520 điểm\n" 
 BLK "    Ngân lượng :34000",
										23:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt gian tặc Vũ Chi Chân rồi báo cho " HIR "Hàn Quốc Ngự Sử Trịnh Quốc" BLK "汇报\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Ngự Sử Trịnh Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Yêu nghiệt ở " HIR "Linh Cốc Động tầng 2" BLK " nhiều vậy là do tên " HIR "Vũ Chi Chân" BLK " cầm đầu, hãy mau đi giết hắn để trừ hại cho dân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :35000 điểm\n" 
 BLK "    Tiềm năng :530 điểm\n" 
 BLK "    Ngân lượng :36000\n",
										24:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Tấu Sách giao cho Đại Vương Hàn An\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Vương Hàn An\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Theo Hàn Quốc Ngự Sử cho biết Hàn ko thể đơn độc chống lại quân Tần, thế nên phải đưa quốc sách lên Đại Vương phê chuẩn. Hãy mau đưa đến cho ngài ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :36000 điểm\n" 
 BLK "    Tiềm năng :520 điểm\n" 
 BLK "    Ngân lượng :35000\n",
										25:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Liên Minh Hàm giao cho Nội Chính Quan Sở Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội Chính Quan Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vì phòng vệ Tần Quốc, chúng ta cần phải liên minh với Sở, hãy mau mang Liên Minh Hàm giao cho Nội Chính Quan Sở Quốc bày tỏ thành ý.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :36000 điểm\n" 
 BLK "    Tiềm năng :540 điểm\n" 
 BLK "    Ngân lượng :37000\n",
										26:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tham kiến Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây ở Tương Lăng thợ săn thấy điểm gì đó bất thường ở các con tiểu quái vật, hẳn là nước sông nơi đây ô nhiễm, hãy báo chuyện này với Nội Chính Quan.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :35000 điểm\n" 
 BLK "    Tiềm năng :530 điểm\n" 
 BLK "    Ngân lượng :36000",
										27:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Mật Kiện giao cho Hàn Quốc Ngự Sử Trịnh Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Ngự Sử Trịnh Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Căn cứ tình hình hiện tại, Tương Lăng có con song6bi5 nguồn rủa bởi ma thuật, Nội Chính Quan có món đồ cần đưa cho Ngự Sử, hãy giúp hắn một tay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :36000 điểm\n" 
 BLK "    Tiềm năng :550 điểm\n" 
 BLK "    Ngân lượng :38000",
										28:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dò hỏi Hàn Quốc Bá Tánh Tử Thắng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Bá Tánh Tử Thắng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Căn cứ vào tình huống bây giờ mà nói, con sông kia đã bị nguyền rủa. Ở Hàn Quốc có Đại Vương Chân Nhân có thể giải trừ nhưng chỉ Hàn Quốc Bá Tánh Tử Thắng biết, hãy mau đi hỏi hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :37000 điểm\n" 
 BLK "    Tiềm năng :540 điểm\n" 
 BLK "    Ngân lượng :37000\n",
										29:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm Lý Phương Sĩ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Phương Sĩ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Con sông bị nguyền rủa kia cần có người giải trừ là Đại Vương Chân Nhân, nhưng nay người quy tiên có thu nhận đồ đệ là Lý Phương Sĩ, hãy tìm và xin hắn giải trừ lời nguyền của con sông kia!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :37000 điểm\n" 
 BLK "    Tiềm năng :550 điểm\n" 
 BLK "    Ngân lượng :38000\n",
										31:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Trạng Chỉ giao cho Hàn Quốc Ngự Sử Trịnh Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Ngự Sử Trịnh Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mấy tháng trước Ngự Sử đi du ngoạn với thê tử, không may bị hổ vồ giết chết thê tử của hắn, Quốc Vương biết chuyện nên muốn giao quà an ủi tới cho hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :38000 điểm\n" 
 BLK "    Tiềm năng :570 điểm\n" 
 BLK "    Ngân lượng :38000",
										32:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi han Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thê tử của Ngự Sử vừa bị chết, ta vừa đem giao quà của Quốc Vương cho hắn, nhưng nay Tần Quốc có âm mưu xâm lược, không ai giải quyết, ta phải đến báo cho Nội Chính Quan dễ bề xử lí.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :40000 điểm\n" 
 BLK "    Tiềm năng :560 điểm\n" 
 BLK "    Ngân lượng :38000",
										34:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt thổ phỉ Mã Đại rồi báo cho Hàn Quốc Ngự Sử Trịnh Quốc biết\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Ngự Sử Trịnh Quốc" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bây giờ đích thân đến " HIR "Linh Cốc Động tầng 3 góc phía Nam" BLK " giết " HIR "thổ phỉ Mã Đại" BLK " trả thù cho thê tử của Hàn Quốc Nội Chính Quan Thân Bất Hại sau đó báo cho Hàn Quốc Ngự Sử Trịnh Quốc biết.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :40000 điểm\n" 
 BLK "    Tiềm năng :590 điểm\n" 
 BLK "    Ngân lượng :40000\n",
										35:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Hàn Quốc Lâm Vi\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Lâm Vi\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hãy đi báo cho Lâm vi biết tên Mã Đại đã bị diệt trừ, để người dân được yên tâm lập nghiệp.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :41000 điểm\n" 
 BLK "    Tiềm năng :600 điểm\n" 
 BLK "    Ngân lượng :40000\n",
										36:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dò hỏi Hàn Quốc Nhạc Sư\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói tại " HIR "Trịnh Thành Bắc Giao Nhạc Sư" BLK " phụ thân của Hàn Quốc Bá Tánh Tử Thắng bị giam, nay cần nhạc sư đến giải bề! Hãy mau tìm ra Nhạc Sư\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :41000 điểm\n" 
 BLK "    Tiềm năng :600 điểm\n" 
 BLK "    Ngân lượng :41000",
										37:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hàn Quốc Ngự Sử Trịnh Quốc cầu xin biện pháp\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Ngự Sử Trịnh Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Do bị oan ức nên Nhạc Sĩ bị giam cầm, hãy tới cầu xin Ngự Sử giải oan này cho y đi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :42000 điểm\n" 
 BLK "    Tiềm năng :610 điểm\n" 
 BLK "    Ngân lượng :42000",
										38:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm bảo vật Hầm Lân Châu giao cho Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nếu có thể đem châu trở về ta có thể giải quyết được vụ án oan cho Nhạc Sĩ, hãy tới " HIR "Linh Cốc Động tầng 3" BLK " tìm châu về giao cho Hàn Quốc Nội Chính Quan Thân Bất Hại.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :43000 điểm\n" 
 BLK "    Tiềm năng :620 điểm\n" 
 BLK "    Ngân lượng :42000\n",
										39:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt tên vô lại Mã Tiểu Tam rồi báo cho Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Quốc Nội Chính Quan Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tên vô lại này đã trộm Châu quý báu của ta đem giấu vào " HIR "Linh Cốc Động tầng 3" BLK " hãy đi giết tên " HIR "Mã Tiểu Tam" BLK " dùm ta, thay trời hành đạo.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :44000 điểm\n" 
 BLK "    Tiềm năng :630 điểm\n" 
 BLK "    Ngân lượng :43000\n",
										40:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đem Trục Tấu Thư giao cho Đại Vương Hàn An\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Vương Hàn An\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vụ án oan của Nhạc Sĩ đã được giải.Hàn Quốc Nội Chính Quan Thân Bất Hại đã có tấu thư dâng lên Đại Vương, hãy mang đem tấu thư đưa Đại Vương dùm hắn để giải oan ức nào.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :43000 điểm\n" 
 BLK "    Tiềm năng :630 điểm\n" 
 BLK "    Ngân lượng :43000\n" 
 BLK "    Vật phẩm :Vũ khí cấp 80",
										45:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Mao Chân Nhân tìm phương pháp hóa giải\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mao Chân Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dạo này Đại vương nằm mơ thấy mình ở nơi u tối, không biết có mệnh hệ gì không, hãy tìm Mao Chân Nhân để giúp đỡ Đại Vương.\n" 
 BLK "    Đường xá nguy hiểm, hãy tổ đội mà đi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :12000 điểm\n" 
 BLK "    Tiềm năng :215 điểm\n" 
 BLK "    Ngân lượng :11000",
										47:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Triệu Quốc Bạch Dịch\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bạch Dịch\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nhập ngũ 10 năm, không có tin tức gì về phu quân, nữ nhân của Bạch Dịch nhờ ta tới tìm Bạch Dịch và kêu Bạch Dịch gửi thư về cho phu nhân hắn đỡ lo lắng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :17000 điểm\n" 
 BLK "    Tiềm năng :260 điểm\n" 
 BLK "    Ngân lượng :17000",
										48:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau 20 cấp" BLK " Đem Thiệp Mời đưa cho Thôi Đại Quan Ngụy Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thôi Đại Quan Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói Thôi Đại Quan là một vị tướng quân mưu lược, ta cần phải đích thân đưa thư mời hắn đến dự tiệc để sau này hắn còn giúp đỡ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1200 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1200",
										49:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau 70 cấp" BLK " đem tâm ý của Hàn Quốc Thủ Vệ nói cho Tề Quốc Công Tượng biết\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Quốc Công Tượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ở chốn cung điện cô đơn và đầy nguy hiểm, Thủ vệ chỉ có mỗi 1 người bạn là CÔng Tượng nhưng lâu rồi vẫn chưa gặp mặt, nay ta muốn nhờ ngươi giúp ta chuyển lời thương nhớ của ta đến vị bằng hữu này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :20000 điểm\n" 
 BLK "    Tiềm năng :220 điểm\n" 
 BLK "    Ngân lượng :25000",
										50:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau 80 cấp" BLK "Tìm Triệu Tổng Quản điều tra thân phận thật sự\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hàn Quốc Thủ Vệ nói hắn là một cô nhi, chỉ có Tổng Quản ở Triệu mới có thể biết thân phận thật của hắn, hãy giúp hắn tìm hiểu thân phận thật của mình.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :30000 điểm\n" 
 BLK "    Tiềm năng :400 điểm\n" 
 BLK "    Ngân lượng :22000",
]),
								TID_WEIGUO:
									([	10:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được người đất sét thần bí ở " HIR "làng Đường Lý Thái Hồ" BLK " giao cho Ngụy Quản Gia\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Có một thầy bói đã bói cho Ngụy Quản Gia, dự đoán tháng này ông ta sẽ có ba kiếp nạn, và đã cho ông ta ba túi gấm, để hóa giải ba kiếp nạn.\n" 
 BLK "    Cách hóa giải kiếp nạn thứ nhất là thu thập 20 quả bí ngô, tôi đã làm xong cho ông ta rồi, còn hóa giải kiếp nạn thứ hai cần giết 20 con yêu lợn và 10 con chó sói gần Vũ Sơn, Bà Dương Hồ, còn kiếp nạn thứ ba này, thì cần đến làng Đường Lý Thái Hồ tìm người đất sét thần bí giao cho Ngụy Quản Gia.\n" 
																	  
 BLK "    Thời gian không còn nhiều, tôi phải hành động nhanh!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :5800 điểm\n" 
 BLK "    Tiềm năng :200 điểm\n" 
 BLK "    Ngân lượng :5000",
										11:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm sắt tinh luyện trăm lần giao cho " HIR "chủ tiệm vũ khí Ngụy Quốc Trương Nghi\n" BLK "Người hoàn thành nhiệm vụ:" HIR "chủ tiệm vũ khí Ngụy Quốc Trương Nghi\n" BLK "Miêu tả nhiệm vụ:\n" BLK "  Chủ tiệm vũ khí Ngụy Quốc Trương Nghi phát hiện người võ lâm đối với vũ khí yêu cầu rất cao, cảm thấy đây là một con đường kiếm tiền, nên quyết định rèn một lô vũ khí tốt để đáp ứng nhu cầu, vũ khí tốt cần nguyên liệu tốt, mà ông ta thiếu chính là sắt tinh luyện trăm lần, ông ta nói có người ở " HIR "Bách Trượng Nguyên Cự Lộc" BLK " thấy một khối sắt tinh luyện trăm lần tốt, nếu tôi có thể tìm về cho ông ta, chắc chắn sẽ không phụ tôi.\n" BLK "  Ra khỏi Ngụy Quốc đi thẳng về phía bắc, xuyên qua Quế Lăng, Mục Dã, Thái Hành Sơn là đến Cự Lộc, hoặc cũng có thể từ Triệu Quốc trực tiếp đến Cự Lộc. Đến Bách Trượng Nguyên Cự Lộc thấy một khối quặng sắt tinh, có thể thu thập về giao cho ông ta nhận thưởng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1000 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1200",
										12:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm đào linh giao cho " HIR "chủ tiệm sửa chữa Ngụy Quốc Thạch Thân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "chủ tiệm sửa chữa Ngụy Quốc Thạch Thân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thiên hạ rơi xuống một quả đào linh? Thật là kỳ lạ, tôi thực sự chưa từng nghe nói. Nghe nói quả đào linh đó còn có công hiệu chữa trăm bệnh, phu nhân của chủ tiệm sửa chữa Ngụy Quốc Thạch Thân sức khỏe không tốt, ông ta muốn tìm quả đào linh đó, nhưng quả đào linh đó không phải ai cũng có thể tìm được.\n" BLK "  Một nhà sư du hành lại nói tôi mới là người có duyên với quả đào linh đó, bản thân tôi sao lại không biết.\n" BLK "  Đã vậy thì tôi tạm thử xem sao, nghe chủ tiệm sửa chữa nói quả đào linh đó có vẻ rơi ở " HIR "Phi Hổ Trại Cự Lộc" BLK ", vào Phi Hổ Trại đi thẳng về phía trước, quả đào linh đó ở dưới cái vại nước lớn kia.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1300 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1000\n" 
 BLK "    Vật phẩm :20 cấp Hài",
										13:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Mã Đại Long rồi về " HIR "thợ thủ công Ngụy Quốc" BLK " báo cáo\n" BLK "Người hoàn thành nhiệm vụ:" HIR "thợ thủ công Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đừng nhìn thợ thủ công Ngụy Quốc có vẻ ngoài không đẹp, nhưng vì tay nghề tốt, vẫn có rất nhiều người mời ông ta làm việc, tay nghề của ông ta còn bị Mã Đại Long để ý, ba lần năm lần mạo danh ông ta lừa người lừa tiền không nói, sau này còn phát triển đến mức không làm điều ác nào, không chỉ ảnh hưởng đến danh tiếng và công việc của thợ thủ công Ngụy Quốc, còn hại mẹ già của thợ thủ công Ngụy Quốc vì thế mà chết oan, nên thợ thủ công Ngụy Quốc mời tôi đi trừ kẻ vô lại Mã Đại Long này.\n" 
																	  BLK "		 Bây giờ Mã Đại Long đang trốn ở " HIR "Bình Khâu Cự Lộc" BLK ", tôi có thể từ Triệu Quốc đi, đến Cự Lộc rẽ phải là tìm được, cũng có thể từ hướng Thái Hành Sơn đi, qua cầu đi thẳng về phía trước là gặp được hắn.\n" BLK "Tôi tin lần này thưởng chắc không ít, hehe.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1000 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1200",
										14:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đánh bại ma cốt rồi báo cho " HIR "chủ tiệm tạp hóa Ngụy Quốc Hồ Trương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "chủ tiệm tạp hóa Ngụy Quốc Hồ Trương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ tiệm tạp hóa Ngụy Quốc Hồ Trương lại nghi ngờ khả năng của tôi, ý nghĩ muốn trở thành anh hùng của tôi là bất kỳ ai bất kỳ việc gì cũng không thể ngăn cản, tôi nhất định phải chứng minh khả năng của mình cho toàn thiên hạ, đã vậy đánh bại con ma cốt ở " HIR "vườn anh đào Mã Lăng Đạo" BLK " có thể chứng minh khả năng của tôi, vậy thì tôi nhất định phải đánh bại nó!\n" BLK "		 Chủ tiệm tạp hóa Ngụy Quốc Hồ Trương nói đi về hướng chính bắc thành Đại Lương, đến Mã Lăng Đạo là thấy con ma cốt đó.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1000 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1200",
										15:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được tơ tằm nghìn năm giao cho " HIR "chủ tiệm phòng thủ Ngụy Quốc Du Bá Nha\n" BLK "Người hoàn thành nhiệm vụ:" HIR "chủ tiệm phòng thủ Ngụy Quốc Du Bá Nha\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôi đã nghe nói về tơ tằm nghìn năm này, nhưng tôi thực sự không nghĩ nó lại có tác dụng lớn như vậy, nghe chủ tiệm phòng thủ Ngụy Quốc Du Bá Nha nói vậy, bản thân tôi cũng muốn làm một cái, nhưng quân tử không cướp của người ta, đã vậy đóa hoa tơ đó là chủ tiệm phòng thủ Ngụy Quốc Du Bá Nha phát hiện, vậy tôi vẫn tìm về cho ông ta trước, còn cái của mình, sau này có cơ hội nói tiếp.\n" BLK "		 Nghe ông ta nói trong " HIR "rừng U Cốc Mã Lăng Đạo" BLK " có một loại hoa tơ, những con tằm nghìn năm đó thích loại hoa này, tơ nhả ra cũng quấn quanh chúng, tuy cơ hội không lớn, nhưng cũng phải thử, những hoa tơ đó màu trắng, tôi nhớ rồi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1100 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1500",
										16:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt " HIR "pháp sư Triệu Thuật Sĩ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng Quản Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Người ở giang hồ, thân không do mình, ngay cả quỷ hồn cũng không ngoại lệ.\n" BLK "Tổng Quản Ngụy Quốc nói đêm qua kiếm hồn báo mộng nói với ông ta, vốn dĩ kiếm hồn khi còn sống là một người lương thiện, sau khi chết vốn chưa từng làm bất kỳ việc gì tổn hại trời đất, nhưng gần đây cảm nhận được một lực lượng tà ác khống chế tư tưởng của hắn, khiến hắn thần trí không rõ, thường xuyên không tự kiểm soát mà làm một số việc tổn hại người, hắn cảm thấy rất ân hận, nên cầu xin sự giúp đỡ của Tổng Quản Ngụy Quốc.\n" 
 BLK "    Tổng Quản Ngụy Quốc điều tra phát hiện, là một tên pháp sư tên Triệu Thuật Sĩ đang làm phép thao túng hắn, nên mời tôi đi tiêu diệt Triệu Thuật Sĩ, hắn bây giờ ở " HIR "rừng cổ mộc Mã Lăng Đạo" BLK ", ước tính hắn lại sắp bắt đầu thi triển phép thuật, tôi phải nhanh chóng hành động!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1200 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1000",
										17:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt cướp " HIR "Lý Đại Sơn" BLK " rồi báo cho " HIR "thương nhân Ngụy Quốc Khổng Thị\n" BLK "Người hoàn thành nhiệm vụ:" HIR "thương nhân Ngụy Quốc Khổng Thị\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tên cướp Lý Đại Sơn này tôi đã nghe nói, sớm muốn trừ hắn rồi. Chỉ là không nghĩ thương nhân Ngụy Quốc Khổng Thị còn lập thề muốn trừ hắn. Tiếc là ông ta chỉ là một người buôn bán, tay không có sức bắt gà, cũng chỉ có thể cầu xin tôi giúp ông ta thực hiện lời thề này.\n" BLK "		 Những năm qua, tên cướp đó không chỉ cướp đi quá nhiều tài vật, còn hại chết rất nhiều dân nghèo, bây giờ hắn đang ở gần " HIR "Bạch Mã Hồ Bạch Mã Trang" BLK " vui chơi, từ Mã Đạp Hồ và Mã Lăng Đạo đều có thể đến Bạch Mã Trang. Tôi nhanh chóng đi trừ hắn thôi.\n" 
																	  BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1300 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1200 lượng\n" 
 BLK "    Vật phẩm :20 cấp vũ khí",
										18:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm bản đồ bảo vật vân xanh giao cho " HIR "Ngụy Quốc Chu Cuồng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Quốc Chu Cuồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôi nghĩ, thế giới này thực sự tồn tại kho báu, nên tôi nhất định phải tìm được bản đồ bảo vật vân xanh mà Chu Cuồng nói để chứng minh sự tồn tại của kho báu, chỉ là không biết địa điểm mà Chu Cuồng cung cấp có chính xác hay không.\n" BLK "		 Hắn nói bản đồ bảo vật đó từng xuất hiện ở " HIR "Tử Trúc Tiểu Cư Bạch Mã Trang" BLK ", ở nơi không xa bên cầu, có lẽ ở dưới một tảng " HIR "đá cổ" BLK " nào đó, từ Mã Lăng Đạo và Mã Đạp Hồ đều có thể đến Bạch Mã Cư.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1300 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1200",
										19:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt kẻ ác " HIR "Tiền Tam Sẹo" BLK " sau đó, báo cho Lý Tam Thẩm Ngụy Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Tam Thẩm Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lý Tam Thẩm nói oan hồn đó khi còn sống là một cô gái nhà bình thường, không biết sao bị kẻ ác Tiền Tam Sẹo nhìn trúng, cứ muốn cô ta làm thiếp, kẻ ác Tiền Tam Sẹo không làm điều ác nào, là địa đầu xà địa phương, cô ta đương nhiên không chịu, nhưng kẻ ác Tiền Tam Sẹo bức chết cha mẹ cô ta, muốn cô ta phải chịu, cô ta chết không chịu, liền treo cổ tự vẫn, thật là một cô gái trinh tiết liệt nữ!\n" 
 BLK "    Kẻ ác Tiền Tam Sẹo quá đáng ghét, lại làm ra việc thú vật không bằng như vậy, tôi nhất định phải thay cô ta báo thù! Tiền Tam Sẹo đang hoạt động ở khu vực " HIR "Thanh Khâu Trạch Kỳ Quan" BLK ", có thể từ Chu Quốc trực tiếp đến Kỳ Quan.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1400 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1200",
										20:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt bọn cướp " HIR "Hu Xiaosa" BLK " rồi báo cho " HIR "chủ tiệm rượu Ngụy Quốc Mang Từ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "chủ tiệm rượu Ngụy Quốc Mang Từ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ tiệm rượu Ngụy Quốc Mang Từ này thật đủ vất vả, mở một tiệm rượu nhỏ, cả nhà đều dựa vào ông ta nuôi gia đình, nhưng Hu Xiaosa còn bắt nạt người ta hiền lành, quy định chủ tiệm rượu Ngụy Quốc Mang Từ phải mỗi tháng nộp cho hắn 30 lượng bạc phí bảo vệ, không thì đập nát tiệm của ông ta, chủ tiệm rượu Ngụy Quốc Mang Từ tự nhận không dám đụng hắn, nhưng thương tiếc tiệm rượu nhỏ đó một tháng còn không kiếm được 30 lượng bạc, ông ta không biết làm sao, chỉ có thể mời tôi giúp đi dạy dỗ Hu Xiaosa đó, ông ta nói Hu Xiaosa đang ở làng Ngư Long Mã Đạp Hồ, xuyên qua Mã Lăng Đạo, Bạch Mã Trang là đến.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1600 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1500",
										21:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại giáp anh hùng giao cho " HIR "thủ vệ Ngụy Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "thủ vệ Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thủ vệ Ngụy Quốc đã thấy tướng quân phi ngựa trên sa trường anh dũng, từ nhỏ đã mơ ước khoác giáp anh hùng phi ngựa trên sa trường! Nhưng giấc mơ anh hùng này không dễ thực hiện, hắn nói hắn đang chuẩn bị đầy đủ. Làm một võ sĩ phi ngựa trên sa trường giết địch, thể chất khỏe mạnh là quan trọng nhất, nhưng, bây giờ hắn nóng lòng muốn có được một bộ giáp anh hùng, hắn nói có được giáp anh hùng là bằng với viên mãn một nửa giấc mơ của hắn, nên khẩn cầu tôi thay hắn tìm về.\n" BLK "		 Nghe hắn nói có người ở " HIR "Tam Hiền Đình Mã Đạp Hồ" BLK " thấy giáp anh hùng, từ Ngụy Quốc xuất phát, xuyên qua Mã Lăng Đạo và Bạch Mã Trang là đến Mã Đạp Hồ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1500 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1200",
										22:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đánh bại đao khách Hồ Tử Sơn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "thủ vệ Ngụy Quốc\n" 
										BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đao khách Hồ Tử Sơn, người ta gọi là đao khách thiên hạ đệ nhất, thanh đao đó được hắn sử dụng xuất thần nhập hóa, kinh thiên động địa khóc quỷ thần.\n" BLK "		 Thủ vệ Ngụy Quốc từng thử thách hắn, nhưng đều thất bại, hắn nói hắn có thể cảm nhận được, mỗi lần quyết đấu với Hồ Tử Sơn, hắn đều có được sự nâng cao rất lớn, nhưng dù vậy, khoảng cách giữa hắn và Hồ Tử Sơn ngày càng lớn, đánh bại đao khách đệ nhất Hồ Tử Sơn nổi danh lập vạn là giấc mơ của hắn, nhưng qua mấy lần thử thách này, khiến hắn cảm thấy giấc mơ này ngày càng xa vời, tôi nghĩ tôi có thể thử thử thách Hồ Tử Sơn, dù không thành công, tôi cũng có thể thấy kiếm pháp của hắn rốt cuộc lợi hại đến mức nào.\n" 
										
 BLK "    Thủ vệ Ngụy Quốc nói với tôi, Hồ Tử Sơn mỗi ngày đều ở khu vực Linh Cốc Nhai Mã Đạp Hồ luyện đao.\n" 
										BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1600 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1400",
										23:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại sừng ngọc, giao cho chủ tiệm rượu Ngụy Quốc Mang Từ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "chủ tiệm rượu Ngụy Quốc Mang Từ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dùng sừng nấu rượu thì bình thường thôi, nhưng dùng sừng ngọc nấu rượu, tôi nghĩ khắp thiên hạ, không có mấy người nếm qua.\n" 
 BLK "    Hươu ngọc, như tên gọi, là một loại hươu có lông như ngọc đẹp trong suốt, hiếm có trên đời, mà sừng của nó càng quý giá, dùng sừng ngọc nấu ra rượu có thể kéo dài tuổi thọ, không ít người muốn có được nó, chủ tiệm rượu Ngụy Quốc Mang Từ nói, theo tin tức ông ta nghe được, loại sừng này chưa có ai tìm được, bình thường trong tiệm rượu đông người, ông ta nghe nói gần Cự Lộc có một cành sừng lớn, hỏi tôi có hứng thú đi tìm không, vì hươu ngọc quá quý giá, mà người biết không nhiều, nên nếu tôi muốn đi tìm sừng ngọc, còn phải cẩn thận từ từ tìm kiếm, có vẻ ở khu vực " HIR "Phi Hổ Trại" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1800 điểm\n" 
 BLK "    Tiềm năng :80 điểm\n" 
 BLK "    Ngân lượng :1500",
										24:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt quỷ hồn u minh rồi báo cho " HIR "Hứa Thị Ngụy Quốc báo cáo\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hứa Thị Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hứa Thị nói mấy ngày trước cô ta ở " HIR "Lang Nha Sơn Dịch Thủy" BLK " hái thuốc, nghe thấy từ thung lũng vọng lại tiếng quỷ khóc sói tru, cô ta nhìn vào thung lũng đó, lại thấy có một hang động trước màn sương đen cuồn cuộn, tiếng vọng đó có vẻ từ trong hang động vọng ra, cô ta nói cô ta nhớ rõ ràng, tiếng kêu đó không giống động vật bình thường trong hang động kêu, mà là một loại âm thanh rất kỳ lạ, liên tục vang vọng trong thung lũng, lúc đó cô ta sợ chạy xuống núi, sau này nghe nói khu vực đó có quỷ hồn u minh thường xuyên ra hại người, nên gọi tôi đi trừ nó.\n" BLK "		 Xuyên qua Quế Lăng, Bình Nguyên là đến Dịch Thủy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1700 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1500\n" 
 BLK "    Vật phẩm :20 cấp Hạng liên",
										25:BLK "Mục đích:\n" 
											
 BLK "    Đánh bại Quỷ Dạ Minh và báo cho " HIR "Hứa Thị Ngụy Quốc\n"
											BLK "Người giao nhiệm vụ: " HIR "Hứa Thị Ngụy Quốc\n"
											BLK "Miêu tả:\n" 
											
 BLK "    Thần Dịch Thủy nhân từ, từng nhiều lần khuyên răn Quỷ Dạ Minh nhưng không thành. Hứa Thị tuy là người ngoài cuộc, nhưng vì dân chúng, quyết tâm đuổi hắn đi.\n"
											
 BLK "    Từ Quế Lăng, Bình Nguyên đi đến " HIR "Dịch Thủy" BLK ".\n"
											BLK "Phần thưởng:\n"
											
 BLK "    Kinh nghiệm : 1800\n"
											
 BLK "    Tiềm năng   : 60\n"
											
 BLK "    Ngân lượng  : 1300\n"
											,
										36:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Trình Phong Yên Quốc nói chuyện về bí mật này\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Phong Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe giọng điệu của Trình Lâm Khai, việc này thật sự rất thần bí, khơi dậy tính tò mò của tôi, tôi muốn tiếp tục xem sự phát triển của sự việc, rốt cuộc có một ngày, tôi sẽ biết bí mật này, trước tiên nghe lệnh của hắn đi Yên Quốc tìm Trình Phong.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :30000 điểm\n" 
 BLK "    Tiềm năng :600 điểm\n" 
 BLK "    Ngân lượng :29000",
										37:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ Lý Đức\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đức\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói Lý Đức ở ngoại ô phía tây biết tin tức về một bảo vật trong động Tử Vân, thấy săn tâm hỷ bạn há lại bỏ lỡ cơ hội này?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :70000 điểm\n" 
 BLK "    Tiềm năng :880 điểm\n" 
 BLK "    Ngân lượng :58000",
										39:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt kẻ bắt nạt Chu Cửu về báo cáo " HIR "Lý Đức\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đức\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Để có thể lấy được bảo vật, bạn đi giúp hắn tiêu diệt kẻ bắt nạt Chu Cửu, nghe nói Chu Cửu đó ở góc tây nam " HIR "động Hư Lăng" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :72000 điểm\n" 
 BLK "    Tiềm năng :900 điểm\n" 
 BLK "    Ngân lượng :61000",
										40:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm ngọc tinh linh giao cho Tín Linh Quân, nội chính quan nước Ngụy\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tín Linh Quân, nội chính quan nước Ngụy\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bạn đã tiêu diệt kẻ bắt nạt Chu Cửu, chú ý chiếc rương bên cạnh chưa? Ngay tại rương ở phía tây nam động Hư Lăng, trong đó có ngọc tinh linh chứa linh khí của động Tử Vân, bạn tìm được rồi giao cho Tín Linh Quân, nội chính quan nước Ngụy nhé, ông ấy đang rất cần thứ này, sẽ thưởng hậu hĩnh cho bạn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :71000 điểm\n" 
 BLK "    Tiềm năng :910 điểm\n" 
 BLK "    Ngân lượng :62000",
										41:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Truyền lời cho dân nước Ngụy Nhạc Dương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân nước Ngụy Nhạc Dương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Việc Tín Linh Quân, nội chính quan nước Ngụy có được bảo vật này tốt nhất đừng để Đại Vương biết, bạn đi nhắc dân đó đừng truyền tin này lung tung.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :73000 điểm\n" 
 BLK "    Tiềm năng :900 điểm\n" 
 BLK "    Ngân lượng :60000",
										44:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt tên lừa đảo Chu Lão Tứ và trở lại thăm Ngụy lão hán\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy lão hán\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau khi Thủy Tinh và Hỏa Tinh chết, Ngụy lão hán dường như tạm thời thoát khỏi trạng thái điên loạn, nhưng ông vẫn chưa nhận ra sự thật rằng Đạo Tiên là một kẻ lừa đảo. Tuy nhiên, ông đã tiết lộ rằng Đạo Tiên thực chất tên là Chu Lão Tứ, vốn là người bạn thời thơ ấu đã mất tích nhiều năm, khi trở lại tự xưng là Đạo Tiên. Ngươi quyết định đến " HIR "phía tây nam Huyền Chân Động" BLK " để trừ khử hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :72000 điểm\n" 
 BLK "    Tiềm năng :900 điểm\n" 
 BLK "    Ngân lượng :61000",
										45:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thông báo cho Điển ngục quan Ngụy quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Điển ngục quan Ngụy quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngươi đã giết tên lừa đảo đó, tốt nhất hãy báo cho Điển ngục quan Ngụy quốc biết, để hắn lập hồ sơ và tâu lên Đại Vương ra lệnh truy nã toàn quốc những kẻ như vậy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :73000 điểm\n" 
 BLK "     Tiềm năng :910 điểm\n" 
 BLK "    Ngân lượng :63000",
										46:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao tấu thư thỉnh mệnh cho Ngụy Chiêu Đại Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Chiêu Đại Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Điển ngục quan Ngụy quốc biết được sự việc của Ngụy lão hán, ông cho rằng chuyện này rất quan trọng nên đã soạn thảo một tấu thư, nhờ ngươi chuyển trình lên Ngụy Chiêu Đại Vương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :74000 điểm\n" 
 BLK "    Tiềm năng :930 điểm\n" 
 BLK "    Ngân lượng :62000",
										47:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm tiểu thư Sa Tiễn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tiểu thư Sa Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Có tình nhưng không thể bên nhau, một mối duyên lành như vậy lại bị chia cắt. Nếu muốn biết nguyên nhân sự việc, hãy đến hỏi tiểu thư Sa Tiễn ở làng nhỏ phía tây thành.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :75000 điểm\n" 
 BLK "    Tiềm năng :950 điểm\n" 
 BLK "    Ngân lượng :65000",
										48:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thỉnh cầu Tôn thiếu gia\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tôn thiếu gia\n" BLK "Miêu tả nhiệm vụ:\n" 
										
 BLK "    Hai năm trước, tiểu thư Sa Tiễn gặp thư sinh Lý Đức khi đi xem hội hoa đăng. Họ cùng đối đố, dần nảy sinh tình cảm và hứa hẹn sau này sẽ kết duyên. Tuy nhiên, trong một lần đi dạo ở rừng Tương Phi, nàng bị lạc và chạm mặt Tôn thiếu gia – người khiến nàng hoảng sợ bỏ chạy. Không lâu sau, Tôn thiếu gia đến nhà cầu hôn, và cha nàng vì ham của đã hứa gả nàng cho hắn, bất chấp lời van xin của nàng. Lý Đức, nghèo khổ, không thể làm gì. Nay, Sa Tiễn mong nhờ bạn đến gặp Tôn thiếu gia, thay nàng thuyết phục từ hôn.\n" 
										BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :75000 điểm\n" 
 BLK "    Tiềm năng :940 điểm\n" 
 BLK "    Ngân lượng :66000",
										50:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt đánh thủ Chu Lão Ngũ và trở lại cảnh cáo Tôn thiếu gia\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tôn thiếu gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôn thiếu gia giả vờ nói rằng Chu Lão Ngũ cũng là khách mời của hắn. Nếu Chu Lão Ngũ đến và biết đám cưới bị hủy, chắc chắn hắn sẽ gây náo loạn. Nếu ngươi có thể đánh bại hắn, khiến hắn không còn gây rối, Tôn thiếu gia sẽ đồng ý với yêu cầu của ngươi. Hiện Chu Lão Ngũ đang ở phía tây bắc động Hư Lăng, ngươi có thể đến “nói chuyện” tử tế với hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :77000 điểm\n" 
 BLK "    Tiềm năng :980 điểm\n" 
 BLK "    Ngân lượng :68000",
										51:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thông báo cho tiểu thư Sa Tiễn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tiểu thư Sa Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôn thiếu gia quả không hổ là Tôn thiếu gia, sau khi đám đánh thủ bị thanh trừ, hắn vẫn nhanh chóng bình phục và thản nhiên trò chuyện với ngươi. Ngươi đã hoàn thành nhiệm vụ, có thể trở lại báo cho tiểu thư Sa Tiễn rằng Tôn thiếu gia đã đồng ý hủy hôn ước. Nàng và Lý Đức giờ đây có thể toại nguyện.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :75000 điểm\n" 
 BLK "    Tiềm năng :980 điểm\n" 
 BLK "    Ngân lượng :67000",
										52:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ Mạnh Cầu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mạnh Cầu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, thị trấn Lâm Hà được cho là xảy ra nhiều chuyện kỳ lạ, dân chúng đồn đại rất nhiều, nào là thần tiên hạ phàm thu nhận tọa kỵ, nào là yêu quái rời hang tìm người tế sống. Ngươi hãy đi điều tra kỹ lưỡng xem rốt cuộc ai đang giả thần giả quỷ. Nghe nói Mạnh Cầu ở " HIR "thị trấn Lâm Hà" BLK " phía tây thành rất hiểu biết và từng trải, ngươi hãy đến hỏi thăm và học hỏi từ ông ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :77000 điểm\n" 
 BLK "    Tiềm năng :990 điểm\n" 
 BLK "    Ngân lượng :69000",
										53:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tình hình cụ thể từ Chu Đồng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Đồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, gia súc và đồ đạc cá nhân của dân chúng trong trấn thường xuyên mất tích một cách bí ẩn. Một số gia súc thậm chí còn đột nhiên xuất hiện trong chuồng của người khác, hoặc đồ đạc cá nhân xuất hiện trong phòng của hàng xóm. Những chuyện kỳ lạ này khiến mọi người hoang mang, nghi thần nghi quỷ, khổ sở không chịu nổi. Chu Đồng ở đầu trấn biết rõ hơn về những việc này, ngươi hãy đến hỏi thăm ông ấy để biết thêm chi tiết.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :76000 điểm\n" 
 BLK "    Tiềm năng :1100 điểm\n" 
 BLK "    Ngân lượng :68000",
										55:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt đạo tặc Thạch Đại Long và trở lại báo cáo cho Chu Đồng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Đồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Số lượng Hỏa Tinh và Thủy Tinh bỗng giảm đi đáng kể. Chu Đồng đoán rằng có thể kẻ đứng sau đã xuất hiện. Tối qua, ông ấy đã phục kích quanh chuồng gia súc và phát hiện tung tích của đạo tặc Thạch Đại Long. Rất có thể hắn là kẻ chủ mưu đằng sau loạt sự kiện này. Sau đó, Chu Đồng lần theo dấu vết của Thạch Đại Long đến khu vực " HIR "phía bắc Huyền Chân Động" BLK ", nhưng không dám hành động khinh suất. Chu Đồng bảo ngươi đến đó tiêu diệt hắn. Có lẽ sau khi làm được việc này, những chuyện kỳ lạ ở thị trấn Lâm Hà sẽ chấm dứt.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :79000 điểm\n" 
 BLK "    Tiềm năng :1050 điểm\n" 
 BLK "    Ngân lượng :67000",
										56:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo cho Ngụy quốc Ngự sử Ngụy Bạt\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy quốc Ngự sử Ngụy Bạt\n" BLK "Miêu tả nhiệm vụ:\n" BLK "   Dvì Thạch Đại Long tuy đã chết và không có bằng chứng, không rõ làm thế nào hắn có thể gây ra nhiều chuyện như vậy mà không ai hay biết, nhưng dù sao thì giờ đây thị trấn đã trở lại yên bình. Chu Đồng yêu cầu ngươi báo cáo lại cho Ngự sử, để ông ấy yên tâm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :78000 điểm\n" 
 BLK "    Tiềm năng :1100 điểm\n" 
 BLK "    Ngân lượng :68000",
										57:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ Ngụy lão hán\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy lão hán\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, Ngụy lão hán lại tâu báo rằng ở " HIR "thị trấn Lâm Hà phía tây thành" BLK " lại xuất hiện những sự kiện tương tự như lần trước. Nhưng hung thủ đã chết, vậy tại sao chuyện này lại xảy ra lần nữa? Lẽ nào còn đồng đảng? Ngụy quốc Ngự sử Ngụy Bạt yêu cầu ngươi đến gặp Ngụy lão hán để hỏi chi tiết về sự việc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :80000 điểm\n" 
 BLK "    Tiềm năng :1200 điểm\n" 
 BLK "    Ngân lượng :69000",
										59:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt mã tặc Ngụy Tiểu Tam và trở lại báo cáo cho Ngụy lão hán\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy lão hán\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, mã tặc Ngụy Tiểu Tam thường xuyên đến quấy nhiễu làng xóm, nhưng những chuyện kỳ lạ như lần trước thì không xảy ra. Tuy nhiên, mọi người sợ bị trả thù nên chỉ dám tức giận mà không dám lên tiếng, khiến sự việc trở nên bí ẩn. Lần trước, có dân làng nhìn thấy mã tặc Ngụy Tiểu Tam đang lẩn trốn ở khu vực " HIR "phía nam động Hư Lăng" BLK ". Ngươi hãy đi tiêu diệt hắn, có lẽ sau đó mọi người sẽ lại được ngủ yên giấc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :79000 điểm\n" 
 BLK "    Tiềm năng :1100 điểm\n" 
 BLK "    Ngân lượng :70000",
										60:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo tình hình cho Ngụy quốc Ngự sử Ngụy Bạt\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy quốc Ngự sử Ngụy Bạt\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hiện nay thị trấn Lâm Hà đã yên bình trở lại, nhưng không biết sự yên bình này sẽ kéo dài được bao lâu. Ngươi hãy báo cáo loạt sự kiện gần đây cho Ngự sử, xem liệu có nên phái một quan viên đắc lực đến để nghiêm ngặt phòng ngừa những việc tương tự xảy ra thường xuyên, bởi vì khu vực kinh kỳ vốn là nơi trọng yếu.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :80000 điểm\n" 
 BLK "    Tiềm năng :1150 điểm\n" 
 BLK "    Ngân lượng :70000",
										61:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo tình hình cho Ngụy Chiêu Đại Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Chiêu Đại Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngự sử Tần quốc Lý Tư vừa nhận được tin tức do Ngụy lão hán nhờ người chuyển告. Hóa ra vụ án Thạch Đại Long trước đây quả nhiên có ẩn tình. Gần nơi Thạch Đại Long bị phục kích, người ta tìm thấy một vật gọi là Càn Khôn Đại. Sau đó, có cao nhân cho biết chiếc túi này có thể chứa đựng rất nhiều vật phẩm mà không hề có trọng lượng. Bảo vật như vậy, Ngụy quốc Ngự sử Ngụy Bạt đã giao cho cao nhân nghiên cứu cách sử dụng, sau đó sẽ dâng lên Ngụy Chiêu Đại Vương. Ngươi hãy đi báo tin trước để Ngụy Chiêu Đại Vương vui mừng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :81000 điểm\n" 
 BLK "    Tiềm năng :1100 điểm\n" 
 BLK "    Ngân lượng :71000\n" 
 BLK "    Vật phẩm :Y Phục cấp 100",
										65:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau cấp 25" BLK " truyền lời nhắn của Lý Tam Thẩm đến Lý Đức ở thị trấn Lâm Hà\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đức ở thị trấn Lâm Hà\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lý Tam Thẩm là người thích náo nhiệt, cũng thích cả gia đình quây quần bên nhau. Lý Đức ở thị trấn Lâm Hà ngoài thành là cháu trai của bà. Lý Đức đã lâu không đến nhà bà, và cả gia đình cũng đã lâu không cùng nhau ăn một bữa cơm. Vì vậy, hôm nay bà muốn mời những người thân ở gần đến nhà ăn bữa tối. Bản thân bà thì bận chuẩn bị bữa ăn, không thể đi mời họ, nên nhờ ta giúp việc này, đến thị trấn Lâm Hà để truyền lời nhắn này cho Lý Đức.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :1400 điểm\n" 
 BLK "    Tiềm năng :70 điểm\n" 
 BLK "    Ngân lượng :1400",
										66:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau cấp 30" BLK " giao quân cờ cho Sở tổng quản\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở tổng quản\n" BLK "Miêu tả nhiệm vụ:\n" 
										
 BLK "    Nhớ đến người đó, lòng ta vẫn mãi không thể bình yên, không phải vì xúc động, không phải vì tức giận, mà là xót xa… Vệ binh Ngụy quốc đã nói với ta như vậy.\n" 
 BLK "    Mấy ngày trước, một người đã đến ngoài thành Ngụy. Hắn loạng choạng bước đến bên vệ binh Ngụy quốc, đưa một quân cờ và nhờ vệ binh giao nó cho Sở tổng quản. Khi vệ binh Ngụy quốc nói rằng đây là Ngụy quốc, hắn lộ vẻ tuyệt vọng và kể rằng mình đến từ rất xa, mang theo vết thương nặng. Quân cờ này là cách duy nhất để liên lạc với Sở tổng quản, là tín vật từ khi họ kết nghĩa. Hắn tha thiết nhờ vệ binh bằng mọi giá phải giao quân cờ đến tay Sở tổng quản, để Sở tổng quản biết rằng huynh đệ của mình đã bị người khác sát hại. Nói xong, hắn gục ngã trước mặt vệ binh Ngụy quốc… Giờ đây, vệ binh Ngụy quốc nhờ ta thay hắn mang quân cờ này đến cho Sở tổng quản, đồng thời báo cho Sở tổng quản rằng hắn đã an táng huynh đệ của Sở tổng quản tử tế.\n" 
										BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2500 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :3000",
										67:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau cấp 100" BLK " truyền đạt ý định của vệ binh Ngụy quốc cho Tề quốc tài chính quan Điền Đan\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề quốc tài chính quan Điền Đan\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Công việc của vệ binh là ngày ngày đứng đó, như một bức tượng, ngày qua ngày, tháng qua tháng, năm qua năm. Vệ binh Ngụy quốc nói rằng hắn đã chán ngán công việc này. Hắn nghe nói Tề quốc đang chuẩn bị gia cố Trường Thành, có lẽ hắn có thể đến đó làm lính tuần tra ở công trường, như vậy có thể thú vị hơn nhiều so với làm vệ binh. Nhưng hắn không dám công khai đi hỏi, nên nhờ ta đến hỏi ý kiến Tề quốc tài chính quan Điền Đan thay hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :38000 điểm\n" 
 BLK "    Tiềm năng :600 điểm\n" 
 BLK "    Ngân lượng :35000",
										68:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi cấp 10" BLK " giao hộp trang sức do thợ thủ công Ngụy quốc làm xong cho Tề Quản Gia\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mấy ngày trước, Tề Quản Gia đã nhờ thợ thủ công Ngụy quốc làm một hộp trang sức cho tiểu thư nhà mình, và dặn dò rằng hộp phải đơn giản, dễ dùng, không cần kiểu dáng quá cầu kỳ vì tiểu thư nhà ông là một cô gái rất mộc mạc. Thợ thủ công Ngụy quốc nói rằng ông ta đã mất nhiều ngày để hoàn thành chiếc hộp này, sử dụng gỗ tốt nhất, đơn giản nhưng không kém phần tinh tế. Ông nhờ ta mang chiếc hộp trang sức này giao cho Tề Quản Gia. Thực ra, ông cũng rất muốn tự mình đi, để gặp cô tiểu thư đặc biệt ấy, nhưng tiếc là không có thời gian.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :50000 điểm\n" 
 BLK "    Tiềm năng :615 điểm\n" 
 BLK "    Ngân lượng :48000",
]),
								 TID_QIGUO:
									 ([1:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được" HIR "Tề Quốc tài chính quan Điền Đan" BLK ", báo cáo việc cầu cứu của Triệu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Quốc tài chính quan Điền Đan\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tần Triệu đại chiến Trường Bình, Tề, Yên hợp lực cứu Triệu. Quân Triệu thiếu lương thực, mượn của Tề Quốc, hy vọng Tề Quốc hết lòng tương trợ, giúp Triệu có thể dồn toàn lực đánh Tần. Sứ giả Triệu tìm đến Tề Quốc Đại Vương phủ, nhờ Tề tổng quản báo cáo việc này cho Tề Quốc tài chính quan Điền Đan. Tề tổng quản vì nhất thời không có người bên cạnh, liền giao phó việc này cho ta, ta nhất định sẽ dốc hết sức tương trợ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2500 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1800",
										  2:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay Tề Quốc tài chính quan Điền Đan hỏi ý kiến của Chu Tử\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Tử\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tần Triệu đại chiến Trường Bình, Tề, Yên hợp lực cứu Triệu. Quân Triệu thiếu lương thực, mượn của Tề Quốc, hy vọng Tề Quốc hết lòng tương trợ, giúp Triệu có thể dồn toàn lực đánh Tần. Sứ giả Triệu tìm đến Tề Quốc Đại Vương phủ, nhờ Tề tổng quản báo cáo việc này cho Tề Quốc tài chính quan Điền Đan. Nhưng Tề Quốc tài chính quan Điền Đan dường như chưa quyết định được, muốn hỏi ý kiến của Chu Tử, nên giao phó trọng trách này cho ta. Việc này liên quan đến sự tồn vong của quốc gia, ta nhất định sẽ dốc hết sức tương trợ! Chu Tử gần đây đã đến " 
										  HIR "hồ Bà Dương" BLK " ngắm cảnh, xem ra ta phải tốn thêm chút thời gian rồi!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :2500 điểm\n" 
 BLK "    Tiềm năng :60 điểm\n" 
 BLK "    Ngân lượng :1800",
										  4:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hồi đáp Tề tổng quản, đồng ý cho Triệu Quốc mượn lương thực\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề tổng quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Luận điểm 'môi hở răng lạnh' của Chu Tử quả nhiên sắc bén, khiến vị tài chính quan vốn không muốn cho mượn lương thực cũng đồng ý. Phải nhanh chóng hồi đáp Tề tổng quản, để ông ấy sớm thông báo tin tốt này cho sứ giả Triệu Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "      Kinh nghiệm :3300\n" 
 BLK "    Tiềm năng :100\n" 
 BLK "    Ngân lượng :3000",
										  6:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt gián điệp của bộ tộc Sơn Nhung ẩn náu trong" HIR "Bạch Mã Trang" BLK " rồi báo cáo cho " HIR "Tề Vương \n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mấy ngày trước, một dân tộc thiểu số tên là Sơn Nhung lại xâm phạm Yên Quốc, cướp bóc lương thực, gia súc và tài sản, Yên Quốc đã phái người đến cầu cứu. Tề Vương tham khảo ý kiến của Thừa tướng, xác định Sơn Nhung thường xuyên quấy nhiễu Trung Nguyên, là mối họa cho sự ổn định của Trung Nguyên, nhất định phải chinh phục. Vì vậy, ông chuẩn bị đích thân dẫn đại quân đi cứu viện Yên Quốc. Theo tin tức từ thám tử, Sơn Nhung đã sai một gián điệp trà trộn vào Tề Quốc, việc cấp bách hiện nay là tìm ra và tiêu diệt tên gián điệp này, nhiệm vụ quan trọng này đã được giao cho ta. Theo tình báo đáng tin cậy, gián điệp của bộ tộc Sơn Nhung đang ẩn náu ở góc phía đông của Bạch Mã Trang, đi qua hồ Mã Đạp, sẽ thấy " 
										  HIR "Bạch Mã Trang" BLK ". Sau khi tiêu diệt gián điệp của bộ tộc Sơn Nhung, " HIR "Tề Vương" BLK " chắc chắn sẽ ban thưởng hậu hĩnh!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3800 điểm\n" 
 BLK "    Tiềm năng: 120 điểm\n" 
 BLK "    Ngân lượng: 3500",
										  7:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến " HIR "Thái Công Phủ" BLK " trong lãnh thổ Tề Quốc để tiêu diệt sứ giả Gởi Quốc rồi báo cáo cho " HIR "Tề Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gián điệp của bộ tộc Sơn Nhung đã bị tiêu diệt, nhưng mối đe dọa mà họ gây ra cho Yên Quốc vẫn chưa được giải quyết, vì người Sơn Nhung đã đến cầu viện bộ tộc Cô Trúc, và bộ tộc Cô Trúc cũng đã phái sứ giả đến để bàn bạc về việc này. Để ngăn họ liên kết với nhau, ta phải trừ khử sứ giả Gởi Quốc, mối họa lớn trong lòng! Sứ giả Gởi Quốc hiện đã vào lãnh thổ Tề Quốc và đang nghỉ ngơi tại Thái Công Phủ. Sau khi ta tiêu diệt hắn, " HIR "Tề Vương" BLK " chắc chắn sẽ ban thưởng hậu hĩnh!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3900 điểm\n" 
 BLK "    Tiềm năng: 125 điểm\n" 
 BLK "    Ngân lượng: 3500",
										  8:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay Tề Vương đến Thủy Tạ Hoa Đô tìm Quản Trọng, và thông báo cho ông ấy rằng chiến sự đã dừng, yêu cầu ông ấy nhanh chóng trở về nước.\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản Trọng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gian tế của tộc Sơn Nhung và dân chúng nước Gởi đều đã bị ta tiêu diệt! Quản Trọng hiện vẫn đang ở " HIR "Thủy Tạ Hoa Đô" BLK " chờ lệnh của Tề Vương, ta cần đến Thủy Tạ Hoa Đô để đưa tin cho Quản Trọng, nói rằng chiến sự đã dừng, yêu cầu ông ấy nhanh chóng trở về nước. Ông ấy đang ở ngay lối vào của Thủy Tạ Hoa Đô.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4000 điểm\n" 
 BLK "    Tiềm năng: 130 điểm\n" 
 BLK "    Ngân lượng: 4000",
										  9:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Đại Vương Khải để xin hạt giống, giao cho ông Tôn.\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Vương Khải\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tục ngữ có câu, người khéo léo cũng khó nấu ăn nếu không có gạo. Hạt giống không tốt, dù có bón phân thế nào cũng không thể trồng được vụ mùa tốt. Ông Tôn đã phải chịu khổ vì những hạt giống kém chất lượng này, cả năm vất vả nhưng vụ mùa thu hoạch không tốt, cả nhà phải sống cảnh bữa no bữa đói.\n" 
 BLK "    Đại Vương Khải vẫn luôn nghiên cứu về hạt giống, có lẽ ông ấy có những hạt giống tốt hơn. Nhưng lũ thỏ hoang đang hoành hành, ông Tôn không thể rời đi được. Bạn hãy đến tìm Đại Vương Khải để xin một ít hạt giống cho ông ấy nhé.\n" 
										  
 BLK "    Đại Vương Khải ở không xa đây, ngay tại thị trấn " HIR "Kiệt Thạch" BLK " phía đông nam.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3000 điểm\n" 
 BLK "    Tiềm năng: 70 điểm\n" 
 BLK "    Ngân lượng: 2000",
										 10:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Trình Phong, thúc giục anh ta tăng tốc độ vận tiêu, nói với anh ta rằng Đại Vương Khải đã đợi rất lâu.\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Phong\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mấy ngày trước, một người bạn đã vận chuyển một ít đồ cho Đại Vương Khải, người nghiên cứu hạt giống, và nhờ Uất Trí Lão Tiêu Đầu vận chuyển đến. Nhưng nghe nói, do thiếu người, Uất Trí Lão Tiêu Đầu đã nhờ một người khác giúp vận chuyến tiêu này. Dù người đó võ nghệ cao cường và là bạn tốt của Uất Trí Lão Tiêu Đầu, nhưng Đại Vương Khải vẫn không yên tâm. Đã nhiều ngày trôi qua mà vẫn không thấy người đó đến. Nghe nói anh ta còn đang lưu lại ở Thiền Võ Đài của nước Yên, không biết đang làm gì. Vì anh ta từng giúp tôi, nên tôi sẽ giúp anh ta lần này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3500 điểm\n" 
 BLK "    Tiềm năng: 90 điểm\n" 
 BLK "    Ngân lượng: 2500",
										 15:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Sở Quốc Bá Tánh Hàn Nhượng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quốc Bá Tánh Hàn Nhượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, Tề Vương vì việc xưng bá bảy nước mà thường xuyên ăn không ngon, đêm không ngủ được. Có người nói với ông rằng ở nước Sở có một loại Trà Jasmine có thể cải thiện khẩu vị và giúp ngủ ngon. Tuy nhiên, là một vị vua, Tề Vương không thể tùy tiện rời khỏi đất nước của mình. Vì vậy, Tề Vương đã nhờ tôi đến dân gian nước Sở để tìm loại Trà Jasmine này. Tôi có thể bắt đầu bằng việc nói chuyện với những " HIR "bá tánh" BLK " của " HIR "nước Sở" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 14000 điểm\n" 
 BLK "    Tiềm năng: 238 điểm\n" 
 BLK "    Ngân lượng: 13000",
										 25:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm dò thương nhân ngọc khí Tề Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân ngọc khí Tề Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bá tánh Tề Quốc nói với bạn rằng, nếu muốn kiếm tiền, hãy tìm thương nhân ngọc khí. Người này giàu có đến mức tiền nhiều như phát sốt. Gần đây, ông ta đang buồn bã, nếu bạn có thể giúp gì được cho ông ta, có lẽ bạn sẽ kiếm được một khoản kha khá.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 48000 điểm\n" 
 BLK "    Tiềm năng: 680 điểm\n" 
 BLK "    Ngân lượng: 50000",
										 26:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm Tề Tổng Quản về ngọc quý hiếm\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thương nhân ngọc khí cả đời say mê châu báu và ngọc khí, đã xem qua vô số viên ngọc đẹp, nhưng ngọc quý hiếm trong truyền thuyết thì ông ta chưa từng được diện kiến, chỉ thoáng thấy một lần rồi không còn tìm thấy tung tích. Ông ta chỉ mong sở hữu được viên ngọc đó để đời này không còn tiếc nuối. Nhưng núi non biển cả bao la, ngọc quý hiếm rốt cuộc đang ẩn mình nơi đâu? Nghe nói Tề Tổng Quản kiến thức uyên thâm, nhưng dường như ông ấy không muốn qua lại với thương nhân, nên chỉ còn cách nhờ bạn giúp ông ta tìm kiếm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 50000 điểm\n" 
 BLK "    Tiềm năng: 700 điểm\n" 
 BLK "    Ngân lượng: 52000",
										 28:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ quan tài chính Tề quốc Điền Đan\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan tài chính Tề quốc Điền Đan\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tổng quản Tề cho biết viên ngọc quý này được cho là mang tà khí, bất kỳ ai sở hữu và đặt nó trong nhà đều sẽ gặp ma quỷ. Chủ nhân trước đây của nó, anh họ của quan tài chính, cả gia đình đã bị viên ngọc này hại chết. Vì vậy, quan tài chính tuy rất thích viên ngọc này, nhưng để tránh gây hại cho gia đình, đành phải vứt bỏ nó ở một nơi nào đó. Cụ thể thì bạn phải đi hỏi quan tài chính.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 52000 điểm\n" 
 BLK "    Tiềm năng: 720 điểm\n" 
 BLK "    Ngân lượng: 54000",
										 29:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm viên ngọc quý hiếm và giao cho thương nhân ngọc khí Tề quốc\n" BLK "Người hoàn thành nhiệm vụ:" 
										 HIR "Thương nhân ngọc khí Tề quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quan tài chính Tề quốc Điền Đan đã cảnh báo rằng viên ngọc quý hiếm này là vật không may mắn. Nếu bạn khăng khăng muốn lấy, ông ấy cũng không ngăn cản, nhưng khuyên bạn nếu trong nhà xuất hiện ma quỷ thì hãy nhanh chóng vứt bỏ nó. Những thứ đẹp đẽ thường đầy rẫy nguy hiểm, đừng vì tham lam nhất thời mà gây bất hạnh cho gia đình. Chuyện gia đình anh họ ông ấy bạn cũng đã biết rồi, ông ấy không nói thêm nhiều, chỉ chúc bạn tự cầu may mắn. Viên ngọc nằm trong" HIR "tầng hai của lăng mộ Tướng Quân" BLK ", bên trong một chiếc hộp nhỏ. Trên hộp có dán một lá bùa nhỏ do quan tài chính Tề quốc Điền Đan phong ấn để đề phòng. Khi mở hộp, hãy đứng xa một chút và cẩn thận, chắc hẳn sẽ không có vấn đề gì lớn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 55000 điểm\n" 
 BLK "    Tiềm năng: 730 điểm\n" 
 BLK "    Ngân lượng: 52000",
										 30:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm dò Đại tướng quân Tề quốc Điền Kỵ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Tề quốc Điền Kỵ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bá Tánh Tề Quốc hôm trước đi ngang qua đại doanh Tề quân, thấy quân doanh trên dưới rối loạn, chắc hẳn có chuyện rắc rối gì đó. Nếu bạn rảnh rỗi, hãy đến hỏi xem có chỗ nào bạn có thể giúp đỡ không, biết đâu sẽ có thu hoạch bất ngờ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 56000 điểm\n" 
 BLK "    Tiềm năng: 750 điểm\n" 
 BLK "    Ngân lượng: 53000",
										 31:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thư của tướng quân cho Ngự sử Doãn Văn nước Tề\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự sử Doãn Văn nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân nước Tề Điền Kỵ đã làm mất tín vật điều binh Uy Hổ Tướng Quân Lệnh, bạn hãy thay hắn giao lá thư tướng quân này cho Ngự sử Doãn Văn nước Tề, xem liệu ông ấy có phương pháp hay nào không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 58000 điểm\n" 
 BLK "    Tiềm năng: 770 điểm\n" 
 BLK "    Ngân lượng: 51000",
										 32:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ dân chúng nước Tề\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngự sử Doãn Văn nước Tề khuyên rằng tốt nhất nên đi hỏi thăm dân chúng xem có tin tức gì về Tướng Quân Lệnh không, bạn hãy đến hỏi dân chúng nước Tề trước nhé! Xem có thể tìm được manh mối gì không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 57000 điểm\n" 
 BLK "    Tiềm năng: 790 điểm\n" 
 BLK "    Ngân lượng: 50000",
										 34:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Lấy lại Tướng Quân Lệnh và giao cho Đại tướng quân nước Tề Điền Kỵ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Tề Điền Kỵ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dân chúng nước Tề nghe nói chủ nhân của Đao Tượng và Thương Tượng đã giấu Uy Hổ Tướng Quân Lệnh trong rương báu ở tầng bốn của " HIR "Cổ mộ Tướng quân" BLK ", ra lệnh cho chúng canh gác. May mắn thay, gần đây chủ nhân của chúng thấy tình hình căng thẳng nên đã bỏ trốn. Nếu bạn không hạ được chúng, dân chúng nước Tề thật sự không dám tiết lộ cho bạn. Mau chóng đi lấy đi, nếu tướng quân có thưởng, đừng quên chia cho dân chúng nước Tề một nửa nhé!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 63000 điểm\n" 
 BLK "    Tiềm năng: 800 điểm\n" 
 BLK "    Ngân lượng: 52000",
										 35:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm dò Lý Đồ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đồ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tranh chấp dân sự luôn khó phân định đúng sai, Ngự sử Tề quốc Doãn Văn được biết gần đây vì tranh chấp đất đai, Lý Đồ và Lôi Bá Thiên đấu đá kịch liệt, lý chính cũng không biết can thiệp thế nào. Nghe nói Lý Đồ hiện tại không tranh lại được, bị đuổi sang bên này sông, bạn hãy đến chỗ hắn điều tra xem rốt cuộc chuyện là thế nào.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 62000 điểm\n" 
 BLK "    Tiềm năng: 770 điểm\n" 
 BLK "    Ngân lượng: 53000",
										 36:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi nói chuyện với Lôi Bá Thiên\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lôi Bá Thiên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lôi Bá Thiên thật sự quá đáng, nhà của Lý Đồ sát cạnh nhà hắn, vậy mà hắn lại nói mái hiên nhà Lý Đồ chiếm sân trời nhà hắn, tường nhà lại lấn thêm một tấc, nên đã tự ý phá mái hiên nhà Lý Đồ, đập vỡ nửa bức tường, khiến nhà Lý Đồ mưa thì dột, gió thổi ù ù vào trong, hoàn toàn không thể ở được. Vì thế, Lý Đồ đành phải chuyển sang ở tạm tại căn nhà tạm bên bờ sông để trông coi ruộng đất. Lý Đồ nhờ bạn đứng ra đòi lại công lý cho anh ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 65000 điểm\n" 
 BLK "    Tiềm năng: 780 điểm\n" 
 BLK "    Ngân lượng: 51000",
										 38:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt ác bá Chu Tam để cảnh cáo Lôi Bá Thiên\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lôi Bá Thiên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ binh mà bạn tiêu diệt là do Lôi Bá Thiên mượn từ Chu Tam, bạn đã giết người của hắn, nguy to rồi! Mau đến tầng bốn phía đông bắc của cổ mộ tướng quân để hạ gục hắn trước đã.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 66000 điểm\n" 
 BLK "    Tiềm năng: 790 điểm\n" 
 BLK "    Ngân lượng: 52000",
										 39:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thông báo cho Lý Đồ mọi việc đã kết thúc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đồ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quay về thông báo cho Lý Đồ rằng có thể chuyển về, Lôi Bá Thiên sẽ không làm phiền anh ta nữa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :68000 điểm\n" 
 BLK "    Tiềm năng :800 điểm\n" 
 BLK "    Ngân lượng :51000",
										 40:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tình hình từ dân chúng Tề Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Quốc Bá Tánh\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, Ngự sử Tề Quốc Doãn Văn đang có tâm trạng tốt, muốn đi sâu vào dân chúng để làm một số việc tốt nhằm nâng cao danh tiếng. Bạn hãy đến khu chợ tìm dân chúng để hỏi thăm, xem gần đây họ có vấn đề gì không quá khó khăn để báo cáo lên không. Những việc bạn thấy Ngự sử Tề Quốc Doãn Văn có thể dễ dàng thực hiện thì cứ hứa với họ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :69000 điểm\n" 
 BLK "    Tiềm năng :810 điểm\n" 
 BLK "    Ngân lượng :50000",
										 41:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm dò thương nhân Tề Quốc Nghĩ Đốn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân Tề Quốc Nghĩ Đốn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dân chúng Tề Quốc nói với bạn rằng nếu muốn có chút thành tích mà không quá khó khăn, hãy tìm thương nhân Tề Quốc Nghĩ Đốn. Ông ta cả ngày lo sợ bị cướp, thế nào, giờ bị cướp thật rồi đúng không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm :70000 điểm\n" 
 BLK "    Tiềm năng :820 điểm\n" 
 BLK "    Ngân lượng :53000",
										 43:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt tên cướp Mã Tiểu Thất và quay lại báo cáo cho Ngự sử Tề Quốc Doãn Văn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự sử Tề Quốc Doãn Văn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thương nhân Tề Quốc Nghi Đốn lần trước đi buôn bán ở nước láng giềng, kết quả trên đường bị tên cướp Mã Tiểu Thất chặn đường, cướp sạch số tiền buôn bán của ông ta. Nghe nói Mã Tiểu Thất hiện đang ẩn náu ở phía bắc tầng bốn của Lăng mộ Tướng quân. Hãy đến đó tiêu diệt hắn, sau khi tiêu diệt xong, báo lại cho Ngự sử Tề Quốc Doãn Văn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 68000 điểm\n" 
 BLK "    Tiềm năng: 830 điểm\n" 
 BLK "    Ngân lượng: 56000",
										 44:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo cho Tề Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tên Mã Tiểu Thất vốn là một tên cướp khét tiếng, từng cùng đồng bọn trộm cắp ở cung điện Đại Vương. Hắn cực kỳ xảo quyệt, khiến việc bắt giữ hắn luôn thất bại. Tề Vương rất tức giận về chuyện này. Nay cuối cùng đã tiêu diệt được hắn, đồng thời giải quyết được khó khăn cho dân chúng, thật là nhất cử lưỡng tiện! Hãy nhanh chóng vào cung báo cáo cho Tề Vương để ngài vui mừng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 71000 điểm\n" 
 BLK "    Tiềm năng: 850 điểm\n" 
 BLK "    Ngân lượng: 55000",
										 45:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tình hình từ tiểu thương Tề\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tiểu thương Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, tổng quản Tề đi ngang qua quầy hàng của tiểu thương Tề, thường thấy anh ta thở dài thườn thượt. Hãy đến hỏi tiểu thương Tề xem rốt cuộc là chuyện gì.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 70000 điểm\n" 
 BLK "    Tiềm năng: 840 điểm\n" 
 BLK "    Ngân lượng: 56000",
										 47:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Trương Thất Long và báo lại cho Tề Tiểu Phẩm\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Tiểu Phẩm\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Kẻ ác bá tên Trương Thất Long đã ép buộc Tề Tiểu Phẩm nộp tiền bảo kê. Nghe nói hiện tại Trương Thất Long đang hoạt động ở khu vực phía nam của" HIR "Tầng năm Lăng Mộ Tướng Quân" BLK ". Hãy đến đó tiêu diệt hắn và thông báo cho Tề Tiểu Phẩm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 70000 điểm\n" 
 BLK "    Tiềm năng: 820 điểm\n" 
 BLK "    Ngân lượng: 57000 ",
										 48:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo cho Nội chính quan Tề quốc Mạnh Thường Quân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội chính quan Tề quốc Mạnh Thường Quân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tề Tiểu Phẩm nghe nói dường như tên ác bá này có mối quan hệ gì đó với Nội chính quan. Tốt nhất bạn nên đến báo cáo để tránh việc hắn gây rắc rối cho bạn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 71000 điểm\n" 
 BLK "    Tiềm năng: 810 điểm\n" 
 BLK "    Ngân lượng: 56000",
										 49:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thông báo cho Bá Tánh Tề Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá Tánh Tề Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bạn đã giúp Nội chính quan Tề quốc Mạnh Thường Quân tiêu diệt tên ác bá. Hãy thông báo tin này cho Bá Tánh Tề Quốc để họ có thể yên tâm sinh sống.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 69000 điểm\n" 
 BLK "    Tiềm năng: 830 điểm\n" 
 BLK "    Ngân lượng: 57000\n" 
 BLK "    Vật phẩm: Y Phục cấp 90",
										 61:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến đảo Đông Hải tìm Mã Đồng, hỏi về chuyện của Tiểu Đồ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mã Đồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tiểu Đồ cùng với" HIR "Mã Đồng trên đảo Đông Hải" BLK " đã ra ngoài, bà肖 (Tiêu phu nhân) bảo tôi đến đảo Đông Hải xem Mã Đồng đã về nhà chưa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "     Kinh nghiệm: 36000 điểm\n" 
 BLK "    Tiềm năng: 600 điểm\n" 
 BLK "    Ngân lượng: 40000",
										 63:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến chỗ Công Thâu Ban ở nước Chu để sửa cái thùng gỗ nhỏ bị hỏng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban ở nước Chu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bạn bị coi là con của Bá Tánh Ngô Cơ nước Triệu, bị chế giễu một phen. Cái thùng gỗ đỏ thượng hạng của Bá Tánh nước Tề cũng bị mượn và làm hỏng. Ban đầu, Bá Tánh Ngô Cơ nước Triệu nói dối là cần thùng để chứa rượu Tiên Nhân Túy mới mượn, giờ Bá Tánh nước Tề yêu cầu bạn mang thùng đến cho Công Thâu Ban ở nước Chu để sửa chữa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "      Kinh nghiệm: 36000 điểm\n" 
 BLK "    Tiềm năng: 600 điểm\n" 
 BLK "    Ngân lượng: 35000",
										 65:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Tần Tổng Quản để trò chuyện\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Tổng Quản\n" 
										 BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tề Quản Gia khuyên bạn nên nhân lúc còn trẻ mà chu du thiên hạ, học hỏi tinh hoa quân sự khắp nơi để mở rộng tầm nhìn. Trong số các nước, Tần hiện là cường quốc quân sự mạnh nhất, đặc biệt nổi bật với Tần Trường Thành – công trình phòng thủ chống ngoại xâm kiên cố, do các danh tướng như Mông Điềm và Đại Vương Ly trấn giữ. Tuy hiện tại ông bận vì Tần – Triệu đang giao tranh, nhưng ông khuyên bạn nên tìm gặp Tần Tổng Quản – người trọng dụng nhân tài – để tìm hiểu thêm về Tần Trường Thành, chắc chắn ông ấy sẽ sẵn lòng tiếp đón.\n" 
										 BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 48000 điểm\n" 
 BLK "    Tiềm năng: 750 điểm\n" 
 BLK "    Ngân lượng: 50000",
										 71:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao Trà Mây cho Sở Đại Vương Khảo Liệt Đại Vương, có thể sẽ nhận được thu hoạch bất ngờ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Đại Vương Khảo Liệt Đại Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sở Đại Vương Khảo Liệt Đại Vương trước đây đã sai người gửi tặng Tề Vương 100 con cá Tinh Ngư, thả nuôi trong hồ Bế Dạ, Thái hậu Tề rất yêu thích. Đến mà không đáp lễ là không phải phép, Tề Vương cũng muốn tặng lại một số quà cho Sở Đại Vương Khảo Liệt Đại Vương. Ông có một loại Trà Mây, được sản xuất từ vách núi tiên, đều là quà tặng từ những bậc đạo sĩ cao nhân khi luận đạo với Tề Vương. Nghe nói mỗi năm không quá 10 cân, tin rằng món quà này xứng đáng với danh tiếng của một nước lớn như chúng ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 200000 điểm\n" 
 BLK "    Tiềm năng: 1500 điểm\n" 
 BLK "    Ngân lượng: 197000",
										 72:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi cấp 35" BLK " Giao cái cuốc cho ông lão Tôn ở nước Tề\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ông lão Tôn ở nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vì vệ binh vào thành thuận tiện, trước đây ông lão Tôn ở nước Tề đã đến nhà vệ binh, nhờ vệ binh mang cho ông một cái cuốc dùng để trồng trọt, và dặn vệ binh phải chọn một cái vừa tốt vừa rẻ. Vệ binh đã đến chợ chọn lựa rất lâu, cuối cùng chọn được một cái cuốc tốt, giá cả cũng hợp lý. Nhưng vệ binh không có thời gian mang đi giao, nên nhờ tôi mang cái cuốc này đến cho ông lão Tôn. Ông ấy nói với tôi rằng ông lão Tôn đang làm việc ở vườn tược ngoài thành.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 2500 điểm\n" 
 BLK "    Tiềm năng: 65 điểm\n" 
 BLK "    Ngân lượng: 2000",
										 73:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 40" BLK " Tìm Quản gia Tần để trò chuyện\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản gia Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói Quản gia Tần quản lý rất tài tình, cả phủ Đại Vương Tần rộng lớn được ông quản lý đâu ra đấy, chủ nhân và người hầu trên dưới trật tự rõ ràng. Tục ngữ có câu, không có quy củ thì không thành công việc, Tổng quản Tề cảm thấy mình cần phải học hỏi Quản gia Tần về cách quản lý. Để quản lý tốt đám người hầu lớn nhỏ này, quả thực cần phải bỏ ra không ít công sức. Vì vậy, ông ấy nhờ tôi thay mặt đến nước Tần để học hỏi kinh nghiệm quản lý từ Quản gia Tần.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3000 điểm\n" 
 BLK "    Tiềm năng: 70 điểm\n" 
 BLK "    Ngân lượng: 2500",
										 74:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 75" BLK " sẽ truyền đạt lời cảm ơn của vệ binh Tề Quốc đến vệ binh Hàn Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Hàn Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôi cũng không nhớ rõ lắm, liệu vệ binh Hàn Quốc có nhờ tôi gửi lời nhắn đến vệ binh Tề Quốc hay không, hì hì, nhưng không sao, tôi vẫn sẽ truyền đạt lời cảm ơn của anh ấy đến vệ binh Hàn Quốc. Vệ binh Tề Quốc cuối cùng cũng nghĩ đến việc vực dậy tinh thần của mình, hy vọng anh ấy sẽ sớm điều chỉnh được trạng thái, sống tích cực hơn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "      Kinh nghiệm: 25000 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 25000",
										 75:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 90" BLK " tìm thương nhân Ngụy Quốc họ Khổng để hỏi giá vải vóc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân Ngụy Quốc họ Khổng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thương nhân Ngụy Quốc có một lô vải cần bán gấp, và lô vải này không phải bán vì vấn đề chất lượng, mà vì thương nhân Ngụy Quốc muốn chuyển sang làm ăn khác, cần gấp vốn khởi nghiệp, nên mới bán rẻ. Vệ binh Tề Quốc nghĩ đây là cơ hội tốt, có lẽ anh ta có thể mua vào bán ra để kiếm chút lợi nhuận. Anh ta nhờ tôi đi hỏi thương nhân Ngụy Quốc xem giá lô vải đó là bao nhiêu, và dặn dò tôi không được tự ý mua trộm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 33000 điểm\n" 
 BLK "    Tiềm năng: 420 điểm\n" 
 BLK "    Ngân lượng: 25000",
										 76:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 100" BLK " giao anh đào cho Triệu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói Triệu Vương rất thích ăn anh đào, tiếc là Triệu Quốc không sản xuất nhiều loại quả này, nên Triệu Vương ra lệnh thu thập anh đào để thỏa mãn sở thích của mình. Thương nhân Tề Quốc nói rằng gần đây ông ta nhập được một lô hàng tốt, những quả anh đào tươi mọng, hạt nào cũng tròn đầy, màu sắc đẹp mắt. Ông ta muốn tặng cho Triệu Vương, và nói rằng mình không có ý đồ gì khác, chỉ là người làm ăn muốn kiếm chút tiền. Nhưng vì ông ta là người Tề, việc trực tiếp tặng anh đào cho Triệu Vương sẽ không phù hợp, nên nhờ tôi giao anh đào cho Triệu Vương, đồng thời nói rằng phần thưởng của Triệu Vương chắc chắn sẽ chia cho tôi một nửa!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 40000 điểm\n" 
 BLK "    Tiềm năng: 605 điểm\n" 
 BLK "    Ngân lượng: 38000",
										 77:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 100" BLK " hãy giao Nhật ký thử thách cho Tần Quốc Thủ Vệ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Quốc Thủ Vệ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tần Quốc Thủ Vệ dường như rất coi thường Tề Quốc Thủ Vệ, luôn cho rằng họ mới là những người xuất sắc nhất, võ nghệ đứng đầu, sự nhạy bén đứng đầu, v.v. Tề Quốc Thủ Vệ muốn cho Tần Quốc Thủ Vệ biết sự lợi hại của mình, vì vậy quyết định gửi thư khiêu chiến đến Tần Quốc Thủ Vệ, để tiến hành một trận đấu tay đôi giữa những người đàn ông! Anh ta nhờ tôi giao lá thư Nhật ký thử thách này cho Tần Quốc Thủ Vệ!\n" 
										 BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "      Kinh nghiệm: 42000 điểm\n" 
 BLK "    Tiềm năng: 600 điểm\n" 
 BLK "    Ngân lượng: 40000", 77:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "100 cấp后" BLK "将Nhật ký thử thách交给Tần Quốc Thủ Vệ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Quốc Thủ Vệ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    那Tần Quốc Thủ Vệ似乎很瞧不起齐国守卫,总认为他们才是最好的守卫,武艺第一,敏锐第一等等.齐国守卫想让Tần Quốc Thủ Vệ知道他的厉害,所以决定向Tần Quốc Thủ Vệ下战书,来一场男人之间的决斗!他请我将这封Nhật ký thử thách交给Tần Quốc Thủ Vệ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "      Kinh nghiệm :42000 điểm\n" 
 BLK "    Tiềm năng :600 điểm\n" 
 BLK "    Ngân lượng :40000",
]),
								TID_QINGUO:
									([3:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được chuỗi ngọc trai trên người Tôm Binh Cua Tướng rồi giao cho" HIR "Trình Cường ngoài thành Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Cường ngoài thành Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trình Cường chỉ là một thư sinh nghèo khổ, gia cảnh bần hàn, một lần tình cờ nhìn thấy tiểu thư Bối Bối của Tần cung và cảm thấy một sự thương yêu và xót xa chưa từng có.\n" 
 BLK "    Kể từ khi gặp tiểu thư Bối Bối, anh ta ngày đêm mong nhớ, muốn tặng một món quà để bày tỏ lòng mình, nhưng thực sự không có gì đáng giá để tặng.\n" 
 BLK "    Trình Cường nói rằng anh ta luôn muốn tặng tiểu thư Bối Bối một chuỗi ngọc trai, nhưng anh ta không đủ tiền mua, nghe nói" HIR "Tôm Binh Cua Tướng ở làng chài Đông Hải" BLK " có, bạn hãy đi tìm một chuỗi ngọc trai giúp anh ta nhé!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4500 điểm\n" 
 BLK "    Tiềm năng: 140 điểm\n" 
 BLK "    Ngân lượng: 3500",
										 4:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi chuỗi ngọc trai đến cho Bối Bối\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bối Bối ở Tần cung\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trình Cường chỉ là một thư sinh nghèo khổ, gia cảnh bần hàn, một lần tình cờ nhìn thấy tiểu thư Bối Bối của Tần cung và cảm thấy một sự thương yêu và xót xa chưa từng có. Anh ta muốn gửi một món quà làm tín vật cho tiểu thư Bối Bối, nhưng không đủ can đảm để tự mình đi, vì vậy nhờ tôi mang đến cho cô ấy!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4200 điểm\n" 
 BLK "    Tiềm năng: 130 điểm\n" 
 BLK "    Ngân lượng: 3500",
										 6:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi tín vật của Bối Bối đến cho Trình Cường\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Cường ngoài thành Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    May mắn thay, tôi đã nhanh chóng hoàn thành việc tiểu thư Bối Bối giao phó, nếu không sẽ khó ăn nói với Trình Cường. Giờ đây, tiểu thư Bối Bối cũng nhận thấy Trình Cường là một người rất có trách nhiệm, nên dường như có chút cảm tình với anh ta, thậm chí còn nhờ tôi mang bánh ngọt do chính tay cô ấy làm đến cho Trình Cường.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4300 điểm\n" 
 BLK "    Tiềm năng: 138 điểm\n" 
 BLK "    Ngân lượng: 3800\n" 
 BLK "    Vật phẩm: Nón cấp 40",
										 8:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm" HIR "Vệ binh Yên Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ binh Tần Quốc có một người anh trai làm vệ binh ở Yên Quốc, họ đã lâu không gặp nhau và rất nhớ nhau. Họ hy vọng tôi có thể chuyển lời nhung nhớ của mình.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4400 điểm\n" 
 BLK "    Tiềm năng: 140 điểm\n" 
 BLK "    Ngân lượng: 3800",
										 9:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi quà chúc mừng đến" HIR "Tổng quản Triệu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng quản Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Cha của Tổng quản Triệu quả là một người phi thường, đã lớn tuổi mà vẫn có con. Quản gia Tần nhờ bạn thay mặt ông ấy gửi món quà chúc mừng này đến Tổng quản Triệu. Thiếu gia Triệu sinh ra đúng vào dịp đại thọ 80 của cha mình, tương lai chắc chắn sẽ vô cùng rộng mở. Nếu không phải vì quản gia Tần bận rộn, ông ấy nhất định sẽ tự mình đến chúc mừng và thăm hỏi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 265 điểm\n" 
 BLK "    Ngân lượng: 6500",
										10:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi hạt giống đến cho" HIR "Dược sư Tần\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Cuối cùng cũng lấy được hạt giống, cần nhanh chóng gửi đến cho Dược sư Tần.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3830 điểm\n" 
 BLK "    Tiềm năng: 165 điểm\n" 
 BLK "    Ngân lượng: 3560",
										12:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Hạ Hầu Đảng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hạ Hầu Đảng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đừng thấy Hạ Hầu Đảng trong thành này là một tên thổ phỉ mà xem thường, hắn rất tinh thông về chiến thuật. Đại tướng quân vốn muốn chiêu mộ hắn, nhưng hắn nói không hứng thú với quan trường, vì vậy đành phải đi thêm một chuyến, hỏi xem hắn có đề xuất gì hay cho trận chiến lần này. Hắn đang ở" HIR "làng ngoài thành" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6900 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 6600",
										13:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo lại cho Đại tướng quân Tần Quốc Vương Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ý kiến của Hạ Hầu Đảng dường như khá hay, chỉ không biết Đại tướng quân Tần Quốc Vương Tiễn có đồng ý hay không, hãy nhanh chóng báo cáo cho tướng quân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 263 điểm\n" 
 BLK "    Ngân lượng: 6500",
										17:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm thực đơn ở" HIR "Trịnh Quốc Cừ 1" BLK " rồi giao cho" HIR "Mã Hiển ở Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mã Hiển ở Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mở khách sạn dựa vào thực đơn để thu hút khách. Thực đơn làm tốt sẽ khiến khách hàng nhìn thấy là muốn ăn ngay, như vậy mới kiếm được tiền. Mã Hiển nói ngoài tài nấu nướng của mình, thực đơn cũng là linh hồn của khách sạn họ. Vì vậy, bình thường anh ta luôn mang theo bên mình.\n" 
 BLK "    Nhưng hôm trước khi đi chơi, anh ta không cẩn thận làm mất thực đơn, có lẽ đã rơi ở Trịnh Quốc Cừ. Vì vậy, bạn hãy đi xem có thể tìm lại giúp anh ta không, hãy cố gắng hết sức nhé!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4200 điểm\n" 
 BLK "    Tiềm năng: 115 điểm\n" 
 BLK "    Ngân lượng: 3000",
										22:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm" HIR "Lã Bất Vi ở Triệu Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lã Bất Vi ở Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tiểu vệ binh nói Lã Bất Vi ở Triệu Quốc có việc tìm tôi, tôi sẽ đến phủ Triệu xem sao.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3800 điểm\n" 
 BLK "    Tiềm năng: 170 điểm\n" 
 BLK "    Ngân lượng: 3600",
										23:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dò hỏi Quản gia Tần\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản gia Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói gần đây Đại vương Tần định tu sửa cung Cánh Khuyết, đây là một cơ hội tốt. Thợ thủ công Tần Quốc muốn bạn đến chỗ Quản gia Tần để dò hỏi thông tin thực hư.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 11000 điểm\n" 
 BLK "    Tiềm năng: 320 điểm\n" 
 BLK "    Ngân lượng: 9000",
										24:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm bản vẽ cung điện và giao cho Thợ thủ công Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bản vẽ gốc của cung Cánh Khuyết đã bị thất lạc gần" HIR "Đường vòng Tần Trường Thành" BLK ". Bạn hãy đến đó tìm bản vẽ cung điện và giao cho Thợ thủ công Tần Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 12000 điểm\n" 
 BLK "    Tiềm năng: 330 điểm\n" 
 BLK "    Ngân lượng: 9500",
										25:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Gỗ gụ thiên niên kỷ và giao cho" HIR "Thợ thủ công Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thợ thủ công Tần Quốc đã xem kỹ bản vẽ cung điện, sau đó khảo sát tình hình cung Cánh Khuyết, phát hiện một chỗ trong Thái Miếu vốn sử dụng Gỗ gụ thiên niên kỷ đã bị hư hại do binh đao, cần phải thay thế. Nghe nói ở" HIR "Đài hỏa hiệu Tần Trường Thành" BLK " có một cây, bạn hãy đi lấy và mang về.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 12500 điểm\n" 
 BLK "    Tiềm năng: 340 điểm\n" 
 BLK "    Ngân lượng: 10500",
										26:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt ác bá Tần Lão Tứ và báo cáo lại cho Thợ thủ công Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngoài bản vẽ cung điện và gỗ, còn cần đá xanh chất lượng cao từ mỏ đá gần" HIR "Tần Trường Thành" BLK ". Nhưng ác bá Tần Lão Tứ đang kiểm soát việc khai thác đá, thậm chí còn dám không bán cho Đại vương Tần, thật là vì tiền mà mất trí! Thợ thủ công Tần Quốc yêu cầu bạn đến tiêu diệt hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 13000 điểm\n" 
 BLK "    Tiềm năng: 340 điểm\n" 
 BLK "    Ngân lượng: 10000",
										27:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo cho Quan nội chính Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hiện tại mọi thứ đã được chuẩn bị đầy đủ, việc tu sửa cung Cánh Khuyết có thể bắt đầu ngay. Tuy nhiên, trước khi khởi công, cần báo cáo cho Quan nội chính Tần Quốc, bạn hãy đến báo cáo một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 15000 điểm\n" 
 BLK "    Tiềm năng: 360 điểm\n" 
 BLK "    Ngân lượng: 13000",
										28:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm " HIR "Nội chính quan Tần Quốc Cam La\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội chính quan Tần Quốc Cam La\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói gần đây Đại Vương Tần Doanh Chính rất hứng thú với cơ quan thuật, dự định huy động các thợ thủ công tài giỏi trong nước để xây dựng một địa cung tập hợp tinh hoa cơ quan thuật của thiên hạ. Nhưng đồng thời, ngài cũng nghiêm khắc ra lệnh không được làm hao dân tổn tài, gây tổn hại đến nền tảng quốc gia. Nghe được tin này, các thợ thủ công Tần Quốc ngứa ngáy tay chân, muốn tham gia, nhưng không biết kế hoạch cụ thể ra sao. Ngươi có thể đến hỏi thăm Nội chính quan Tần Quốc Cam La xem sao?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 13000 điểm\n" 
 BLK "    Tiềm năng: 350 điểm\n" 
 BLK "    Ngân lượng: 12000",
										28:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm " HIR "Nội chính quan Tần Quốc Cam La\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội chính quan Tần Quốc Cam La\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói gần đây Đại Vương Tần Doanh Chính rất hứng thú với cơ quan thuật, dự định huy động các thợ thủ công tài giỏi trong nước để xây dựng một địa cung tập hợp tinh hoa cơ quan thuật của thiên hạ. Nhưng đồng thời, ngài cũng nghiêm khắc ra lệnh không được làm hao dân tổn tài, gây tổn hại đến nền tảng quốc gia. Nghe được tin này, các thợ thủ công Tần Quốc ngứa ngáy tay chân, muốn tham gia, nhưng không biết kế hoạch cụ thể ra sao. Ngươi có thể đến hỏi thăm Nội chính quan Tần Quốc Cam La xem sao?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 13000 điểm\n" 
 BLK "    Tiềm năng: 350 điểm\n" 
 BLK "    Ngân lượng: 12000",
										29:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm cuốc khai sơn và giao cho" HIR "Thợ thủ công Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói vùng đất đá hỗn loạn ở Lịch Sơn, muốn khai phá xây dựng công trình tại đó mà không có cuốc khai sơn thì rất phiền phức. Lần này, Đại vương Tần Doanh Chính đã phân phát nhiều cuốc khai sơn, đặt tại" HIR "Đài hỏa hiệu Tần Trường Thành" BLK " để Thợ thủ công Tần Quốc tự đến nhận. Bạn có sẵn lòng giúp anh ta lấy cuốc khai sơn về không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 14000 điểm\n" 
 BLK "    Tiềm năng: 360 điểm\n" 
 BLK "    Ngân lượng: 13000",
										30:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi thư cho Đại vương Tần Doanh Chính\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại vương Tần Doanh Chính\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thợ thủ công Tần Quốc xem việc xây dựng địa cung cơ quan Lịch Sơn lần này là cơ hội để thể hiện tài năng. Mọi vật tư đã được chuẩn bị đầy đủ, bạn hãy giao lá thư xây dựng này cho Đại vương Tần Doanh Chính, để Đại vương Tần Doanh Chính ban chiếu chỉ xây lăng mộ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 15000 điểm\n" 
 BLK "    Tiềm năng: 370 điểm\n" 
 BLK "    Ngân lượng: 14000",
										31:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thoát khỏi kẻ bắt nạt Trương Cửu và báo cáo cho" HIR "Thợ thủ công Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại vương đã ra lệnh bắt đầu xây dựng, dân chúng lập tức khởi công. Nhưng vật liệu đá dùng để xây dựng bị Trương Phú chiếm giữ, bạn hãy đến" HIR "Đài hỏa hiệu Tần Trường Thành" BLK " để trừ khử hắn, sau khi trừ khử thì thông báo cho Thợ thủ công Tần Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 15500 điểm\n" 
 BLK "    Tiềm năng: 370 điểm\n" 
 BLK "    Ngân lượng: 15000",
										32:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo cho Quan nội chính Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mọi thứ liên quan đến địa cung Lịch Sơn đã sẵn sàng, chỉ còn thiếu văn bản phê chuẩn nội chính. Bạn hãy báo cáo tin tức này cho Quan nội chính Tần Quốc, hy vọng ông ta có thể sớm phê chuẩn văn bản.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 16000 điểm\n" 
 BLK "    Tiềm năng: 380 điểm\n" 
 BLK "    Ngân lượng: 15500",
										33:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo cho Đại vương Tần Doanh Chính\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại vương Tần Doanh Chính\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hiện nay Tề Quốc liên minh với các nước khác mưu toan chống lại nước ta. Sứ giả Tần Quốc cho rằng Tần Quốc và Triệu Quốc vốn cùng gốc rễ, đều là con cháu của đại thần Si Vưu. Nếu sửa chữa mối quan hệ với Triệu Quốc sẽ là điều dễ dàng nhất, hơn nữa anh em đồng lòng thì lợi ích sẽ lớn lao. Điều này không chỉ phá vỡ kế hoạch của Tề Quốc liên minh sáu nước chống lại chúng ta, mà còn giúp Triệu Quốc và Tần Quốc cùng hưởng lợi từ thương mại và tài nguyên khoáng sản, mang lại lợi ích đôi bên.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 17000 điểm\n" 
 BLK "    Tiềm năng: 380 điểm\n" 
 BLK "    Ngân lượng: 16000",
										34:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt gian tế Thạch Thất và báo cáo cho" HIR "Sứ giả Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sứ giả Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại vương đã ra lệnh cho Sứ giả Tần Quốc đi sứ Triệu Quốc, Sứ giả Tần Quốc nhất định sẽ dốc toàn lực hoàn thành trọng trách này. Nghe nói có một gian tế tên Thạch Thất chuẩn bị ám hại ông ta, bạn hãy đến" HIR "Đường vòng Tần Trường Thành" BLK " để tiêu diệt hắn, sau khi tiêu diệt thì thông báo cho Sứ giả Tần Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 16500 điểm\n" 
 BLK "    Tiềm năng: 370 điểm\n" 
 BLK "    Ngân lượng: 16000",
										35:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thư đi sứ cho Sứ giả Triệu Quốc Mao Toại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sứ giả Triệu Quốc Mao Toại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mặc dù Tần Quốc và Triệu Quốc là anh em đồng tông, nhưng lần đi sứ này, Sứ giả Tần Quốc hy vọng có thể hoàn thành trọng trách một cách xuất sắc, tăng cơ hội thành công. Trước đây ông ta từng có chút giao tình với Sứ giả Triệu Quốc Mao Toại. Nếu Mao Toại có thể nói giúp vài lời bên cạnh Triệu Vương, sẽ giảm bớt khó khăn cho Sứ giả Tần Quốc. Nhưng hành trình của đoàn sứ giả đã được định sẵn, bạn có thể thay tôi giao lá thư đi sứ này cho Sứ giả Triệu Quốc Mao Toại trước được không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 17000 điểm\n" 
 BLK "    Tiềm năng: 390 điểm\n" 
 BLK "    Ngân lượng: 17000",
										36:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dò hỏi ý định của Triệu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Việc được đề cập trong thư, Sứ giả Triệu Quốc Mao Toại đã tâu lên Triệu Vương. Về phần quyết định ra sao, bạn nên tự mình đến dò hỏi Triệu Vương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 17500 điểm\n" 
 BLK "    Tiềm năng: 380 điểm\n" 
 BLK "    Ngân lượng: 19000",
										37:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thư trả lời cho Đại vương Tần Doanh Chính\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại vương Tần Doanh Chính\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân Tần Quốc Vương Tiễn trấn thủ biên quan nhiều năm, trung thành tuyệt đối với Đại vương Tần Doanh Chính, mới giữ được Tần Trường Thành không bị thất thủ, ngăn cản quân Khuyển Nhung xâm phạm vùng đất phì nhiêu Quan Trung. Gần đây có kẻ vu khống ông trước mặt Đại vương Tần Doanh Chính, nói rằng ông nắm binh quyền tự trọng, không tuân lệnh, thậm chí còn thông đồng với Khuyển Nhung. Điều này khiến ông oan ức và phẫn nộ. Đại vương Tần Doanh Chính lại bị lời gièm pha làm lung lay, trách phạt ông nhiều lần. Bạn hãy thay ông mang lá thư quân sự này đến cho Quan nội chính Cam La, nhờ ông ta biện minh trước Đại vương, tránh để ông rơi vào bẫy của kẻ tiểu nhân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 18000 điểm\n" 
 BLK "    Tiềm năng: 400 điểm\n" 
 BLK "    Ngân lượng: 19000",
										38:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm Quan nội chính và gửi thư\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân Tần Quốc trấn thủ biên quan nhiều năm, trung thành tuyệt đối với Đại vương Tần. Gần đây có kẻ vu khống ông trước mặt Đại vương Tần, khiến Đại vương rõ ràng có ý bất mãn với ông. Bạn hãy mang lá thư của tướng quân này đến cho Quan nội chính Tần Quốc, Đại tướng quân muốn bàn bạc với ông ta xem nên xử lý việc này thế nào.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 19000 điểm\n" 
 BLK "    Tiềm năng: 390 điểm\n" 
 BLK "    Ngân lượng: 20000",
										39:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt gian tặc Diệp Cửu và báo cáo cho" HIR "Quan nội chính Tần Quốc Cam La\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính Tần Quốc Cam La\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quan nội chính Tần Quốc Cam La nói rằng quả thực có nhiều kẻ tiểu nhân nói xấu Đại tướng quân Tần Quốc Vương Tiễn trước mặt Đại vương Tần Doanh Chính. Sau khi điều tra kỹ lưỡng, ông phát hiện kẻ nhảy nhót tích cực nhất là" HIR "gian tặc Diệp Cửu" BLK ". Hắn ta chức vị không cao, bình thường cũng có nhiều kẻ thù. Hiện tại hắn đang một mình ở khu vực" HIR "Đài hỏa hiệu Tần Trường Thành" BLK ", dường như đang âm mưu điều gì. Quan nội chính Tần Quốc Cam La yêu cầu bạn đóng giả làm thích khách để ám sát hắn, nhằm dẫn dụ con cá lớn phía sau sa lưới.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 20000 điểm\n" 
 BLK "    Tiềm năng: 400 điểm\n" 
 BLK "    Ngân lượng: 21000",
										40:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thư cho Ngự sử Tần Quốc Lý Tư\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự sử Tần Quốc Lý Tư\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Để hoàn toàn minh oan cho Đại tướng quân, cần phải giải thích rõ ràng việc này với Ngự sử Tần Quốc Lý Tư, để ông ta tâu lên Đại vương Tần Doanh Chính, đó mới là thượng sách.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 21000 điểm\n" 
 BLK "    Tiềm năng: 410 điểm\n" 
 BLK "    Ngân lượng: 22000",
										41:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao tấu thư cho Đại vương Tần Doanh Chính\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại vương Tần Doanh Chính\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngự sử có một tấu thư, trong đó trình bày rõ ràng việc Đại tướng quân bị oan ức. Bạn hãy giao tấu thư này cho Đại vương Tần Doanh Chính, sau khi đọc xong, Đại vương Tần Doanh Chính chắc chắn sẽ trả lại công đạo cho Đại tướng quân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 22000 điểm\n" 
 BLK "    Tiềm năng: 410 điểm\n" 
 BLK "    Ngân lượng: 21000",
										42:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt tiểu nhân Hứa Tử Cao và báo cáo cho" HIR "Điển ngục quan Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Điển ngục quan Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại vương Tần Doanh Chính, với tư cách là vua một nước, đương nhiên không dễ dàng thừa nhận sai lầm của mình, nên đã đổ trách nhiệm lên Hứa Tử Cao. Ông ta yêu cầu bạn đến Đài hỏa hiệu để xử tử hắn tại chỗ, sau đó báo cáo cho Điển ngục quan Tần Quốc để lưu hồ sơ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 23000 điểm\n" 
 BLK "    Tiềm năng: 420 điểm\n" 
 BLK "    Ngân lượng: 22000",
										43:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dò hỏi tin tức từ Tần Tổng Quản\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, dân chúng Tần Quốc là Trọng Mạc tình cờ gặp con gái của một người làm việc trong cung Đại vương. Cô ta thì thầm rằng trong cung Tần có yêu ma quấy phá, nhưng khi thấy cung nữ đến tìm thì không dám nói thêm, vội vàng rời đi. Có lẽ lúc này Tần cung sẽ chiêu mộ dũng sĩ trừ yêu. Bạn có thể thử vận may, trước tiên hãy đến dò hỏi Tần Tổng Quản xem sao.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 22000 điểm\n" 
 BLK "    Tiềm năng: 410 điểm\n" 
 BLK "    Ngân lượng: 21000",
										44:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR "Yêu tinh quái vật" BLK " và báo cáo cho Tần Tổng Quản\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thái tử Tần cung bị một nam tử yêu mị do yêu tinh ngàn năm hóa thành mê hoặc. Dù Đại vương Tần Doanh Chính thường xuyên mời những người biết chút đạo thuật đến bí mật đối phó, nhưng sau khi phá được pháp thuật của vài người, yêu tinh ngàn năm hóa thành nam tử kia cảm thấy Tần cung không phải nơi ở lâu dài, bèn tự rời đi. Tuy nhiên, Hoàng hậu vẫn phát hiện Thái tử thường tìm cớ ra ngoài đến khu vực" HIR "Đường vòng Tần Trường Thành" BLK ". Có người phát hiện Thái tử vẫn qua lại với nam tử do yêu tinh ngàn năm hóa thành. Những người tự xưng là bậc thầy đạo thuật không phải đối thủ của yêu tinh này. Dũng sĩ, liệu bạn có thể trừ yêu diệt ma, cứu Thái tử điện hạ của chúng ta không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 23000 điểm\n" 
 BLK "    Tiềm năng: 430 điểm\n" 
 BLK "    Ngân lượng: 23000",
										46:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi thư khuyên can cho Quan nội chính Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" 
										HIR "Quan nội chính Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Việc Đại vương Tần Doanh Chính sát phạt như vậy e rằng sẽ khiến các tướng sĩ thề chết trung thành với ông lạnh lòng. Hơn nữa, Trường Thành là trọng điểm chiến lược để ngăn chặn quân Khuyển Nhung xâm lược Quan Trung. Nếu quân tâm của các tướng sĩ không ổn định, không chỉ dân chúng trong và ngoài Trường Thành chịu thiệt hại, mà xã tắc của Đại vương Tần Doanh Chính cũng bị ảnh hưởng. Điển ngục quan Tần Quốc vừa viết một lá thư khuyên can, bạn hãy chuyển cho Quan nội chính để ông ta thay mặt nhắc nhở Đại vương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 25000 điểm\n" 
 BLK "    Tiềm năng: 420 điểm\n" 
 BLK "    Ngân lượng: 24000",
										47:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Trừ khử tên cướp Võ Tam và báo cáo cho" HIR "Ngự sử Tần Quốc Lý Tư\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự sử Tần Quốc Lý Tư\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, gia đình Quan nội chính Tần Quốc Cam La thường xuyên bị bọn cướp đe dọa, yêu cầu ông ta không can thiệp vào việc sát phạt binh sĩ lần này. Dù chưa rõ kẻ chủ mưu phía sau là ai, nhưng ông đã điều tra được kẻ đe dọa là" HIR "tên cướp Võ Tam" BLK ", chuyên cướp bóc người qua đường ở khu vực" HIR "Đường vòng Tần Trường Thành" 
										BLK ". Ông ta yêu cầu bạn giúp bắt giữ hắn để tra hỏi kẻ chủ mưu, nhưng với loại người hung ác này, bạn thấy chẳng cần phí sức tra hỏi, cứ một đao giết cho sạch sẽ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 25500 điểm\n" 
 BLK "    Tiềm năng: 430 điểm\n" 
 BLK "    Ngân lượng: 24000\n" 
 BLK "    Vật phẩm: Y Phục cấp 70", 51:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    找周国守卫要到Cây cúc交给" HIR "秦国百姓仲莫\n" BLK "Người hoàn thành nhiệm vụ:" HIR "秦国百姓仲莫\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    九月称为菊月,重阳日称为菊节.乡俗这一日,设Cây cúc宴, điểmCây cúc灯,饮Cây cúc茶,品Cây cúc酒,睡Cây cúc枕,可百病不生,长生不老.上次周国守卫说他老娘开了个很大的花圃,里面就有不少Cây cúc,他早已允诺送秦国百姓仲莫一 điểm了,你就辛苦跑一趟,帮他弄来吧.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "      Kinh nghiệm :7000 điểm\n" 
 BLK "    Tiềm năng :260 điểm\n" 
 BLK "    Ngân lượng :7500",
										52:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi Cây cúc đến chỗ " HIR "dân chúng Tần Quốc Trọng Mạch" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng Tần Quốc Trọng Mạch\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta đã lấy được Cây cúc từ chỗ vệ binh Chu Quốc, ta cần nhanh chóng gửi đến chỗ dân chúng Tần Quốc Trọng Mạch, tránh để hắn phải chờ lâu mà sốt ruột.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7000 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 7500",
										54:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm " HIR "Lý Đại Mao nước Ngụy\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đại Mao nước Ngụy\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói có một loại bầu lớn, có thể chứa được năm thạch, chỉ có Lý Đại Mao ở nước Ngụy mới có hạt giống. Dược sư Tần nói rằng nếu ta có thể xin được hạt giống, khi bầu được trồng thành công, ông ấy chắc chắn sẽ tặng ta một quả.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3800 điểm\n" 
 BLK "    Tiềm năng: 165 điểm\n" 
 BLK "    Ngân lượng: 3550",
										64:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ Tần Lão Hán\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Lão Hán\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quản gia Tần nhận tin rằng Đao Hồn trong Tru Tiên Trận mỗi ngày mười hàng tháng lại thoát khỏi trận pháp, gây ra những vụ thảm sát kỳ dị ở thị trấn Bình Dương. Nạn nhân, chủ yếu là thanh niên, chết trong tư thế như đang ngủ, nét mặt mang nụ cười quỷ dị. Dân chúng kinh hoàng, bỏ xứ mà đi, khiến Bình Dương trở thành vùng đất ai cũng khiếp sợ. Quản gia nghi ngờ có tà đạo lợi dụng Đao Hồn để hút sinh hồn, âm mưu có thể ảnh hưởng đến vận mệnh Đại Tần. Là nghĩa sĩ Đại Tần, bạn được lệnh lập tức điều tra vụ việc. Trước tiên, hãy tìm gặp Tần Lão Hán – người sống lâu năm tại đây, am hiểu tình hình – để hỏi thăm manh mối.\n" 
										BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 82000 điểm\n" 
 BLK "    Tiềm năng: 980 điểm\n" 
 BLK "    Ngân lượng: 68000",
										66:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm kết quả từ Mã Hiển\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mã Hiển\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mã Hiển ở thị trấn Bình Dương từng dặn rằng nếu tiêu diệt được Tiển Cửu, cần báo cho ông ta biết để ông ta bói một quẻ cho tương lai của Bình Dương. Tần Lão Hán đã phái người thông báo cho ông ta rồi, giờ ngươi hãy đến nhờ ông ta bói một quẻ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 85000 điểm\n" 
 BLK "    Tiềm năng: 810 điểm\n" 
 BLK "    Ngân lượng: 98000",
										68:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thông báo cho Quản gia Tần rằng nguy hiểm đã được giải trừ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản gia Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tru Tiên Trận đã được khôi phục bình thường, Đao Hồn tạm thời không thể tự do chạy loạn nữa. Mã Hiển bảo ngươi báo cáo với Quản gia Tần rằng nguy hiểm ở thị trấn Bình Dương đã được giải trừ, dân chúng cũng có thể trở về quê hương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 92000 điểm\n" 
 BLK "    Tiềm năng: 1100 điểm\n" 
 BLK "    Ngân lượng: 93000",
										69:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ Dược sư Tần\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thời buổi này thật lắm drama, Ngự sử bị các vụ án trên thẻ tre làm cho焦头烂额. Hy vọng ngươi có thể giúp ông ta chia sẻ gánh nặng. Có nhiều vụ án giết người được lý chính Bình Dương báo cáo, nhưng đều không rõ ràng, những người biết chuyện đều im lặng. Từ sau vụ Đao Hồn ở Bình Dương quấy rối, mọi thứ đã yên bình một thời gian, không ngờ gần đây lại nổi sóng gió. Ngươi đi điều tra xem sao, nghe nói Dược sư Tần biết rõ nội tình, ngươi tìm cách hỏi ông ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 89000 điểm\n" 
 BLK "    Tiềm năng: 950 điểm\n" 
 BLK "    Ngân lượng: 91000",
										73:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi thư Bình Dương cho Ngự sử Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự sử Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thị trấn Bình Dương giờ đã được giải trừ tai họa, mọi người lại có thể an cư lạc nghiệp. Trình Cường đã viết một bản tấu trình bày những sự việc gần đây, nhờ ngươi gửi đến Ngự sử Tần Quốc để ông ta yên tâm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 94000 điểm\n" 
 BLK "    Tiềm năng: 950 điểm\n" 
 BLK "    Ngân lượng: 92000",
										74:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến thị trấn Bình Dương thăm Dược sư Tần\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dược sư Tần đang luyện tiên đan cho Đại Vương Tần, nghe nói gặp chút rắc rối. Ông ta yêu cầu Quản gia Tần phái người hỗ trợ, và ông ta nhờ ngươi đến giúp Dược sư Tần.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 98000 điểm\n" 
 BLK "    Tiềm năng: 1010 điểm\n" 
 BLK "    Ngân lượng: 91000",
										76:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi công thức luyện dược cho Hạ Hầu Đảng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hạ Hầu Đảng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hạ Hầu Đảng là bạn tri giao nhiều năm của Dược sư Tần, rất am hiểu về dược lý và tính chất thuốc. Dược sư Tần lo rằng công thức đan dược có chỗ chưa hoàn thiện, nên bảo ngươi mang công thức này giao cho Hạ Hầu Đảng, hỏi ý kiến của ông ta, rồi quay về báo lại cho Dược sư Tần.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 87000 điểm\n" 
 BLK "    Tiềm năng: 920 điểm\n" 
 BLK "    Ngân lượng: 91000",
										78:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Truyền tin cho Hạ Hầu Đảng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hạ Hầu Đảng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nhờ có vị thuốc điểm xuyết của Hạ Hầu lão đệ, Dược sư Tần cuối cùng cũng luyện được tiên đan để dâng lên Đại Vương Tần. Chỉ cần chờ thêm một ngày một đêm, đan dược sẽ ra lò. Ông ta thay ta gửi lời cảm tạ đến Hạ Hầu Đảng, bảo rằng khi đan dược ra lò, Dược sư Tần sẽ mời ông ta đến Tử Quỳnh Các uống rượu Tiên Nhân Túy!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 86000 điểm\n" 
 BLK "    Tiềm năng: 1000 điểm\n" 
 BLK "    Ngân lượng: 91000",
										79:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ Mã Hiển\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mã Hiển\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây ngoài thành lại có người đồn rằng Vương Phi Đại Vương là do yêu tước hóa thành, chuyên đến mê hoặc Đại Vương Tần. Vương Phi là người được trời phó thác, mẫu nghi thiên hạ, vậy mà lại có kẻ dám coi thường quyền uy Đại Vương, tung tin đồn nhảm, đặt uy nghiêm nhà Đại Vương vào đâu! Ngự sử đại nhân ra lệnh cho ngươi nhanh chóng điều tra việc này. Mã Hiển ở thị trấn Bình Dương luôn tận tụy với công việc, trung thành với triều đình, ngươi có thể đến hỏi ông ta về nguồn gốc sự việc trước.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 87000 điểm\n" 
 BLK "    Tiềm năng: 1100 điểm\n" 
 BLK "    Ngân lượng: 90000",
										80:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Chất vấn Nghiện Tử\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nghiện Tử\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Qua nhiều ngày quan sát của Mã Hiển, những tin đồn này đều do Nghiện Tử ở phía bắc thị trấn Bình Dương nói năng bừa bãi. Ông ta bảo ngươi nên chất vấn kỹ lưỡng xem rốt cuộc là ai sai khiến hắn. Cẩn thận, gã này không hề thành thật, ngươi nhất định phải moi được sự thật, đừng để hắn lừa gạt mà cắn lung tung. Nhưng thà giết nhầm còn hơn bỏ sót, nếu hắn cứ một mực nói bậy, cũng chẳng có cách nào, ngươi tự cân nhắc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 91000 điểm\n" 
 BLK "    Tiềm năng: 1200 điểm\n" 
 BLK "    Ngân lượng: 88000",
										82:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm Tần Lão Hán\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Lão Hán\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghiện Tử khai rằng hôm đó hắn đến dưới lầu Tử Yên xin rượu uống, tình cờ gặp Đại Vương Tần tuần du, Tần Lão Hán cũng ở trong đám đông. Mọi người thấy Vương Phi thì kinh ngạc như tiên nữ, uống chút rượu vào, thần trí mơ hồ, liền bịa chuyện lung tung. Sau đó mọi người rảnh rỗi, càng bịa càng huyền. Nghiện Tử thề thốt rằng tuyệt đối không có ý phản nghịch, cầu xin ngươi rộng lượng, nói tốt vài câu cho hắn. Nếu không tin, ngươi có thể đi hỏi Tần Lão Hán, ông ta có thể làm chứng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 95000 điểm\n" 
 BLK "    Tiềm năng: 1200 điểm\n" 
 BLK "    Ngân lượng: 97000",
										83:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi thư nhận tội cho Ngự sử Tần Quốc Lý Tư\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự sử Tần Quốc Lý Tư\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tần Lão Hán nghe lời Nghiện Tử thì kinh hoàng thất sắc, như người mất hồn, sau đó vội vàng thanh minh và viết một lá thư nhận tội, nhờ ngươi giao cho Ngự sử. Nhưng liệu mọi chuyện có đơn giản như vậy mà kết thúc không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 96000 điểm\n" 
 BLK "    Tiềm năng: 1300 điểm\n" 
 BLK "    Ngân lượng: 95000",
										84:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm Đại tướng quân Tần Quốc Đại Vương Tiễn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Tần Quốc Đại Vương Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngự sử Tần Quốc nghe nói gần đây Đại tướng quân có chút tâm sự, nhưng ông ta không nắm quân vụ, không tiện hỏi trực tiếp. Ngươi thay Ngự sử đến thăm, hỏi Đại tướng quân xem có cần giúp gì không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 97000 điểm\n" 
 BLK "    Tiềm năng: 1200 điểm\n" 
 BLK "    Ngân lượng: 94000",
										85:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi thăm tin tức từ Hạ Hầu Đảng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hạ Hầu Đảng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân Tần Quốc nghe nói gần đây có một thanh thần kiếm xuất thế. Tự cổ thần kiếm xứng tướng quân, ông rất muốn mang theo thanh kiếm này khi ra trận giết địch. Nhưng nghe nói hiện tại nhiều thế lực đang nhòm ngó, mà ông vì trách nhiệm không dám rời bỏ nhiệm vụ, chỉ phái vài tay chân đắc lực đi tìm kiếm nhưng đều không thấy tăm hơi. Ông đang lo lắng, sợ lại bỏ lỡ thần kiếm. Ông nhờ ngươi tìm kiếm thần kiếm cho ông. Hạ Hầu Đảng ở thị trấn Bình Dương ngoài thành biết rõ về việc này, ngươi đến hỏi ông ta xem.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 98000 điểm\n" 
 BLK "    Tiềm năng: 1400 điểm\n" 
 BLK "    Ngân lượng: 91000",
										88:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Báo cáo cho Đại Vương Tần Doanh Chính\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Vương Tần Doanh Chính\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân Tần Quốc nhận được thần kiếm trời ban, đây là điềm trời phù hộ Tần Quốc. Đại tướng quân chắc chắn sẽ bách chiến bách thắng, giúp Đại Vương Tần bình định thiên hạ, quét sạch lục hợp! Hãy truyền lời này đến Đại Vương Tần!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 100000 điểm\n" 
 BLK "    Tiềm năng: 1500 điểm\n" 
 BLK "    Ngân lượng: 93000",
										89:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi viên ngọc cam tinh hoàn hảo đã luyện chế cho Triệu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lần đầu luyện dược, Dược sư Tần đã thành công, nhưng ông ta thành thật rằng việc cải tử hoàn sinh chỉ là lời tuyên truyền của sư huynh. Thực tế, viên ngọc này đeo bên mình cũng chỉ giúp kéo dài tuổi thọ. Nhưng ta nghĩ, một người thông minh như đại hiệp ngươi chắc chắn biết cách báo cáo với Triệu Vương, không để Dược sư Tần và ngươi bị liên lụy vào tội lừa dối. Dù sao Dược sư Tần ở xa tại Tần Quốc có thể tránh khỏi, nhưng khi ngươi báo cáo lại, có thể sẽ bị Triệu Vương chém đầu. Hy vọng chúng ta hợp tác vui vẻ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 200000 điểm\n" 
 BLK "    Tiềm năng: 2250 điểm\n" 
 BLK "    Ngân lượng: 200000\n" 
 BLK "    Vật phẩm: Hạng liên cấp 100",
										90:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau cấp 40" BLK " Gửi nho tím cho Tổng quản Yên\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng quản Yên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tổng quản Yên vốn thích ăn nho, khi nghe nói Vệ binh Tần Quốc trồng được nhiều nho tím, ông ta thèm thuồng, liên tục nhờ người mua nho từ Vệ binh Tần Quốc. Nhưng nho chưa chín, Vệ binh Tần Quốc dĩ nhiên không bán, nếu không sẽ làm mất danh tiếng. Giờ nho đã chín, Vệ binh Tần Quốc muốn tặng một chùm cho Tổng quản Yên nếm thử, đợi ông ta thấy đáng giá rồi mua sau cũng không muộn. Vì vậy, Vệ binh Tần Quốc nhờ ta mang nho đến cho Tổng quản Yên.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4000 điểm\n" 
 BLK "    Tiềm năng: 130 điểm\n" 
 BLK "    Ngân lượng: 4000",
										91:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau cấp 70" BLK " Tìm Tổng quản Hàn của nước Hàn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng quản Hàn của nước Hàn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thật kỳ lạ, ta với Tổng quản Hàn của nước Hàn không thân không thích, không oán không thù, chưa từng gặp mặt, vậy hắn tìm ta để làm gì? Nghe nói còn tốn không ít công sức! Ta phải nhanh chóng đi xem, rốt cuộc Tổng quản Hàn này có ý đồ gì!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 20000 điểm\n" 
 BLK "    Tiềm năng: 210 điểm\n" 
 BLK "    Ngân lượng: 22000",
										92:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau cấp 100" BLK " Truyền ý hòa giải của Vệ binh Tần Quốc cho dân chúng Triệu Quốc Ngô Cơ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng Triệu Quốc Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Em trai của dân chúng Triệu Quốc từng cùng làm việc với Vệ binh Tần Quốc trong triều đình, họ từng là huynh đệ đồng cam cộng khổ. Nếu không có chuyện đó, có lẽ giờ họ vẫn cùng nhau uống rượu, ăn thịt. Chính vì Vệ binh Tần Quốc ép buộc mà em trai dân chúng Triệu Quốc quyết định bỏ chức vệ binh, lưu lạc đến Triệu Quốc, làm một người dân bình thường. Vệ binh Tần Quốc hy vọng lời xin lỗi của mình có thể khiến người kia trở lại Tần Quốc, nhưng tự mình không thể mở lời, nên nhờ ta thay mặt truyền đạt ý hòa giải này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 45000 điểm\n" 
 BLK "    Tiềm năng: 610 điểm\n" 
 BLK "    Ngân lượng: 40000",
										93:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau cấp 110" BLK " Truyền ý của dân chúng Tần Quốc Trọng Mạch cho Đại tướng quân Yên Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đàn ông đại trượng phu, không nên sống vô công rỗi nghề. Dân chúng Tần Quốc Trọng Mạch nói rằng mình sống đến giờ vẫn chưa làm nên sự nghiệp lớn, ở Tần Quốc sống ngày tháng bình lặng, chẳng làm được gì. Hắn hy vọng một ngày nào đó có thể trở thành tướng quân, tung hoành sa trường, chứ không mãi ở nhà cày cấy. Hắn nghĩ, muốn làm tướng quân thì phải bắt đầu từ lính trơn. Nghe nói quân đội Yên Quốc đang cần binh sĩ, lần này hắn豁出去了, dù quan hộ tịch có biết mà trục xuất hắn, hắn cũng không màng. Hắn nhờ ta đến hỏi Đại tướng quân Yên Quốc xem có chuyện này không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 48000 điểm\n" 
 BLK "    Tiềm năng: 610 điểm\n" 
 BLK "    Ngân lượng: 45000",
										94:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau cấp 110" BLK " Mang lời nhắn của Thợ thủ công Tần Quốc đến cho Đại tướng quân Triệu Quốc Lý Mục\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Triệu Quốc Lý Mục\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thợ thủ công Tần Quốc nói rằng trước đây Đại tướng quân Triệu Quốc từng dặn ông ta một việc, dĩ nhiên là bí mật, không thể nói cho ta. Giờ việc này Thợ thủ công Tần Quốc đã hoàn thành, vì là cơ mật, ông ta không thể tự mình báo tin cho Đại tướng quân Triệu Quốc. Ta chỉ cần tìm Đại tướng quân Triệu Quốc và nói rằng việc của thợ thủ công đã xong. Thợ thủ công Tần Quốc còn nói Đại tướng quân Triệu Quốc chắc chắn sẽ thưởng lớn cho ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 50000 điểm\n" 
 BLK "    Tiềm năng: 610 điểm\n" 
 BLK "    Ngân lượng: 48000",
]),
								TID_YANGUO:
									([1:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR "Oán Ma" BLK " rồi báo cho " HIR "Yên Quốc Bá Tánh" BLK " một tiếng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Yên Quốc Bá Tánh\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Khu vực " HIR "Trịnh Quốc Cừ" BLK " có gió âm u, oán khí ngút trời, khiến dân chúng hoảng loạn bất an. Chắc chắn là do Oán Ma gây ra. Hãy đến đó tiêu diệt Oán Ma và sau đó thông báo cho Yên Quốc Bá Tánh một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4500\n" 
 BLK "    Tiềm năng: 180\n" 
 BLK "    Ngân lượng: 4000\n",
										 2:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dạy cho tên cai đầu dài độc ác " HIR "Hồ Sơn" BLK " một bài học rồi báo cho " HIR "Yên Quốc Thợ Thủ Công" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Yên Quốc Thợ Thủ Công\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Yên Quốc Thợ Thủ Công làm việc cật lực để xây dựng công trình cho quốc gia, vậy mà tên cai đầu dài Hồ Sơn thường xuyên đánh mắng và cố ý tìm cách trừ tiền công của họ. Hãy đến " HIR "Trịnh Quốc Cừ" BLK " dạy cho tên cai đầu dài độc ác Hồ Sơn một bài học, sau đó thông báo cho " HIR "Yên Quốc Thợ Thủ Công" BLK " một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4600\n" 
 BLK "    Tiềm năng: 170\n" 
 BLK "    Ngân lượng: 3900\n",
										 3:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Bảo Long Châu và giao cho " HIR "Chủ Tiệm Rượu Yên Quốc Tàng Tôn" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Rượu Yên Quốc Tàng Tôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Từ rất lâu về trước, từng có một con giao long thường xuất hiện ở khu vực Trịnh Quốc Cừ. Trong một lần vui chơi, nó vô tình làm rơi Bảo Long Châu quý giá của mình tại đó và tìm mãi không thấy. Cuối cùng, nó buồn bã mà chết…\n" 
 BLK "    Sau này, giang hồ đồn đại rằng Bảo Long Châu có thể tăng cường nội lực võ thuật, nên mọi người đổ xô đi tìm, nhưng đến nay chưa ai tìm được. Hãy thử vận may của mình, biết đâu bạn sẽ tìm thấy?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4700 điểm\n" 
 BLK "    Tiềm năng: 180 điểm\n" 
 BLK "    Ngân lượng: 4000\n",
										 4:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Quỷ Mị rồi báo cho " HIR "Tào Thanh" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tào Thanh\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, nhiều người đi qua Trịnh Quốc Cừ bỗng dưng mất tích một cách kỳ lạ, khiến " HIR "Trịnh Quốc Cừ" BLK " bị bao phủ bởi một lớp bóng tối kinh hoàng. Chắc chắn là do Quỷ Mị gây ra. Hãy đến đó tiêu diệt Quỷ Mị và sau đó thông báo cho Tào Thanh một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4900 điểm\n" 
 BLK "    Tiềm năng: 160 điểm\n" 
 BLK "    Ngân lượng: 4100\n",
										 5:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Linh Lung Ngọc và giao cho " HIR "Trình Phong" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Phong\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trình Phong trong lúc đi qua Trịnh Quốc Cừ đã vô tình làm mất bảo vật gia truyền Linh Lung Ngọc tại đó. Hãy đến tìm lại bảo vật đó và trả lại cho anh ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4800 điểm\n" 
 BLK "    Tiềm năng: 170 điểm\n" 
 BLK "    Ngân lượng: 4200\n",
										 6:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt " HIR "Thiên Tầng Quái" BLK " rồi báo cho " HIR "Chủ Tiệm Vũ Khí Yên Quốc Từ Phu Nhân" BLK "\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói có người mất tích ở khu vực " HIR "Trịnh Quốc Cừ" BLK ", chắc chắn là do Thiên Tầng Quái gây ra. Hãy đến đó tiêu diệt con yêu quái này, sau đó thông báo cho Chủ Tiệm Vũ Khí Yên Quốc Từ Phu Nhân một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5000 điểm\n" 
 BLK "    Tiềm năng: 180 điểm\n" 
 BLK "    Ngân lượng: 4500\n",
										 7:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt " HIR "Thủy Mị" BLK " rồi báo cho " HIR "Chủ Tiệm Sửa Chữa Yên Quốc Phàn Vu Kỳ" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Sửa Chữa Yên Quốc Phàn Vu Kỳ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ở " HIR "Trịnh Quốc Cừ" BLK " có tiếng khóc của phụ nữ, chắc chắn là do Thủy Mị đang dụ dỗ người đi đường. Hãy đến đó tiêu diệt Thủy Mị, sau khi tiêu diệt xong thì thông báo cho " HIR "Chủ Tiệm Sửa Chữa Yên Quốc Phàn Vu Kỳ" BLK " một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5200 điểm\n" 
 BLK "    Tiềm năng: 190 điểm\n" 
 BLK "    Ngân lượng: 4600\n",
										 8:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dạy cho tên ác bá " HIR "Trương Sơn" BLK " một bài học rồi báo cho " HIR "Lưu Lão Bản" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lưu Lão Bản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Làm ăn tuy kiếm được tiền nhưng cũng rất vất vả, phải chạy đông chạy tây, gặp cướp trên đường là chuyện thường tình.\n" 
 BLK "    Tháng trước, Lưu Lão Bản trên đường làm ăn đi qua " HIR "Trịnh Quốc Cừ" BLK " thì bị một tên ác bá cướp bóc. Nếu không trừ khử tên ác bá này, sau này ai dám đi qua đó nữa. Chắc chắn đó là do " HIR "Trương Sơn" BLK " gây ra. Hãy đến dạy cho hắn một bài học, sau đó thông báo cho Lưu Lão Bản một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5100 điểm\n" 
 BLK "    Tiềm năng: 200 điểm\n" 
 BLK "    Ngân lượng: 4700\n",
										 9:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt " HIR "Dạ Túc Quỷ" BLK " rồi thông báo cho " HIR "Yên Quốc Bá Tánh" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Yên Quốc Bá Tánh\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vài ngày trước, một thầy phong thủy đi qua " HIR "Trịnh Quốc Cừ" BLK " nói rằng, Trịnh Quốc Cừ dù bề ngoài yên bình nhưng thực chất bị bao phủ bởi sương mù dày đặc, oán khí ngút trời, do oan hồn tụ tập. Những oan hồn này chắc chắn bị " HIR "Dạ Túc Quỷ" BLK " triệu hồi.\n" 
 BLK "    Hãy đến tiêu diệt Dạ Túc Quỷ để ngăn nó triệu hồi thêm nhiều hồn ma làm hại người, sau khi tiêu diệt thì thông báo cho " HIR "Yên Quốc Bá Tánh" BLK " một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5300 điểm\n" 
 BLK "    Tiềm năng: 210 điểm\n" 
 BLK "    Ngân lượng: 4500\n",
										10:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Bóng Ma rồi báo cho " HIR "Lưu Lão Bản" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lưu Lão Bản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lại có người mất tích ở Trịnh Quốc Cừ, bạn có biết không?\n" 
 BLK "    Gần đây mọi người bàn tán về việc dân chúng ở khu vực " HIR "Trịnh Quốc Cừ" BLK " thường xuyên mất tích một cách kỳ lạ, khiến lòng người hoảng loạn. Bạn có biết trên đời này có một loại " HIR "Bóng Ma" BLK " chuyên mê hoặc tâm trí con người, thao túng họ làm những việc thương thiên hại lý? Tôi đoán rằng loạt vụ mất tích này cũng liên quan đến Bóng Ma. Hãy đến Trịnh Quốc Cừ tiêu diệt Bóng Ma đó, sau khi tiêu diệt thì thông báo cho " HIR "Lưu Lão Bản" BLK " một tiếng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5500 điểm\n" 
 BLK "    Tiềm năng: 200 điểm\n" 
 BLK "    Ngân lượng: 4800\n",
										11:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Bích Long Cầu và giao cho " HIR "Yên Quản Gia" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Yên Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Yên Quản Gia gặp rắc rối lớn! Anh ta làm mất bảo vật tiến cống cho Yên Đại Vương, đây là tội chém đầu!\n" 
 BLK "    Anh ta nói sau khi trở về từ Trịnh Quốc Cừ thì không thấy bảo vật đâu, đã quay lại tìm kỹ nhưng không thấy. Tuy nhiên, anh ta không muốn bỏ qua hy vọng cuối cùng. Hãy đi tìm Bích Long Cầu thay anh ta và giao lại cho Yên Quản Gia.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5400 điểm\n" 
 BLK "    Tiềm năng: 190 điểm\n" 
 BLK "    Ngân lượng: 4900\n",
										12:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Hàn Tơ và giao cho " HIR "Chủ Tiệm May Mặc Yên Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm May Mặc Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Từ khi còn nhỏ, Chủ Tiệm May Mặc Yên Quốc đã nghe sư phụ nói rằng Hàn Tơ là một nguyên liệu may mặc rất quý hiếm. Sau nhiều năm mở tiệm, bà nghe được nhiều tin đồn về Hàn Tơ và ngày càng trở nên hứng thú với nó.\n" 
 BLK "    Gần đây, bà nghe nói Hàn Tơ từng xuất hiện ở khu vực " HIR "Trịnh Quốc Cừ" BLK ". Hãy đi tìm giúp bà, nếu tìm được, bà sẽ không để bạn chịu thiệt!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5400 điểm\n" 
 BLK "    Tiềm năng: 200 điểm\n" 
 BLK "    Ngân lượng: 5000\n",
										13:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Nghịch Thế Quỷ và thông báo cho Chủ Tiệm Cầm Đồ Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Theo lời tiên tri của thầy phong thủy, chẳng bao lâu nữa sẽ có yêu ma xuất hiện ở khu vực Trịnh Quốc Cừ, chắc chắn là do Nghịch Thế Quỷ gây ra. Hãy đến tiêu diệt nó, sau khi tiêu diệt thì thông báo cho Chủ Tiệm Cầm Đồ Yên Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5600\n" 
 BLK "    Tiềm năng: 220\n" 
 BLK "    Ngân lượng: 4800\n",
										14:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Minh Kính và giao cho " HIR "Ngự Sử Yên Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự Sử Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tương truyền có một tấm Minh Kính, nếu treo nó ở cổng sẽ khiến những người đi qua được cảm hóa, tâm trí trở nên trong sáng, xua tan mọi ý niệm tham ô hối lộ. Ngự Sử Yên Quốc nói rằng nếu treo tấm Minh Kính này ở cổng cung điện của Đại Vương, số kẻ tham ô sẽ giảm đi, và công việc của ông sẽ nhẹ nhàng hơn.\n" 
 BLK "    Có người từng thấy tấm Minh Kính ở khu vực Trịnh Quốc Cừ, hãy đi tìm giúp ông ta!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5800 điểm\n" 
 BLK "    Tiềm năng: 210 điểm\n" 
 BLK "    Ngân lượng: 5000\n" 
 BLK "    Vật phẩm: Vũ khí cấp 50",
										15:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Cự Linh Thần Chùy và giao cho " HIR "Chủ Tiệm Vũ Khí Yên Quốc Từ Phu Nhân" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Vũ Khí Yên Quốc Từ Phu Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chỉ những người có sức mạnh phi thường mới có thể cầm được Cự Linh Thần Chùy, nhưng một khi cầm được, uy lực của nó vượt ngoài sức tưởng tượng, không chỉ giúp tăng lực ra chiêu mà còn tăng nội lực. Vì thế, Cự Linh Thần Chùy là vũ khí mà nhiều người trong võ lâm mơ ước.\n" 
 BLK "    Nghe nói có người từng thấy Cự Linh Thần Chùy ở khu vực Trịnh Quốc Cừ, hãy đi tìm xem có thể tìm được không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5700 điểm\n" 
 BLK "    Tiềm năng: 210 điểm\n" 
 BLK "    Ngân lượng: 4600\n",
										17:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm " HIR "Thợ Rèn Đại Vương Triệu Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ Rèn Đại Vương Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Yên Thương Thiên gần đây gặp phải một việc vô cùng phiền phức, nhưng vì không muốn làm rùm beng nên không thể bàn bạc với ai. Ông ấy chỉ muốn tìm một người có thể giúp giải quyết việc này và giữ bí mật, ông ấy sẽ không để người giúp mình chịu thiệt.\n" 
 BLK "    Bạn có sẵn lòng giúp ông ấy không? Nếu sẵn lòng, hãy tìm Thợ Rèn Đại Vương Triệu Quốc và nói rằng chuyện của Yên Thương Thiên phải làm sao, ông ấy sẽ hiểu.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4400\n" 
 BLK "    Tiềm năng: 140\n" 
 BLK "    Ngân lượng: 3800\n",
										27:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Triệu Quốc Lý Phòng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Lý Phòng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dụng cụ đã làm xong, nhưng cần đặt tên, và ba chiếc vòng cũng cần có tên hay. " HIR "Triệu Quốc Lý Phòng" BLK " là một cao nhân, học thức uyên thâm, hãy đến nhờ ông ấy đặt tên cho dụng cụ do Ngự Sử Yên Quốc chế tạo.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 8000 điểm\n" 
 BLK "    Tiềm năng: 480 điểm\n" 
 BLK "    Ngân lượng: 7000\n",
										30:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm " HIR "Chủ Tiệm Y Dược Yên Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Y Dược Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi tìm Chủ Tiệm Y Dược Yên Quốc để xin ba cây Cỏ Linh Chi mang về chữa bệnh cho Phu Nhân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4800 điểm\n" 
 BLK "    Tiềm năng: 180 điểm\n" 
 BLK "    Ngân lượng: 2800\n",
										35:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm " HIR "Thương Nhân Triệu Quốc Quách Túng" BLK " để thương lượng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương Nhân Triệu Quốc Quách Túng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Để giảm rủi ro trong kinh doanh, Thương Nhân Yên Quốc Kinh Kha định hợp tác làm ăn với Thương Nhân Triệu Quốc Quách Túng, nhưng trước tiên cần hỏi ý kiến của Quách Túng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5500 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 5000\n",
										38:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao “Thư” cho Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau bao khó khăn, cuối cùng cũng lấy được lá thư này, tôi phải nhanh chóng giao nó cho Triệu Quốc Bá Tánh Ngô Cơ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 24000 điểm\n" 
 BLK "    Tiềm năng: 420 điểm\n" 
 BLK "    Ngân lượng: 22000\n",
										54:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 50" BLK " mang Dạ Minh Châu trả lại cho Triệu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ Binh Yên Quốc nhặt được một viên Dạ Minh Châu, vốn định mang đến tiệm cầm đồ đổi lấy tiền, nhưng nghe nói Triệu Đại Vương trong lúc viếng thăm Yên Quốc đã làm mất một viên Dạ Minh Châu. Anh ta nghĩ viên mình nhặt được chắc chắn là của Triệu Đại Vương, nên muốn trả lại để thể hiện phẩm chất cao thượng của dân chúng Yên Quốc! Anh ta nhờ tôi mang viên Dạ Minh Châu này đến tay Triệu Đại Vương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5500 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 5000\n",
]),
							   TID_ZHAOGUO:
								   ([2:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dạy cho tên ác nhân quấy rối " HIR "Vũ Tàng" BLK " một bài học rồi trở về báo cho " HIR "Thợ Rèn Đại Vương" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ Rèn Đại Vương Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phải giúp Thợ Rèn Đại Vương dạy cho tên ác nhân quấy rối Vũ Tàng một bài học, thì ông ấy mới có thể giúp Yên Thương Thiên. Xem ra việc này thật sự rất khó khăn. Tên " HIR "Vũ Tàng" BLK " đang ở phía đông nhất của " HIR "Mục Trường" BLK "!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6000 điểm\n" 
 BLK "    Tiềm năng: 190 điểm\n" 
 BLK "    Ngân lượng: 4500\n",
										3:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thư cho " HIR "Yên Thương Thiên của Yên Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Yên Thương Thiên của Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau một loạt nỗ lực, Thợ Rèn Đại Vương cuối cùng đã tìm ra cách giải quyết vấn đề. Ông ấy đã viết phương pháp vào một lá thư và nhờ tôi chuyển giao cho Yên Thương Thiên.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4500 điểm\n" 
 BLK "    Tiềm năng: 145 điểm\n" 
 BLK "    Ngân lượng: 3900\n" 
 BLK "    Vật phẩm: Hạng liên cấp 40\n",
										4:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Chuồn Chuồn Tre và giao cho " HIR "Phu Nhân Triệu Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phu nhân mỗi ngày vất vả kiếm tiền công, thật sự khổ cực và đáng thương. Hiếm khi anh ta nhớ đến chiếc Chuồn Chuồn Tre thời thơ ấu. " HIR "Triệu Trường Thành 1" BLK " cũng không xa, tôi sẽ đi tìm giúp anh ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6400 điểm\n" 
 BLK "    Tiềm năng: 258 điểm\n" 
 BLK "    Ngân lượng: 5400\n",
										8:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm viếng " HIR "Sứ thần Tần Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sứ thần Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nhờ lần xuất sứ thành công trước đó đến Tần Quốc, Đại Vương càng tin tưởng sứ thần Triệu Quốc. Lần này, ông lại phái sứ thần đến Tần Quốc và nói rằng sứ thần có thể mang theo trợ thủ. Bạn hãy đến trước để gặp Sứ thần Tần Quốc, sứ thần Triệu Quốc sẽ đến sau.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5500 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 5100\n",
									   10:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt tên cai đầu dài độc ác Triệu Tứ rồi báo cho " HIR "Thợ Thủ Công Triệu Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ Thủ Công Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Làm thợ thủ công ngày ngày mệt nhọc, không chỉ công việc vất vả mà còn bị chủ coi như không phải con người. Tên cai đầu dài độc ác Triệu Tứ ngày nào cũng áp bức Thợ Thủ Công Triệu Quốc, chưa kể còn quá đáng hơn khi trừ tiền công của họ. Số tiền công này là thứ họ đổi bằng danh dự và cả tính mạng!\n" 
 BLK "    Thiếu hiệp/cô nương, xin hãy đứng ra đòi công lý cho họ! Tên Triệu Tứ đang ở trên " HIR "Dốc Triệu Trường Thành" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6000\n" 
 BLK "    Tiềm năng: 240\n" 
 BLK "    Ngân lượng: 6000\n",
									   11:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại tiền công khổ cực và giao cho " HIR "Phu Nhân Triệu Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phu nhân mấy ngày trước khi đi qua dốc Triệu Trường Thành 1 đã vô tình làm mất số tiền công khổ cực kiếm được. Hãy đến tìm lại số tiền đó và trả lại cho anh ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6200 điểm\n" 
 BLK "    Tiềm năng: 250 điểm\n" 
 BLK "    Ngân lượng: 6200\n",
									   12:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Thạch Hồn rồi báo cho " HIR "Phu Nhân" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phu nhân nói rằng đã thấy một hòn đá biết nói? Không phải khoác lác đấy chứ! Nhưng nhìn vẻ sợ hãi của anh ta, không giống như đang nói dối.\n" 
 BLK "    Anh ta kể rằng hòn đá đó không có mặt mũi gì, chỉ có một cái miệng lớn, lúc mở lúc đóng, phát ra âm thanh khiến người ta lạnh gáy. Khi thấy nó, anh ta lập tức quay đầu bỏ chạy, dù đã đi xa vẫn nghe tiếng cười nhạo sắc bén của nó, âm thanh đó thật sự quá đáng sợ.\n" 
 BLK "    Anh ta nói hòn đá đó chắc chắn bị Thạch Hồn thao túng, nên nhờ tôi đến " HIR "Đài Hỏa Hiệu Triệu Trường Thành" BLK " tiêu diệt Thạch Hồn đang gây họa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6100 điểm\n" 
 BLK "    Tiềm năng: 240 điểm\n" 
 BLK "    Ngân lượng: 6000\n",
									   13:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt ác bá Triệu Lục rồi báo cho " HIR "Phu Nhân" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thời thế này sao lại rối loạn đến vậy!\n" 
 BLK "    Phu nhân chỉ là một công nhân nghèo khổ đi qua Triệu Trường Thành, vậy mà vẫn bị cướp! Kẻ cướp lấy đi số tiền công anh ta vất vả kiếm được, còn cướp hết mọi thứ đáng giá trên người anh ta, thật khiến người ta phẫn nộ!\n" 
 BLK "    Thiếu hiệp/cô nương, xin hãy thương xót người đáng thương này và đòi công lý cho anh ta!\n" 
 BLK "    Tên cướp đó tên Triệu Lục, đang ở trên dốc Triệu Trường Thành!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6300\n" 
 BLK "    Tiềm năng: 250\n" 
 BLK "    Ngân lượng: 6400\n",
									   14:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Linh Kiến và giao cho Phu Nhân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phu nhân gần đây mê mẩn việc酿 rượu, anh ta đã thử nhiều phương pháp mới lạ và cuối cùng tìm ra cách酿 chế rượu tuyệt thế. Đáng tiếc là thiếu nguyên liệu Linh Kiến. Nghe nói có người từng thấy Linh Kiến ở " HIR "Dốc Triệu Trường Thành 1" BLK ". Bạn có thể giúp anh ta tìm lại không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6300 điểm\n" 
 BLK "    Tiềm năng: 240 điểm\n" 
 BLK "    Ngân lượng: 6300\n",
									   15:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt du côn Thạch Lục rồi báo cho " HIR "Triệu Quốc Bá Tánh Ngô Cơ" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Danh dự của một cô gái làm sao có thể bị tùy tiện chà đạp! Thật đáng thương…\n" 
 BLK "    Vài ngày trước, Triệu Quốc Bá Tánh Ngô Cơ khi đi dạo ở Đài Hỏa Hiệu Triệu Trường Thành đã thấy một cô gái bị du côn bắt nạt. Cô ấy định ngăn cản, nhưng không ngờ tên du côn khỏe như trâu, đẩy cô ra khiến cô không thể đến gần. Đáng thương thay, cô chỉ biết đứng nhìn cô gái trẻ đẹp như hoa bị tên du côn làm nhục! Oan nghiệt, oan nghiệt!\n" 
 BLK "    Nếu bạn có lòng hiệp nghĩa, hãy đến Đài Hỏa Hiệu Triệu Trường Thành tiêu diệt tên du côn Thạch Lục, kẻ này không biết sẽ còn hại bao nhiêu người nữa!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6400 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 6500\n",
									   16:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Tâm Chi Ma, rồi báo lại cho Phu Nhân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phu nhân nói rằng gần đây anh ta thường gặp những chuyện kỳ lạ, thế gian này đã trở thành nơi yêu ma hoành hành.\n" 
 BLK "    Lần trước khi đi qua " HIR "Đài Hỏa Hiệu Triệu Trường Thành" BLK ", anh ta thấy yêu khí ngút trời, chắc chắn là do Tâm Chi Ma bị phong ấn ngàn năm đang rục rịch. Chúng ta phải tiêu diệt nó trước khi nó gây họa, nếu không hậu quả sẽ khôn lường. Hãy đi tiêu diệt nó!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6300 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 6300\n",
									   17:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến " HIR "Triệu Trường Thành" BLK " tiêu diệt Tam Đao Quỷ rồi báo cho " HIR "Triệu Quốc Bá Tánh Ngô Cơ" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chú của Triệu Quốc Bá Tánh Ngô Cơ trước khi qua đời đã dặn cô ấy phải bằng mọi cách tiêu diệt Tam Đao Quỷ ở Đài Hỏa Hiệu Triệu Trường Thành. Cô không biết giữa họ có ân oán gì, nhưng đó là di nguyện của chú, nên cô đã thử thách Tam Đao Quỷ ba lần nhưng đều thất bại, suýt mất mạng. Nghe nói Tam Đao Quỷ có biệt danh “ba nhát lấy mạng”, có thể thoát chết dưới lưỡi đao của hắn đã là may mắn. Vì vậy, cô nhờ bạn đến " HIR "Đài Hỏa Hiệu Triệu Trường Thành" BLK " tiêu diệt " HIR "Tam Đao Quỷ" BLK " để hoàn thành di nguyện của chú cô.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6600 điểm\n" 
 BLK "    Tiềm năng: 240 điểm\n" 
 BLK "    Ngân lượng: 6400\n",
									   18:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Ngọc Tơ và giao cho " HIR "Triệu Quốc Bá Tánh Ngô Cơ" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Từ nhỏ, Triệu Quốc Bá Tánh Ngô Cơ đã học thêu thùa. Hồi đó, bất cứ thứ gì cô tự làm ra đều thấy đẹp. Giờ đây, khi mức sống cao hơn, yêu cầu của cô cũng cao hơn, nên cô luôn muốn may một bộ thần y. Vì nghe nói mặc bộ thần y làm từ Ngọc Tơ sẽ khiến người ta trẻ ra vài tuổi.\n" 
 BLK "    Nhưng Ngọc Tơ là một nguyên liệu rất khó tìm. Chỉ nghe nói có người từng thấy ở " HIR "Đài Hỏa Hiệu Triệu Trường Thành 3" BLK ". Hãy đi tìm và giao nó cho Triệu Quốc Bá Tánh Ngô Cơ, tôi tin cô ấy sẽ trả bạn một cái giá hậu hĩnh!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6500 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 6300\n",
									   19:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Thần Hành Lộ và giao cho " HIR "Triệu Quốc Bá Tánh Ngô Cơ" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Triệu Quốc Bá Tánh Ngô Cơ thật không biết lễ phép, dám gọi tôi là “người kia”. Chẳng lẽ tôi không có tên họ sao? Cô ấy còn nghĩ tôi là kẻ ít học! Công phu Thần Hành Thiên Lý, người trong giang hồ ai mà chưa nghe qua!\n" 
 BLK "    Nhưng Thần Hành Lộ mà cô ấy nhắc đến thì tôi chưa từng nghe. Triệu Trường Thành 3 thật sự có thứ đó sao? Ăn nó vào có thật sự đi được ngàn dặm một ngày không? Ha ha, vậy thì tôi phải cảm ơn cô ấy đã cung cấp thông tin này. Tôi sẽ đi tìm ngay, thứ này ai mà không muốn! Nếu tôi giữ riêng, đừng trách tôi bất nhân bất nghĩa, ha ha…\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6500 điểm\n" 
 BLK "    Tiềm năng: 250 điểm\n" 
 BLK "    Ngân lượng: 6500\n",
									   20:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Linh Quang Kính và giao cho " HIR "Thợ Thủ Công Triệu Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ Thủ Công Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đừng thấy Thợ Thủ Công Triệu Quốc là một thợ già mà xem thường, đôi khi gặp vấn đề thật sự khó giải quyết. Như mấy việc tinh xảo, có khi vật phẩm quá nhỏ mà vẫn phải chạm khắc hoa văn, thật đau đầu.\n" 
 BLK "    Nghe nói có một loại kính, đặt lên vật phẩm sẽ phóng to, nếu có thứ này, công việc tinh xảo chẳng phải dễ hơn sao. Loại kính đó gọi là Linh Quang Kính, là vật phẩm hiếm, khó tìm. Tối qua ở Đài Hỏa Hiệu Triệu Trường Thành 3, Thợ Thủ Công Triệu Quốc thấy một tia sáng lóe lên, có lẽ là từ Linh Quang Kính phát ra. Hãy đi giúp anh ta tìm!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6600 điểm\n" 
 BLK "    Tiềm năng: 250 điểm\n" 
 BLK "    Ngân lượng: 6200\n",
									   21:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Hỗn Thế Ma rồi báo cho " HIR "Phu Nhân" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tối qua có một tiếng nổ lớn? Sao tôi chẳng nghe thấy gì? Có lẽ tai tôi có vấn đề thật, phải đi khám đại phu.\n" 
 BLK "    Phu nhân nói anh ta nghe rõ mồn một, trên không trung ở dốc Triệu Trường Thành có một tiếng nổ lớn, nhiều người cũng nghe thấy. Mọi người bàn tán rằng có lẽ Hỗn Thế Ma ngủ ngàn năm đã xuất hiện. Việc tiêu diệt hắn nên giao cho những người trong võ lâm như chúng ta. Hãy nhanh chóng đến Triệu Trường Thành tiêu diệt hắn trước khi hắn hoàn toàn tỉnh giấc, nếu không sẽ gây họa cho dân chúng!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6400 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 6400\n",
									   22:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Minh Chi Yêu rồi báo cho " HIR "Triệu Quốc Bá Tánh Ngô Cơ" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chiếc chuông hỏng cả trăm năm bỗng tự kêu, chuyện này quá kỳ lạ, thật quỷ dị!\n" 
 BLK "    Chuông kêu chỉ có một lý do, chắc chắn có thứ không sạch sẽ đang gây họa. Nghĩ đi nghĩ lại, có lẽ là " HIR "Minh Chi Yêu" BLK " lại ra làm ác. Hãy đến " HIR "Dốc Triệu Trường Thành" BLK " tiêu diệt nó!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6600 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 6700\n",
									   23:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dạy cho tên vô lại Lý Tứ một bài học rồi báo cho " HIR "Bạch Dịch" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bạch Dịch\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trên đời này đúng là có những kẻ rỗi hơi, không có việc gì làm lại đi quấy rối, khiến lòng người hoảng loạn.\n" 
 BLK "    Nghe nói trên không trung ở " HIR "Dốc Triệu Trường Thành" BLK " bỗng xuất hiện một đám khói, nếu không phải có người giở trò thì chẳng lẽ là ma quỷ làm? Hãy nhanh chóng đi xem, có lẽ là do tên " HIR "Lý Tứ" BLK " gây ra. Trời khô vật khô, cẩn thận lửa nến!\n" 
 BLK "    Gặp hắn thì nhớ dạy cho hắn một bài học, để hắn chừa thói không biết điều, tránh làm chuyện như vậy nữa!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6500 điểm\n" 
 BLK "    Tiềm năng: 240 điểm\n" 
 BLK "    Ngân lượng: 6600\n",
									   24:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Ngọc Minh Châu và giao cho " HIR "Phu Nhân" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    “Dạ Minh Châu… Ngọc Minh Châu…\n" 
 BLK "    Nghe nói về Dạ Minh Châu? Tôi tin. Nghe nói về Ngọc Minh Châu? Khoác lác! Bạn biết Ngọc Minh Châu dùng để làm gì không? Tôi tin bạn chắc chắn không biết, vì tôi cũng không biết, ha ha!” Nghe lời phu nhân nói, đúng là điên rồ, điên rồ!\n" 
 BLK "    Nhưng anh ta nói thứ này chắc chắn rất giá trị, nếu tìm được sẽ bán được giá tốt. Vậy tôi sẽ đi tìm, bán được giá tốt còn chia nửa! Ngọc Minh Châu ở dốc Triệu Trường Thành 1.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 240 điểm\n" 
 BLK "    Ngân lượng: 6500\n",
									   25:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt ác bá Tề Tiểu Lục, báo cho " HIR "Thợ Rèn Đại Vương Triệu Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ Rèn Đại Vương Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thợ Rèn Đại Vương nói rằng tối qua khi vừa nằm xuống, ông thấy một người đứng trước giường, tự xưng là hồn ma dã quỷ, bảo ông đừng sợ, chỉ muốn tìm người báo thù thay!\n" 
 BLK "    Hắn nói chỉ vì hai lượng bạc mà ác bá Tề Tiểu Lục đã hại chết hắn, khiến hắn chết không nhắm mắt, nhất định phải báo mối thù này. Nhưng âm dương cách biệt, hắn chỉ có thể nhờ người báo thù!\n" 
 BLK "    Bạn là người thích hợp nhất, vì bạn không quen biết Tề Tiểu Lục, không có thù oán, dù giết hắn cũng không ai nghi ngờ bạn. Hãy đến " HIR "Dốc Triệu Trường Thành" BLK " tiêu diệt hắn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6700 điểm\n" 
 BLK "    Tiềm năng: 250 điểm\n" 
 BLK "    Ngân lượng: 6400\n",
									   26:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Thần Long Hiệu Giác và giao cho Thợ Rèn Đại Vương Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hôm trước, khi Thợ Rèn Đại Vương đi qua Đài Hỏa Hiệu Triệu Trường Thành 2, ông thấy một người lấy ra một chiếc kèn thổi lên trời, triệu hồi được mấy con lôi long, khiến ông hoảng hốt.\n" 
 BLK "    Sau đó, ông mới biết chiếc kèn đó là Thần Long Hiệu Giác trong truyền thuyết. Người thổi được nó có thể học được tuyệt thế thần công – Lôi Long Quyết. Thợ Rèn Đại Vương nói ông rất muốn học Lôi Long Quyết, nên nhờ bạn tìm Thần Long Hiệu Giác. Ông thấy người đó cất Thần Long Hiệu Giác vào một rương báu ở Đài Hỏa Hiệu Triệu Trường Thành, hãy đi tìm!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 270 điểm\n" 
 BLK "    Ngân lượng: 6500\n",
									   27:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Bích Quang Thạch và giao cho " HIR "Thợ Rèn Đại Vương Triệu Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ Rèn Đại Vương Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hôm qua, khi Thợ Rèn Đại Vương đi qua dốc Triệu Trường Thành 2, ông thấy một luồng sáng huỳnh quang bí ẩn bay lượn phía trên. Có lẽ đó là Bích Quang Thạch đã thất lạc từ lâu. Hãy đi tìm viên thần thạch đó và giao cho Thợ Rèn Đại Vương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7000 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 6300\n",
									   28:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt ác phỉ Triệu Ngũ rồi báo cho " HIR "Triệu Quốc Bá Tánh Ngô Cơ" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Triệu Ngũ là một tên cướp giết người, cướp của, không từ thủ đoạn ác độc nào. Gần đây, hắn cướp phá nhiều nhà dân, khiến người ta tan cửa nát nhà. Hôm qua, nhà của Triệu Quốc Bá Tánh Ngô Cơ cũng bị hắn cướp!\n" 
 BLK "    Triệu Quốc Bá Tánh Ngô Cơ không thù oán gì với hắn, vậy mà hắn vẫn cướp. Mối thù này cô ấy đã kết với hắn! Hãy đi dạy hắn một bài học, cho hắn biết thế nào là lễ độ! Hắn đang ở " HIR "Dốc Triệu Trường Thành" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6900 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 6800\n",
									   29:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Thư Phục Mệnh và giao cho " HIR "Phu Nhân" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hôm qua, một vị khách làm mất một lá Thư Phục Mệnh ở " HIR "Dốc Triệu Trường Thành 2" BLK ". Vị khách này để lại lời nhắn ở chỗ phu nhân, nếu ai tìm được Thư Phục Mệnh, ông ta sẽ thưởng hậu. Hãy đi tìm và giao cho tôi, tôi sẽ trả thù lao cho bạn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 250 điểm\n" 
 BLK "    Ngân lượng: 6700\n",
									   30:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dạy cho tên vô lại Thạch Cửu một bài học rồi báo cho " HIR "Triệu Quản Gia" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Những tên vô lại này, ngày nào cũng rảnh rỗi đi lung tung, tìm cơ hội gây rối để kiếm chút tiền lẻ. Ta ghét nhất là loại người không làm mà đòi có ăn này. Phải tìm cách trị hắn, nếu không hắn sẽ càng ngày càng lộng hành. Hãy đến " HIR "Dốc Triệu Trường Thành" BLK " dạy hắn một bài học, nhưng nhớ đừng ra tay quá nặng, chỉ cần hắn nhớ đời là được!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6900 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 6600\n",
									   31:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt phản tặc Diệp Thanh rồi báo cho " HIR "Triệu Quản Gia" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Toàn quốc truy nã – Diệp Thanh, bạn hẳn đã nghe nói? Gần đây, hắn lẩn trốn gần Yên Quốc. Phải nhanh chóng bắt hắn quy án, nếu không sẽ hại thêm nhiều dân vô tội.\n" 
 BLK "    Nghe nói triều đình treo thưởng mười vạn lượng vàng để bắt hắn. Nếu bạn tiêu diệt được hắn, bạn sẽ phát tài! Hãy nhanh chóng đến Triệu Trường Thành tiêu diệt hắn trước khi tin tức lộ ra!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7100 điểm\n" 
 BLK "    Tiềm năng: 270 điểm\n" 
 BLK "    Ngân lượng: 6200\n",
									   32:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Ngọc Lan Thạch và giao cho " HIR "Thương Nhân Lang Thang" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương Nhân Lang Thang\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi khắp nam bắc, gặp không ít kỳ nhân dị sự, điều khiến ta ngạc nhiên nhất là truyền thuyết về một viên Ngọc Lan Thạch. Không biết viên đá này có công dụng gì mà khiến người ta bỏ bao công sức để tranh giành. Muốn phát tài? Hãy nhanh chóng đến " HIR "Triệu Trường Thành 2" BLK " tìm viên Ngọc Lan Thạch đó, tương truyền chỉ người có duyên mới tìm được!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7000 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 6500\n",
									   33:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Lệnh Binh Phù và giao cho " HIR "Vệ Binh Triệu Quốc" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ Binh Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lần trước, Vệ Binh Triệu Quốc dẫn đội đánh úp hậu phương địch ở " HIR "Dốc Triệu Trường Thành 2" BLK ", tiêu diệt toàn bộ quân địch, nhưng lại không tìm thấy Lệnh Binh Phù của thủ lĩnh địch. Không có nó, không thể chứng minh công lao để luận công ban thưởng. Bạn có sẵn lòng giúp tôi tìm nó không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7000 điểm\n" 
 BLK "    Tiềm năng: 270 điểm\n" 
 BLK "    Ngân lượng: 6300\n" 
 BLK "    Vật phẩm: Hạng liên cấp 60\n",
									   34:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dạy cho tên vô lại Lý Tiểu Lục một bài học rồi báo cho " HIR "Triệu Quản Gia" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, Triệu Quản Gia đi qua Triệu Trường Thành thấy khói lửa bốc lên ở Đài Hỏa Hiệu, khiến mọi thứ rối loạn, suýt nữa bị coi là gian tế mà bắt. Chắc chắn là do tên vô lại Lý Tiểu Lục gây rối, hắn thích quấy nhiễu Triệu Quản Gia. Thằng nhãi này cần được dạy dỗ! Hãy đánh hắn cho đến khi hắn chịu phục, rồi trở về báo cho Triệu Quản Gia.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 250 điểm\n" 
 BLK "    Ngân lượng: 6800\n",
									   36:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Mang quà của Lã Bất Vi đến cho " HIR "Triệu Cơ" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" 
									   HIR "Triệu Cơ ở ngoại ô Hàm Đan\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lã Bất Vi gần đây mê mẩn một ca kỹ. Từ khi nghe giọng hát và thấy điệu múa của cô ấy ở Tử Yên Lâu, ngày nào cũng hồn xiêu phách lạc. Nếu không đến Tử Yên Lâu gặp cô ấy, anh ta sẽ bồn chồn không yên. Người đẹp kiều diễm như vậy, anh ta chỉ hận không thể lúc nào cũng có cô ấy bên cạnh. Nhưng ca kỹ này rất kiêu kỳ, ở Tử Yên Lâu cũng chỉ treo bảng mà thôi. Bao nhiêu công tử vương tôn muốn rước cô về đều bị từ chối khéo. Lã Bất Vi muốn chinh phục trái tim cô để thật sự có được mỹ nhân nghiêng thành này. Trước khi làm thương nhân, anh ta từng là một hiệp khách, biết đôi chút thi văn. Anh ta nhờ thợ dưới tay làm một chiếc Phượng Điệp Bội, khắc bài thơ thời thiếu niên của mình lên đó, và nhờ bạn mang món quà này đến cho Triệu Cơ ở ngoại ô Hàm Đan.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3880 điểm\n" 
 BLK "    Tiềm năng: 175 điểm\n" 
 BLK "    Ngân lượng: 3600\n",
									   38:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thanh bảo kiếm cho " HIR "Lã Bất Vi" BLK "\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lã Bất Vi\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vì tôi đã giúp Triệu Cơ tìm được thanh bảo kiếm, hãy thay cô ấy giao nó cho Lã Bất Vi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3800 điểm\n" 
 BLK "    Tiềm năng: 177 điểm\n" 
 BLK "    Ngân lượng: 3600\n",
									   42:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Tổng Quản Yên Quốc, hỏi về tung tích Đồng Tâm Tỏa\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng Quản Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nhiều năm trước, trong giang hồ xuất hiện một cặp bảo vật gọi là Đồng Tâm Tỏa. Chỉ cần hai người đeo nó, họ có thể tìm thấy nhau bất cứ lúc nào. Triệu Quốc Bá Tánh Ngô Cơ muốn tìm cặp bảo vật này để cô và người yêu không phải chịu nỗi đau tương tư. Nghe nói Tổng Quản Yên Quốc rất rành về các bảo vật trên đời, cô ấy nhờ tôi đi hỏi ông ta về tung tích của bảo vật này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 24000 điểm\n" 
 BLK "    Tiềm năng: 420 điểm\n" 
 BLK "    Ngân lượng: 22000\n",
									   48:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Thợ Rèn Đại Vương để lấy chìa khóa\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ Rèn Đại Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ở ngoại thành Hàm Đan có một Thợ Rèn Đại Vương, chắc hẳn ông ấy biết làm chìa khóa. Vệ Binh Triệu Quốc nhờ tôi đi hỏi ông ấy xem.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 23500 điểm\n" 
 BLK "    Tiềm năng: 430 điểm\n" 
 BLK "    Ngân lượng: 23000\n",
									   49:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Công Thâu Ban của Chu Quốc, hỏi về việc làm chìa khóa\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban của Chu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thợ Rèn Đại Vương nói với tôi rằng Công Thâu Ban của Chu Quốc có thể chế tạo vật phẩm tinh xảo. Ông ấy bảo tôi đến gặp ông ta, có lẽ ông ấy sẽ giúp được tôi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 24000 điểm\n" 
 BLK "    Tiềm năng: 435 điểm\n" 
 BLK "    Ngân lượng: 22500\n",
									   53:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay Đại Tướng Quân Triệu Quốc Lý Mục tiêu diệt sát thủ Lý Vũ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Tướng Quân Triệu Quốc Lý Mục\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ở " HIR "Mục Trường ngoại thành Hàm Đan" BLK " là một vùng hoang vu, thường là nơi ẩn náu của những kẻ có ý đồ xấu. Gần đây, Đại Tướng Quân Triệu Quốc Lý Mục nhận được mật báo rằng Tần Quốc đã phái một sát thủ có bí danh " HIR "Lý Ngũ" BLK " đang lẩn trốn ở đó để âm mưu hành động. Hãy nhanh chóng tiêu diệt hắn để tránh đêm dài lắm mộng, nhưng hãy hành sự cẩn thận.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 52500 điểm\n" 
 BLK "    Tiềm năng: 730 điểm\n" 
 BLK "    Ngân lượng: 50000\n",
									   54:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi thư đến chỗ Sứ thần Yên Quốc Tần Khai\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sứ thần Yên Quốc Tần Khai\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lần trước, Sứ thần Yên Quốc Tần Khai đến gặp Nội Chính Quan Tề Quốc Mạnh Thường Quân, hai người trò chuyện rất vui, nói về phong tục và sản vật các nơi, ông ấy kể vanh vách như trong lòng bàn tay. Gần đây, phu nhân Nội Chính Quan bỗng có ý tưởng, cần nhờ ông ấy giúp. Nội Chính Quan đã viết chi tiết trong thư. Nghe nói bạn sắp đến Yên Quốc, hy vọng bạn có thể tiện đường giúp ông ấy mang thư.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 58000 điểm\n" 
 BLK "    Tiềm năng: 850 điểm\n" 
 BLK "    Ngân lượng: 50000\n",
									   56:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi sách “Luận Ngữ” cho Tổng Quản Yên Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng Quản Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Triệu Quản Gia nghe nói Tổng Quản Yên Quốc đang tìm kiếm bản gốc của “Luận Ngữ”. Hôm qua, trong số vật phẩm cống nạp, ông ấy phát hiện ra cuốn sách này. Sau khi nhờ người thẩm định xác nhận là thật, vì là bạn cũ, ông ấy không dám giữ riêng món đồ tốt. Vì Tổng Quản Yên Quốc rất cần nó, Triệu Quản Gia nhờ bạn mang sách đến cho ông ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 58000 điểm\n" 
 BLK "    Tiềm năng: 850 điểm\n" 
 BLK "    Ngân lượng: 50000\n",
									   57:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Tề Vương hỏi về chuyện Viên Ngọc Cam Hoàn Mỹ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hạc Phi của Triệu Vương lần trước vì bảo vệ Triệu Vương mà bị sát thủ giết chết. Triệu Vương đau lòng khôn nguôi, luôn giữ thi thể nàng trong quan tài thủy tinh, thường nhìn gương mặt tươi tắn của nàng như thể hôm qua vẫn còn cùng ngắm hoa cúc, trò chuyện dưới ánh trăng. Gần đây, có người nói Tề Vương có được một viên ngọc có thể khiến người chết sống lại. Triệu Vương rất muốn có viên ngọc này, chỉ cần Hạc Phi sống lại, ông sẵn sàng trả bất kỳ giá nào. Triệu Vương nhờ bạn làm đặc sứ Triệu Quốc đến gặp Tề Vương để xin viên ngọc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 32000 điểm\n" 
 BLK "    Tiềm năng: 608 điểm\n" 
 BLK "    Ngân lượng: 30000\n",
									   58:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Nội Chính Quan Tề Quốc Mạnh Thường Quân để bàn về việc giúp Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội Chính Quan Tề Quốc Mạnh Thường Quân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Khi Bá Tánh Tề Quốc kết hôn, không một ai đến chúc mừng, khiến chú rể nổi giận, ngay đêm tân hôn đã nhốt cô dâu ngoài cửa, thật thê lương. Cô ấy cuối cùng nhận ra hoàn cảnh của mình và muốn tìm cách giải quyết, nên nhờ bạn đến hỏi Nội Chính Quan Tề Quốc Mạnh Thường Quân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 36000 điểm\n" 
 BLK "    Tiềm năng: 600 điểm\n" 
 BLK "    Ngân lượng: 35000\n",
									   61:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Quỷ Cốc Tử hỏi về cách chữa bệnh\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quỷ Cốc Tử\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đạo trưởng Từ Phúc đến dùng Như Ý Ngọc Bài, bệnh tình của thế tử quả nhiên tốt hơn nhiều. Ông ấy nhắc với Triệu Vương rằng ở Vân Mộng Cốc có một thần y ẩn thế tên Quỷ Cốc Tử, được đồn là có thể cứu người chết, làm xương trắng sống lại, trên đời chưa có bệnh nào ông ấy không chữa được. Triệu Vương nhờ bạn đến thay mặt hỏi thăm, xem ông ấy có thể chữa dứt bệnh cho thế tử không. Nếu bệnh của thế tử được chữa khỏi, Triệu Vương hứa sẽ ban cho bạn vinh hoa phú quý tùy ý lựa chọn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 48000 điểm\n" 
 BLK "    Tiềm năng: 750 điểm\n" 
 BLK "    Ngân lượng: 50000\n",
									   64:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 60" BLK " thay Vệ Binh Triệu Quốc tìm Thợ Thủ Công Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ Thủ Công Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ Binh Triệu Quốc nghe nói ở Tần Quốc có một thợ thủ công biết chế tạo vũ khí, vũ khí ông ấy làm ra các cửa hàng bình thường không mua được. Gần đây, ông ấy nhận nhiều đệ tử, và các đệ tử học chế tạo vũ khí đều ca ngợi tài nghệ của ông. Thợ Thủ Công Triệu Quốc nói anh ta muốn bái ông ấy làm thầy, nhưng không biết Thợ Thủ Công Tần Quốc ở đâu. Anh ta nhờ tôi đến Tần Quốc tìm xem Thợ Thủ Công Tần Quốc có nhận anh ta làm đệ tử không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6500 điểm\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 6500\n",
									   65:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 85" BLK " tìm Tề Tiểu Phu, chuyển lời quan tâm của Vệ Binh Triệu Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Tiểu Phu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Anh trai của Vệ Binh Triệu Quốc đã đi Tề Quốc làm ăn từ lâu, mãi không về nhà, gia đình không biết anh ấy sống thế nào. Chỉ nghe nói việc kinh doanh của anh ấy ngày càng lớn, không chỉ bán dưa hấu, cam, lê, mà còn bán cả dứa, chuối, thậm chí mở chi nhánh chuyên bán thịt. Vệ Binh Triệu Quốc nhờ tôi hỏi thăm tình hình của anh trai, nói với anh ấy rằng gia đình rất nhớ anh.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 30000 điểm\n" 
 BLK "    Tiềm năng: 400 điểm\n" 
 BLK "    Ngân lượng: 22000\n",
									   66:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 110" BLK " tìm Vệ Binh Tần Quốc, chuyển lời ngưỡng mộ của Đại Tướng Quân Triệu Quốc Lý Mục\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ Binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại Tướng Quân Triệu Quốc Lý Mục nói rằng ông đã nghe từ lâu về Vệ Binh Tần Quốc, một nhân tài hiếm có. Tần Quốc dùng anh ta làm vệ binh thật sự là uổng phí tài năng! Về tư chất, Vệ Binh Tần Quốc thông minh hơn bất kỳ binh sĩ nào trong doanh trại Triệu Quốc; về sự chăm chỉ, anh ta vượt xa bất kỳ ai; về sự linh hoạt, anh ta nhanh nhẹn hơn tất cả. Một nhân tài như vậy, người yêu tài sao có thể không quý! Vì vậy, Đại Tướng Quân Triệu Quốc Lý Mục hy vọng tôi có thể thuyết phục anh ta đến quân đội Triệu Quốc làm một vị tướng xuất sắc!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 48000 điểm\n" 
 BLK "    Tiềm năng: 610 điểm\n" 
 BLK "    Ngân lượng: 45000\n",
									   67:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    " HIR "Sau khi đạt cấp 115" BLK " chuyển tâm nguyện của anh em Vệ Binh Tần Quốc đến Triệu Quản Gia\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Anh trai của Vệ Binh Tần Quốc mắc bệnh nặng, đã sắp qua đời. Nguyện vọng lớn nhất đời anh ta là được gặp Tần Quản Gia. Tần Quản Gia là một người mưu trí hơn người, sau khi nghe về các chiến tích của ông, anh ta rất ngưỡng mộ. Giờ đây, khi đã cận kề cái chết, anh ta chỉ mong được gặp Tần Quản Gia một lần. Thật đáng thương, tôi sẽ giúp anh ta hoàn thành tâm nguyện cuối cùng này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 52000 điểm\n" 
 BLK "    Tiềm năng: 620 điểm\n" 
 BLK "    Ngân lượng: 48000\n",
									   68:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay Thợ Rèn Đại Vương thăm Đại Tướng Quân Triệu Quốc Lý Mục\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Tướng Quân Triệu Quốc Lý Mục\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quân đội Triệu Quốc luôn là khách hàng lớn nhất của Thợ Rèn Đại Vương, nhưng gần đây khi giao hàng, ông thấy Đại Tướng Quân Triệu Quốc Lý Mục luôn chau mày, dường như có chuyện phiền lòng khó giải. Là phận bề tôi, giúp đại tướng giải ưu là bổn phận, nhưng Thợ Rèn Đại Vương đã thử hỏi nhiều lần mà ông không nói, có lẽ vì thấy ông không đủ năng lực. Không còn cách nào, ông đành nhờ bạn giúp đại tướng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 89000 điểm\n" 
 BLK "    Tiềm năng: 1500 điểm\n" 
 BLK "    Ngân lượng: 81000\n",
									   69:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi Triệu Tổng Quản về Thiên Môn Trận Pháp\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại Tướng Quân Triệu Quốc nghe nói có một cuốn kỳ thư ghi chép về Thiên Môn Trận Pháp, học được trận pháp này sẽ bách chiến bách thắng khi dẫn quân đánh trận. Hãy thay ông hỏi Triệu Tổng Quản xem có thể tìm trận pháp này ở đâu.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 91000 điểm\n" 
 BLK "    Tiềm năng: 1600 điểm\n" 
 BLK "    Ngân lượng: 83000\n",
									   71:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại sách trận pháp cho Đại Tướng Quân Triệu Quốc Lý Mục\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Tướng Quân Triệu Quốc Lý Mục\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thiên Môn Trận Pháp được cất trong một chiếc rương có bùa chú. Bạn phải niệm thần chú “Lâm, Binh, Đấu, Giả, Giai, Trận, Liệt, Tại, Tiền” năm lần mới mở được rương, nếu không cơ quan Tiểu Nguyên Trận Pháp trong bùa sẽ phóng Tiểu Nguyên Lôi Sát, khiến bạn hóa thành tro bụi trong chớp mắt. Hãy cẩn thận! Rương ở phía tây bắc tầng hai Thiên Môn Trận, bạn hãy tìm kỹ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 94000 điểm\n" 
 BLK "    Tiềm năng: 1700 điểm\n" 
 BLK "    Ngân lượng: 84000\n",
									   72:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thư xin ra trận của Đại Tướng Quân Triệu Quốc Lý Mục cho Triệu Đại Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Đại Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại Tướng Quân Triệu Quốc Lý Mục hiện rất tự tin với trận chiến Tần-Triệu sắp tới. Ông cho rằng thay vì bị động chịu đánh, nên chủ động xuất kích. Ông đã viết một lá thư xin ra trận, nhờ bạn chuyển đến Đại Vương. Ông muốn chủ động xin đi trấn thủ Thượng Đảng Quận, nhất định sẽ đại bại quân địch, không để Triệu Vương thất vọng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 93000 điểm\n" 
 BLK "    Tiềm năng: 1600 điểm\n" 
 BLK "    Ngân lượng: 83000\n",
									   73:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm dò Nội Chính Quan Triệu Quốc Bình Nguyên Quân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội Chính Quan Triệu Quốc Bình Nguyên Quân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phu nhân mấy ngày nay khiêng đồ đến phủ Đại Vương, thường nghe Nội Chính Quan lẩm bẩm gì đó, có vẻ rất sốt ruột. Là dân, góp sức cho nước là bổn phận, nhưng phu nhân thân phận thấp kém, e không giúp được gì, đành nhờ bạn đi dò hỏi, vừa góp sức cho nước vừa nhận được thưởng, sao không làm?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 95000 điểm\n" 
 BLK "    Tiềm năng: 1550 điểm\n" 
 BLK "    Ngân lượng: 83000\n",
									   74:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi Đại Tướng Quân Triệu Quốc Lý Mục\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Tướng Quân Triệu Quốc Lý Mục\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lão tướng Liêm Pha xuất chinh đã mấy tháng, nhưng chiến báo vẫn chưa tới. Triệu Vương lo lắng bất an, bạn hãy ra ngoại thành hỏi Đại Tướng Quân Triệu Quốc Lý Mục xem có chiến báo nào được gửi đến chưa?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 94000 điểm\n" 
 BLK "    Tiềm năng: 1550 điểm\n" 
 BLK "    Ngân lượng: 84000\n",
									   75:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi Triệu Quốc Bá Tánh Ngô Cơ về tung tích chiến báo\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chiến báo cả tháng chưa đến phủ Đại Vương, chuyện quan trọng như vậy mà lính truyền tin lại không báo, thậm chí còn bỏ trốn, sự việc nghiêm trọng rồi. Đại Tướng Quân Triệu Quốc Lý Mục nhờ bạn âm thầm đến dân gian hỏi Triệu Quốc Bá Tánh Ngô Cơ xem có manh mối nào về chiến báo không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 95000 điểm\n" 
 BLK "    Tiềm năng: 1650 điểm\n" 
 BLK "    Ngân lượng: 85000\n",
									   77:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại chiến báo và giao cho Nội Chính Quan Triệu Quốc Bình Nguyên Quân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội Chính Quan Triệu Quốc Bình Nguyên Quân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Triệu Quốc Bá Tánh Ngô Cơ thông qua thuật Tầm Hồn biết được chiến báo bị giấu trong một chiếc rương ở góc phía nam tầng hai Thiên Môn Trận. Hãy đi tìm và giao nó cho Nội Chính Quan Triệu Quốc Bình Nguyên Quân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 92000 điểm\n" 
 BLK "    Tiềm năng: 1700 điểm\n" 
 BLK "    Ngân lượng: 85000\n",
									   78:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Dò la dân chúng Triệu Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thám tử Triệu Quốc báo cáo gần đây phát hiện một nhóm người lai lịch bất minh, lén lút tụ tập gần ngoại thành, mơ hồ nghe nói về chuyện ám sát, tướng quân, thưởng赐. Ngự Sử Triệu Quốc Mạc Thiên Hành ra lệnh bạn nhanh chóng đến dân gian hỏi thăm dân chúng, xem có ai biết thêm chi tiết không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 96000 điểm\n" 
 BLK "    Tiềm năng: 1750 điểm\n" 
 BLK "    Ngân lượng: 87000\n",
									   80:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt sát thủ Từ Tứ rồi báo cho Điển Ngục Quan Triệu Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Điển Ngục Quan Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Triệu Quốc Bá Tánh Ngô Cơ hỏi ra được kẻ cầm đầu nhóm người này tên là Từ Tứ, dường như không phải người của Thái Cực Môn, không biết từ đâu chui ra. Nhưng đừng mong moi được gì từ miệng loại người này, tốt nhất là giết hắn một lần cho xong, với điều kiện bạn hạ được hắn chứ không phải hắn hạ bạn. Hiện hắn đang ở khu vực " HIR "phía bắc tầng ba Thiên Môn Trận" BLK " liên lạc với tay sai, lên kế hoạch hành động. Nghe nói hắn đã có bản đồ phủ Đại Vương và đang ráo riết lập kế hoạch chi tiết. Hãy đến đó tìm hắn quyết đấu, nếu còn sống trở về thì báo cho Điển Ngục Quan Triệu Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 97000 điểm\n" 
 BLK "    Tiềm năng: 1650 điểm\n" 
 BLK "    Ngân lượng: 88000\n",
									   81:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại bản đồ phủ Đại Vương và giao cho Điển Ngục Quan Triệu Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Điển Ngục Quan Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sát thủ chắc chắn sẽ cất bản đồ phủ Đại Vương ở nơi hắn dễ lấy. Nơi sát thủ hoạt động chắc chắn có bản đồ này. Hãy đến khu vực " HIR "phía bắc tầng ba Thiên Môn Trận" BLK " tìm kiếm, chúng chắc chắn sẽ cẩn thận cất giấu, có lẽ trong một rương báu nào đó của chúng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 99000 điểm\n" 
 BLK "    Tiềm năng: 1600 điểm\n" 
 BLK "    Ngân lượng: 86000\n",
									   82:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thông báo cho Triệu Vương tăng cường vệ binh\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Điển Ngục Quan Triệu Quốc cho rằng vụ ám sát thất bại lần này đã phơi bày lỗ hổng lớn trong công tác bảo vệ phủ Đại Vương. Ông tự kiểm điểm vì không quét sạch bọn gian tặc, đồng thời nhờ bạn vào cung thay ông tấu trình Đại Vương, một mặt đề nghị tăng cường bảo mật và chế độ kiểm tra nhân sự nghiêm ngặt, mặt khác cần nghiêm khắc kỷ luật, tránh lơ là nhiệm vụ, để xảy ra sự kiện đe dọa an toàn của Triệu Vương lần nữa. Nếu thiếu nhân lực, nên tuyển chọn một nhóm vệ binh chính trực, tác phong tốt, võ lực mạnh mẽ để tăng cường bảo vệ Triệu Vương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 98000 điểm\n" 
 BLK "    Tiềm năng: 1750 điểm\n" 
 BLK "    Ngân lượng: 88000\n",
									   83:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm dò Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nội Chính Quan Triệu Quốc Bình Nguyên Quân gần đây cảm thấy dân chúng dường như ngày càng bất mãn, nhưng ông không nhận được báo cáo cụ thể nào. Ông lo ngại quan dưới che giấu, khiến chính lệnh không thông, tình hình dân chúng không đến được tai. Ông nhờ bạn làm đặc sứ đến dân gian nghe ngóng ý kiến.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 98000 điểm\n" 
 BLK "    Tiềm năng: 1800 điểm\n" 
 BLK "    Ngân lượng: 89000\n",
									   84:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt ác quan Tự Tam rồi báo cho Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bạn có nghe bài đồng dao “Trời chín đất ba, khó qua năm mới” chưa? Đất ba chính là ác quan Tự Tam. Hắn dựa vào chỗ dựa phía sau, lại nắm quyền lực, mượn danh thuế má để cưỡng đoạt tài sản, thậm chí cướp dân nữ, phá nhà cửa, lập danh mục để tư lợi. Mọi người đều sống trong sợ hãi, uy tín của Triệu Vương bị chà đạp. Nếu không trừ Tự Tam, e rằng lòng tin vào Đại Vương sẽ sụp đổ. Hiện Tự Tam đang làm khách ở " HIR "phía nam tầng ba Thiên Môn Trận" BLK ". Nếu bạn không trừ hắn, dân chúng Triệu Quốc Bá Tánh Ngô Cơ cũng không dám nói thêm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 97000 điểm\n" 
 BLK "    Tiềm năng: 1850 điểm\n" 
 BLK "    Ngân lượng: 90000\n",
									   85:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thư tố khổ cho Nội Chính Quan Triệu Quốc Bình Nguyên Quân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội Chính Quan Triệu Quốc Bình Nguyên Quân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Về “Trời chín” trong bài đồng dao lần trước, Triệu Quốc Bá Tánh Ngô Cơ không dám nói thẳng với bạn, sợ bạn nhất thời nóng giận gây họa. Cô ấy đã viết mọi chuyện gần đây vào một lá thư tố khổ, bạn hãy giao cho Nội Chính Quan để ông ấy quyết định.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 99000 điểm\n" 
 BLK "    Tiềm năng: 1800 điểm\n" 
 BLK "    Ngân lượng: 91000\n",
									   86:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Phó Điển Ngục Sứ Thái Cửu rồi báo cho Ngự Sử Triệu Quốc Mạc Thiên Hành\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự Sử Triệu Quốc Mạc Thiên Hành\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thì ra Phó Điển Ngục Sứ Thái Cửu thông đồng với quan địa phương, bóp méo pháp luật, áp bức dân chúng. Nội Chính Quan Triệu Quốc Bình Nguyên Quân đã thông báo cho Điển Ngục Quan và Tể Tướng, đồng ý trừng trị nghiêm khắc Thái Cửu. Ai ngờ Thái Cửu nghe phong thanh đã trốn vào Thiên Môn Trận, hiện đang lẩn trốn ở " HIR "phía nam tầng ba Thiên Môn Trận" BLK ", tưởng mình an toàn. Nội Chính Quan Triệu Quốc Bình Nguyên Quân yêu cầu bạn tiêu diệt Thái Cửu, sau đó báo cho Ngự Sử Triệu Quốc Mạc Thiên Hành.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 100000 điểm\n" 
 BLK "    Tiềm năng: 1950 điểm\n" 
 BLK "    Ngân lượng: 90000\n",
									   87:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao tấu chương thi hành chính sách cho Triệu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lần thăm dò dân tình này đã phơi bày nhiều vấn đề trong hệ thống pháp luật của nước ta, đáng để suy ngẫm. Ngự Sử Triệu Quốc Mạc Thiên Hành đã viết một tấu chương về luật pháp Triệu Quốc và việc thi hành, bạn hãy thay ông giao cho Triệu Vương, hy vọng ông ấy thi hành nhiều chính sách nhân từ để được lòng dân.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 96000 điểm\n" 
 BLK "    Tiềm năng: 1900 điểm\n" 
 BLK "    Ngân lượng: 92000\n",
									   88:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Hỏi Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Quốc Bá Tánh Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sứ thần Triệu Quốc Mao Toại khi đi ngang ngoại ô Hàm Đan thường nghe dân chúng bàn tán xôn xao về việc mất tích thường xuyên xảy ra ở đó. Ông rất lo lắng, nhưng vì nhiệm vụ không thể dừng lại lâu. Bạn hãy đến hỏi dân chúng nước này để tìm hiểu nguyên nhân sự việc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 93000 điểm\n" 
 BLK "    Tiềm năng: 1750 điểm\n" 
 BLK "    Ngân lượng: 91000\n",
									   89:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao thư thăm hỏi cho Lý Phòng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Phòng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Triệu Quốc Bá Tánh Ngô Cơ nghĩ rằng có một người có thể giúp bạn điều tra kỹ lưỡng việc này. Bạn sớm tìm ra sự thật để họ yên tâm. Ở khu vực lối vào Triệu Trường Thành, cô ấy có một người bạn tên Lý Phòng. Hãy mang thư thăm hỏi của Triệu Quốc Bá Tánh Ngô Cơ đến cho anh ta, có lẽ anh ta sẽ tiết lộ thêm tình hình.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 96000 điểm\n" 
 BLK "    Tiềm năng: 1900 điểm\n" 
 BLK "    Ngân lượng: 92000\n",
									   90:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt cường đạo Long Cửu Hồi Lai rồi báo cho Lý Phòng\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Phòng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Triệu Trường Thành tiêu diệt cường đạo Long Cửu Hồi Lai, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 99000 điểm\n" 
 BLK "    Tiềm năng: 1800 điểm\n" 
 BLK "    Ngân lượng: 91000\n",
									   91:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại danh sách người mất tích\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Điển Ngục Quan Triệu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Người chết đã mất, giờ chỉ có thể thông báo cho gia đình và lo hậu sự. Nơi Long Cửu hoạt động chắc chắn có danh sách những người mất tích, nghe nói danh sách đó được giấu trong một chiếc rương ở giữa tầng ba Thiên Môn Trận. Hãy đi lấy và giao cho Điển Ngục Quan Triệu Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 110000 điểm\n" 
 BLK "    Tiềm năng: 1850 điểm\n" 
 BLK "    Ngân lượng: 93000\n",
									   92:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao tấu chương điều tra cho Triệu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vụ việc cuối cùng đã sáng tỏ, nhưng kết quả thật khiến người ta xót xa. Điển Ngục Quan Triệu Quốc không ngờ trong địa hạt của mình lại có những kẻ hung ác đến vậy, thậm chí còn có đám phương sĩ yêu ma quỷ quái. Ông đã viết một tấu chương báo cáo vụ án cho Triệu Vương, nhờ bạn chuyển giao.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 120000 điểm\n" 
 BLK "    Tiềm năng: 2000 điểm\n" 
 BLK "    Ngân lượng: 92000 điểm\n" 
 BLK "    Vật phẩm: Yêu Đới cấp 110\n",
]),
							   TID_MAOSHAN:
								   ([1:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Mua một thanh kiếm gỗ đào và 10 lá bùa, giao cho Mậu Chân Nhân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mậu Chân Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hàn Đại Vương An đã trúng một loại tà thuật bị Mao Sơn cấm từ nhiều năm – Thuật Du Hồn. Trên đời này, chỉ có Mậu Chân Nhân của Mao Sơn mới có thể giải được tà thuật này. Mậu Chân Nhân yêu cầu tôi đi tìm một thanh " HIR "kiếm gỗ đào" BLK " và " HIR "10 lá bùa" BLK " mang về. Nếu số lần du hồn của Hàn Đại Vương An đạt đến 21 lần, sinh mệnh của ngài sẽ chấm dứt. Vì vậy, tôi không còn nhiều thời gian, phải nhanh chóng tìm kiếm thanh kiếm gỗ đào và 10 lá bùa để đưa cho Mậu Chân Nhân.\n" 
 BLK "    Đường đi nguy hiểm, tốt nhất tôi nên kết bạn đồng hành.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 12000 điểm\n" 
 BLK "    Tiềm năng: 215 điểm\n" 
 BLK "    Ngân lượng: 11000\n",
									   3:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Hoa Sơn bắt một con Chó Đốm, sau đó giao cho Mậu Chân Nhân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mậu Chân Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hàn Đại Vương An đã trúng một loại tà thuật bị Mao Sơn cấm từ nhiều năm – Thuật Du Hồn. Trên đời này, chỉ có Mậu Chân Nhân của Mao Sơn mới có thể giải được tà thuật này. Để phá giải Thuật Du Hồn, Mậu Chân Nhân cần một con Chó Đốm làm vật hiến tế để tế trời đất, từ đó tìm ra vị trí của kẻ thi triển tà thuật. Sinh mệnh của Hàn Đại Vương An phụ thuộc vào hiệu quả làm việc của tôi, tôi phải nhanh chóng đến khu vực " HIR "Hoa Sơn" BLK " bắt một con Chó Đốm mang về.\n" 
 BLK "    Đường đi nguy hiểm, tốt nhất tôi nên kết bạn đồng hành.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 17000 điểm\n" 
 BLK "    Tiềm năng: 280 điểm\n" 
 BLK "    Ngân lượng: 19000\n",
									   4:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt kẻ phản bội Mao Sơn Mã Ninh, sau đó báo lại cho Mậu Chân Nhân\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mậu Chân Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thực ra, kẻ thi triển Thuật Du Hồn lên Hàn Đại Vương An chính là đệ tử của Mậu Chân Nhân: Mã Ninh. Để trả thù Hàn Đại Vương An, hắn đã phản bội Mao Sơn, rơi vào ma đạo. Hiện tại, hắn đang ở " HIR "tầng một Hang Bí Ẩn" BLK " gần núi Thái Hành, thi triển thuật pháp lên Hàn Đại Vương An. Số lần du hồn của Hàn Đại Vương An đã đạt đến 20 lần, tôi phải phá giải Thuật Du Hồn trước lần du hồn thứ 21, nếu không sinh mệnh của Hàn Đại Vương An sẽ gặp nguy hiểm. Cách duy nhất để phá giải Thuật Du Hồn là tiêu diệt Mã Ninh.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 17000 điểm\n" 
 BLK "    Tiềm năng: 280 điểm\n" 
 BLK "    Ngân lượng: 19000\n",
									   6:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao tấm gương đã làm phép cho Hàn Đại Vương An\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Đại Vương An\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau bao khó khăn, cuối cùng Thuật Du Hồn đã được phá giải, và linh hồn bị hút đi qua 20 lần du hồn của Hàn Đại Vương An đã được thu hồi. Bây giờ, Mậu Chân Nhân giao cho tôi tấm gương chứa toàn bộ linh hồn bị hút đi của Hàn Đại Vương An. Chỉ cần tôi giao tấm gương này cho Hàn Đại Vương An, ngài sẽ được cứu. Tôi phải nhanh chóng đến Hàn Quốc để giao tấm gương này cho Hàn Đại Vương An, người đang còn rất ít thời gian sống!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 85000 điểm\n" 
 BLK "    Tiềm năng: 14000 điểm\n" 
 BLK "    Ngân lượng: 86000\n" 
 BLK "    Vật phẩm: Nón cấp 70\n",
]),
							  TID_YUNMENZE:
								  ([3:BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi Ngự Phong Đan đến chỗ Triệu Vương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hộp Ngự Phong Đan này được Quỷ Cốc Tử luyện chế trong ba ngày ba đêm, cuối cùng cũng thành công. Ông dặn bạn mang hộp này giao lại cho Triệu Vương, và nói với ông ấy rằng 4 viên đan dược trong hộp cần được uống vào ngày thứ nhất, thứ hai, thứ tư và thứ tám, mỗi lần vào giờ Ngọ khi dương khí mạnh nhất. Ngoài ra, mỗi ngày vào giờ Tý khi âm khí thịnh nhất, hãy cho ông ấy uống canh bổ được nấu chủ yếu từ nhân sâm ngàn năm. Hai thứ này bổ trợ lẫn nhau, nếu không có gì bất ngờ, trong vòng mười ngày Triệu Vương chắc chắn sẽ hồi phục.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 230000 điểm\n" 
 BLK "    Tiềm năng: 2450 điểm\n" 
 BLK "    Ngân lượng: 225000",
]),
]),

]);

mapping get_taskdesc() { return copy(mpTaskDesc); }

string get_task_str(object who, int iTask, int iKind)
{
	int i;
	string result = "";
	object item;
	if (iTask == TID_CHUGUO)
	{
		if (iKind == 1)
		{
			if (!objectp(present("Hàng hóa của Tiền Lão Cửu", who, 1, MAX_CARRY)))
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Lấy lại" HIR "Hàng hóa của Tiền Lão Cửu" BLK "bị tịch thu tại Sở Phương Thành\n" BLK "Hàng hóa của Tiền Lão Cửu 0/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tiền Lão Cửu Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Năm ngày trước, Tiền Lão Cửu chịu trách nhiệm vận chuyển một lô hàng, khi đi qua Sở Phương Thành thì bị lính canh tịch thu! Vì vậy, ông ấy ủy thác tôi giúp lấy lại lô hàng bị tịch thu đó, và hứa sẽ trả tôi rất nhiều thù lao sau khi hoàn thành. Cổng vào Sở Phương Thành nằm ở phía tây" HIR "Thập Lý Lâm" BLK ", từ thành Dĩnh xuất phát đi nửa canh giờ là đến. Tôi tin rằng lô hàng đó vẫn đang được lưu giữ tại Sở Phương Thành.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 5000";
			else
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Lấy lại" HIR "Hàng hóa của Tiền Lão Cửu" BLK "bị tịch thu tại Sở Phương Thành\n" BLK "Hàng hóa của Tiền Lão Cửu 1/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tiền Lão Cửu Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Năm ngày trước, Tiền Lão Cửu chịu trách nhiệm vận chuyển một lô hàng, khi đi qua Sở Phương Thành thì bị lính canh tịch thu! Vì vậy, ông ấy ủy thác tôi giúp lấy lại lô hàng bị tịch thu đó, và hứa sẽ trả tôi rất nhiều thù lao sau khi hoàn thành. Cổng vào Sở Phương Thành nằm ở phía tây Thập Lý Lâm, từ thành Dĩnh xuất phát đi nửa canh giờ là đến. Tôi tin rằng lô hàng đó vẫn đang được lưu giữ tại Sở Phương Thành.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 5000";
		}
		else if (iKind == 2)
		{
			if (objectp(item = present("Trân Châu Hạng Liên", who, 1, MAX_CARRY)) && item->is_xianglian())
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được Trân Châu Hạng Liên và giao cho" HIR "Tôn Lục Sở Quốc" BLK "\n" BLK "Trân Châu Hạng Liên 1/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tôn Lục Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôn Lục đã thầm yêu con gái của chủ khách sạn từ lâu, luôn tìm cách làm nàng vui lòng. Gần đây, anh ta tích cóp được ít tiền, mua một Trân Châu Hạng Liên để tặng nàng làm quà đính hôn, nhưng không may bị" HIR "Độc Giác Tiên" BLK "ở" HIR "Đào Hoa Nguyên" BLK "cướp mất. Tôi sẽ đi lấy lại nó!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 320 điểm\n" 
 BLK "    Tiềm năng: 40 điểm\n" 
 BLK "    Ngân lượng: 1000";
			else
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm được Trân Châu Hạng Liên và giao cho" HIR "Tôn Lục Sở Quốc" BLK "\n" BLK "Trân Châu Hạng Liên 0/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tôn Lục Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôn Lục đã thầm yêu con gái của chủ khách sạn từ lâu, luôn tìm cách làm nàng vui lòng. Gần đây, anh ta tích cóp được ít tiền, mua một Trân Châu Hạng Liên để tặng nàng làm quà đính hôn, nhưng không may bị" HIR "Độc Giác Tiên" BLK "ở" HIR "Đào Hoa Nguyên" BLK "cướp mất. Tôi sẽ đi lấy lại nó!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 320 điểm\n" 
 BLK "    Tiềm năng: 40 điểm\n" 
 BLK "    Ngân lượng: 1000";
		}
		else if (iKind == 3)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 18 con" HIR "Tứ cước xà" BLK " rồi báo cáo cho " HIR "Sở Quản Gia\n" BLK "Tứ cước xà %d/18\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sở Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Không biết vì lý do gì, gần đây khu vực" HIR "Hoa Sơn" BLK "xuất hiện rất nhiều Tứ cước xà, chúng còn thường xuyên tấn công các lữ khách và thương đội đi qua. Những con vật đáng ghét này đã gây cản trở nghiêm trọng đến việc giao thương bình thường giữa phủ Mị và thôn Đào Nguyên! Phủ Mị đã ban bố thông báo treo thưởng, kêu gọi các chí sĩ đến tiêu diệt lũ côn trùng gây hại này. Có vẻ như tôi cũng nên tham gia góp một tay, phủ Mị chắc chắn sẽ thưởng hậu hĩnh.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 400 điểm\n" 
 BLK "    Tiềm năng: 40 điểm\n" 
 BLK "    Ngân lượng: 3000\n" 
 BLK "    Vật phẩm: Yêu Đới cấp 10", who->get_save_2("sijiaose"));
		else if (iKind == 4)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm 3 viên" HIR "Đúc kiếm thạch" BLK " rồi báo cáo cho " HIR "Lưu Đầu\n" BLK "Đúc kiếm thạch %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lưu Đầu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Rèn được một thanh thần binh sắc bén như “Càn Tương Mạc Tà” luôn là giấc mơ bao năm của Lưu Đầu ở Sở Quốc. Gần đây, ý định rèn một thanh kiếm tốt càng trở nên mãnh liệt. Tuy nhiên, để rèn được một thanh thần binh kinh thế, cần có thiên thời, địa lợi, nhân hòa, không thể thiếu một thứ. Hiện tại, Lưu Đầu rất cần 3 viên" HIR "Đúc kiếm thạch" BLK " để hoàn thành tâm nguyện này. Tôi tin rằng ở khu vực" HIR "Hoa Sơn hoặc Triêu Dương Phong" BLK " có thể tìm thấy những viên đá này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 500 điểm\n" 
 BLK "    Tiềm năng: 50 điểm\n" 
 BLK "    Ngân lượng: 1300", who->get_save_2("xuantieshi"));
		else if (iKind == 5)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến" HIR "Hoa Sơn" BLK " giết một con" HIR "Chó Đốm" BLK " rồi báo cáo cho Lưu Đầu\n" BLK "Chó Đốm %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lưu Đầu ở Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Hoa Sơn giết một con Chó Đốm, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 550 điểm\n" 
 BLK "    Tiềm năng: 55 điểm\n" 
 BLK "    Ngân lượng: 1300", who->get_save_2("bandiangou"));
		else if (iKind == 7)
			result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm" HIR "Thương nhân Tề Quốc Nghi Đốn" BLK " để nói chuyện\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân Tề Quốc Nghi Đốn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thật ra tôi đã từng vô tình nhìn thấy viên ngọc Nam Hải một lần, đó thực sự là một món đồ quý giá, tỏa ra ánh sáng ấm áp, khiến lòng người ngay lập tức trở nên bình yên.\n" 
 BLK "    Gần đây, giá trị của châu báu tăng vọt, đặc biệt là viên ngọc Nam Hải được đẩy lên giá trên trời. May mắn thay, viên ngọc này vừa được người anh em ở Tề Quốc của tôi mua lại. Anh ta đã tốn không ít tiền cho viên ngọc Nam Hải này, tất nhiên cũng muốn bán được giá tốt. Anh ta luôn muốn tìm một chiếc hộp để đựng viên ngọc Nam Hải, nhưng mãi chưa tìm được cái phù hợp. Bạn hãy đến xem có thể giúp gì cho anh ta không, anh ta là một đại gia giàu có, sẽ không để bạn thiệt thòi đâu.\n" 
 BLK "    Anh ta đang ở trong thành Lâm Truy của" HIR "Tề Quốc" BLK ", qua cầu ở ngoài" HIR "Đại Vương Phủ" BLK " là bạn sẽ thấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 600 điểm\n" 
 BLK "    Tiềm năng: 20 điểm";
		else if (iKind == 8)
			result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm" HIR "Công Thâu Ban tài khéo ở Chu Quốc" BLK " để làm hộp\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban tài khéo ở Chu Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    " HIR "Thương nhân Tề Quốc Nghi Đốn" BLK " đã mua được một viên ngọc quý, muốn đóng gói cẩn thận để bán với giá tốt, nhưng mãi không tìm được một chiếc hộp đẹp. Tôi sẽ đến chỗ Công Thâu Ban tài khéo ở Chu Quốc để làm một cái!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 600 điểm\n" 
 BLK "    Tiềm năng: 10 điểm\n" 
 BLK "    Ngân lượng: 1000 lượng";
		else if (iKind == 10)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 Sừng Thú giao cho" HIR "Thủ Vệ Sở Quốc\n" BLK "Sừng Thú %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thủ Vệ Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mẹ của Thủ Vệ Sở Quốc đang bệnh rất nặng, đã đi nhiều thầy thuốc nhưng không khỏi. Anh ta nghe được một bài thuốc dân gian, nói rằng dùng 20 Sừng Thú nấu thành một bát nước, uống vào sẽ khỏi bệnh. Nhưng từ xưa trung hiếu khó vẹn toàn, anh ta phải canh gác cổng thành mỗi ngày, thực sự không có thời gian. Một người lính canh hiếu thảo như vậy, tôi sẽ giúp anh ta hoàn thành việc này!\n" BLK "   Nghe nói ở khu vực" HIR "Hàm Cốc Quan" BLK " có những con" HIR "Độc Nhãn Thú" BLK " mang Sừng Thú.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 850 điểm\n" 
 BLK "    Tiềm năng: 50 điểm\n" 
 BLK "    Ngân lượng: 1200", who->get_save_2("souweisoujiao"));
		else if (iKind == 13)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm 6 bộ Y Phục giao cho" HIR "Nội Chính Quan Sở Quốc\n" BLK "Y Phục %d/6\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội Chính Quan Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nội Chính Quan Sở Quốc chắc hẳn đã đợi rất lâu mới có người chịu giúp ông ta việc này.\n" 
 BLK "    Ông ta nói Y Phục của Thủ Vệ Sở Quốc đã không còn đủ để giữ ấm, nhưng hiện tại nội chính bận rộn, không đủ nhân lực để mua sắm. Tuy số lượng không nhiều, nhưng yêu cầu rất cao, cần chọn lựa kỹ càng. Y Phục của lính canh không chỉ phải chất lượng tốt, đủ để giữ ấm, mà còn phải đẹp và giá rẻ.\n" 
 BLK "    Nội Chính Quan Sở Quốc nghe nói ở khu vực" HIR "Đầm Lầy" BLK " có một lô Y Phục tốt từ" HIR "Nhện Quái" BLK ", nên bảo tôi đi một chuyến, khi xong việc ông ta sẽ trả thù lao cho tôi!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3500 điểm\n" 
 BLK "    Tiềm năng: 70 điểm\n" 
 BLK "    Ngân lượng: 3000", who->get_save_2("cgyifu"));
		else if (iKind == 29)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến tầng 1 hang Linh Cốc gần Tề Quốc tiêu diệt Đậu Binh, lấy Hoa Nhài giao cho dân chúng Sở Quốc.\n" BLK "Hoa Nhài: %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dân chúng Sở Quốc nói rằng Đậu Binh ở tầng 1 hang Linh Cốc có một số Hoa Nhài, nếu tôi lấy được, ông ấy sẽ nhanh chóng chế tạo Trà Nhài mà tôi cần.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 22000 điểm\n" 
 BLK "    Tiềm năng: 300 điểm\n" 
 BLK "    Ngân lượng: 21000", who->get_save_2("cgbxmolihua"));
		else if (iKind == 30)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Nước Tuyết ở Trường Bạch Thiên Trì, giao cho" HIR "Dân chúng Sở Quốc Hàn Nhượng\n" BLK "Nước Tuyết %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng Sở Quốc Hàn Nhượng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, Tề Vương vì việc bá chủ thất quốc mà ăn không ngon, đêm không ngủ được. Có người nói với ông rằng ở Sở Quốc có một loại Trà Nhài giúp tăng cảm giác ngon miệng và cải thiện giấc ngủ. Vì vậy, Tề Vương nhờ tôi đến dân gian Sở Quốc tìm loại Trà Nhài này. Dân chúng Sở Quốc quả thực biết cách pha loại trà này, và tôi đã tìm được Hoa Nhài để pha trà, nhưng để Hoa Nhài phát huy tác dụng tăng cảm giác ngon miệng và cải thiện giấc ngủ, cần phải dùng Nước Tuyết ở Trường Bạch Thiên Trì để pha. Có vẻ như tôi phải đến đó tìm trên người Mãng Lượng và Hoa Báo Tinh để lấy Nước Tuyết này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 22000 điểm\n" 
 BLK "    Tiềm năng: 300 điểm\n" 
 BLK "    Ngân lượng: 21000", who->get_legend(TASK_24, 13) ? 1 : 0);
		else if (iKind == 33)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt kẻ sát hại ông nội - 5 con Lượng Tinh và 7 con Mộc Tinh ở hang Hư Lăng, rồi báo cáo cho Lưu Đầu để hỏi về việc thừa kế di sản\n" BLK "Lượng Tinh %d/5\n" BLK "Mộc Tinh %d/7\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lưu Đầu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hóa ra ông nội của Đinh Hạc Niên bị Lượng Tinh và Mộc Tinh ở hang Hư Lăng hại chết. Thôi được,既然 Đinh Hạc Niên đã ủy thác tôi làm việc này, tôi cũng nên tận tâm tận lực giúp cậu ta. Trước tiên, tôi sẽ đến hang Hư Lăng để báo thù cho ông nội cậu ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 37000 điểm\n" 
 BLK "    Tiềm năng: 633 điểm\n" 
 BLK "    Ngân lượng: 33500", who->get_save("ltjinj"), who->get_save("ltmuj"));
		else if (iKind == 34)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm rương báu chứa bản đồ chỉ dẫn đến hang chứa kho báu, rồi giao cho Đinh Hạc Niên\n" BLK "Rương báu %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đinh Hạc Niên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lưu Đầu nói với tôi, để tìm được rương báu của ông nội Đinh Hạc Niên, trước tiên phải đi qua hang Hư Lăng, đến một nơi gọi là Tiểu Sơn Đạo. Khi gần đến một lối vào khác, sẽ có một khoảng đất trống lớn, tìm cái bình vỡ trên mặt đất, có lẽ rương báu được chôn dưới đó.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 160000 điểm\n" 
 BLK "    Tiềm năng: 2000 điểm\n" 
 BLK "    Ngân lượng: 150000\n" 
 BLK "    Vật phẩm: Vũ khí cấp 90", who->get_legend(TASK_33, 5) ? 1 : 0);
		else if (iKind == 35)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến hang Hư Lăng tiêu diệt 7 con Thủy Tinh và 6 con Thổ Tinh, rồi trở về báo cáo cho Thủ Vệ Sở Quốc\n" BLK "Thủy Tinh %d/7\n" BLK "Thổ Tinh %d/6\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thủ Vệ Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thủ Vệ Sở Quốc từ nhỏ có một dị năng, đó là nghe được lời của gia cầm. Mẹ anh ta rất sợ, cấm anh ta không được nói với người khác. Nhưng gần đây, gà vịt nhà hàng xóm bỗng nhiên mất tích không rõ lý do. Anh ta không nhịn được, lại nghe lời của những con gà vịt còn lại, phát hiện ra là" HIR "Thủy Tinh và Thổ Tinh" BLK "ở" HIR "hang Hư Lăng" BLK "đã trộm chúng đi, nói là để tế Ngũ Tạng Miếu. Ngũ Tạng Miếu ở đâu thì anh ta không biết, nhưng anh ta coi những con gà vịt này như anh em của mình, không muốn chúng gặp bất trắc. Tuy nhiên, mẹ anh ta cấm anh ta rời khỏi nhiệm vụ canh gác, nên anh ta muốn ủy thác bạn giúp đỡ. Chắc chắn bạn sẽ vui lòng giúp anh ta chứ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 63000 điểm\n" 
 BLK "    Tiềm năng: 908 điểm\n" 
 BLK "    Ngân lượng: 54500", who->get_save("cgswsuijing"), who->get_save("cgswtujing"));
		else if (iKind == 36)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 Lá Trà Quan Vũ, giao cho Thủ Vệ Sở Quốc\n" BLK "Lá Trà Quan Vũ %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thủ Vệ Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Cha già của Thủ Vệ Sở Quốc gần đây đột nhiên nói rằng đã nhiều năm không được thưởng thức Trà Quan Vũ ở hang Hư Lăng. Ông nói năm xưa lạc đường, gặp được hai vị tiên nhân và được họ cho trà. Ông nói gần đây có lẽ không qua khỏi, nên thúc giục Thủ Vệ Sở Quốc tìm lại để hoàn thành tâm nguyện. Nhưng anh ta chỉ là một lính quèn, làm sao có khả năng đến" HIR "hang Hư Lăng" BLK " xin trà từ tiên nhân. Nghe nói bạn thân thủ bất phàm, thường giao thiệp với tiên nhân, liệu bạn có thể giúp cha anh ta hoàn thành tâm nguyện không? Chỉ cần 20 lá trà đủ để pha một lần là được.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 70000 điểm\n" 
 BLK "    Tiềm năng: 925 điểm\n" 
 BLK "    Ngân lượng: 58000", who->get_save("cgswtiegy"));
		else if (iKind == 37)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm 11 bông Hoa Hồng ở hang Hư Lăng, giao cho Thủ Vệ Sở Quốc\n" BLK "Hoa Hồng %d/11\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thủ Vệ Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, Thủ Vệ Sở Quốc nói rằng mỗi đêm đều không ngủ được, mỗi ngày đến gác cổng đều mang quầng thâm mắt. Hóa ra anh ta đang thầm yêu một người, nhưng vẫn chưa dám tỏ tình. Nghe nói Hoa Hồng tượng trưng cho tình yêu, anh ta muốn tặng người ấy 11 bông Hoa Hồng. Nhưng viên quan gác cổng không cho nghỉ phép, anh ta không có thời gian đến hang Hư Lăng tìm hoa. Bạn có thể giúp anh ta lấy chúng không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 63500 điểm\n" 
 BLK "    Tiềm năng: 910 điểm\n" 
 BLK "    Ngân lượng: 55000", who->get_save("cgswmeigui"));
		else if (iKind == 39)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Hỏa Tinh, Thổ Tinh để lấy lại Búa Gỗ và Cái Bào, giao cho Công Tượng Sở Quốc\n" BLK "Búa Gỗ của thợ thủ công %d/1\n" BLK "Cái Bào của thợ thủ công %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Tượng Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Những" HIR "Hỏa Tinh, Thổ Tinh" BLK " từng thuê Dân chúng Sở Quốc Hàn Nhượng làm một số việc không thể để lộ. Giờ đây, anh ta rất hối hận, nhưng bọn yêu tinh sợ anh ta tiết lộ chuyện này nên định trừ khử anh ta! Vì vậy, đừng bao giờ tin bọn yêu tinh. Vấn đề bây giờ là anh ta vẫn còn một số đồ vật trong tay chúng, đó là Búa Gỗ và Cái Bào mượn của thợ thủ công. Khi tôi lấy lại được, cứ giao trực tiếp cho Công Tượng Sở Quốc là được.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 64000 điểm\n" 
 BLK "    Tiềm năng: 910 điểm\n" 
 BLK "    Ngân lượng: 55000", who->get_save("cgbxmuz"), who->get_save("cgbxpaoz"));
		else if (iKind == 40)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Thủy Tinh và Hỏa Tinh đã cướp thực phẩm, rồi trở về báo cáo cho Công Tượng Sở Quốc\n" BLK "Thủy Tinh %d/10\n" BLK "Hỏa Tinh %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Tượng Sở Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ở Sở Quốc, cuộc chiến giữa yêu tinh và con người đã kéo dài từ lâu. Vì thực phẩm, Thủy Tinh và Hỏa Tinh sinh sôi ngày càng nhiều, thực phẩm quanh chúng không còn đủ đáp ứng nhu cầu. Thế là chúng ỷ vào phép thuật biến đổi ngũ hành, cướp đi thực phẩm mà Công Tượng Sở Quốc dựa vào để sinh sống. Dù có thể thực phẩm đã bị chúng ăn hết, nhưng họ không thể nuốt trôi cục tức này. Vì vậy, bạn hãy đi tiêu diệt Thủy Tinh và Hỏa Tinh, rồi trở lại báo cáo cho Công Tượng Sở Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 72000 điểm\n" 
 BLK "    Tiềm năng: 935 điểm\n" 
 BLK "    Ngân lượng: 60000", who->get_save("cggjsuij"), who->get_save("cggjhuoj"));
		else if (iKind == 41)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 12 Thương Hồn - nguồn gốc của mọi tội ác, rồi trở về báo cáo cho Đại Vương Sở Quốc Khảo Liệt\n" BLK "Thương Hồn %d/12\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Vương Sở Quốc Khảo Liệt\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bạn muốn trở thành người được mọi người kính ngưỡng, tất nhiên cần có đức hạnh, phẩm chất, lòng nhân ái và sự trung thành, nhưng còn cần một thứ nữa, đó là võ lực. Đại Vương Sở Quốc Khảo Liệt khá tán thưởng bạn, nhưng về mặt võ lực, ông ấy vẫn cần kiểm tra thêm. Gần đây, dân chúng trong thành bị đau đầu không rõ nguyên nhân, sau khi điều tra phát hiện ra là do Thương Hồn trong Tru Tiên Trận gây rối. Nếu bạn có thể tiêu diệt 12 Thương Hồn độc ác này, khi đó ông ấy sẽ thông báo khắp thành, dân chúng tự nhiên sẽ kính ngưỡng bạn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 91500 điểm\n" 
 BLK "    Tiềm năng: 988 điểm\n" 
 BLK "    Ngân lượng: 95000", who->get_save("cwqianhun"));
	}
	else if (iTask == TID_WEIGUO)
	{
		if (iKind == 1)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 Dây buộc tóc giao cho Tiểu thư Sa Tiễn\n" BLK "Dây buộc tóc %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tiểu thư Sa Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Anh cả nhà nhị cô của Tiểu thư Sa Tiễn sắp cưới vợ, cha cô ấy bảo cô cùng đi dự tiệc chúc mừng. Là một tiểu thư khuê các, ra ngoài phải trang điểm cho thật đẹp, cô ấy nói muốn ăn mặc lộng lẫy để không làm cha mất mặt, nên muốn tết tóc thành vài bím. Tiếc là bên cạnh cô chỉ có trâm cài, không có dây buộc tóc, nên cô nhờ tôi tìm 20 Dây buộc tóc.\n" 
 BLK "    Khu vực Quế Lăng, Mục Dã có đám" HIR "Thảo khấu" BLK " tuy hung dữ, nhưng rất tốt với vợ ở nhà, chắc hẳn trên người chúng có Dây buộc tóc tặng cho vợ. Nên tôi đến đó chắc chắn sẽ tìm được.\n" 
 BLK "    Đường không xa, tôi phải nhanh chóng tìm cho cô ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 2000 điểm\n" 
 BLK "    Tiềm năng: 60 điểm\n" 
 BLK "    Ngân lượng: 1500", who->get_save_2("saqianfashen"));
		else if (iKind == 2)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay Chu Đồng tiêu diệt 15 Thổ phỉ\n" BLK "Thổ phỉ %d/15\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Đồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chu Đồng vốn định nhờ cha dẫn đi chơi vài ngày, nhưng hôm qua một đám Thổ phỉ đến nhà, cướp sạch tài sản và còn đánh cha cậu bị thương, giờ cha cậu phải nằm liệt giường. Chu Đồng muốn báo thù cho cha, nhưng còn nhỏ tuổi, sức yếu, không đủ khả năng, nên ủy thác tôi làm việc này!\n" 
 BLK "    Tôi nhất định sẽ đòi lại công lý! Đám Thổ phỉ có tổng cộng" HIR "15" BLK " người, tụ tập ở khu vực" HIR "Mục Dã" BLK ".\n" 
 BLK "    Từ Ngụy Quốc đi qua Quế Lăng là đến Mục Dã.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 1800 điểm\n" 
 BLK "    Tiềm năng: 70 điểm\n" 
 BLK "    Ngân lượng: 1200", who->get_save_2("zuietufei"));
		else if (iKind == 3)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20" HIR "Thảo khấu trộm gà" BLK " rồi báo cáo cho" HIR "Lý Tam Thẩm\n" BLK "Thảo khấu %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Tam Thẩm\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lý Tam Thẩm nói bà nuôi một đàn gà, định bán trứng để kiếm ít tiền mua sắm đồ đạc, sửa sang nhà cửa, nhưng đàn gà của bà bị bọn trộm nhòm ngó, hôm nay mất một con, ngày mai mất hai con, giờ thì bị trộm sạch. Bọn trộm này, nếu không dạy cho chúng một bài học, chúng sẽ càng làm càn!\n" 
 BLK "    Qua quan sát, bà phát hiện đám trộm gà thực chất là một đám Thảo khấu, không chỉ trộm gà mà còn làm đủ điều ác, đáng chết muôn phần! Vì vậy, bà nhờ tôi dạy cho đám Thảo khấu đó một bài học. Chúng có 20 người, hiện đang lẩn trốn gây án ở khu vực" HIR "Bình Nguyên" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 2500 điểm\n" 
 BLK "    Tiềm năng: 50 điểm\n" 
 BLK "    Ngân lượng: 1000", who->get_save_2("toujizei"));
		else if (iKind == 4)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10 vò Rượu vang đỏ giao cho Mạnh Cầu\n" BLK "Rượu vang đỏ %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mạnh Cầu Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mạnh Cầu phấn khởi nói với tôi rằng anh ta sắp đến thăm Đinh Hạc Niên ở Yên Quốc, đây là điều anh ta ngày đêm mong mỏi!\n" 
 BLK "    Đinh Hạc Niên ở Yên Quốc là một người rất tuyệt vời, họ đã kết giao qua thư từ lâu, Mạnh Cầu rất ngưỡng mộ tài học của anh ta. Qua thư, anh ta biết Đinh Hạc Niên sống trong thành Yên Quốc, luôn muốn đến thăm, nhưng khổ nỗi không có món quà nào ra hồn để mang theo.\n" 
 BLK "    Mạnh Cầu nghe nói lính tuần tra Yên Quốc ở Dịch Thủy thích uống rượu, cất giữ một lô Rượu vang đỏ, nên nhờ tôi giúp tìm 10 vò.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 1500 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 1200", who->get_save_2("haophatóu"));
		else if (iKind == 5)
		{
			if (who->get_legend(TASK_07, 8) && !who->get_legend(TASK_07, 9))
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao tiền lộ phí mượn được cho Mạnh Cầu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mạnh Cầu Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tuy dân chúng Ngụy Quốc Nhạc Dương cũng đang túng thiếu, nhưng sau khi tôi thu thập được 10 Hoa mẫu đơn núi, anh ta vẫn gom đủ tiền lộ phí cho Mạnh Cầu và nhờ tôi mang đến. Giờ tôi phải nhanh chóng đưa cho Mạnh Cầu, để anh ta sớm lên đường đến Yên Quốc thăm Đinh Hạc Niên, cũng coi như hoàn thành tâm nguyện bấy lâu của anh ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5000 điểm\n" 
 BLK "    Tiềm năng: 160 điểm\n" 
 BLK "    Ngân lượng: 4000";
			else
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay Mạnh Cầu mượn tiền lộ phí từ dân chúng Ngụy Quốc Nhạc Dương\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng Ngụy Quốc Nhạc Dương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôi đã tìm được Rượu vang đỏ cho Mạnh Cầu, anh ta tưởng tượng cảnh cùng Đinh Hạc Niên nâng chén trò chuyện thật là thích thú. Tôi cũng coi như làm được một việc tốt, hì hì.\n" 
 BLK "    Nhưng anh ta lại nói với tôi, sau khi tính toán, thấy tiền lộ phí chuẩn bị dường như không đủ. Đường xa, mà anh ta là một thư sinh, mặt mũi mỏng, nếu đến lúc phải đi ăn xin dọc đường thì tuyệt đối không được!\n" 
 BLK "    Anh ta nói bình thường có giao hảo với dân chúng Ngụy Quốc Nhạc Dương, hiện anh ấy sống trong thành Ngụy, nhờ tôi đến mượn giúp ít tiền lộ phí từ Nhạc Dương, nói rằng khi từ Yên Quốc trở về sẽ trả lại!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 1000 điểm\n" 
 BLK "    Tiềm năng: 10 điểm\n" 
 BLK "    Ngân lượng: 1000";
		}
		else if (iKind == 6)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10" HIR "Hoa mẫu đơn núi" BLK " để đổi tiền lộ phí giao cho" HIR "Dân chúng Ngụy Quốc Nhạc Dương\n" BLK "Hoa mẫu đơn núi %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng Ngụy Quốc Nhạc Dương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôi đã tìm được Rượu vang đỏ cho Mạnh Cầu, nhưng anh ta nói tiền lộ phí đi Yên Quốc vẫn còn thiếu, muốn tôi giúp mượn tiền từ dân chúng Ngụy Quốc Nhạc Dương sống trong thành Ngụy.\n" 
 BLK "    Nhưng khi tôi tìm đến Nhạc Dương, anh ta nói hiện đang túng thiếu, rồi đưa ra cách là bảo tôi đi thu thập Hoa mẫu đơn núi. Theo anh ta biết, Hoa mẫu đơn núi là loại hoa có giá cao nhất và bán chạy nhất ở chợ, nhưng thu thập khá khó khăn, chỉ có" HIR "Hỏa Quỷ sông Vô Định" BLK " mới có. Nhạc Dương nói nếu tôi muốn giúp Mạnh Cầu, hãy đến sông Vô Định tìm Hoa mẫu đơn núi, anh ta ước tính bán được 10 bông là đủ tiền lộ phí cho Mạnh Cầu.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 1500 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 1300", who->get_save_2("sansaoyao"));
		else if (iKind == 7)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 7 con Hạt Vĩ Hạt rồi báo cáo cho Chu Cuồng\n" BLK "Hạt Vĩ Hạt %d/7\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Cuồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Ranh Giới Đầm Lầy giết 7 con Hạt Vĩ Hạt, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 2800 điểm\n" 
 BLK "    Tiềm năng: 90 điểm\n" 
 BLK "    Ngân lượng: 2000", who->get_save_2("heweixie"));
		else if (iKind == 8)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20" HIR "Bí ngô" BLK " giao cho" HIR "Ngụy Quản Gia\n" BLK "Bí ngô %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngụy Quản Gia gần đây hơi phiền lòng, vì có một thầy bói được cho là rất linh đến nhà ông ta cách đây hai hôm, đưa cho ông ba túi gấm, nói rằng tháng này ông sẽ gặp ba kiếp nạn, và dặn tuyệt đối không được tự ý mở ba túi gấm này, phải đợi một người đến tìm ông mới được mở! Không ngờ người đó lại là tôi!\n" 
 BLK "    Ngụy Quản Gia mở túi gấm đầu tiên, nói rằng cần tôi thu thập 20 Bí ngô để hóa giải kiếp nạn đầu tiên của ông, mà loại Bí ngô này chỉ có thể lấy được từ việc tiêu diệt" HIR "Ngưu Đầu Quái" BLK " ở khu vực" HIR "Đại Biệt Sơn" BLK ".\n" 
 BLK "    Tôi nghĩ mình vẫn nên giúp ông ấy, ông ấy sắp gặp kiếp nạn, thật đáng thương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 1800 điểm\n" 
 BLK "    Tiềm năng: 40 điểm\n" 
 BLK "    Ngân lượng: 1500", who->get_save_2("wgjnangua"));
		else if (iKind == 9)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20" HIR "Trư Yêu" BLK " và 10" HIR "Chó Sài" BLK " rồi trở về báo cáo cho" HIR "Ngụy Quản Gia\n" BLK "Trư Yêu %d/20\n" BLK "Chó Sài %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Có một thầy bói tiên đoán cho Ngụy Quản Gia rằng tháng này ông sẽ gặp ba kiếp nạn, và đưa cho ông ba túi gấm để hóa giải từng kiếp nạn.\n" 
 BLK "    Cách hóa giải kiếp nạn đầu tiên là thu thập 20 Bí ngô, tôi đã làm xong cho ông. Còn để hóa giải kiếp nạn thứ hai, cần tiêu diệt 20 Trư Yêu và 10 Chó Sài ở khu vực" HIR "Vu Sơn, hồ Bà Dương" BLK ", và còn ám chỉ rằng nếu người hóa giải kiếp nạn đầu tiên làm việc này thì sẽ tốt hơn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 1800 điểm\n" 
 BLK "    Tiềm năng: 40 điểm\n" 
 BLK "    Ngân lượng: 1500", who->get_save_2("wgjzhuyao"), who->get_save_2("wgjcaigou"));
		else if (iKind == 26)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 3 Củ sen, 2 Ngô, 4 Củ cải giao cho Tôn Thiếu Gia\n" BLK "Củ sen %d/3 Ngô %d/2 Củ cải %d/4\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tôn Thiếu Gia Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôn Thiếu Gia đúng là một công tử ăn chơi, đến cả món canh cho bữa tối cũng kén chọn như vậy! Anh ta nói nguyên liệu nấu canh phải tươi nhất, canh nấu ra mới giữ được hương vị nguyên bản, lửa cũng phải vừa đúng độ. Hôm nay, anh ta muốn uống canh nấu từ 3 Củ sen, 2 Ngô, 4 Củ cải. Nếu không phải vì anh ta hứa trả thù lao, tôi đã chẳng thèm để ý!\n" 
 BLK "    Củ sen và Ngô có thể lấy từ việc tiêu diệt" HIR "Ong Độc" BLK " ở khu vực" HIR "Đầm Lầy" BLK ", còn Củ cải phải đến" HIR "Đại Biệt Sơn tiêu diệt Ngưu Đầu Quái" BLK " mới có. Thật phiền phức!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3000 điểm\n" 
 BLK "    Tiềm năng: 60 điểm\n" 
 BLK "    Ngân lượng: 2000\n" 
 BLK "    Vật phẩm: Mũ lượng sắc cấp 30", who->get_save_2("ssylianou"), who->get_save_2("ssyyumi"), who->get_save_2("ssyluobo"));
		else if (iKind == 27)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến" HIR "Làng Bạch Lộ ở Dịch Thủy" BLK " tìm Hà Thủ Ô giao cho" HIR "Lý Đại Mao\n" BLK "Hà Thủ Ô %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đại Mao\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hạt giống hồ lô lớn quá quý giá, Lý Đại Mao không chịu dễ dàng đưa cho bạn. Anh ta nói đó là thứ anh ta cầu xin từ tiên nhân, vốn muốn xin thuốc trường sinh bất lão nhưng tiên nhân không cho, nghe nói ở" HIR "Làng Bạch Lộ ở Dịch Thủy" BLK " có Hà Thủ Ô hình người, nghiền thành bột uống có thể trường sinh bất lão. Nếu bạn tìm được cái này cho anh ta, anh ta sẽ đồng ý đổi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3830 điểm\n" 
 BLK "    Tiềm năng: 165 điểm\n" 
 BLK "    Ngân lượng: 3500", who->get_legend(TASK_19, 4) ? 1 : 0);
		else if (iKind == 29)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập Xuyên Tâm Liên, Đông Trùng Hạ Thảo, Kim Ngân Hoa giao cho Tầm Nhi\n" BLK "Xuyên Tâm Liên %d/5\n" BLK "Đông Trùng Hạ Thảo %d/5\n" BLK "Kim Ngân Hoa %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tầm Nhi\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tầm Nhi vì tương tư quá độ mà mắc bệnh tương tư mãn tính, cần điều trị. Tôi làm người tốt đến cùng, sẽ đến Vịnh Đạo thu thập Xuyên Tâm Liên, Đông Trùng Hạ Thảo, Kim Ngân Hoa cho cô ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 56000 điểm\n" 
 BLK "    Tiềm năng: 830 điểm\n" 
 BLK "    Ngân lượng: 57000\n" 
 BLK "    Vật phẩm: Yêu Đới cấp 70", who->get_save_2("xercuanxinlian"), who->get_save_2("xerdongcongcao"), who->get_save_2("xerjinyinhua"));
		else if (iKind == 30)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến tầng 1 Lăng Mộ Tướng Quân tìm Cổ Ngọc giao cho Thủ Vệ Ngụy Quốc\n" BLK "Cổ Ngọc %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thủ Vệ Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thủ Vệ Ngụy Quốc nói rằng tổ tiên ba đời của anh ta là những người sưu tầm báu vật phong thủy - biệt danh là đạo mộ giả. Sau khi nói lan man một hồi, anh ta mới vào vấn đề chính, rằng anh ta muốn một khối Cổ Ngọc được cất giấu gần đây trong" HIR "Lăng Mộ Tướng Quân" BLK ", nhờ bạn giúp đi tìm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 47000 điểm\n" 
 BLK "    Tiềm năng: 690 điểm\n" 
 BLK "    Ngân lượng: 47000", who->get_legend(TASK_28, 24) ? 1 : 0);
		else if (iKind == 31)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Vạn Nhân Khanh tìm Linh Chi Thảo, Tiền, Tiểu Mễ giao cho Thủ Vệ Ngụy Quốc\n" BLK "Linh Chi Thảo %d/1\n" BLK "Tiền %d/1\n" BLK "Tiểu Mễ %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thủ Vệ Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thủ Vệ Ngụy Quốc thật đáng thương, vợ anh ta bị bệnh, đồ đạc đáng giá trong nhà đều đã cầm cố, có thể mượn cũng đã mượn hết. Tôi sẽ đến" HIR "Vạn Nhân Khanh" BLK " tìm ít thứ cứu mạng cho anh ta, như Linh Chi Thảo, Tiểu Mễ chẳng hạn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 53000 điểm\n" 
 BLK "    Tiềm năng: 740 điểm\n" 
 BLK "    Ngân lượng: 50000", who->get_save("wgswlingzc"), who->get_save("wgswqian"), who->get_save("wgswxiaomi"));
		else if (iKind == 32)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20 Sư Tử Đá rồi báo cáo cho Đại Tướng Quân Ngụy Quốc Tấn Tất\n" BLK "Sư Tử Đá %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại Tướng Quân Ngụy Quốc Tấn Tất\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại Tướng Quân Ngụy Quốc Tấn Tất nói rằng trong" HIR "Lăng Mộ Tướng Quân" BLK " có một loại cơ quan kỳ lạ, hình dạng là" HIR "Sư Tử Đá" BLK ", nhưng bên trong ẩn chứa nhiều kim độc và cơ quan quái lạ. Những người vào thường nghĩ chúng chỉ là vật trang trí mà lơ là, kết quả nhiều người mất mạng. Gần đây, Đại Vương phái Công tử đi rèn luyện trong đó, nhưng Tấn Tất lo sợ Sư Tử Đá sẽ làm hại Công tử. Ông ta yêu cầu bạn tiêu diệt 20 Sư Tử Đá trước để đảm bảo an toàn cho Công tử.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 52000 điểm\n" 
 BLK "    Tiềm năng: 720 điểm\n" 
 BLK "    Ngân lượng: 48000", who->get_save("wgdjjshisi"));
		else if (iKind == 33)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 Ngọc Điêu giao cho Dân chúng Ngụy Quốc Nhạc Dương\n" BLK "Ngọc Điêu %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng Ngụy Quốc Nhạc Dương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Con trai của Dân chúng Ngụy Quốc Nhạc Dương hôm qua đi chơi với cô bé hàng xóm, kết quả cô bé khóc lóc chạy về, nói có một gã hung dữ bắt cóc con trai anh ta, đòi dùng Ngọc Điêu gia truyền để đổi. Ôi, đều tại tôi trước đây khoe khoang khắp nơi, thực ra thứ đó đâu phải gia truyền, chỉ là lần tôi theo một hiệp sĩ vào Lăng Mộ Tướng Quân nhặt được khi người đó không để ý, rồi đem bán hết lấy tiền tiêu xài. Giờ tôi đâu có khả năng một mình vào Lăng Mộ Tướng Quân lấy Ngọc Điêu nữa. Anh ta thấy bạn có thân thủ tốt, nhờ bạn giúp đến" HIR "Lăng Mộ Tướng Quân" BLK " thu thập" HIR "20 Ngọc Điêu" BLK " để đổi lấy con trai anh ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 54000 điểm\n" 
 BLK "    Tiềm năng: 745 điểm\n" 
 BLK "    Ngân lượng: 50000", who->get_save("wgbxyudiao"));
		else if (iKind == 34)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 Thạch Hổ, 8 Đao Tượng rồi tìm Thủ Vệ Ngụy Quốc\n" BLK "Thạch Hổ %d/10\n" BLK "Đao Tượng %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thủ Vệ Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thủ Vệ Ngụy Quốc nói rằng bất kể làm gì cũng không dễ dàng. Để cảnh tỉnh bạn vì coi thường công việc của lính canh, anh ta yêu cầu bạn đến" HIR "Lăng Mộ Tướng Quân" BLK " tiêu diệt" HIR "10 Thạch Hổ, 8 Đao Tượng" BLK " rồi quay lại tìm anh ta.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 52000 điểm\n" 
 BLK "    Tiềm năng: 720 điểm\n" 
 BLK "    Ngân lượng: 48000", who->get_save("wgswshihu"), who->get_save("wgswdaoyong"));
		else if (iKind == 35)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Theo lệnh Ngụy Chiêu Đại Vương, đến Lăng Mộ Tướng Quân tiêu diệt 9 Thương Tượng, 12 Kiếm Tượng\n" BLK "Thương Tượng %d/9\n" BLK "Kiếm Tượng %d/12\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Chiêu Đại Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Có kẻ dùng tà thuật điều khiển Thương Tượng và Kiếm Tượng, định ám sát khi Mạnh Thường Quân thay mặt ta tế lễ ở lăng tẩm tổ tiên. Sau khi thất bại, chúng trốn vào Lăng Mộ Tướng Quân. Những kẻ cả gan này phải bị trừng trị nghiêm khắc! Bạn hãy đến Lăng Mộ Tướng Quân tiêu diệt 9 Thương Tượng và 12 Kiếm Tượng đang lẩn trốn, đồng thời xem có thể tìm ra manh mối của kẻ đứng sau hay không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 60000 điểm\n" 
 BLK "    Tiềm năng: 900 điểm\n" 
 BLK "    Ngân lượng: 50000", who->get_save("wwqianyong"), who->get_save("wwjianyong"));
		else if (iKind == 38)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Thổ Tinh, 30 Lượng Tinh rồi báo cáo cho Lý Đức\n" BLK "Thổ Tinh %d/30\n" BLK "Lượng Tinh %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đức\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bạn đến hang Tử Vân tiêu diệt 30 Thổ Tinh và 30 Lượng Tinh để cho Lý Đức thấy thực lực của bạn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 71000 điểm\n" 
 BLK "    Tiềm năng: 890 điểm\n" 
 BLK "    Ngân lượng: 60000", who->get_save("lidetujing"), who->get_save("lidejinjing"));
		else if (iKind == 43)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Thủy Tinh, 30 Hỏa Tinh rồi quay lại thăm Ngụy Lão Hán\n" BLK "Thủy Tinh %d/30\n" BLK "Hỏa Tinh %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Lão Hán\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngụy Lão Hán dường như đã mất trí, qua những lời nói lung tung của ông, bạn biết được một số thông tin. Bạn chuẩn bị đến" HIR "Hang Huyền Chân" BLK " tiêu diệt 30 Thủy Tinh và 30 Hỏa Tinh thuộc hạ của Đạo Tiên, rồi quay lại thăm Ngụy Lão Hán.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 72000 điểm\n" 
 BLK "    Tiềm năng: 880 điểm\n" 
 BLK "    Ngân lượng: 62000", who->get_save("wlhsuijing"), who->get_save("wlhhuojing"));
		else if (iKind == 49)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Hỏa Tinh, 30 Lượng Tinh rồi báo cáo cho Tôn Thiếu Gia\n" BLK "Hỏa Tinh %d/30\n" BLK "Lượng Tinh %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tôn Thiếu Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôn Thiếu Gia đúng là quân tử khiêm tốn, anh ta chỉ muốn xóa nợ khoản vay từ Lượng Tinh và Hỏa Tinh để chuẩn bị cho hôn lễ của mình. Để giúp Tiểu thư Sa Tiễn thành hôn, bạn hãy đáp ứng yêu cầu của Tôn Thiếu Gia, đến" HIR "Hang Tử Vân" BLK " tiêu diệt 30 Hỏa Tinh và 30 Lượng Tinh.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 76000 điểm\n" 
 BLK "    Tiềm năng: 960 điểm\n" 
 BLK "    Ngân lượng: 67000", who->get_save("ssyhuojing"), who->get_save("ssyjinjing"));
		else if (iKind == 54)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Thủy Tinh, 30 Hỏa Tinh rồi báo cáo cho Chu Đồng\n" BLK "Thủy Tinh %d/30\n" BLK "Hỏa Tinh %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Đồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chu Đồng dường như nhìn thấy bóng dáng của Thủy Tinh và Hỏa Tinh. Bạn đến" HIR "Hang Huyền Chân" BLK " tiêu diệt 30 Thủy Tinh và 30 Hỏa Tinh, kết quả ra sao thì cứ chờ xem.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 78000 điểm\n" 
 BLK "    Tiềm năng: 1000 điểm\n" 
 BLK "    Ngân lượng: 65000", who->get_save("ztsuijing"), who->get_save("zthuojing"));
		else if (iKind == 58)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Thổ Tinh, 30 Thủy Tinh rồi báo cáo cho Ngụy Lão Hán\n" BLK "Thổ Tinh %d/30\n" BLK "Thủy Tinh %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngụy Lão Hán\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngụy Lão Hán nói rằng lần này kẻ đồng lõa dường như là Thổ Tinh và Thủy Tinh ở" HIR "Hang Hư Lăng" BLK ". Thật không biết tên ác tặc đó học được thuật điều khiển yêu tinh gì, Ngụy Lão Hán muốn bạn cắt đứt cánh tay của tên ác tặc, tiêu diệt 30 Thổ Tinh và 30 Thủy Tinh rồi trở về báo cáo cho ông.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 81000 điểm\n" 
 BLK "    Tiềm năng: 1200 điểm\n" 
 BLK "    Ngân lượng: 69000", who->get_save("wlhtujing1"), who->get_save("wlhsuijing1"));
		else if (iKind == 62)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Trận Thiên Môn tìm 30 Gỗ làm giường giao cho Thợ thủ công Ngụy Quốc\n" BLK "Gỗ làm giường %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Con gái của Thợ thủ công Ngụy Quốc sắp xuất giá, làm cha thì phải chuẩn bị chút của hồi môn ra hồn chứ. Ông ta tự hào nhất là tay nghề, nhưng những thứ bình thường ông khắc không làm ông hài lòng. Ông muốn tạo ra một báu vật trấn hòm, sư phụ ông từng truyền lại một bản vẽ gọi là Giường Thước Duyên, nghe nói ngủ trên đó sẽ giúp vợ chồng ân ái, sinh nhiều quý tử. Ông nhờ bạn giúp hoàn thành tâm nguyện này. Trước tiên, ông cần 30 khúc gỗ Tùng Mỹ Nhân dài một trượng, rộng ba tấc, không có mắt cây, nghe nói có ở Trận Thiên Môn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 50000 điểm\n" 
 BLK "    Tiềm năng: 700 điểm\n" 
 BLK "    Ngân lượng: 48000", who->get_save("wggjmutou"));
		else if (iKind == 63)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Cướp lại Cưa từ tay Đỗ Độc giao cho Thợ thủ công Ngụy Quốc\n" BLK "Cưa làm giường %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Không sợ trộm ăn cắp, chỉ sợ trộm nhòm ngó. Chiếc Cưa của Thợ thủ công Ngụy Quốc là do đại sư Âu Trị Tử rèn để cảm ơn ông làm Giường Thước Duyên. Thợ thủ công vốn kín đáo, có báu vật cũng không khoe, nhưng hôm nọ say rượu lỡ lời, kết quả Đỗ Độc, kẻ ham báu vật, nghe được, hôm qua xông vào nhà cướp mất Cưa. Thợ thủ công đâu đánh lại Đỗ Độc, kẻ không biết học được võ công tạp nham từ đâu. Ông cầu xin bạn đến" HIR "Tử Trúc Tiểu Cư ở Bạch Mã Trang" BLK " cướp lại Cưa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 51000 điểm\n" 
 BLK "    Tiềm năng: 710 điểm\n" 
 BLK "    Ngân lượng: 50000", who->get_legend(44, 8) ? 1 : 0);
		else if (iKind == 64)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Trận Tru Tiên tìm Hoàng Tinh Thạch giao cho Thợ thủ công Ngụy Quốc\n" BLK "Hoàng Tinh Thạch đẹp %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Ngụy Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thợ thủ công Ngụy Quốc nói rằng chỉ dùng gỗ Tùng Mỹ Nhân thì chưa đủ để phát huy hiệu quả. Ông muốn khắc phù chú và trận pháp lên giường, mà Hoàng Tinh Thạch là pháp khí cần thiết. Nghe nói trong Trận Tru Tiên thượng cổ có Hoàng Tinh Thạch sót lại từ chiến tranh thần ma, tuy không mạnh như pháp khí của tiên nhân xưa, nhưng dùng cho Giường Thước Duyên thì thừa sức. Ông thách bạn đến Trận Tru Tiên lấy Hoàng Tinh Thạch. Bạn hỏi về cách khắc phù chú và trận pháp, nhưng Thợ thủ công Ngụy Quốc chỉ bí mật cười, không tiết lộ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 180000 điểm\n" 
 BLK "    Tiềm năng: 1400 điểm\n" 
 BLK "    Ngân lượng: 190000", who->get_save("wggjhuangjs"));
	}
	else if (iTask == TID_YANGUO)
	{
		if (iKind == 16)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 con" HIR "Nhện vỏ xanh" BLK " rồi báo cáo cho " HIR "Quan điển ngục Yên Quốc\n" BLK "Nhện vỏ xanh %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan điển ngục Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Truyền thuyết kể rằng cứ mỗi ngàn năm, Trường Bạch Sơn sẽ xuất hiện một kiếp nạn, và kiếp nạn này cần sự đoàn kết của những người trong võ lâm để hóa giải. Dựa trên quan sát gần đây của ta, kiếp nạn lần này có thể là do" HIR "Nhện vỏ xanh Trường Bạch Sơn" BLK " gây loạn. Gần đây, khu vực đó đột nhiên xuất hiện rất nhiều nhện vỏ xanh. Hãy đến đó xem xét, nếu đúng như vậy, hãy tiêu diệt chúng và quay lại báo cho ta!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4800 điểm\n" 
 BLK "    Tiềm năng: 150 điểm\n" 
 BLK "    Ngân lượng: 3600", who->get_save_2("lkzhizhu"));
		else if (iKind == 18)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR "Tinh báo hoa" BLK " 10 con rồi báo cáo cho " HIR "Đại tướng quân Yên Quốc\n" BLK "Tinh báo hoa %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nếu đã chọn ta để nhận thử thách này, ta sẽ không để họ thất vọng! Tại Trường Bạch Sơn, ta sẽ phát huy hết khả năng của mình, tiêu diệt 10 con tinh báo hoa!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5000 điểm\n" 
 BLK "    Tiềm năng: 160 điểm\n" 
 BLK "    Ngân lượng: 4000", who->get_save_2("huabaojing"));
		else if (iKind == 19)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm 5 viên đá phát sáng giao cho" HIR "Thương nhân dược liệu Yên Quốc\n" BLK "Đá phát sáng %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân dược liệu Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thương nhân dược liệu muốn nghiên cứu dược liệu mới, cần một số viên đá phát sáng. Có lẽ trên người yêu quái ở Thiên Trì Trường Bạch có thể tìm thấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5000 điểm\n" 
 BLK "    Tiềm năng: 160 điểm\n" 
 BLK "    Ngân lượng: 4000", who->get_save_2("yanjiushitou"));
		else if (iKind == 20)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10 bức tượng bùn giao cho" HIR "Thương nhân cổ vật Yên Quốc\n" BLK "Tượng bùn %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân cổ vật Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trong dân gian có một nghề thủ công đã thất truyền – Tượng bùn.\n" 
 BLK "    Họ có thể dùng đất bùn đen để tạc nên đủ loại cầm thú, cá, côn trùng, hoa, chim. Đáng tiếc là nghề này đã thất truyền từ rất lâu. Gần đây, nghe nói ở khu vực" HIR "Trường Thành Yên Quốc" BLK " xuất hiện một loạt tượng bùn. Có thể tưởng tượng đây là những bức tượng bùn quý giá đến mức nào. Nếu ngươi có thể tìm được 10 bức, thương nhân cổ vật Yên Quốc chắc chắn sẽ trả giá cao để thu mua!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5700 điểm\n" 
 BLK "    Tiềm năng: 220 điểm\n" 
 BLK "    Ngân lượng: 4600\n", who->get_save_2("gdsnidiao"));
		else if (iKind == 21)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 quân cờ giao cho" HIR "Vệ binh Yên Quốc\n" BLK "Quân cờ %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mặc dù vệ binh Yên Quốc không quá tinh thông cờ vua, nhưng đó vẫn là sở thích của anh ta. Vì yêu thích cờ vua, anh ta cũng thích sưu tầm quân cờ. Nhiều lữ khách đi ngang qua đó đều giúp anh ta thu thập quân cờ. Ngươi cũng đến" HIR "Trường Bạch Sơn" BLK " giúp anh ta thu thập 20 quân cờ đi, ta nghĩ anh ta sẽ không để ngươi chịu thiệt đâu!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5700 điểm\n" 
 BLK "    Tiềm năng: 220 điểm\n" 
 BLK "    Ngân lượng: 4600", who->get_save_2("swqizhi"));
		else if (iKind == 22)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR "Binh đao thuẫn Yên Quốc" BLK " 20 tênimg rồi báo cáo cho Đại tướng quân\n" BLK "Binh đao thuẫn %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Những binh đao thuẫn đóng tại Trường Thành Yên Quốc đều là những kẻ đào tẩu từ doanh trại năm xưa. Biết đâu một ngày nào đó, chúng sẽ gây ra một cuộc nổi loạn lớn, đây là một mối họa lớn! Đại tướng quân Yên Quốc ngày nào cũng đau đầu nghĩ cách giải quyết vấn đề này. Ông ấy muốn huy động sức dân để giải quyết, nhưng chưa ai giúp ông ấy. Ngươi đến đúng lúc, hãy đến Trường Thành Yên Quốc tiêu diệt chúng đi!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5800 điểm\n" 
 BLK "    Tiềm năng: 230\n" 
 BLK "    Ngân lượng: 4700", who->get_save_2("jjdaodunbing"));
		else if (iKind == 23)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay Yên lão hán giết" HIR "Binh kiếm thuẫn Yên Quốc" BLK " 10 tên\n" BLK "Binh kiếm thuẫn Yên Quốc %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Yên lão hán Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thật đáng thương cho Yên lão hán, tóc bạc tiễn tóc xanh!\n" 
 BLK "    Năm ngoái, con trai của Yên lão hán trên đường về nhà đi qua" HIR "Trường Thành Yên Quốc" BLK " đã bị 10 tên binh kiếm thuẫn giết chết!! Đám binh kiếm thuẫn đó thật là một đám yêu quái đáng sợ, Yên lão hán muốn báo thù cho con trai mình!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5800\n" 
 BLK "    Tiềm năng: 230 điểm\n" 
 BLK "    Ngân lượng: 4700", who->get_save_2("bcjdbing"));
		else if (iKind == 24)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10 viên hồng bảo thạch giao cho Thương nhân bảo thạch\n" BLK "Hồng bảo thạch %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân bảo thạch Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói giết quái vật ở Trường Bạch Sơn có thể thu được hồng bảo thạch, phải đi thử một chuyến xem sao.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6000 điểm\n" 
 BLK "    Tiềm năng: 240 điểm\n" 
 BLK "    Ngân lượng: 4800\n" 
 BLK "    Vật phẩm: Hạng liên cấp 50", who->get_save_2("zghongbaoshi"));
		else if (iKind == 25)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập vòng tròn để chế tạo hồn nghi giao cho" HIR "Ngự sử Yên Quốc\n" BLK "Vòng tròn %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự sử Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngự sử Yên Quốc thích quan sát các vì sao, muốn chế tạo một dụng cụ giúp quan sát gần hơn, cần 3 vòng tròn. Ta sẽ đến" HIR "Trường Thành Yên Quốc" BLK " tìm chúng cho ông ấy!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4000 điểm\n" 
 BLK "    Tiềm năng: 140\n" 
 BLK "    Ngân lượng: 2800", who->get_save_2("ysyuanhuan"));
		else if (iKind == 26)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập trục để chế tạo hồn nghi giao cho" HIR "Ngự sử Yên Quốc\n" BLK "Trục %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Ngự sử Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngự sử Yên Quốc thích quan sát các vì sao, muốn chế tạo một dụng cụ giúp quan sát gần hơn, cần 1" HIR "trục lượng thuộc" BLK ". Ta sẽ đến" HIR "Trường Thành Yên Quốc" BLK " tìm nó cho ông ấy!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4000 điểm\n" 
 BLK "    Tiềm năng: 140\n" 
 BLK "    Ngân lượng: 2800", who->get_legend(14, 11) ? 1 : 0);
		else if (iKind == 28)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay" HIR "Lưu lão bản Yên Quốc" BLK " tìm cây đàn nhị\n" BLK "Đàn nhị %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lưu lão bản Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Âm nhạc là lương thực tinh thần của con người; âm nhạc là thứ gần gũi nhất với tâm hồn; âm nhạc là thứ chạm đến những dây cung sâu thẳm trong lòng người…\n" 
 BLK "    Lưu lão bản yêu thích nhạc cụ, đặc biệt là đàn nhị, bởi âm thanh của nó mang đến cảm giác ai oán, như khóc như kể. Có lẽ một thương nhân như ông không nên đa sầu đa cảm như vậy, nhưng ông đã sưu tầm rất nhiều đàn nhị và vẫn đang tiếp tục sưu tầm. Nghe nói ở Trường Bạch Sơn có những cây đàn nhị rất tốt, hãy đến đó tìm thử cho ông ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6000 điểm\n" 
 BLK "    Tiềm năng: 240 điểm\n" 
 BLK "    Ngân lượng: 4800", who->get_legend(14, 16) ? 1 : 0);
		else if (iKind == 29)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 15 con gấu ngốc lớn, sau đó báo cáo cho Quan tài chính Yên Quốc\n" BLK "Gấu ngốc lớn %d/15\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan tài chính Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Không ngờ có những con gấu ngốc lớn dám trộm tiền kho bạc, khiến Quan tài chính tức giận! Ta sẽ đến đỉnh Ngọc Trụ tiêu diệt chúng ngay!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6000 điểm\n" 
 BLK "    Tiềm năng: 245 điểm\n" 
 BLK "    Ngân lượng: 4900", who->get_save_2("tqbengxiong"));
		else if (iKind == 31)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 3 cây cỏ linh chi giao cho" HIR "Bá tánh Yên Quốc\n" BLK "Cỏ linh chi %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ tiệm y dược không có cỏ linh chi, có lẽ phải đến" HIR "Trường Thành Yên Quốc" BLK " mới có hy vọng tìm được.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5000 điểm\n" 
 BLK "    Tiềm năng: 200 điểm\n" 
 BLK "    Ngân lượng: 3500", who->get_save_2("frlingzhi"));
		else if (iKind == 32)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 5 cây hoàng liên giao cho" HIR "Bá tánh Yên Quốc\n" BLK "Hoàng liên %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Trường Bạch Sơn cố gắng tìm 5 cây hoàng liên mang về chữa bệnh.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 8500 điểm\n" 
 BLK "    Tiềm năng: 500 điểm\n" 
 BLK "    Ngân lượng: 8600\n" 
 BLK "    Vật phẩm: Nón cấp 50", who->get_save_2("frhuanglian"));
		else if (iKind == 33)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến" HIR "Trường Thành Yên Quốc" BLK " thu thập 10" HIR "kẹp tóc" BLK " giao cho" HIR "Tào Thanh Yên Quốc\n" BLK "Kẹp tóc %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tào Thanh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tào Thanh tự cho rằng mình có gu thẩm mỹ khá tốt, nên định mở một cửa hàng kinh doanh kẹp tóc. Cô ấy nhờ ta đến" HIR "Trường Thành Yên Quốc" BLK " thu thập 10 chiếc kẹp tóc cho cô ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6500 điểm\n" 
 BLK "    Tiềm năng: 255 điểm\n" 
 BLK "    Ngân lượng: 5500", who->get_save_2("cqfajia"));
		else if (iKind == 34)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 quả ớt giao cho" HIR "Trình Phong Yên Quốc\n" BLK "Ớt %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Phong Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, nhà Trình Phong có vài vị khách thích ăn ớt, mọi món ăn đều phải có ớt. Nhưng nhà họ ăn ít ớt, nên thường xuyên thiếu. Ta sẽ đến Trường Thành Yên Quốc tìm xem có thể thu thập được 20 quả ớt không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6300 điểm\n" 
 BLK "    Tiềm năng: 252 điểm\n" 
 BLK "    Ngân lượng: 5300", who->get_save_2("cflajiao"));
		else if (iKind == 36)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20" HIR "Binh thương Yên Quốc" BLK " rồi báo cáo cho" HIR "Quan điển ngục Yên Quốc\n" BLK "Binh thương Yên Quốc %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan điển ngục Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quan điển ngục Yên Quốc có vẻ hơi tàn nhẫn, ông ta nói宁可误杀一千，也不放过一个. Thôi được, vì phần thưởng hậu hĩnh, ta sẽ đến Trường Thành Yên Quốc tiêu diệt 20 binh thương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 5600", who->get_save_2("ygqianbing"));
		else if (iKind == 37)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm bút lông, nghiên mực, thỏi mực ở Linh Cốc Động giao cho Tổng quản Yên\n" BLK "Bút lông %d/1\n" BLK "Nghiên mực %d/1\n" BLK "Thỏi mực %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng quản Yên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Muốn biết vị trí của khóa đồng tâm, phải khiến Tổng quản Yên viết một lá thư. Nhưng lá thư này phải được viết bằng" HIR "bút lông, nghiên mực, thỏi mực" BLK " tìm được ở tầng một, hai, ba của Linh Cốc Động. Vì vậy, ta phải đến Linh Cốc Động tìm ba thứ này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 26000 điểm\n" 
 BLK "    Tiềm năng: 450 điểm\n" 
 BLK "    Ngân lượng: 25000", who->get_save_2("yzgmaobi"), who->get_save_2("yzgyantai"), who->get_save_2("yzgmokuai"));
		else if (iKind == 39)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Khốn Ma Trận tiêu diệt Yêu Khô Lâu và Tà Linh, sau đó báo cáo cho Trình Phong\n" BLK "Yêu Khô Lâu %d/5\n" BLK "Tà Linh %d/7\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Phong\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Khốn Ma Trận tiêu diệt Yêu Khô Lâu và Tà Linh, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 35000 điểm\n" 
 BLK "    Tiềm năng: 620 điểm\n" 
 BLK "    Ngân lượng: 32000", who->get_save("cfkuly"), who->get_save("cfxieling"));
		else if (iKind == 40)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR "Đại Vương Yêu Khô Lâu" BLK ", sau đó trở về báo cáo cho Trình Phong để nhận chỉ thị tiếp theo\n" BLK "Đại Vương Yêu Khô Lâu %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Phong\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trình Lâm Khai và Trình Phong che giấu một bí mật lớn. Hóa ra những con quái vật ở Khốn Ma Trận chỉ có thể bị khuất phục bởi Hồi Chuông đều là do con người thả ra. Gần đây, những con yêu quái gây hại đều xuất phát từ Khốn Ma Trận. Tục ngữ có câu bắt giặc phải bắt vương trước, ta phải tiêu diệt Đại Vương Yêu Khô Lâu. Đại Vương Yêu Khô Lâu ở khu đất trống lớn tại" HIR "tầng 1 Khốn Ma Trận" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 40000 điểm\n" 
 BLK "    Tiềm năng: 650 điểm\n" 
 BLK "    Ngân lượng: 37000", who->get_legend(TASK_31, 22) ? 1 : 0);
		else if (iKind == 41)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến tầng 4 Ma Thần Điện ở Khốn Ma Trận lấy Hồi Chuông giao cho Trình Phong\n" BLK "Hồi Chuông %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Phong\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bây giờ là thời khắc then chốt để tái phong ấn những con yêu quái này. Hồi Chuông ở Khốn Ma Trận vừa là nguồn sức mạnh khiến chúng gây loạn, vừa là vũ khí khắc chế chúng. Khi ở trong trận, Hồi Chuông khuếch đại sức mạnh của chúng, làm suy yếu phong ấn. Nhưng khi ra ngoài trận, nó trở thành pháp khí để kiềm chế sức mạnh và gia cố phong ấn. Hãy đến Ma Thần Điện lấy Hồi Chuông và giao cho Trình Phong. Sau khi vào Khốn Ma Trận, đi thẳng xuống tầng thấp nhất là Ma Thần Điện, vào cửa điện rồi đi thẳng, ngươi sẽ thấy nó.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 150000 điểm\n" 
 BLK "    Tiềm năng: 1800 điểm\n" 
 BLK "    Ngân lượng: 140000\n" 
 BLK "    Vật phẩm: Yêu Đới cấp 90", who->get_legend(TASK_31, 25) ? 1 : 0);
		else if (iKind == 42)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm 5 viên Khí Mạch Đan giao cho Vệ binh Yên Quốc\n" BLK "Khí Mạch Đan %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Một vài vệ binh Yên Quốc bị thương khi truy bắt tù nhân trốn khỏi thiên lao là Nghiêm Phi, ngày nào cũng nôn ra máu, đầu đau dữ dội. Nghe nói kẻ đó là đường chủ Thần Võ Đường. Nhiều thầy thuốc đã xem qua nhưng không chữa được. Một người thân xa là Tần Dược Sư khuyên họ tìm Khí Mạch Đan, nói rằng đây là nội thương, thuốc thường không chữa được. Nghe nói ở Khốn Ma Trận có thể tìm thấy, họ nhờ ngươi đi tìm giúp.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 62000 điểm\n" 
 BLK "    Tiềm năng: 900 điểm\n" 
 BLK "    Ngân lượng: 53000", who->get_save("ygswqimaidan"));
		else if (iKind == 43)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm 8 thanh Đao Đơn giao cho Đại tướng quân Yên Quốc\n" BLK "Đao Đơn %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ binh Yên Quốc nói rằng trong Khốn Ma Trận có những Hài Cốt Tinh, trước khi chết họ là những chiến binh trong trận chiến thần ma thượng cổ. Sau khi chết, họ vẫn tiếp tục chiến đấu, dùng ma khí tôi luyện những thanh Đao Đơn họ mang theo, khiến chúng trở nên vô cùng sắc bén. Đại tướng quân Yên Quốc rất muốn có những thanh đao này để trang bị cho quân đội. Hãy đến" HIR "Khốn Ma Trận" BLK " tiêu diệt" HIR "Hài Cốt Tinh" BLK " và lấy 8 thanh Đao Đơn, mang về cho Đại tướng quân Yên Quốc xem xét.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 62000 điểm\n" 
 BLK "    Tiềm năng: 900 điểm\n" 
 BLK "    Ngân lượng: 53000", who->get_save("ygswdandao"));
		else if (iKind == 44)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Khốn Ma Trận giết Thi Ma, Oán Linh, sau đó báo cáo cho Vệ binh Yên Quốc\n" BLK "Thi Ma %d/8\n" BLK "Oán Linh %d/6\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hiện nay, yêu khí ở Khốn Ma Trận ngập trời, phong ấn có dấu hiệu bị lỏng lẻo. Nếu để tình trạng này tiếp diễn, e rằng sẽ có những biến cố không lường trước được, hoặc có kẻ xấu lợi dụng. Vệ binh Yên Quốc mong ngươi đến tiêu diệt 8 Thi Ma và 6 Oán Linh để kiềm chế yêu khí, tránh dân chúng hoảng loạn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 63000 điểm\n" 
 BLK "    Tiềm năng: 905 điểm\n" 
 BLK "    Ngân lượng: 53500", who->get_save("ygswsimo"), who->get_save("ygswyuanling"));
		else if (iKind == 45)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Khốn Ma Trận giết quái thu thập 10 quả táo tàu giao cho Tô Đại, Quan nội chính Yên Quốc\n" BLK "Táo tàu %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tô Đại, Quan nội chính Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tô Đại, Quan nội chính Yên Quốc nói rằng người thân của ông ta mắc bệnh kín, cần táo tàu được nuôi dưỡng bởi âm khí ở Khốn Ma Trận để chữa trị. Ông ta nhờ ngươi tìm 10 quả. Lạ thật, bệnh gì mà lại cần thứ này?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 67000 điểm\n" 
 BLK "    Tiềm năng: 930 điểm\n" 
 BLK "    Ngân lượng: 56000", who->get_save("ygnzgdazao"));
		else if (iKind == 46)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 8 Yêu Khô Lâu và 8 Hài Cốt Tinh, sau đó báo cáo cho Vệ binh Yên Quốc\n" BLK "Yêu Khô Lâu %d/8\n" BLK "Hài Cốt Tinh %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đêm qua, Vệ binh Yên Quốc mơ thấy Yêu Khô Lâu và Hài Cốt Tinh ở" HIR "Khốn Ma Trận" BLK " liên tục thôn tính lẫn nhau, trở thành những yêu ma ngày càng mạnh, cuối cùng hóa thành một đám mây đen ngập trời, bao phủ cả nước Đại Yên. Đám mây đen đi qua, cung điện, người, thú không ai sống sót, chỉ còn lại đổ nát và xác chết. Quá đáng sợ! Nếu không tiêu diệt những Yêu Khô Lâu và Hài Cốt Tinh này, chúng sẽ ngày càng mạnh, gây họa cho đất nước. Vệ binh Yên Quốc ra lệnh ngươi nhanh chóng tiêu diệt 8 Yêu Khô Lâu và 8 Hài Cốt Tinh, ông ta sẽ tìm thêm người để ngăn chặn chúng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 63000 điểm\n" 
 BLK "    Tiềm năng: 905 điểm\n" 
 BLK "    Ngân lượng: 53800", who->get_save("ygswkulouy"), who->get_save("ygswhaiguj"));
		else if (iKind == 47)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến thôn Thạch Môn ở Trác Lộc tiêu diệt Hỏa, sau đó báo cáo cho Đại tướng quân Yên Quốc\n" BLK "Hỏa %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hỏa từng là phó tướng dưới trướng Đại tướng quân Yên Quốc, cùng ông chinh chiến khắp nơi. Nhưng hắn không tuân thủ kỷ luật, nhiều lần vi phạm quân quy, thậm chí bán bí mật quân sự của quân Yên cho địch quốc, suýt khiến toàn quân bị tiêu diệt. Gần đây, hắn tiêu hết tiền bán nước, lại bắt đầu cướp bóc, giết chóc ở khu vực lân cận. Một cô gái chạy thoát đã kể lại những lời hắn nói khi say rượu, khiến Đại tướng quân Yên Quốc liên hệ được hắn với kẻ phản bội trong trận chiến năm xưa. Một kẻ đại gian đại ác như vậy không thể để hắn tiếp tục nhởn nhơ ngoài vòng pháp luật, đó là nỗi sỉ nhục của Yên Quốc! Đại tướng quân Yên Quốc ra lệnh ngươi nhanh chóng đến thôn Thạch Môn ở Trác Lộc, tiêu diệt Hỏa!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 68000 điểm\n" 
 BLK "    Tiềm năng: 915 điểm\n" 
 BLK "    Ngân lượng: 57000", who->get_legend(TASK_32, 21) ? 1 : 0);
		else if (iKind == 48)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 5 Yêu Khô Lâu, 5 Hài Cốt Tinh, 5 Tà Linh, sau đó báo cáo cho Vương Hỷ Đại Vương Yên\n" BLK "Yêu Khô Lâu %d/5\n" BLK "Hài Cốt Tinh %d/5\n" BLK "Tà Linh %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vương Hỷ Đại Vương Yên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Công chúa Nghi Cơ, con gái út của Vương Hỷ Đại Vương Yên, khi đi chơi ở Trường Bạch Sơn đã bị một đám yêu quái làm cho hoảng sợ. May nhờ tướng hộ vệ tài giỏi bảo vệ, công chúa mới an toàn trở về, nhưng vẫn bị ám ảnh, nói sảng không ngừng. Vương Hỷ Đại Vương Yên cho rằng đám yêu quái to gan này dám xúc phạm con gái ông, suýt làm cô ấy bị thương. Ông ra lệnh ngươi đến Khốn Ma Trận tiêu diệt 5 Yêu Khô Lâu, 5 Hài Cốt Tinh, 5 Tà Linh, để chúng phải khiếp sợ và hối cải!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 64000 điểm\n" 
 BLK "    Tiềm năng: 906 điểm\n" 
 BLK "    Ngân lượng: 53800", who->get_save("ywkulouy"), who->get_save("ywhaiguj"), who->get_save("ywxieling"));
		else if (iKind == 49)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến tầng 3 Khốn Ma Trận tìm di sản của ông nội Đinh Hạc Niên giao cho anh ta\n" BLK "Chìa khóa lượng %d/1\n" BLK "Di thư da hổ %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đinh Hạc Niên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ông nội của Đinh Hạc Niên từng là một anh hùng lẫy lừng, nhưng không rõ vì sao lại chết nơi đất khách. Trước khi chết, ông gửi lại một bức thư vẽ hình một bộ xương, xung quanh là mật ngữ mà chỉ gia tộc họ hiểu. Mật ngữ dịch ra là" HIR "bàn thờ Ma Thần tầng 3 Khốn Ma Trận" BLK ". Có lẽ mọi bí mật đều ở đó. Đáng tiếc, cha của Đinh Hạc Niên khi ấy còn trong quân ngũ, không kịp lấy di vật. Khi ông ấy về quê thì đã già yếu, không đủ sức đi tìm. Đinh Hạc Niên quyết tìm ra sự thật năm xưa, nhưng cha anh ta chỉ học được một phần mười bản lĩnh của ông nội, còn bản thân anh ta thể nhược, không thể luyện võ. Gần đây, anh ta kết bạn với ngươi, thấy rất hợp ý, không biết ngươi có thể giúp anh ta lấy di vật của ông nội, tìm ra chân tướng năm xưa không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 36000 điểm\n" 
 BLK "    Tiềm năng: 630 điểm\n" 
 BLK "    Ngân lượng: 33000", i = who->get_legend(TASK_32, 27) ? 1 : 0, i);
		else if (iKind == 50)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Khốn Ma Trận thu thập 8 quả bí ngô lớn, 12 củ cà rốt lớn, 7 quả trứng gà ta giao cho Đại tướng quân Yên Quốc\n" BLK "Bí ngô lớn %d/8\n" BLK "Cà rốt lớn %d/12\n" BLK "Trứng gà ta %d/7\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Qua nhiều năm cai trị tận tâm, thời cơ để Tần Vương Doanh Chính chinh phục thiên hạ đã chín muồi. Quân Tần sắp xuất phát, tục ngữ có câu quân chưa động, lương thảo đi trước. Nhưng viên quan phụ trách lương thực lại chưa chuẩn bị đủ. Hiện ông ta đã bị phạt 50 trượng. Đại tướng quân Yên Quốc ra lệnh ngươi đến Khốn Ma Trận tìm 8 quả bí ngô, 12 củ cà rốt, 7 quả trứng gà. Nếu không làm được, ngươi muốn chịu chung số phận với viên quan kia sao? Nhưng nếu hoàn thành đúng hạn, Đại tướng quân Yên Quốc sẽ thưởng hậu! Dù ngươi chỉ tìm được một phần nhỏ, nhưng mọi người cùng cố gắng sẽ nhanh chóng bù đắp thiếu hụt lương thực.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 98000 điểm\n" 
 BLK "    Tiềm năng: 1100 điểm\n" 
 BLK "    Ngân lượng: 95000", who->get_save("ygdjjnangua"), who->get_save("ygdjjluobo"), who->get_save("ygdjjjidan"));
		else if (iKind == 51)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 9 Địa Sát Môn Thủ, 11 Thái Cực Môn Thủ, sau đó báo cáo cho Vệ binh Yên Quốc\n" BLK "Địa Sát Môn Thủ %d/9\n" BLK "Thái Cực Môn Thủ %d/11\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Từ khi thiên tượng bất thường, địa khí rối loạn, đại loạn sắp đến, yêu ma nhảy múa. Sau khi Địa Sát Môn và Thái Cực Môn chiếm đóng ngoài thành, tình hình càng tệ. Cả thành phố bị lũ yêu quái khuấy đảo, dân chúng hoảng loạn cả ngày. Vệ binh Yên Quốc thấy ngươi võ nghệ cao cường, lòng nhân hậu, chắc chắn không忍 thấy dân chúng khổ sở. Họ cầu xin ngươi ra tay, tiêu diệt 9 Địa Sát Môn Thủ và 11 Thái Cực Môn Thủ, cứu dân chúng khỏi cảnh lầm than.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 90000 điểm\n" 
 BLK "    Tiềm năng: 973 điểm\n" 
 BLK "    Ngân lượng: 93500", who->get_save("ygswdismzs"), who->get_save("ygswtaijmzs"));
		else if (iKind == 53)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Khốn Ma Trận tìm vải thiều giao cho Tần Khai, Sứ giả Yên Quốc\n" BLK "Vải thiều %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Khai, Sứ giả Yên Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phu nhân Bình Nguyên Quân, Quan nội chính nước Triệu, từng nếm vải thiều mà Tần Khai, Sứ giả Yên Quốc mang đến cho Triệu Vương, muốn có thêm. Đáng tiếc, vải thiều mà Tần Khai mang đến chỉ có vào mùa đó, giờ chỉ còn một nơi có thể bảo quản được vải thiều." HIR "Khốn Ma Trận" BLK " là nơi âm hàn, nơi đó" HIR "Tà Linh" BLK " thích thu thập thứ này và có thể giữ chúng không hỏng. Nếu muốn giúp ông ấy lấy thêm, hãy đến Khốn Ma Trận thử vận may.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 65000 điểm\n" 
 BLK "    Tiềm năng: 920 điểm\n" 
 BLK "    Ngân lượng: 55000", who->get_save("ygsjlizi"));
	}
	else if (iTask == TID_QINGUO)
	{
		if (iKind == 1)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30" HIR "Tráng đinh" BLK " rồi báo cáo cho " HIR "Quan nội chính Tần Quốc Cam La\n" BLK "Tráng đinh %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính Tần Quốc Cam La\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Khi xây dựng Trường Thành, từng có một đám tráng đinh và khổ dịch âm mưu tạo phản. Chúng lên kế hoạch rất lâu, cuối cùng trốn khỏi công trường, và trước khi bỏ trốn, chúng đã chôn thuốc nổ. Tối hôm đó, những nông dân làm việc tại công trường chết và bị thương rất nhiều. Đám dân lưu manh gây hại này phải bị trừng trị!\n" 
 BLK "    Ngươi hãy đi tiêu diệt chúng! Ở" HIR "Trịnh Quốc Cừ" BLK ", 30 tráng đinh, nhớ kỹ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4700 điểm\n" 
 BLK "    Tiềm năng: 150 điểm\n" 
 BLK "    Ngân lượng: 3800", who->get_save_2("tpzuangding"));
		else if (iKind == 2)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30" HIR "Khổ dịch" BLK " rồi báo cáo cho " HIR "Quan nội chính Tần Quốc Cam La\n" BLK "Khổ dịch %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính Tần Quốc Cam La\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Khi xây dựng Trường Thành, từng có một đám tráng đinh và khổ dịch âm mưu tạo phản. Chúng lên kế hoạch rất lâu, cuối cùng trốn khỏi công trường, và trước khi bỏ trốn, chúng đã chôn thuốc nổ. Tối hôm đó, những nông dân làm việc tại công trường chết và bị thương rất nhiều. Đám dân lưu manh gây hại này phải bị trừng trị!\n" 
 BLK "    Ngươi hãy đi tiêu diệt chúng! Ở" HIR "Trịnh Quốc Cừ" BLK ", 30 khổ dịch, nhớ kỹ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5000 điểm\n" 
 BLK "    Tiềm năng: 160 điểm\n" 
 BLK "    Ngân lượng: 3500\n" 
 BLK "    Vật phẩm: Y phục cấp 40", who->get_save_2("plkuyi"));
		else if (iKind == 5)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đánh bại 30 lao dịch rồi báo cáo cho Bối Bối\n" BLK "Lao dịch %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bối Bối Tần Cung\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tục ngữ có câu, vật hợp theo loài, người tụ theo bầy.\n" 
 BLK "    Tiểu thư Bối Bối nói rằng nếu Trình Cường đã giao tín vật cho ngươi, chắc chắn ngươi là người đáng tin cậy. Vì vậy, hãy đến" HIR "Trịnh Quốc Cừ" BLK " đánh bại 30" HIR "lao dịch" BLK " để chứng minh khả năng của ngươi, đồng thời chứng tỏ ánh mắt của Trình Cường không tệ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5500 điểm\n" 
 BLK "    Tiềm năng: 180 điểm\n" 
 BLK "    Ngân lượng: 4000", who->get_save_2("bbkuyi"));
		else if (iKind == 7)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10 viên đá ma thuật giao cho" HIR "Vệ binh Tần Quốc\n" BLK "Đá ma thuật %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Từ lâu, Vệ binh Tần Quốc luôn ấp ủ làm một việc lớn, nhưng tất nhiên, anh ta sẽ không nói cho ngươi biết đó là việc gì. Tuy nhiên, nếu ngươi sẵn lòng giúp anh ta hoàn thành việc này, anh ta chắc chắn sẽ không để ngươi chịu thiệt!\n" 
 BLK "    Trước tiên, hãy tìm cho ta 10 viên đá ma thuật, đến" HIR "Trịnh Quốc Cừ" BLK " là có thể thu thập được!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 5800 điểm\n" 
 BLK "    Tiềm năng: 186 điểm\n" 
 BLK "    Ngân lượng: 4000", who->get_save_2("moqingshi"));
		else if (iKind == 11)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 thanh kiếm giao cho" HIR "Đại tướng quân Tần Quốc Vương Tiễn\n" BLK "Kiếm %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Tần Quốc Vương Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân Tần Quốc Vương Tiễn sắp phải đánh một trận lớn, gần đây có nhiều binh sĩ mới, nhưng vũ khí lại chưa được bổ sung kịp thời. Hãy đến" HIR "Trường Thành Tần Quốc" BLK " tìm 20 thanh kiếm cho ông ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7500 điểm\n" 
 BLK "    Tiềm năng: 280 điểm\n" BLK " Ngân lượng: 6500", who->get_save_2("qgdjjjian"));
		else if (iKind == 14)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 cái cuốc giao cho" HIR "Đại tướng quân Tần Quốc Vương Tiễn\n" BLK "Cuốc %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Tần Quốc Vương Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân Tần Quốc Vương Tiễn chấp nhận ý kiến của Hạ Hầu Đảng, chuẩn bị đào 5 hào sâu. Cần ta đến" HIR "Trường Thành Tần Quốc" BLK " thu thập 20 cái cuốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7500 điểm\n" 
 BLK "    Tiềm năng: 290 điểm\n" BLK " Ngân lượng: 6800", who->get_save_2("qgdjjchutou"));
		else if (iKind == 15)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đánh bại 20 binh thương Tần Quốc rồi báo cáo cho Đại tướng quân Tần Quốc Vương Tiễn\n" BLK "Binh thương Tần Quốc %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Tần Quốc Vương Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tướng quân Tần Quốc đã bắt đầu chuẩn bị đào hào sâu, nhưng ông ấy còn muốn kiểm tra khả năng chiến đấu của binh sĩ. Ông ấy yêu cầu ngươi đến" HIR "Trường Thành Tần Quốc" BLK " thử sức với các binh thương, nhớ là chỉ đánh ngất, không được giết chết.\n" BLK "Phần thưởng nhiệm vụ:Kinh nghiệm: 9000 điểm\n" 
 BLK "    Tiềm năng: 330 điểm\n" 
 BLK "    Ngân lượng: 8000\n" 
 BLK "    Vật phẩm: Giày cấp 60", who->get_save_2("qgdjjqiangbin"));
		else if (iKind == 16)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Săn 20 con" HIR "Tôm binh" BLK " và 20 con" HIR "Cua tướng" BLK " rồi báo cáo cho " HIR "Bành Tiêm Hào\n" BLK "Tôm binh %d/20 Cua tướng %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bành Tiêm Hào Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bây giờ là mùa săn bắn lý tưởng.\n" 
 BLK "    Bành Tiêm Hào là một thợ săn ở Tần Quốc, sống bằng cách đổi lấy tiền từ những con mồi săn được. Mỗi khi đến mùa săn bắn, cuộc sống của gia đình anh ta sẽ khá hơn nhiều, vì vậy anh ta luôn mong chờ thời điểm này.\n" 
 BLK "    Ngươi là người luyện võ, không biết có hứng thú với săn bắn không? Nếu có, hãy đến khu vực làng chài Đông Hải săn tôm binh và cua tướng. Gần đây, số lượng tôm binh và cua tướng ở đó tăng nhiều, ngươi có thể thử đi.\n" BLK "Phần thưởng nhiệm vụ:\n" BLK "Kinh nghiệm: 4500 điểm\n" 
 BLK "    Tiềm năng: 130 điểm\n" 
 BLK "    Ngân lượng: 3200", who->get_save_2("slxiabing"), who->get_save_2("slxiejiang"));
		else if (iKind == 18)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm đất đặc biệt để trồng bầu giao cho" HIR "Dược sư Tần\n" BLK "Đất đặc biệt %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dược sư Tần nghe nói" HIR "Binh cung Trường Thành Tần" BLK " cất giấu một loại đất tiên, có thể thúc đẩy cây trồng kỳ lạ, khiến hạt giống bình thường cần vài tháng mới mọc chỉ cần một ngày là lớn. Ông ấy cho rằng loại đất tiên này mới xứng với bầu tiên. Hãy tìm 20 cân đất tiên cho ông ấy, để các ngươi tận mắt thấy bầu tiên lớn lên thế nào.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6000 điểm\n" 
 BLK "    Tiềm năng: 190 điểm\n" BLK " Ngân lượng: 3700", who->get_save_2("teshunitu"));
		else if (iKind == 19)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm cưa có thể cắt bầu lớn giao cho" HIR "Dược sư Tần\n" BLK "Cưa %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quả đúng là bầu lớn, tròn to như bí ngô, có một cái cuống ngắn và dày, vỏ rất cứng, gõ vào là biết vỏ nó còn dày hơn cả tường thành. Nếu cưa làm đôi, có thể dùng làm gáo múc nước hoặc chứa dược liệu quý để bán giá cao. Nhưng để cắt nó một cách hoàn hảo, cần một chiếc cưa sắc bén. Nghe nói" HIR "Binh đao thuẫn Trường Thành Tần" BLK " có cưa thép, Dược sư Tần nhờ ngươi đi tìm thử.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 10000 điểm\n" 
 BLK "    Tiềm năng: 680 điểm\n" 
 BLK "    Ngân lượng: 15000\n" 
 BLK "    Vật phẩm: Vũ khí cấp 60", who->get_legend(TASK_19, 11) ? 1 : 0);
		else if (iKind == 20)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 binh đao thuẫn Tần Quốc, 10 binh thương Tần Quốc, rồi báo cáo cho" HIR "Vệ binh Tần Quốc\n" BLK "Binh đao thuẫn %d/10\n" BLK "Binh thương %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Có người mật báo rằng các binh sĩ trên Trường Thành Tần có ý định đào tẩu. Đại Vương bí mật ra lệnh tiêu diệt. Hãy đi tiêu diệt 10 binh đao thuẫn và 10 binh thương, rồi trở về báo cáo cho Vệ binh Tần Quốc để nhận thưởng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7000 điểm\n" 
 BLK "    Tiềm năng: 280 điểm\n" BLK " Ngân lượng: 7000", who->get_save_2("qgswdaodunbing"), who->get_save_2("qgswqiangbing"));
		else if (iKind == 21)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20 binh cung rồi báo cáo cho Quan điển ngục Tần Quốc\n" BLK "Binh cung Tần Quốc %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan điển ngục Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, thị vệ lơ là nhiệm vụ, chỉ lo vơ vét tiền bạc. Những tù nhân vi phạm quân kỷ càng thêm ngang ngược, thậm chí có kẻ biết được thông tin Đại Vương Doanh Chính đi săn, mang theo phần lớn thị vệ. Chúng nhân cơ hội thông đồng với bên ngoài, trốn đến Trường Thành Tần, định ở lại một thời gian rồi chạy ra ngoài lãnh thổ. Đại Vương đã nổi giận, hành vi khinh nhờn uy quyền của Đại Vương như vậy, nếu không bắt giữ và xử tử ngay, sẽ khiến các quan lại noi theo. Ngươi hãy nhanh chóng đến Trường Thành Tần, dùng loạn đao giết chết 20 binh cung đó!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7500 điểm\n" 
 BLK "    Tiềm năng: 300 điểm\n" 
 BLK "    Ngân lượng: 7000", who->get_save_2("qgtaofan"));
		else if (iKind == 45)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10" HIR "Binh đao thuẫn Tần Quốc (%d/10)\n" 
 BLK "    Tiêu diệt 10" HIR "Binh thương Tần Quốc (%d/10)\n" 
 BLK "    Tiêu diệt 10" HIR "Binh cung Tần Quốc (%d/10) rồi báo cáo cho Quan điển ngục Tần Quốc\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan điển ngục Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại Vương biết rằng yêu tinh ở Trường Thành Tần mà không một binh sĩ nào đi tiêu diệt, vô cùng tức giận. Đại Vương ra lệnh xử tử một số binh sĩ trên Trường Thành Tần để răn đe. Sau khi hoàn thành, báo cáo cho Quan điển ngục Tần Quốc để lưu hồ sơ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 24000 điểm\n" 
 BLK "    Tiềm năng: 430 điểm\n" 
 BLK "    Ngân lượng: 22000\n", who->get_save_2("qzgdaodunbing"), who->get_save_2("qzgqiangbing"), who->get_save_2("qzggongbing"));
		else if (iKind == 48)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đánh bại 20" HIR "Binh đao thuẫn Tần Quốc" BLK " rồi báo cáo cho " HIR "Vệ binh Tần Quốc\n" BLK "Binh đao thuẫn %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, dân chúng quanh khu vực Trường Thành Tần thường bị phân thây một cách bí ẩn. Sau khi điều tra lâu dài, cuối cùng phát hiện ra thủ phạm là" HIR "Binh đao thuẫn" BLK " ở" HIR "Trường Thành Tần" BLK ". Chúng hung ác thành tính, lại cực kỳ xảo quyệt. Đại Vương Doanh Chính nghiêm lệnh không để sót một tên nào, nhưng không được để xảy ra mâu thuẫn với các tướng lĩnh giữ thành. Ông ra lệnh cho cận vệ Tần Quốc bí mật tìm một dũng sĩ võ nghệ cao cường và kín miệng để thực hiện việc này. Ông nhờ ngươi đi tiêu diệt 20 tên binh đao thuẫn tàn bạo, mất hết nhân tính đó.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7700 điểm\n" 
 BLK "    Tiềm năng: 270 điểm\n" BLK " Ngân lượng: 8000", who->get_save_2("sarenemo"));
		else if (iKind == 49)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến" HIR "Trường Thành Tần" BLK " tìm" HIR "Hùng hoàng" BLK " giao cho" HIR "Vệ binh Tần Quốc\n" BLK "Hùng hoàng %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phong tục Đoan Ngọ của nước Sở dần lan đến Tần Quốc. Gần đây, Vệ binh Tần Quốc học được từ người thân ở nước Sở cách làm rượu hùng hoàng, nghe nói có thể trừ tà, giải độc. Vào sáng Đoan Ngọ, khi các rồng làm mưa, bày tiệc rượu hùng hoàng còn có thể cầu mong một năm mưa thuận gió hòa, mùa màng bội thu. Nhưng Đoan Ngọ sắp đến, hùng hoàng đã hết hàng. Nghe nói ở" HIR "Đài hỏa hiệu Trường Thành Tần" BLK " có thể tìm được, Vệ binh Tần Quốc nhờ ngươi đi tìm thử.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7800 điểm\n" 
 BLK "    Tiềm năng: 280 điểm\n" 
 BLK "    Ngân lượng: 8000", who->get_legend(TASK_20, 8) ? 1 : 0);
		else if (iKind == 50)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm tiền giấy dùng cho cúng tế giao cho" HIR "Bá tánh Tần Quốc Trọng Mạc\n" BLK "Tiền giấy %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh Tần Quốc Trọng Mạc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngày mùng chín tháng chín, Tết Trùng Dương, khi gia đình đoàn tụ, bá tánh Tần Quốc Trọng Mạc càng thêm nhớ thương người vợ đã khuất. Nghe nói tiền giấy ở" HIR "Trường Thành Tần" BLK " có thể vượt qua sông Vô Định đến thẳng âm phủ, không bị tiểu quỷ trên đường lấy mất. Ông ấy nhờ ngươi giúp tìm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7800 điểm\n" 
 BLK "    Tiềm năng: 280 điểm\n" BLK " Ngân lượng: 8000", who->get_save_2("qgbxzhiqian"));
		else if (iKind == 53)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt tên nghiện rượu, lấy Lão Tửu, giao cho" HIR "Bá tánh Tần Quốc Trọng Mạc\n" BLK "Lão Tửu %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh Tần Quốc Trọng Mạc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta đã thay bá tánh Tần Quốc Trọng Mạc tìm được cây cúc, nhưng ông ấy nói rượu dùng để ngâm cúc không thể quá tệ. Ở" HIR "trấn Bình Dương Tần Quốc" BLK " có một tên nghiện rượu rất nổi tiếng. Hãy đến xem có thể lấy được Lão Tửu từ hắn không. Tất nhiên, xin rượu từ một tên nghiện rượu chẳng khác nào xin da hổ. Ngươi cứ đánh ngất hắn đi, đỡ phải nghe hắn lằng nhằng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 13000 điểm\n" 
 BLK "    Tiềm năng: 750 điểm\n" 
 BLK "    Ngân lượng: 17000", who->get_legend(TASK_20, 17) ? 1 : 0);
		else if (iKind == 55)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 5 tên Thiên Cương Môn Thủ, 7 tên Thủ Trận Thiên Binh, 7 tên Thủ Trận Thần Tướng\n" BLK "Thiên Cương Môn Thủ %d/5\n" BLK "Thủ Trận Thiên Binh %d/7\n" BLK "Thủ Trận Thần Tướng %d/7\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Thiên Môn Trận tiêu diệt yêu quái, sau đó về báo cáo cho Vệ binh Tần Quốc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 80000 điểm\n" 
 BLK "    Tiềm năng: 960 điểm\n" 
 BLK "    Ngân lượng: 70000", who->get_save("qgswtiangmzs"), who->get_save("qgswsouztb"), who->get_save("qgswsouzsj"));
		else if (iKind == 56)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến" HIR "Thiên Môn Trận" BLK " tìm Lệ Ma Lam giao cho Vệ binh Tần Quốc\n" BLK "Lệ Ma Lam %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ binh Tần Quốc nói rằng gần đây có một nhân vật bí ẩn cần làm một việc rất quan trọng nhưng khó khăn, cần Lệ Ma Lam từ Thiên Môn Trận. Chắc chắn trên người các thần tướng thủ trận sẽ có. Ông ấy không cho phép ngươi hỏi tại sao cần thứ này, nếu không ngươi sẽ gặp rắc rối lớn. Ông ấy cảnh báo rằng bí mật của nhân vật này, tốt nhất ngươi nên tránh xa. Hừ, nếu đến lúc đó ông ấy không nói, ta sẽ không giao đồ cho ông ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 35000 điểm\n" 
 BLK "    Tiềm năng: 649 điểm\n" 
 BLK "    Ngân lượng: 55000", who->get_legend(TASK_39, 15) ? 1 : 0);
		else if (iKind == 57)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Thiên Môn Trận tìm 5 sợi chỉ bông, 7 quả bồ hòn giao cho Vệ binh Tần Quốc\n" BLK "Chỉ bông %d/5\n" BLK "Bồ hòn %d/7\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ binh Tần Quốc nói rằng làm vậy là tốt cho ngươi. Ông ấy phàn nàn rằng ngươi đang làm khó ông ấy. Ông ấy không muốn bị người khác mắng là hại mạng người. Bất đắc dĩ, ông ấy yêu cầu ngươi đến Thiên Môn Trận thu thập 5 sợi chỉ bông, 7 quả bồ hòn, rồi quay lại nói chuyện.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 40000 điểm\n" 
 BLK "    Tiềm năng: 658 điểm\n" 
 BLK "    Ngân lượng: 38000", who->get_save("qgswmianxian"), who->get_save("qgswzaojiao"));
		else if (iKind == 58)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 3 Địa Sát Môn Thủ ở tầng 2 Thiên Môn Trận, 6 Thái Cực Môn Thủ ở tầng 3, rồi báo cáo cho Vệ binh Tần Quốc.\n" BLK "Địa Sát Môn Thủ %d/3\n" BLK "Thái Cực Môn Thủ %d/6\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ binh Tần Quốc lo rằng ngươi sẽ bị người khác truy sát. Ông ấy bảo ngươi đi tiêu diệt 3" HIR "Địa Sát Môn Thủ ở tầng 2 Thiên Môn Trận" BLK " và 6 Thái Cực Môn Thủ ở tầng 3. Ông ấy nói chính chúng chịu trách nhiệm truy sát và giám sát ngươi. Sau đó, ông ấy sẽ tiết lộ sự thật về chuyện ngươi đang truy hỏi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 145000 điểm\n" 
 BLK "    Tiềm năng: 1500 điểm\n" 
 BLK "    Ngân lượng: 148000", who->get_save("qgswdisamzs"), who->get_save("qgswtaijimzs"));
		else if (iKind == 59)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Thiên Môn Trận tìm Cứu Cấp Đan giao cho bá tánh Tần Quốc Trọng Mạc\n" BLK "Cứu Cấp Đan %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh Tần Quốc Trọng Mạc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trời không lường trước được, người sớm tối gặp họa. Ai ngờ các cô gái khỏe mạnh lại mắc phải căn bệnh này. Gần đây, vài cô gái trong nhà dân chúng thành Hàm Dương đêm nào cũng đau đầu. Mời vài thầy thuốc đến nhưng không chữa được, bệnh càng ngày càng nặng. Nhìn các cô gái đau đớn đến không muốn sống, thật khiến người ta xót xa. Nghe nói" HIR "Thiên Môn Trận" BLK " ẩn chứa nhiều linh đan diệu dược, trong đó Cứu Cấp Đan có thể trị đau đầu. Vệ binh Tần Quốc nhờ ngươi giúp lấy 5 viên Cứu Cấp Đan cho bá tánh Tần Quốc Trọng Mạc.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 91000 điểm\n" 
 BLK "    Tiềm năng: 1000 điểm\n" 
 BLK "    Ngân lượng: 92000", who->get_save("qgswjiujd"));
		else if (iKind == 60)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 5 Thổ Tinh ở Hư Lăng Động, 6 Quy Tiên Nhân ở Cửu Khúc Kiều, 8 Thiên Cương Môn Thủ ở Thiên Môn Trận, sau đó báo cáo cho thợ thủ công Tần Quốc\n" BLK "Thổ Tinh %d/5\n" BLK "Quy Tiên Nhân %d/6\n" BLK "Thiên Cương Môn Thủ %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thợ thủ công Tần Quốc bị yêu quái và đạo tặc quấy nhiễu không ngừng, nhiều năm tâm huyết bị phá hủy. Dù tin rằng đây chỉ là bóng tối trước bình minh, sau khi thiên hạ bình định, Đại Vương sẽ quét sạch chúng, nhưng hiện tại cần người đánh tan khí thế hung hăng của chúng. Thợ thủ công Tần Quốc nhờ ngươi tiêu diệt 5 Thổ Tinh ở Hư Lăng Động, 6 Quy Tiên Nhân ở Cửu Khúc Kiều, 8 Thiên Cương Môn Thủ ở Thiên Môn Trận, rồi trở về báo cáo.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 98000 điểm\n" 
 BLK "    Tiềm năng: 1120 điểm\n" 
 BLK "    Ngân lượng: 95000\n" 
 BLK "    Vật phẩm: Vũ khí cấp 110", who->get_save("qggjtuj"), who->get_save("qggjguixr"), who->get_save("qggjtiangmzs"));
		else if (iKind == 61)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Tru Tiên Trận tầng 1 tìm Tú Hoa Châm giao cho Tần Tổng Quản\n" BLK "Tú Hoa Châm %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Giúp Tần Tổng Quản tìm lại Tú Hoa Châm ở Tru Tiên Trận tầng 1, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 51000 điểm\n" 
 BLK "    Tiềm năng: 778 điểm\n" 
 BLK "    Ngân lượng: 50300", who->get_legend(44, 19) ? 1 : 0);
		else if (iKind == 62)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 8 Địa Sát Môn Thủ, 8 Thái Cực Môn Thủ ở Thiên Môn Trận, 10 Lượng Tinh ở Hư Lăng Động, 4 Đao Hồn ở Tru Tiên Trận, sau đó báo cáo cho Tề Quản Gia\n" BLK "Địa Sát Môn Thủ %d/8\n" BLK "Thái Cực Môn Thủ %d/8\n" BLK "Lượng Tinh %d/10\n" BLK "Đao Hồn %d/4\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Quản Gia\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tiêu diệt yêu quái, sau đó về báo cáo cho Tề Quản Gia.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 230000 điểm\n" 
 BLK "    Tiềm năng: 2400 điểm\n" 
 BLK "    Ngân lượng: 220000\n" 
 BLK "    Vật phẩm: Giày cấp 110", who->get_save("qzgdismzs"), who->get_save("qzgtaijmzs"), who->get_save("qzgjinj"), who->get_save("qzgdaohun"));
		else if (iKind == 63)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Tru Tiên Trận tìm 5 bộ giáp giao cho Đại tướng quân Tần Quốc\n" BLK "Giáp %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây trời trở lạnh, nhưng thương lộ bị đạo tặc chặn, khiến quan quân nhu Tần Quốc không mua đủ quần áo chống lạnh. Nghe nói trong Tru Tiên Trận, bọn cướp có kho giáp bí mật. Với võ nghệ của ngươi, vào Tru Tiên Trận không phải là khó. Đại tướng quân Tần Quốc Vương Tiễn nhờ ngươi đi thám thính, tìm 5 bộ giáp cho quân Tần.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 91000 điểm\n" 
 BLK "    Tiềm năng: 980 điểm\n" 
 BLK "    Ngân lượng: 94000", who->get_save("qgdjjkuijia"));
		else if (iKind == 65)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt kẻ ác Tăng Cửu, rồi báo cáo cho Tần lão hán\n" BLK "Tăng Cửu %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tần lão hán\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tần lão hán vừa nhận được tin, sở dĩ Đao Hồn tàn sát ở trấn này là vì tên lưu manh Tăng Cửu ở trấn Bình Dương đã vô tình vào Tru Tiên Trận, cướp đá trấn hồn của Đao Hồn. Hiện hắn đang trốn ở phía nam tầng 1 Tru Tiên Trận, vẫn mơ mộng làm giàu, không hề biết hành vi của hắn đã mang đến tai họa lớn cho trấn Bình Dương. Hãy đi tiêu diệt hắn, mang đầu hắn về làm lễ tế cho Tần lão hán, có lẽ sẽ làm dịu cơn giận của Đao Hồn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 83000 điểm\n" 
 BLK "    Tiềm năng: 920 điểm\n" 
 BLK "    Ngân lượng: 96000", who->get_legend(46, 4) ? 1 : 0);
		else if (iKind == 67)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Đao Hồn, 30 Thương Hồn, rồi báo cáo cho Mã Hiển\n" BLK "Đao Hồn %d/30\n" BLK "Thương Hồn %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mã Hiển\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau khi Mã Hiển bói toán, được trời cao mách bảo rằng Tăng Cửu đã cướp 30 đá trấn hồn của Đao Hồn và 30 đá của Thương Hồn. Để trật tự trời đất trở lại bình thường, phải tiêu diệt đúng 30 Đao Hồn và 30 Thương Hồn để sức mạnh trấn hồn tương ứng với số lượng hồn phách, không được thừa thiếu một cái, nếu không sẽ gây ra thảm họa không kiểm soát được. Sau khi hoàn thành, báo cáo cho Mã Hiển, ông ấy sẽ hỏi trời xem có gì bỏ sót không.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 89000 điểm\n" 
 BLK "    Tiềm năng: 1000 điểm\n" 
 BLK "    Ngân lượng: 96000", who->get_save("mxdaohun"), who->get_save("mxqianhun"));
		else if (iKind == 70)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Kiếm Hồn, 30 Thương Hồn, rồi báo cáo cho Dược sư Tần\n" BLK "Kiếm Hồn %d/30\n" BLK "Thương Hồn %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngươi chắc chắn muốn xen vào việc này? Nếu chỉ là tò mò, hãy rời đi ngay. Việc này không phải ai cũng lo được. Nếu không, hãy đến Tru Tiên Trận tiêu diệt 30 Kiếm Hồn và 30 Thương Hồn trước, Dược sư Tần sẽ cân nhắc lại. Nếu thấy không đáng, đừng đi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 88000 điểm\n" 
 BLK "    Tiềm năng: 910 điểm\n" 
 BLK "    Ngân lượng: 93000", who->get_save("qysjianhun"), who->get_save("qysqianhun"));
		else if (iKind == 71)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tống khứ tên cướp Triển Ngũ, rồi báo cáo cho Trình Cường\n" BLK "Triển Ngũ %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Cường\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tiêu diệt tên cướp Triển Ngũ đang ẩn náu tại tầng 2 Tru Tiên Trận, kẻ chuyên cướp bóc và giết hại dân lành ở trấn Bình Dương. Không được gặp lại Dược sư Tần trước khi hoàn thành nhiệm vụ để tránh liên lụy ông. Sau khi hoàn tất, báo cáo cho Trình Cường.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 92000 điểm\n" 
 BLK "    Tiềm năng: 980 điểm\n" 
 BLK "    Ngân lượng: 93000", who->get_legend(46, 19) ? 1 : 0);
		else if (iKind == 72)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp Trình Cường tìm lại Lượng Long Châu\n" BLK "Lượng Long Châu %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trình Cường\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến tầng 2 Tru Tiên Trận tìm lại Lượng Long Châu, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 92000 điểm\n" 
 BLK "    Tiềm năng: 980 điểm\n" 
 BLK "    Ngân lượng: 93000", who->get_legend(46, 22) ? 1 : 0);
		else if (iKind == 75)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại Ngư Long Thảo ở tầng 2 Tru Tiên Trận\n" BLK "Ngư Long Thảo %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, Dược sư Tần luyện đan cho Đại Vương Tần, hiện chỉ thiếu một vị Ngư Long Thảo. Sau khi tìm hiểu nhiều, ông biết rằng thứ này được hình thành từ hồn khí, thường bám vào các vật như rương. Góc tây bắc tầng 2 Tru Tiên Trận có hồn khí và vị trí trận phù hợp để loại cỏ này mọc. Ông nhờ ngươi giúp lấy về.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 89000 điểm\n" 
 BLK "    Tiềm năng: 990 điểm\n" 
 BLK "    Ngân lượng: 92000", who->get_legend(46, 29) ? 1 : 0);
		else if (iKind == 77)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Nguyệt Kiến Thảo giao cho Dược sư Tần\n" BLK "Nguyệt Kiến Thảo %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau khi Hạ Hầu Đảng điều tra, biết được Nguyệt Kiến Thảo có thể khắc phục khuyết điểm của loại thuốc này. Mỗi 12 viên đan dược cần một cây Nguyệt Kiến Thảo. Nghe nói trong rương báu ở phía bắc tầng 3 Tru Tiên Trận thường có loại dược liệu này. Ông ấy yêu cầu ngươi nhanh chóng đến lấy và giao cho Dược sư Tần, đồng thời chuyển lời dặn của ông ấy cho Dược sư Tần.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 88000 điểm\n" 
 BLK "    Tiềm năng: 910 điểm\n" 
 BLK "    Ngân lượng: 93000", who->get_legend(47, 4) ? 1 : 0);
		else if (iKind == 81)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt kẻ ác Hứa Tiểu Tứ, rồi cảnh báo tên nghiện\n" BLK "Hứa Tiểu Tứ %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tên nghiện\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tên nghiện nói rằng mọi thông tin hắn biết đều do lão đại Hứa Tiểu Tứ kể. Nếu không, hắn mù chữ, làm sao biết được những chuyện bí mật như vậy. Có bản lĩnh thì ngươi đến hỏi Hứa Tiểu Tứ ở phía bắc tầng 3 Tru Tiên Trận. Nhưng Hứa Tiểu Tứ sẽ rất “thân thiện” để lại cái đầu của ngươi làm bình rượu. Vì vậy, hoặc là ngươi chết, hoặc là hắn chết. Nhưng nếu Hứa Tiểu Tứ chết, tên nghiện có lẽ sẽ tiết lộ thêm thông tin.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 93000 điểm\n" 
 BLK "    Tiềm năng: 1350 điểm\n" 
 BLK "    Ngân lượng: 86000", who->get_legend(47, 13) ? 1 : 0);
		else if (iKind == 86)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Kiếm Hồn, 30 Thương Hồn, rồi báo cáo cho Hạ Hầu Đảng\n" BLK "Kiếm Hồn %d/30\n" BLK "Thương Hồn %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hạ Hầu Đảng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hạ Hầu Đảng tuyên bố ông ấy chỉ là người bán tin tức, nhưng vì ngươi được Đại tướng quân phái đến, mọi điều kiện đã được thỏa thuận. Ông ấy sẽ nói cho ngươi biết, nhưng trước đó, để tránh ngươi đi vào vết xe đổ của vài người trước, ông yêu cầu ngươi đến tầng 3 Tru Tiên Trận tiêu diệt 30 Kiếm Hồn và 30 Thương Hồn. Ông ấy sẽ dùng hồn khí và sát khí để tạo một lớp bảo vệ cho ngươi, hy vọng với những thứ này, ngươi có thể an toàn mang thần kiếm về.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 95000 điểm\n" 
 BLK "    Tiềm năng: 1500 điểm\n" 
 BLK "    Ngân lượng: 88000", who->get_save("xhdjianhun"), who->get_save("xhdqianhun"));
		else if (iKind == 87)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm lại thần kiếm giao cho Đại tướng quân Tần Quốc\n" BLK "Thần kiếm %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hạ Hầu Đảng đã hoàn thành phép thuật, ngươi giờ đây co rúm lại, toàn thân run rẩy, bao phủ bởi làn da màu mực đỏ. Ông ấy dạy ngươi cách đi trong trận, đến góc tây bắc tầng 3 Tru Tiên Trận, niệm một đoạn chú phá ẩn. Thần kiếm hẳn là được giấu trong rương xung quanh. Sau khi lấy được thần kiếm, giao ngay cho Đại tướng quân, đừng nghĩ đến việc giữ riêng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 93000 điểm\n" 
 BLK "    Tiềm năng: 1300 điểm\n" 
 BLK "    Ngân lượng: 92000", who->get_legend(47, 27) ? 1 : 0);
		else if (iKind == 101)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến doanh trại Thành Kiệu tiêu diệt 4 kiếm binh phản loạn, 4 cung binh phản loạn, 4 mã phu phản loạn, 10 đạo trưởng phản loạn, 10 tiểu đội trưởng phản loạn.\n" BLK "Kiếm binh phản loạn %d/4\n" BLK "Cung binh phản loạn %d/4\n" BLK "Mã phu phản loạn %d/4\n" BLK "Đạo trưởng phản loạn %d/10\n" BLK "Tiểu đội trưởng phản loạn %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân Tần Quốc Vương Tiễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân Tần Quốc Vương Tiễn nói với ngươi, Đại Vương lên ngôi là mong mỏi của muôn dân, nhưng Thành Kiệu, em trai Đại Vương, bị phu nhân Hoa Dương xúi giục, có ý định làm phản, thật là bất hạnh của đất nước. Ngươi hãy đến doanh trại Thành Kiệu tiêu diệt những kẻ phản loạn, rồi báo cáo lại.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 400 điểm\n" 
 BLK "    Ngân lượng: 9600", who->get_save("fb_001_001"), who->get_save("fb_001_002"), who->get_save("fb_001_003"), who->get_save("fb_001_004"), who->get_save("fb_001_005"));
		else if (iKind == 102)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Công Tượng và Khổ Dịch ở Lăng Ly Sơn!\n" BLK "Tần Lăng Công Tượng %d/12\n" BLK "Tần Lăng Khổ Dịch %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tửu Lâu Tần Quốc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ta phải đến Lăng Ly Sơn phá hoại công trình của Tần Vương, ta phải đi ngay!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 9800 điểm\n" 
 BLK "    Tiềm năng: 400 điểm\n" 
 BLK "    Ngân lượng: 19600", who->get_save("fb_sx_qlgj"), who->get_save("fb_sx_qlky"));
		else if (iKind == 103)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp Nhược Thiền hoàn hồn\n" BLK "Ba hồn bảy vía %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ tiệm trang sức Nhược Thiền\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ tiệm trang sức Nhược Thiền đã chuyển đến Hàm Dương được vài năm. Người thanh mai trúc mã được chỉ phúc vi hôn với cô, Đường Truy, vì gia đình gặp đại họa mà thất lạc nhiều năm. Sau này anh ta đến tìm cô để hoàn thành hôn lễ, nhưng cha mẹ Nhược Thiền vì trọng lợi, không muốn họ thành thân, đuổi anh ta đi, còn nói rằng chính cô không ưng anh ta. Từ đó, Nhược Thiền luôn buồn bã, không muốn lấy ai khác.\n" 
 BLK "    Một năm sau, Đường Truy lại đến cầu hôn, vẫn không được chấp thuận. Sau khi anh ta rời đi, Nhược Thiền trở nên ngẩn ngơ, không nói không rằng. Nghe nói Đường Truy học được tà thuật, câu mất ba hồn bảy vía của cô, khiến cô ra nông nỗi này.\n" 
 BLK "    Nghe nói Đường Truy hiện đang gây họa ở lăng mộ Ly Sơn, hãy giúp Nhược Thiền tìm lại ba hồn bảy vía.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 16800 điểm\n" 
 BLK "    Tiềm năng: 400 điểm\n" 
 BLK "    Ngân lượng: 19600", who->get_legend(51, 2) ? 1 : 0);
	}
	else if (iTask == TID_ZHAOGUO)
	{
		if (iKind == 1)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10"HIR "Than đá" BLK " giao cho"HIR "Thợ rèn Đại Vương nước Triệu\n" BLK "Than đá %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ rèn Đại Vương nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Việc này của Yên Thương Thiên có phần khó khăn, ngươi hãy thu thập 10 than đá trước, Thợ rèn Đại Vương sẽ từ từ nghĩ cách. Nếu không biết tìm ở đâu, cứ đến Bạch Vân Phong.\n" 
 BLK "    Tuy nhiên, với khả năng hiện tại của ngươi, đến"HIR "Bạch Vân Phong" BLK " đánh bại"HIR "Mãng lượng" BLK "," HIR "Tinh báo hoa" BLK " để tìm 10 than đá này quá khó. Tốt nhất ngươi nên gọi bạn bè hỗ trợ, hoặc đợi khi khả năng của mình cao hơn rồi đi!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6000\n" 
 BLK "    Tiềm năng: 190\n" 
 BLK "    Ngân lượng: 4500", who->get_save_2("wtjshitan"));
		else if (iKind == 5)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập Liêm đao, Cái cuốc và Bá ki giao cho " HIR "Bá tánh nước Triệu Ngô Cơ\n" 
 BLK "    Cái cuốc %d/1\n" 
 BLK "    Liêm đao %d/1\n" 
 BLK "    Bá ki %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh nước Triệu Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bá tánh nước Triệu Ngô Cơ muốn ta tìm giúp Liêm đao, Cái cuốc, Bá ki. Nghe nói có thể lấy được khi đánh bại Đao Thuẫn Binh hoặc Kiếm Thuẫn Binh nước Triệu tại Trường Thành Triệu.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6500 điểm\n" 
 BLK "    Tiềm năng: 265 điểm\n" 
 BLK "    Ngân lượng: 5600\n" 
 BLK "    Vật phẩm: Yêu Đới cấp 50", who->get_save_2("bxcutou"), who->get_save_2("bxliandao"), who->get_save_2("bxboji"));
		else if (iKind == 6)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20"HIR "Binh cung nước Triệu" BLK ", sau đó báo cáo cho " HIR "Vệ binh nước Triệu\n" BLK "Binh cung nước Triệu %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    " HIR "Binh cung Trường Thành Triệu" BLK " là đám người xấu xa, chúng coi thường luật pháp Đại Vương, ỷ vào tài bắn cung giỏi, bừa bãi làm thương vô số người vô tội. Không biết bao nhiêu người đã bị thương hoặc chết dưới mũi tên của chúng. Tướng quân từng phái nhiều người đi tiêu diệt chúng, nhưng đều thất bại. Giờ hy vọng ngươi có thể giúp, đến Trường Thành Triệu tiêu diệt binh cung nước Triệu. Nhớ cẩn thận, tài bắn cung của chúng không thể xem thường.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6350 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 5500", who->get_save_2("zggongbing"));
		else if (iKind == 7)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20"HIR "Kiếm thuẫn binh nước Triệu" BLK ", sau đó báo cáo cho " HIR "Vệ binh nước Triệu\n" 
 BLK "    Kiếm thuẫn binh %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trường Thành Triệu vốn là con đường tất yếu để dân chúng ra ngoài, nhưng có kẻ lại đánh chủ ý, thu phí qua đường, thật là đám chó đường phố tham tiền.\n" 
 BLK "    Chính đám kiếm thuẫn binh đó đã chặn con đường này bằng hàng rào. Dân thường muốn qua phải nộp tiền mua đường, thật sự coi thường luật pháp Đại Vương. Ngươi hãy đi tiêu diệt đám chó đường phố đó, đứng lên vì dân chúng!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6500 điểm\n" 
 BLK "    Tiềm năng: 260 điểm\n" 
 BLK "    Ngân lượng: 5600", who->get_save_2("zgjianbing"));
		else if (iKind == 9)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 15"HIR "Đao thuẫn binh nước Triệu" BLK ", sau đó báo cáo cho " HIR "Quan tài chính nước Triệu Lận Tương Như\n" BLK "Đao thuẫn binh nước Triệu %d/15\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan tài chính nước Triệu Lận Tương Như\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quan tài chính nước Triệu Lận Tương Như nói rằng ông nhớ ta, lần trước chính ta đã đến mục trường giúp Đại tướng quân nước Triệu Lý Mục tiêu diệt tên đầu sỏ phản loạn ở Trường Thành Triệu? Hừ, nhầm người rồi chăng? Nhưng dường như cũng có chút ấn tượng…\n" 
 BLK "    Thôi, đừng nghĩ nữa, cứ giúp Quan tài chính nước Triệu Lận Tương Như trước. Để tiết kiệm chi phí, đáng lẽ phải phái quân đội tiêu diệt phản tặc, nhưng giờ chỉ có thể nhờ người làm. Vì vậy, ông ấy bảo ta đến Trường Thành Triệu tiêu diệt 15 đao thuẫn binh. Với ta, chuyện này chẳng có vấn đề gì!\n" 
 BLK "    Lát nữa còn có phần thưởng, hì hì~\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6500 điểm\n" 
 BLK "    Tiềm năng: 265 điểm\n" 
 BLK "    Ngân lượng: 5800", who->get_save_2("zgdaobing"));
		else if (iKind == 35)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 5 vò rượu ngon giao cho"HIR "Quan nội chính nước Triệu Bình Nguyên Quân\n" BLK "Rượu ngon %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính nước Triệu Bình Nguyên Quân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại Vương nước Sở Khảo Liệt muốn liên hôn với nước Triệu, Triệu Vương ra lệnh cho các bộ phận dâng lễ vật. Ta nghe nói quân sĩ ở Trường Thành Triệu thường cướp rượu ngon của thương nhân ngoài lãnh thổ, rượu ấy thơm nồng tuyệt hảo. Gần đây ngân sách của bản quan hơi eo hẹp, phu nhân còn chờ ta bớt chút ngân sách mua son phấn cho bà. Thật sự không thể ra chợ mua, mua kém thì lại bị cho là làm việc bất lợi. Vậy nên nhờ ngươi đến Trường Thành Triệu cướp 5 vò rượu ngon về cho ta. Dù sao ai cũng cướp, đừng ai cười ai, hì hì.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 7000 điểm\n" 
 BLK "    Tiềm năng: 280 điểm\n" 
 BLK "    Ngân lượng: 7000", who->get_save_2("zgnzgmeijiu"));
		else if (iKind == 37)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm bảo kiếm ở Trường Thành Triệu giao cho"HIR "Triệu Cơ\n" BLK "Bảo kiếm %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Triệu Cơ dường như rất hiểu biết, cô ấy biết được tung tích của bảo kiếm Vi Kiếm, bảo ngươi đến Trường Thành Triệu lấy về, còn nói chỉ người xứng đôi mới lấy được, ngang nhiên xem việc cướp bóc là chính đáng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4000 điểm\n" 
 BLK "    Tiềm năng: 188 điểm\n" 
 BLK "    Ngân lượng: 3700", who->get_legend(TASK_19, 27) ? 1 : 0);
		else if (iKind == 39)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10"HIR "Đao thuẫn binh" BLK ", 10"HIR "Kiếm thuẫn binh" BLK ", 10"HIR "Binh cung" BLK " rồi báo cáo cho " HIR "Lã Bất Vi\n" BLK "Đao thuẫn binh %d/10\n" BLK "Kiếm thuẫn binh %d/10\n" BLK "Binh cung %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lã Bất Vi\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hóa ra Triệu Cơ tặng bảo kiếm cho ông ta là để ông ta duyệt hậu, hẹn gặp mặt, hì hì. Ta đến"HIR "Trường Thành Triệu" BLK " giúp họ duyệt vậy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 12000 điểm\n" 
 BLK "    Tiềm năng: 730 điểm\n" 
 BLK "    Ngân lượng: 18000", who->get_save_2("lbwdaodunbing"), who->get_save_2("lbwjiandunbing"), who->get_save_2("lbwgongbing"));
		else if (iKind == 40)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Gửi thư cho"HIR "Tầm Nhi" BLK " và ở"HIR "bờ sông Vô Định" BLK " tiêu diệt"HIR "con bạc Triệu Tấn\n" BLK "Triệu Tấn %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Con bạc Triệu Tấn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi lính 10 năm, anh ta không gặp lại người phụ nữ của mình lần nào, trong đầu chỉ còn lại tiếng khóc xé lòng và khuôn mặt mờ nhạt của cô ấy. Anh ta chịu nhục, thề không để mình chết trên chiến trường, vì anh ta chờ ngày vinh quy bái tổ, đoàn tụ với người phụ nữ đó. Anh ta không biết chữ, không viết được thư, người phụ nữ của anh ta cũng mù chữ. Anh ta thường nhờ đồng đội viết thư, dù biết cô ấy không đọc được, nhưng chỉ cần cô ấy biết anh ta còn sống. Bạch Dịch đã viết xong thư, bảo ta gửi cho Tầm Nhi, và nói rằng ở"HIR "bờ sông Vô Định" BLK " có một con bạc tên"HIR "Triệu Tấn" BLK " luôn nhòm ngó Tầm Nhi, bảo ta tiện thể dạy dỗ hắn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 20000 điểm\n" 
 BLK "    Tiềm năng: 290 điểm\n" 
 BLK "    Ngân lượng: 20000", who->get_legend(TASK_23, 28) ? 1 : 0);
		else if (iKind == 41)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20 đao thuẫn khô lâu, 10 kiếm thuẫn khô lâu, sau đó báo cáo cho Đại tướng quân nước Triệu Lý Mục\n" BLK "Đao thuẫn khô lâu %d/20\n" BLK "Kiếm thuẫn khô lâu %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Triệu Lý Mục\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, trong hố vạn nhân tập trung một lượng lớn quân khô lâu. Nếu tiếp tục để chúng gia tăng, sẽ gây mối đe dọa lớn cho an ninh nước Triệu. Vì vậy, phải tiên hạ thủ vi cường, tiêu diệt chúng trước khi chúng trở thành mối nguy chính thức. Hãy đến hố vạn nhân tiêu diệt"HIR "20 đao thuẫn khô lâu" BLK " và"HIR "10 kiếm thuẫn khô lâu" BLK ", sau đó báo cáo cho Đại tướng quân nước Triệu.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 46000 điểm\n" 
 BLK "    Tiềm năng: 645 điểm\n" 
 BLK "    Ngân lượng: 45000", who->get_save_2("zgdjjdaodkl"), who->get_save_2("zgdjjjiandkl"));
		else if (iKind == 43)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt khô lâu ở hố vạn nhân để lấy khóa đồng tâm, giao cho Bá tánh nước Triệu Ngô Cơ\n" BLK "Khóa đồng tâm %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh nước Triệu Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Theo gợi ý trong thư của Tổng quản Yên, đôi khóa đồng tâm này hẳn ở trên một khô lâu trong"HIR "hố vạn nhân" BLK ". Nhưng"HIR "khô lâu trong hố vạn nhân" BLK " Bá tánh nước Triệu Ngô Cơ không đánh nổi, nên cần ta giúp. Đến hố vạn nhân tiêu diệt khô lâu và tìm khóa đồng tâm giao cho Bá tánh nước Triệu Ngô Cơ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 100000 điểm\n" 
 BLK "    Tiềm năng: 1400 điểm\n" 
 BLK "    Ngân lượng: 100000\n" 
 BLK "    Vật phẩm: Hạng liên cấp 80", who->get_legend(TASK_27, 17) ? 1 : 0);
		else if (iKind == 44)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 sừng hươu cho Vệ binh nước Triệu\n" BLK "Sừng hươu %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ binh nước Triệu nói rằng trong"HIR "hố vạn nhân" BLK " có nhiều người từng là thương nhân buôn sừng hươu. Họ đến chết vẫn không bỏ hàng hóa, kết quả để lại lợi ích cho người sau. Đến đó nhặt tùy tiện cũng được nhiều sừng hươu thượng hạng, bán được không ít tiền. Tất nhiên, sừng hươu chỉ dành cho dũng sĩ can đảm, vì chỉ Vệ binh nước Triệu biết cách tẩy uế khí trên sừng hươu. Phần thù lao chắc chắn sẽ khiến ngươi hài lòng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 48000 điểm\n" 
 BLK "    Tiềm năng: 680 điểm\n" 
 BLK "    Ngân lượng: 46000", who->get_save("zgswlujiao"));
		else if (iKind == 45)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 8 tấm gỗ và 3 viên ngọc cho Vệ binh nước Triệu\n" BLK "Tấm gỗ %d/8\n" BLK "Ngọc %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Người thân của Vệ binh nước Triệu là một đại sư điêu khắc nổi tiếng, tác phẩm của ông ấy tinh xảo, được giới quý tộc và hoàng thất coi là báu vật. Gần đây, ông ấy đồng ý làm cho Vệ binh nước Triệu một giá bút trấn trạch, cần 8 tấm gỗ và 3 viên ngọc. Ngọc phải là ngọc chết, gỗ phải là gỗ thi, đều phải hút khí oán linh để lấy độc trị độc. Hai thứ này dễ tìm nhất ở"HIR "hố vạn nhân" BLK ". Ông ấy nhờ ngươi đi một chuyến.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 48600 điểm\n" 
 BLK "    Tiềm năng: 688 điểm\n" 
 BLK "    Ngân lượng: 46800", who->get_save("zgswmuban"), who->get_save("zgswyushi"));
		else if (iKind == 46)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt Cương Thi Lý Nhận\n" BLK "Cương Thi Lý Nhận %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi đến Mục Trường tiêu diệt Cương Thi Lý Nhận, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 49000 điểm\n" 
 BLK "    Tiềm năng: 690 điểm\n" 
 BLK "    Ngân lượng: 47000", who->get_legend(TASK_28, 5) ? 1 : 0);
		else if (iKind == 47)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm rương gỗ, giao cho Vệ binh nước Triệu\n" BLK "Rương gỗ %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ở"HIR "tầng sâu nhất hố vạn nhân" BLK " có một rương gỗ, nghe nói rương này là thứ mà người trong giang hồ mơ ước cả đời. Vệ binh nước Triệu cũng muốn tìm nó, nhưng ông ấy nói trong hố vạn nhân ẩn náu những quỷ quái đáng sợ, chúng sẽ trung thành bảo vệ rương gỗ đó. Ta nghĩ mình phải cẩn thận.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 26000 điểm\n" 
 BLK "    Tiềm năng: 445 điểm\n" 
 BLK "    Ngân lượng: 25000", who->get_legend(TASK_28, 8) ? 1 : 0);
		else if (iKind == 50)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp Vệ binh nước Triệu, đến hố vạn nhân tiêu diệt 20 cương thi\n" BLK "Cương thi %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trong"HIR "hố vạn nhân" BLK " oán khí rất nặng, vì phần lớn là thương khách từ nơi khác chết oan. Do dục vọng chưa được thỏa mãn, họ bất an, gây hại xung quanh. Nhờ oán khí, họ có sức mạnh tà ác lớn, khiến nhiều cao thủ phải chùn bước. Đặc biệt, cương thi gây hại rất rộng, tụ tập thành một thế lực tà ác lớn. Vệ binh nước Triệu hy vọng ngươi tiêu diệt 20 cương thi để giảm bớt sức mạnh của chúng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 50000 điểm\n" 
 BLK "    Tiềm năng: 700 điểm\n" 
 BLK "    Ngân lượng: 48000", who->get_save("zgswjiangsi"));
		else if (iKind == 51)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp thợ thủ công nước Triệu báo thù, tiêu diệt 25 đao thuẫn khô lâu\n" BLK "Đao thuẫn khô lâu %d/25\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thợ thủ công nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Con trai của thợ thủ công nước Triệu vì an toàn của dân chúng đã đến hố vạn nhân chiến đấu với đao thuẫn khô lâu. Anh ta nhiều lần thoát chết, cho đến khi thợ thủ công nhận được thư, nói rằng họ sắp mở một trận chiến lớn để tiêu diệt đao thuẫn khô lâu. Sau đó, không còn tin tức gì nữa. Thợ thủ công nhờ ta báo thù, đến hố vạn nhân tiêu diệt chúng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 51000 điểm\n" 
 BLK "    Tiềm năng: 705 điểm\n" 
 BLK "    Ngân lượng: 48800", who->get_save("zggjdaodkl"));
		else if (iKind == 52)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Chứng minh thực lực cho Đại tướng quân nước Triệu Lý Mục, đến hố vạn nhân tiêu diệt đao thuẫn, kiếm thuẫn, song đao khô lâu\n" BLK "Đao thuẫn khô lâu %d/10\n" BLK "Kiếm thuẫn khô lâu %d/10\n" BLK "Song đao khô lâu %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Triệu Lý Mục\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân nước Triệu Lý Mục muốn thu nhận ngươi làm thuộc hạ, nhưng ông ta không bao giờ nhận người vô danh. Người mới phải nộp một món ‘đầu danh trạng’. Nếu chỉ bắt ngươi xử lý một tên côn đồ nhỏ thì chẳng có giá trị, cùng lắm ngươi chỉ làm được tiểu giáo. Nếu muốn làm chức cao hơn, ngươi phải接受 thử thách khó khăn hơn của Đại tướng quân nước Triệu Lý Mục. Chuẩn bị好了 chưa? Tốt, đến"HIR "hố vạn nhân" BLK " tiêu diệt"HIR "10 đao thuẫn khô lâu, 10 kiếm thuẫn khô lâu, 8 song đao khô lâu" BLK ". Nếu trở về nguyên vẹn, Đại tướng quân Lý Mục sẽ trọng dụng ngươi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 52000 điểm\n" 
 BLK "    Tiềm năng: 710 điểm\n" 
 BLK "    Ngân lượng: 49000", who->get_save("zgdjjdaodunkl"), who->get_save("zgdjjjiandunkl"), who->get_save("zgdjjsuangdaokl"));
		else if (iKind == 59)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến tầng 3 Thiên Môn Trận tiêu diệt Thái Cực Môn Thủ để tìm lệnh kỳ, giao cho Đại tướng quân nước Triệu Lý Mục\n" BLK "Lệnh kỳ %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Triệu Lý Mục\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lệnh kỳ có thể điều khiển toàn bộ binh tướng nước Triệu, nhưng Đại tướng quân Lý Mục vì nhất thời mê muội, mê một nữ tử, không ngờ lại là gián điệp Thái Cực Môn. Chúng dùng mê thần tán bắt cóc ông đến Thiên Môn Trận, ép hợp tác. Đại tướng quân giả vờ đồng ý, nhưng bị buộc để lại lệnh kỳ làm vật thế chấp. Mất lệnh kỳ là tội chết, giờ Đại tướng quân ăn ngủ không yên, nhưng tuyệt đối không muốn hợp tác với bọn giặc này. Ông nhờ ngươi lấy lại lệnh kỳ. Nếu thành công, trong quyền hạn của ông, ông sẽ đáp ứng nguyện vọng của ngươi! Lệnh kỳ được cất ở tầng 3"HIR "Thiên Môn Trận" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 90000 điểm\n" 
 BLK "    Tiềm năng: 970 điểm\n" 
 BLK "    Ngân lượng: 93000", who->get_legend(43, 27) ? 1 : 0);
		else if (iKind == 60)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp Triệu Vương đến Tru Tiên Trận tìm ngọc bội Như Ý\n" BLK "Ngọc bội Như Ý %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Triệu Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thế tử nước Triệu đột nhiên ngã bệnh, sốt cao liên tục, tinh thần hoảng loạn, gầy đi nhanh chóng, nghe nói ban đêm còn mê sảng. Triệu Vương triệu tất cả ngự y trong cung, nhưng đều bó tay. Mấy hôm trước, một đạo trưởng ở Khâm Dương đến, nói rằng ngọc bội Như Ý, một cổ vật thượng cổ, có thể làm dịu bệnh này. Nhưng Triệu Vương đã cử hàng chục dũng sĩ đến Tru Tiên Trận lấy từ Đao Hồn, đều đi không trở lại. Nhìn con trai nguy kịch, Triệu Vương lo lắng không biết ai sẽ kế thừa giang sơn. Ông nhờ ngươi đến Tru Tiên Trận lấy ngọc bội Như Ý từ Đao Hồn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 51500 điểm\n" 
 BLK "    Tiềm năng: 780 điểm\n" 
 BLK "    Ngân lượng: 51000", who->get_legend(45, 19) ? 1 : 0);
		else if (iKind == 70)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Thủ Trận Thiên Binh, 30 Thủ Trận Thần Tướng, báo cáo cho Tổng quản Triệu\n" BLK "Thủ Trận Thiên Binh %d/30\n" BLK "Thủ Trận Thần Tướng %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng quản Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trận pháp Thiên Môn được bảo vệ bởi nhiều tầng thủ vệ. Trước tiên, ngươi phải phá Lục Kiếp Sát trong trận đồ, nếu không, ngươi sẽ chết bất đắc kỳ tử trước khi chạm vào sách. Gián điệp nước Triệu潜 nhập Thiên Môn Trận nhiều năm, cuối cùng biết được danh tính và điểm mấu chốt của Lục Kiếp Sát. Đáng tiếc, trước đó đã có nhiều dũng sĩ hy sinh vô ích. Để phá Lục Kiếp Sát, cần người nội lực tinh thuần, tâm không tạp niệm, theo vị trí Lục Kiếp tiêu diệt 30 Thủ Trận Thiên Binh và 30 Thủ Trận Thần Tướng. Sau khi phá Lục Kiếp Sát, báo cáo cho Tổng quản Triệu, ông ấy sẽ hướng dẫn tiếp.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 92000 điểm\n" 
 BLK "    Tiềm năng: 1400 điểm\n" 
 BLK "    Ngân lượng: 82000", who->get_save("zzgshouztb"), who->get_save("zzgshouzsj"));
		else if (iKind == 76)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Địa Sát Môn Thủ, 30 Thủ Trận Thiên Binh, báo cáo cho Bá tánh nước Triệu Ngô Cơ\n" BLK "Địa Sát Môn Thủ %d/30\n" BLK "Thủ Trận Thiên Binh %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh nước Triệu Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói chiến báo bị Địa Sát Môn ở Thiên Môn Trận đánh cắp. Ngươi hãy tiêu diệt 30 Địa Sát Môn Thủ và 30 Thủ Trận Thiên Binh trước. Bá tánh nước Triệu Ngô Cơ sẽ dùng thuật Tầm Hồn để dò la tin tức.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 95000 điểm\n" 
 BLK "    Tiềm năng: 1650 điểm\n" 
 BLK "    Ngân lượng: 86000", who->get_save("zgbxdsmzs"), who->get_save("zgbxshouztb"));
		else if (iKind == 79)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Thái Cực Môn Thủ, 30 Thủ Trận Thiên Binh, báo cáo cho Bá tánh nước Triệu Ngô Cơ\n" BLK "Thái Cực Môn Thủ %d/30\n" BLK "Thủ Trận Thiên Binh %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Bá tánh nước Triệu Ngô Cơ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bá tánh nước Triệu Ngô Cơ lại phải dùng thuật Tầm Hồn có tác dụng phụ lớn. Theo ông ấy biết, vụ ám sát này liên quan đến Thái Cực Môn. Ngươi đến tầng 3"HIR "Thiên Môn Trận" BLK " tiêu diệt 30 Thái Cực Môn Thủ và 30 Thủ Trận Thiên Binh, rồi báo cáo cho Bá tánh nước Triệu Ngô Cơ. Ông ấy miễn cưỡng dùng thuật Tầm Hồn lần nữa, nhưng dặn ngươi phải báo cáo công lao của ông ấy với Ngự sử đại nhân, không được thiếu phần thưởng, nếu không ông ấy sẽ không muốn nhận việc này nữa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 97000 điểm\n" 
 BLK "    Tiềm năng: 1700 điểm\n" 
 BLK "    Ngân lượng: 88000", who->get_save("zgbxtjmzs"), who->get_save("zgbxshouztb1"));
		else if (iKind == 101)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10 linh kiện cơ quan cho Đại tướng quân nước Triệu\n" BLK "Linh kiện cơ quan %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Triệu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân nước Triệu rất đau đầu vì vũ khí công thành sắc bén của nước Tần, nghe nói do cơ quan vận hành. Vì vậy, nhờ ngươi đến lăng mộ Ly Sơn thu thập 10 linh kiện cơ quan. Nghe nói trong đó có nhiều binh tượng cơ quan, trên người chúng có những linh kiện này.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 12800 điểm\n" 
 BLK "    Tiềm năng: 500 điểm\n" 
 BLK "    Ngân lượng: 9600", who->get_save("fb_qgjggj"));
	}
	else if (iTask == TID_QIGUO)
	{
		if (iKind == 3)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm 9 bó lúa và giao cho quan tài chính nước Tề - Điền Đan\n" BLK "Lúa %d/9\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan tài chính nước Tề - Điền Đan\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nước Triệu đối với hai nước Yên và Tề là một bức tường chắn ở phía Tây, giống như răng có môi bảo vệ. Nếu môi không còn, răng sẽ cảm thấy lạnh. Nếu nước Triệu hôm nay bị diệt, ngày mai sẽ đến lượt Tề và Yên, vì vậy cần phải cứu nước Triệu, và phải nhanh chóng. Lúa là tín vật, tìm 9 bó lúa và giao cho quan tài chính, ông ấy sẽ hiểu ý của Chu Tử! Tiêu diệt" HIR "yêu lang Đại Biệt Sơn" BLK "để lấy được lúa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3000 điểm\n" 
 BLK "    Tiềm năng: 95 điểm\n" 
 BLK "    Ngân lượng: 2200", who->get_save_2("zouzidaozi"));
		else if (iKind == 5)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR "Thái Sơn" BLK "10 con gấu đen và 10 con yêu bọ ngựa, báo cáo cho đại tướng quân nước Tề - Điền Kỵ\n" BLK "Gấu đen %d/10  Yêu bọ ngựa %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Tề - Điền Kỵ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Những con gấu đen và yêu bọ ngựa ở Thái Sơn cách đây 10 năm đã hóa thành người, một nhóm 20 người đến xin làm việc cho đại tướng quân nước Tề. Thấy họ có thể hình cao lớn, tướng quân đồng ý, nhưng một năm sau, tất cả đều bỏ trốn, ăn cắp binh pháp của nước Tề. Tướng quân vô cùng tức giận, luôn muốn bắt họ, nhưng hành tung của họ rất bí ẩn. Nay đã điều tra được họ đang ẩn náu ở Thái Sơn. Lừa dối sẽ bị trời phạt!\n" 
 BLK "    Tiêu diệt chúng và đến chỗ tướng quân nhận thưởng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3500 điểm\n" 
 BLK "    Tiềm năng: 112 điểm\n" 
 BLK "    Ngân lượng: 3000", who->get_save_2("swheixiong"), who->get_save_2("swtanglang"));
		else if (iKind == 11)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm quân cờ đen mà cậu bé Tiểu Hắc ở phủ Thái Công cần\n" BLK "Quân cờ đen: %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Cậu bé Tiểu Hắc ở phủ Thái Công\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Cậu bé Tiểu Hắc ở phủ Thái Công mới đến vài ngày đã làm mất mấy quân cờ. Dù chủ nhân không trách phạt, cậu vẫn cảm thấy áy náy và muốn bù đắp lỗi lầm. Nghe nói gấu đen ở Thái Sơn có quân cờ, cậu muốn tìm 3 quân cờ, nhưng Thái Sơn quá nguy hiểm, một đứa trẻ như cậu không dám đi một mình. Với võ nghệ cao cường của bạn, hãy giúp cậu tìm 3 quân cờ đó.\n" 
 BLK "    Từ phủ Thái Công có thể đi thẳng đến Thái Sơn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4000 điểm\n" 
 BLK "    Tiềm năng: 115 điểm\n" 
 BLK "    Ngân lượng: 3000", who->get_save_2("qtheiqizi"));
		else if (iKind == 12)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 10 vò rượu ngon và giao cho thương nhân nước Tề - Nghĩa Đốn\n" BLK "Rượu ngon %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân nước Tề - Nghĩa Đốn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói doanh trại quân đội mới có thêm nhiều binh sĩ, những người này nghiện rượu như mạng. Thương nhân nước Tề - Nghĩa Đốn cho rằng đây là cơ hội làm ăn lớn, cần nhanh chóng liên hệ với họ. Ông ta muốn tặng vài vò rượu ngon để lấy lòng chỉ huy của họ, nhưng rượu ngon thì khó tìm. Nghe nói" HIR "thôn chài Đông Hải" BLK "có đám tôm binh cua tướng cất giấu một lô rượu ngon, chôn dưới đất hàng trăm năm. Nếu giờ bạn tìm được 10 vò cho ông ta, chẳng khác nào giúp ông ta trong lúc khó khăn, ông ta chắc chắn sẽ cảm tạ bạn hậu hĩnh!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 4000 điểm\n" 
 BLK "    Tiềm năng: 115 điểm\n" 
 BLK "    Ngân lượng: 3000", who->get_save_2("shrmingjiu"));
		else if (iKind == 14)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 con" HIR "Ác ma trong lọ" BLK ", trở về báo cáo cho đại tướng quân nước Tề\n" BLK "Ác ma trong lọ %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Kho lương thực của quân đội nước Tề bị đám ác ma trong lọ quấy phá, những chiếc lọ dùng để chứa thực phẩm đã bị chúng cướp mất. Dù những chiếc lọ này không thể dùng chứa thực phẩm nữa, tướng quân vẫn yêu cầu ta tiêu diệt 10 con" HIR "Ác ma trong lọ" BLK "để trừng phạt. Hiện chúng đã trốn đến" HIR "Động Linh Cốc" BLK "tầng một.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 28000 điểm\n" 
 BLK "    Tiềm năng: 490 điểm\n" 
 BLK "    Ngân lượng: 29000", who->get_save_2("qgdjjguanzy"));
		else if (iKind == 16)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm con dấu quan tại Động Linh Cốc và giao cho nội chính quan nước Tề - Mạnh Thường Quân\n" BLK "Con dấu quan %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội chính quan nước Tề - Mạnh Thường Quân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vài ngày trước, khi nội chính quan Mạnh Thường Quân đang phê duyệt công văn, một hạt đậu trên bàn hóa thành binh đậu và cướp mất con dấu quan của ông. Không có con dấu, ông không thể phê duyệt công văn, dẫn đến việc công văn bị tồn đọng ba ngày. Phải tìm lại con dấu trước khi Tề Vương phát hiện, nếu không ông sẽ gặp rắc rối lớn. Binh đậu đó là một trong số những binh đậu ở" HIR "Động Linh Cốc" BLK ", hãy nhanh chóng tìm lại con dấu cho ông.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 30000 điểm\n" 
 BLK "    Tiềm năng: 498 điểm\n" 
 BLK "    Ngân lượng: 30000", who->get_legend(TASK_24, 18) ? 1 : 0);
		else if (iKind == 17)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20 oan hồn và báo cáo cho đại tướng quân nước Tề - Điền Kỵ\n" BLK "Oan hồn %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Tề - Điền Kỵ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói gần đây phủ Đại Vương thường xuyên bị ma quỷ quấy nhiễu, khiến người trong phủ ai nấy đều tiều tụy, uể oải. Đại tướng quân nước Tề quyết không để mối họa này đe dọa Đại Vương! Theo thám tử điều tra, lũ ma quỷ quấy nhiễu phủ Đại Vương chính là" HIR "những oan hồn ở tầng hai Động Linh Cốc" BLK ". Đại tướng quân ủy thác cho ta đến tầng hai Động Linh Cốc tiêu diệt 20 oan hồn, để chúng không dám quấy nhiễu phủ nữa!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 35000 điểm\n" 
 BLK "    Tiềm năng: 510 điểm\n" 
 BLK "    Ngân lượng: 33000", who->get_save_2("qgdjjyuanhun"));
		else if (iKind == 18)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập một ít viên cứu cấp và giao cho dân chúng nước Tề\n" BLK "Viên cứu cấp %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dân chúng nước Tề thường chuẩn bị một ít viên cứu cấp để bảo vệ tính mạng trong thời chiến, nhưng gần đây đám yêu quái ở Động Linh Cốc không rõ vì lý do gì đã đánh cắp hết viên cứu cấp của họ. Nghe nói sắp có chiến tranh, không có viên cứu cấp, e rằng tính mạng của họ khó được đảm bảo. Có vẻ như ta phải đến" HIR "Động Linh Cốc" BLK "để lấy lại 20 viên cứu cấp cho họ. Tất cả yêu quái ở Động Linh Cốc đều mang theo viên cứu cấp của dân chúng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 35000 điểm\n" 
 BLK "    Tiềm năng: 510 điểm\n" 
 BLK "    Ngân lượng: 33000", who->get_save_2("qgbxjiujiwan"));
		else if (iKind == 19)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20 con" HIR "dịch quỷ" BLK ", trở về báo cáo cho quan điển ngục nước Tề\n" BLK "Dịch quỷ %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan điển ngục nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trong nhà ngục nước Tề xảy ra một trận dịch bệnh kinh hoàng, gần như tất cả mọi người trong ngục đều bị nhiễm bệnh. Dù quan điển ngục đã cách ly nhà ngục với bên ngoài, nhưng e rằng dịch bệnh vẫn sẽ lây lan ra ngoài một ngày nào đó. Nguyên nhân gây ra trận dịch này là đám dịch quỷ ở Động Linh Cốc. Chỉ cần tiêu diệt chúng, có lẽ sẽ khiến trận dịch này lắng xuống. Ta sẽ đến Động Linh Cốc tiêu diệt đám dịch quỷ này, chúng tổng cộng có 20 con.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 37000 điểm\n" 
 BLK "    Tiềm năng: 528 điểm\n" 
 BLK "    Ngân lượng: 35000", who->get_save_2("qgdygyigui"));
		else if (iKind == 20)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay" HIR "vệ binh nước Tề" BLK "đến" HIR "Động Linh Cốc" BLK "tiêu diệt" HIR "20 con quỷ mị" BLK "\n" BLK "Quỷ mị %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, một số quỷ mị ở Động Linh Cốc thường xuyên muốn lẻn vào thành Lâm Truy, nhưng nhờ có vệ binh nước Tề canh gác nên chúng chưa thành công. Tuy nhiên, nếu để chúng lẻn vào thành, dân chúng trong thành sẽ chịu thảm họa không thể tưởng tượng. Để bảo vệ dân chúng, ta sẽ thay vệ binh nước Tề đến" HIR "Động Linh Cốc" BLK "tiến hành một đòn quyết định với đám quỷ mị này. Chỉ cần tiêu diệt một lần" HIR "20 con quỷ mị" BLK ", sẽ gây ra một đòn chí mạng cho chúng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 40000 điểm\n" 
 BLK "    Tiềm năng: 560 điểm\n" 
 BLK "    Ngân lượng: 37000", who->get_save_2("qgswwangliang"));
		else if (iKind == 21)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 25 vệ binh người chết, sau đó trở về báo cáo cho vệ binh nước Tề\n" BLK "Vệ binh người chết %d/25\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Những vệ binh người chết xuất hiện ở Động Linh Cốc thực chất là linh hồn của các vệ binh tử trận trước đây. Sau trận chiến Trường Bình, linh hồn của họ bị thao túng, không được an nghỉ. Vệ binh nước Tề hiện tại thấy đồng đội cũ chết mà không được yên lòng, trong lòng rất khó chịu. Hãy đến" HIR "Động Linh Cốc" BLK "giải quyết những" HIR "vệ binh người chết" BLK "này, giúp họ được an nghỉ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 45000 điểm\n" 
 BLK "    Tiềm năng: 640 điểm\n" 
 BLK "    Ngân lượng: 44500", who->get_save_2("qgswshiwwl"));
		else if (iKind == 22)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay sử tiết nước Tề - Trâu Diễn đến Động Linh Cốc xem xét và tiêu diệt 10 xác đồng giáp\n" BLK "Xác đồng giáp %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sử tiết nước Tề - Trâu Diễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Khi còn nhỏ, sử tiết nước Tề - Trâu Diễn vì ham chơi đã bị bọn cướp bắt đến một hang động rất đẹp. Dù ban đầu bị đám xác đồng giáp dọa cho sợ chết khiếp, nhưng may mắn được một đạo sĩ cứu thoát. Sau đó, ông bị bệnh nặng, nhưng vẫn không quên cảnh sắc kỳ lạ và tuyệt đẹp trong hang. Nay ông biết được nơi đó là" HIR "Động Linh Cốc" BLK ", nhưng vì địa hình hiểm trở và trách nhiệm công việc, ông không thể tự mình đến. Ông nhờ bạn thay ông đến đó xem xét lại một lần, đồng thời tiêu diệt 10 xác đồng giáp để trả mối hận năm xưa.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 44000 điểm\n" 
 BLK "    Tiềm năng: 635 điểm\n" 
 BLK "    Ngân lượng: 43500", who->get_save("qgsjtongjiasi"));
		else if (iKind == 23)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thay vệ binh nước Tề tiêu diệt 10 xác sắt giáp\n" BLK "Xác sắt giáp %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Cha của vệ binh nước Tề luôn nhớ mãi về Động Linh Cốc, nói rằng đó là nơi đẹp nhất ông từng thấy. Nhưng ông bất chấp tuổi già, lén đến đó và chỉ được dân làng cứu về trong tình trạng hấp hối. Vài ngày sau, ông qua đời, nhưng dù đầy thương tích, ông vẫn mỉm cười. Với vệ binh nước Tề, Động Linh Cốc - nơi được gọi là đẹp nhất - cũng là nơi có yêu ma. Ông hận vì trước đây khi tổ chức truy quét lại bị cấp trên ngăn cản, nói rằng không được làm ô uế chốn tiên linh. Vì trách nhiệm, ông không dám tự ý đến đó. Vệ binh nước Tề nhờ bạn tiêu diệt" HIR "10 xác sắt giáp" BLK "để báo thù cho cha.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 45000 điểm\n" 
 BLK "    Tiềm năng: 638 điểm\n" 
 BLK "    Ngân lượng: 43800", who->get_save("qgswtiejiasi"));
		else if (iKind == 24)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Vệ binh nước Tề yêu cầu bạn đến" HIR "Hầm Vạn Nhân" BLK "tiêu diệt 10 con" HIR "khô lâu đao thuẫn\n" BLK "Khô lâu đao thuẫn %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ binh nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ binh nước Tề nói rằng ông đã mong bạn đến từ lâu. Xưa kia, tổ tiên của ông đã không tiếc sức tạo ra hầm Vạn Nhân, giết không biết bao nhiêu người, đến mức tay cũng mỏi. Bà của tổ tiên ông mỗi ngày về nhà đều đau lòng khóc lóc. Nay đám khô lâu trong hầm Vạn Nhân dám đàn áp hài cốt của tổ tiên ông. Tổ tiên ông thường khóc lóc kể với ông về việc bị đám dân đen mà ông giết hại hành hạ ra sao, thê thảm thế nào. Nghe vậy, vệ binh nước Tề khóc như mưa. Ông yêu cầu bạn nhanh chóng tiêu diệt 10 con" HIR "khô lâu đao thuẫn" BLK "đáng ghét, ông đang chờ tin tốt từ bạn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 45500 điểm\n" 
 BLK "    Tiềm năng: 640 điểm\n" 
 BLK "    Ngân lượng: 44000", who->get_save("qgswdaodkl"));
		else if (iKind == 27)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 con sư tử đá, 30 con hổ đá và báo cáo cho tổng quản nước Tề\n" BLK "Sư tử đá %d/30\n" BLK "Hổ đá %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng quản nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tổng quản nước Tề muốn thử thách khả năng của bạn. Hãy đến tầng hai lăng mộ tướng quân tiêu diệt 30 con sư tử đá và 30 con hổ đá để chứng tỏ cho ông ta thấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 53000 điểm\n" 
 BLK "    Tiềm năng: 710 điểm\n" 
 BLK "    Ngân lượng: 53000", who->get_save("qzgshisi"), who->get_save("qzgshihu"));
		else if (iKind == 33)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 tượng đao, 30 tượng thương và báo cáo cho dân chúng nước Tề\n" BLK "Tượng đao %d/30\n" BLK "Tượng thương %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Dân chúng nước Tề bí mật nói với bạn rằng nghe nói" HIR "tượng đao và tượng thương" BLK "cất giấu báu vật. Bạn hãy thử vận may xem sao.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 60000 điểm\n" 
 BLK "    Tiềm năng: 780 điểm\n" 
 BLK "    Ngân lượng: 51000", who->get_save("qgbxdaoyong"), who->get_save("qgbxqianyong"));
		else if (iKind == 37)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 tượng thương, 30 tượng cung tên đá và báo cáo cho Lôi Bá Thiên\n" BLK "Tượng thương %d/30\n" BLK "Tượng cung tên đá %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lôi Bá Thiên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến tầng bốn lăng mộ tướng quân tiêu diệt 30 tượng thương và 30 tượng cung tên đá, vệ binh của Lôi Bá Thiên, để cho ông ta biết đừng quá kiêu ngạo.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 67000 điểm\n" 
 BLK "    Tiềm năng: 790 điểm\n" 
 BLK "    Ngân lượng: 53000", who->get_save("lbtqianyong"), who->get_save("lbtgongjsy"));
		else if (iKind == 42)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt" HIR "30 con sư tử đá, 30 con hổ đá" BLK "và báo cáo cho thương nhân nước Tề - Nghĩa Đốn\n" BLK "Sư tử đá %d/30\n" BLK "Hổ đá %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân nước Tề - Nghĩa Đốn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thương nhân nước Tề - Nghĩa Đốn luôn đề phòng bị cướp, không dám lộ tài sản, không dám đi một mình, nhưng vẫn bị cướp. Ông không ngờ 30 con sư tử đá mình thuê lại là đồng bọn với 30 con hổ đá cướp của ông, phía sau chúng còn có kẻ chỉ huy. Thương nhân nước Tề - Nghĩa Đốn không thể nuốt trôi mối hận này. Hãy nhanh chóng đến" HIR "tầng hai lăng mộ tướng quân" BLK "tiêu diệt" HIR "30 con sư tử đá" BLK "phản bội và" HIR "30 con hổ đá" BLK "cướp của ông!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 69000 điểm\n" 
 BLK "    Tiềm năng: 800 điểm\n" 
 BLK "    Ngân lượng: 55000", who->get_save("qgsrshisi"), who->get_save("qgsrshihu"));
		else if (iKind == 46)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 tượng cung tên đá, 30 tượng thương và báo cáo cho tiểu thương nước Tề\n" BLK "Tượng cung tên đá %d/30\n" BLK "Tượng thương %d/30\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tiểu thương nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Việc đầu tiên của tiểu thương nước Tề là đột nhiên nhớ lại chuyện kiếp trước. Ông ta đến nhà Hàn Tam bên cạnh tìm vợ mình, nhưng bị bọn cướp xông vào giết chết. Diêm Vương phán ông là quỷ phong lưu và bắt làm tiểu thương. Giờ người xưa đã đầu thai, nhưng bọn cướp vẫn còn. Chúng không làm cướp nữa mà chuyển sang làm tượng, chính là tượng cung tên đá và tượng thương trong lăng mộ tướng quân. Tiểu thương nước Tề yêu cầu bạn đến" HIR "lăng mộ tướng quân" BLK "tiêu diệt" HIR "30 tượng cung tên đá và 30 tượng thương" BLK "để ông không còn gặp ác mộng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 69000 điểm\n" 
 BLK "    Tiềm năng: 830 điểm\n" 
 BLK "    Ngân lượng: 55000", who->get_save("qxfgongjsy"), who->get_save("qxfqianyong"));
		else if (iKind == 50)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 18 con ác ma trong lọ, 6 con tiên trong lọ và báo cáo cho thương nhân nước Tề - Nghĩa Đốn\n" BLK "Ác ma trong lọ %d/18\n" BLK "Tiên trong lọ %d/6\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân nước Tề - Nghĩa Đốn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thương nhân nước Tề - Nghĩa Đốn nói rằng khi đi buôn, ông thường gặp nhiều quái vật, nên phải cân nhắc tiêu diệt hay đi đường vòng. Trước đây, ông nghe các thương nhân khác nói ác ma trong lọ rất hung dữ, gần đây lại có tin đồn tiên trong lọ cũng là kẻ đáng gờm. Nhưng ông vẫn chưa biết rõ chúng thế nào. Thấy bạn khỏe mạnh, mang bảo vật, chắc chắn là cao thủ hàng yêu, ông hy vọng bạn tiêu diệt 18 con ác ma trong lọ và 6 con tiên trong lọ để so sánh sức mạnh và đặc điểm của chúng. Nghe nói" HIR "ác ma trong lọ" BLK "tụ tập nhiều ở" HIR "Động Linh Cốc" BLK "làm điều ác, còn" HIR "tiên trong lọ" BLK "thường lang thang ở khu vực" HIR "Cầu Cửu Khúc" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 83000 điểm\n" 
 BLK "    Tiềm năng: 1040 điểm\n" 
 BLK "    Ngân lượng: 72000", who->get_save("qgsrguanzy"), who->get_save("qgsrguanzx"));
		else if (iKind == 51)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Cầu Cửu Khúc tìm viên ngọc chu đỏ hoàn mỹ, viên ngọc trắng hoàn mỹ, viên ngọc vàng hoàn mỹ\n" BLK "Viên ngọc chu đỏ hoàn mỹ %d/3\n" BLK "Viên ngọc trắng hoàn mỹ %d/4\n" BLK "Viên ngọc vàng hoàn mỹ %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Điền Kiến nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Triệu Vương đồng ý với điều kiện của Tề Vương, Tề Vương đồng ý giúp Triệu Vương luyện chế ngọc quý. Công thức viên ngọc cam hoàn mỹ rất phức tạp, nhưng nguyên liệu cơ bản phải có ba loại ngọc. Hãy đến Cầu Cửu Khúc tìm 3 viên ngọc chu đỏ hoàn mỹ, 4 viên ngọc trắng hoàn mỹ, 3 viên ngọc vàng hoàn mỹ và giao cho Triệu Vương.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 39000 điểm\n" 
 BLK "    Tiềm năng: 650 điểm\n" 
 BLK "    Ngân lượng: 37000", who->get_save("qwwmzhuhjs"), who->get_save("qwwmbaijs"), who->get_save("qwwmhuangjs"));
		else if (iKind == 52)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập đá vôi cổ, từ thạch, hùng hoàng và giao cho dược sư nước Tần\n" BLK "Đá vôi cổ %d/5\n" BLK "Từ thạch %d/7\n" BLK "Hùng hoàng %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dược sư nước Tần\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tề Vương nói rằng những viên ngọc bạn thu thập chỉ đại diện cho thủy, hỏa, kim, để luyện thành viên ngọc cam hoàn mỹ bổ huyết dưỡng sinh thuộc tính mộc, cần bổ sung thuộc tính thổ. Ông yêu cầu bạn đến Cầu Cửu Khúc tìm 5 phần đá vôi cổ, 7 viên từ thạch, 3 khối hùng hoàng, sau đó đến nước Tần tìm dược sư - sư đệ của tiên sư, ông ấy sẽ giúp bạn hoàn thành mong muốn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 39000 điểm\n" 
 BLK "    Tiềm năng: 650 điểm\n" 
 BLK "    Ngân lượng: 37000", who->get_save("qwgushihui"), who->get_save("qwcishi"), who->get_save("qwxionghuang"));
		else if (iKind == 53)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến" HIR "Cầu Cửu Khúc" BLK "tiêu diệt 8 con tiên trong lọ, 11 con rùa tiên nhân để chứng minh năng lực với đại tướng quân nước Tề - Điền Kỵ\n" BLK "Tiên trong lọ %d/8\n" BLK "Rùa tiên nhân %d/11\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Tề - Điền Kỵ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại tướng quân nước Tề - Điền Kỵ muốn xây dựng đội quân tinh nhuệ của Đại Vương, đang tuyển chọn nhân tài quy mô lớn theo tiêu chuẩn. Ông đưa ra bài kiểm tra, trong đó điều đầu tiên là phải không sợ hãi. Nếu bạn muốn接受 thử thách và trở thành thành viên đội quân tinh nhuệ của Đại Vương, hãy đến Cầu Cửu Khúc tiêu diệt 8 con tiên trong lọ và 11 con rùa tiên nhân!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 80000 điểm\n" 
 BLK "    Tiềm năng: 955 điểm\n" 
 BLK "    Ngân lượng: 68000", who->get_save("qgdjjguanzx"), who->get_save("qgdjjguixr"));
		else if (iKind == 54)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt thần dịch bệnh truyền bá ôn dịch, sau đó báo cáo cho nội chính quan nước Tề\n" BLK "Thần dịch bệnh %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Nội chính quan nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trời ơi, thần dịch bệnh cãi nhau với vợ, kết quả là trốn đến nước Tề gây sóng gió, truyền bá ôn dịch, thật đáng ghét! Nội chính quan Mạnh Thường Quân yêu cầu bạn đại diện cho nhân dân và quốc gia thực thi án tử hình với thần dịch bệnh! Loại bại hoại đặt thù hận cá nhân lên trên nỗi đau của dân chúng tuyệt đối không thể khoan nhượng! Theo báo cáo từ tai mắt chính nghĩa của nước Tề, thần dịch bệnh đang ẩn náu ở" HIR "Bạch Mã Trang" BLK "tùy ý làm bậy, hãy nhanh chóng đến tiêu diệt hắn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 84000 điểm\n" 
 BLK "    Tiềm năng: 1040 điểm\n" 
 BLK "    Ngân lượng: 73000", who->get_legend(TASK_36, 15) ? 1 : 0);
		else if (iKind == 55)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm ngọc bội phượng hoàng tái sinh từ lửa và giao cho tổng quản nước Tề\n" BLK "Ngọc bội phượng hoàng %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tổng quản nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Một tháng trước, thôn chài Đông Hải đột nhiên có hàng trăm chim tụ hội, hóa ra là điềm lành trời ban, phượng hoàng giáng thế. Không ngờ vài ngày trước, vài gã tự xưng là đại hiệp vì bảo vật đã bất ngờ tấn công khi phượng hoàng sinh sản. Thôn chài Đông Hải bỗng bốc cháy, phượng hoàng tái sinh từ lửa, đồng thời thiêu chết đám kẻ tham lam đó. Người di cư nước Tần là Mã Hiển báo cáo rằng qua bói toán, phượng hoàng sau khi niết bàn để lại một ngọc bội phượng hoàng, được cho là có công hiệu trường sinh bất lão. Tề Vương Hậu nghe nói rất quan tâm, ra lệnh cho tổng quản bí mật tìm người đi tìm. Tổng quản thấy bạn thông minh lanh lợi, nhiều lần hoàn thành xuất sắc nhiệm vụ, quyết định giao phó việc tốt này cho bạn. Bạn có đủ khả năng không?\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 80000 điểm\n" 
 BLK "    Tiềm năng: 958 điểm\n" 
 BLK "    Ngân lượng: 69000", who->get_legend(TASK_36, 18) ? 1 : 0);
		else if (iKind == 56)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Cầu Cửu Khúc thu thập 8 củ khoai lang, 5 củ sơn dược và giao cho dân chúng nước Tề\n" BLK "Khoai lang %d/8\n" BLK "Sơn dược %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đến Cầu Cửu Khúc thu thập 8 củ khoai lang và 5 củ sơn dược, ta phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 84000 điểm\n" 
 BLK "    Tiềm năng: 1040 điểm\n" 
 BLK "    Ngân lượng: 73000", who->get_save("qgbxfansu"), who->get_save("qgbxsanyao"));
		else if (iKind == 57)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 con tiên trong lọ và trở về báo cáo cho quản gia nước Tề\n" BLK "Tiên trong lọ %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản gia nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nước Tần đúng là quá đáng, dám biến người thành quái vật? Suỵt, đây là bí mật tối cao. Gần đây, quản gia nước Tề nghe nói dân chúng nước Tề đến nước Tần vì chiến tranh không biết bị mê hoặc thế nào, một số người接受 huấn luyện đặc biệt của nước Tần, có thể duy trì hình dạng quái vật trong thời gian ngắn, rồi lén trở về gần" HIR "Cầu Cửu Khúc" BLK "làm nội ứng cho nước Tần. Thật không thể chịu nổi! Phải cho chúng biết kết cục của kẻ phản bội, phải triệt để phá hủy âm mưu này của nước Tần! Quản gia nước Tề yêu cầu bạn tiêu diệt 10 con tiên trong lọ, ông muốn xem nước Tần còn chiêu trò gì nữa!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 80000 điểm\n" 
 BLK "    Tiềm năng: 955 điểm\n" 
 BLK "    Ngân lượng: 70000", who->get_save("qgjguanzx"));
		else if (iKind == 58)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm 10 thanh kiếm sắc, 10 thanh đao nhanh và giao cho đại tướng quân nước Tề - Điền Kỵ\n" BLK "Kiếm sắc %d/10\n" BLK "Đao nhanh %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Tề - Điền Kỵ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tề Vương yêu cầu bạn đến Cầu Cửu Khúc – nơi có yêu quái và cướp xuất hiện nhiều năm – thu thập 10 thanh kiếm và 10 thanh đao, mang giao cho Đại tướng quân Điền Kỵ để chuẩn bị chiến đấu chống Tần, góp phần khôi phục nghiệp bá cho nước Tề.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 84000 điểm\n" 
 BLK "    Tiềm năng: 1048 điểm\n" 
 BLK "    Ngân lượng: 73000", who->get_save("qwlijian"), who->get_save("qwkuaidao"));
		else if (iKind == 59)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 4 thủ môn Thiên Cương, 3 thiên binh thủ trận, 4 thần tướng, sau đó trở về báo cáo cho Thôi Ngọc\n" BLK "Thủ môn Thiên Cương %d/4\n" BLK "Thiên binh thủ trận %d/3\n" BLK "Thần tướng thủ trận %d/4\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thôi Ngọc\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thôi Ngọc nói rằng những người chạy tiêu sợ nhất là đi qua" HIR "Trận Thiên Môn" BLK ". Vệ binh ở đó rất lợi hại, gần như không ai vượt qua được nếu xông thẳng. Điều này khiến họ phải đi đường vòng, mất rất nhiều thời gian, khiến khách hàng phàn nàn. Nghe nói bạn là rồng phượng trong loài người, anh tài của đất nước, Thôi Ngọc nhờ bạn dọn sạch một con đường. Gần đây, chỉ cần tiêu diệt 4 thủ môn Thiên Cương, 3 thiên binh thủ trận, và 4 thần tướng là có thể miễn cưỡng vận chuyển tiêu được.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 80000 điểm\n" 
 BLK "    Tiềm năng: 960 điểm\n" 
 BLK "    Ngân lượng: 70000", who->get_save("cytiangmzs"), who->get_save("cysouztb"), who->get_save("cysouzsj"));
		else if (iKind == 60)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Trường Bạch Thiên Trì tiêu diệt tinh nhện, sau đó trở về báo cáo cho phu nhân Tiêu\n" BLK "Tinh nhện %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Phu nhân Tiêu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phu nhân Tiêu nghe các thợ săn khác nói rằng Hắc Phong Khẩu ở Trường Bạch Thiên Trì là nơi tụ tập của các dị thú, là con đường bắt buộc khi săn bắn. Các loại như tinh nhện, tinh cây, quái tuyết đều xuất hiện ở đây. Nghe nói tinh nhện trưởng thành giỏi biến hóa mê hoặc người, thường bắt đàn ông khỏe mạnh để bồi bổ. Phu nhân Tiêu yêu cầu bạn bằng mọi cách, dù phải trói cũng phải mang Tiểu Đồ về. Không săn được thần thú cũng không sao, những thiên vật này không phải gia đình bình thường như họ có thể tiêu thụ. Chỉ cần cả nhà bình an là đủ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 44500 điểm\n" 
 BLK "    Tiềm năng: 650 điểm\n" 
 BLK "    Ngân lượng: 43500", who->get_legend(TASK_37, 5) ? 1 : 0);
		else if (iKind == 62)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm cái cuốc và trả lại cho dân chúng nước Tề\n" BLK "Cái cuốc %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Băng đóng ba thước không phải lạnh trong một ngày. Hoàn cảnh hôm nay của dân chúng nước Triệu - Ngô Cơ cũng do nhiều việc nhỏ tích tụ mà thành. Không biết ông ta có còn nhớ đã mượn cái cuốc của dân chúng nước Tề và làm hỏng nó mà không trả hay không. Vì vậy, bạn hãy tìm một cái cuốc để trả lại cho dân chúng nước Tề. Lúc đó, ông ta ở tầng sâu nhất của" HIR "Trận Thiên Môn" BLK "đào kho báu, làm hỏng cuốc và tiện tay vứt ở đó. Gần cửa vào có vài cột đá, có lẽ cái cuốc nằm trong một cái rương nào đó.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 37000 điểm\n" 
 BLK "    Tiềm năng: 640 điểm\n" 
 BLK "    Ngân lượng: 38000", who->get_legend(TASK_39, 26) ? 1 : 0);
		else if (iKind == 64)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Trận Tru Tiên tiêu diệt 8 hồn đao, 8 hồn kiếm, sau đó trở về báo cáo cho quản gia nước Tề\n" BLK "Hồn đao %d/8\n" BLK "Hồn kiếm %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản gia nước Tề\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quản gia nước Tề thấy bạn đã khá tự tin, nhưng ông nói rằng trăm lần rèn mới thành thép, nhân lúc trẻ nên trải qua nhiều gió sương, rèn luyện nhiều luôn có lợi. Có vẻ như bạn đang gặp bình cảnh trong tu luyện. Ông nghe nói trong Trận Tru Tiên thời thượng cổ có nhiều hồn khí ngưng tụ từ tiên binh cổ, rất có ích cho sự trưởng thành của bạn, có thể còn có thu hoạch bất ngờ. Quản gia nước Tề yêu cầu bạn đến tiêu diệt 8 hồn đao và 8 hồn kiếm để chứng minh năng lực, sau đó báo cáo lại cho ông.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 51000 điểm\n" 
 BLK "    Tiềm năng: 778 điểm\n" 
 BLK "    Ngân lượng: 50300", who->get_save("qgjdaohun"), who->get_save("qgjjianhun"));
		else if (iKind == 66)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 hồn thương ở Trận Tru Tiên, sau đó báo cáo cho Lý Đồ\n" BLK "Hồn thương %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Đồ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lý Đồ nói rằng xưa kia ông cũng là một tướng quân uy phong, một tiếng gọi trăm người đáp, thật oai hùng. Không ngờ gần vua như gần hổ, đặc biệt khi gặp vị vua háo sắc thì càng bất lực. Đại Vương để ý tiểu thiếp Nhĩ Kiều của ông, bịa lý do tống ông vào ngục. Khi ra khỏi ngục, ông đã mất tất cả, gia đình tan nát, thậm chí những thuộc hạ cũ còn đánh đập sỉ nhục ông. Ông tuyệt vọng với lòng trung thành và tình người. Ông yêu cầu bạn tiêu diệt những hồn thương vong ân phụ nghĩa. Dù pháp lực đã bị phế, ông vẫn biết hồn thương ở đâu, chính là trong Trận Tru Tiên. Ông yêu cầu bạn tiêu diệt 10 hồn thương gây rối nhất, để chúng biết hậu quả của việc phản bội ông!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 51000 điểm\n" 
 BLK "    Tiềm năng: 778 điểm\n" 
 BLK "    Ngân lượng: 50300", who->get_save("lituqianhun"));
		else if (iKind == 67)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến Trận Tru Tiên thu thập hạt cải dầu cho Lý Lãng\n" BLK "Hạt cải dầu %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Lãng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lý Đồ luôn phân minh ân oán, không quên những tổn thương người khác gây ra, càng không quên ân huệ người khác ban cho. Gần đây, khi ông lang thang đầu đường, Lý Lãng đã cưu mang và cho ông chỗ nương tựa. Với Lý Đồ, người từng chịu bao lạnh lùng sau khi sa sút, điều này như tái sinh. Nhờ vậy, ông chưa hoàn toàn tuyệt vọng với tình người, trong lòng vẫn còn chút ấm áp. Ông không có gì quý giá để tặng, chỉ biết Lý Lãng đang cần mở rộng xưởng, cần rất nhiều hạt cải dầu. Hạt trên thị trường ông không mua nổi, nhưng ông biết hồn đao, hồn kiếm, hồn thương trong Trận Tru Tiên thích thu thập thứ này. Ông nhờ bạn giúp tìm một ít để ông bày tỏ lòng biết ơn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 51000 điểm\n" 
 BLK "    Tiềm năng: 778 điểm\n" 
 BLK "    Ngân lượng: 50300", who->get_save("lituyoucaizi"));
		else if (iKind == 68)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 18 thủ môn Thái Cực ở Trận Thiên Môn và báo cáo cho Lý Lãng\n" BLK "Thủ môn Thái Cực %d/18\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Lãng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lý Đồ và Lý Lãng đều là người yêu ghét rõ ràng, biết ơn đền đáp. Lý Lãng hiện đang bận mở rộng xưởng, không thể phân thân, nhờ bạn thay ông đi một chuyến. Ông nghe nói thủ môn Thái Cực ở Trận Thiên Môn từng cướp nhà Lý Đồ sau khi ông bị giam, khiến con cái ông mất tích, còn mẹ ông tự sát để bảo vệ thứ gì đó. Lý Lãng hận mình không có võ nghệ cao cường để tự tay báo thù cho Lý Đồ, chỉ có thể nhờ bạn tiêu diệt 18 thủ môn Thái Cực ở Trận Thiên Môn và báo cáo lại cho ông.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 190000 điểm\n" 
 BLK "    Tiềm năng: 1450 điểm\n" 
 BLK "    Ngân lượng: 193000", who->get_save("lilangtaijmzs"));
		else if (iKind == 69)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 hồn kiếm ở Trận Tru Tiên, sau đó trở về báo cáo cho Tề Vương\n" BLK "Hồn kiếm %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Bạn có biết vinh quang tối cao của nước Tề là gì không? Bạn có muốn đạt được vinh quang tối cao của nước Tề không? Tề Vương yêu cầu bạn trước tiên đến tiêu diệt 10 hồn kiếm ở Trận Tru Tiên, sau đó trở về, ông sẽ cho bạn câu trả lời.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 51000 điểm\n" 
 BLK "    Tiềm năng: 780 điểm\n" 
 BLK "    Ngân lượng: 51000", who->get_save("qwjianhun"));
		else if (iKind == 70)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 20 nhánh măng tây và giao cho Tề Vương\n" BLK "Măng tây %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Tề Vương\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây, ái phi của Tề Vương mắc một căn bệnh lạ, chỉ khi ngửi được mùi măng tây mới tỉnh lại, nếu không sẽ mãi mê ngủ. Để ái phi có thể đi lại trong cung đình cùng quả nhân, Tề Vương muốn trồng thật nhiều măng tây trong cung. Ông hy vọng bạn tìm được 20 nhánh măng tây. Nghe nói nhiều dân đen ở Trận Thiên Môn thích thu thập măng tây, chắc hẳn hỏi họ sẽ dễ dàng lấy được.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 55000 điểm\n" 
 BLK "    Tiềm năng: 830 điểm\n" 
 BLK "    Ngân lượng: 53000", who->get_save("qwwenzhu"));
		else if (iKind == 103)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đến doanh trại Thành Kiệu thu thập hồn ma\n" BLK "Hồn ma %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sử tiết nước Tề - Trâu Diễn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trâu Diễn nói với bạn rằng nước Tần có một doanh trại Thành Kiệu, do em trai Tần Đại Vương lập ra với ý đồ mưu phản, kỷ luật quân đội lỏng lẻo, thường bắt cóc dân chúng vào đó và không thấy trở ra. Ông lo lắng oán khí tích tụ, sau này sẽ gây hậu quả lớn, nên nhờ bạn thu thập hồn ma để ông làm phép siêu độ, tránh gây hại sau này. Ông giao cho bạn pháp khí tìm hồn, mang nó theo và tiêu diệt khô lâu đao oán linh hoặc quỷ hỏa oán linh để lấy được hồn ma.\n" 
 BLK "    Sau khi thu thập xong, mang pháp khí tìm hồn và hồn ma trở về tìm Trâu Diễn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 9800 điểm\n" 
 BLK "    Tiềm năng: 500 điểm\n" 
 BLK "    Ngân lượng: 11600", who->get_legend(50, 8) ? 1 : 0);
	}
	else if (iTask == TID_ZHOUGUO)
	{
		if (iKind == 4)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Ở núi Thủ Dương thu thập 20 khối gỗ giao cho Công Thâu Ban của nước Chu\n" BLK "Gỗ  %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban của nước Chu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Công Thâu Ban đồng ý làm hộp gỗ cho tôi, nhưng nguyên liệu không đủ, tôi phải đi thu thập 20 khối gỗ, nghe nói đám côn đồ ở núi Thủ Dương có.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 650 điểm\n" 
 BLK "    Tiềm năng: 50 điểm\n" 
 BLK "    Ngân lượng: 1000 lượng", who->get_save_2("gongsumutou"));
		else if (iKind == 5)
		{
			if (who->get_save_2("gongsupaozi"))
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm cái bào bị đánh cắp cho Công Thâu Ban\n" BLK "Cái bào 1/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban của nước Chu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nguyên liệu làm hộp gỗ đã tìm được, nhưng cái bào của Công Thâu Ban bị đánh cắp, phải tìm lại cái bào để ông ấy bắt đầu làm hộp gỗ. Nghe nói đám đao binh và kiếm binh ở thành Sở đã lấy trộm cái bào, có lẽ tôi phải đến thành Sở một chuyến.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 800 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 1500";
			else
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm cái bào bị đánh cắp cho Công Thâu Ban\n" BLK "Cái bào 0/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban của nước Chu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nguyên liệu làm hộp gỗ đã tìm được, nhưng cái bào của Công Thâu Ban bị đánh cắp, phải tìm lại cái bào để ông ấy bắt đầu làm hộp gỗ. Nghe nói đám đao binh và kiếm binh ở thành Sở đã lấy trộm cái bào, có lẽ tôi phải đến thành Sở một chuyến.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 800 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 1500";
		}
		else if (iKind == 6)
			result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giao hộp gỗ do Công Thâu Ban làm xong cho thương nhân nước Tề Di Đốn\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Thương nhân nước Tề Di Đốn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sau khi tìm được 20 khối gỗ và lấy lại cái bào bị đánh cắp cho Công Thâu Ban, cuối cùng ông ấy đã giao hộp gỗ cho tôi, tôi phải nhanh chóng mang đến cho thương nhân nước Tề Di Đốn, chắc hẳn ông ấy đã đợi lâu rồi!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 800 điểm\n" 
 BLK "    Tiềm năng: 50 điểm\n" 
 BLK "    Ngân lượng: 2000 lượng";
		else if (iKind == 7)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi Tấn Dương tiêu diệt Hùng Bình, lấy được Mộc Khối\n" BLK "Mộc Khối  %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Giúp Công Thâu Ban tìm lại Mộc Khối ở Tấn Dương, tôi phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 120000 điểm\n" 
 BLK "    Tiềm năng: 1500 điểm\n" 
 BLK "    Ngân lượng: 110000\n" 
 BLK "    Vật phẩm: Giày cấp 80", who->get_legend(28, 15) ? 1 : 0);
		else if (iKind == 8)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập 1 vòng sắt và 5 khối gỗ giao cho Công Thâu Ban\n" BLK "Vòng sắt  %d/1\n" BLK "Gỗ  %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ừm, muốn khôi phục chiếc thùng gỗ nhỏ này về nguyên trạng là điều không thể, giờ làm sao tìm được gỗ đỏ có chất lượng tương tự, dù có tìm được cũng quá đắt đỏ, có lẽ chỉ có thể dùng gỗ thường thay thế. Một tấm ván thùng bị gãy, khớp nối cũng lỏng lẻo, thế này đi, tôi cần 1 vòng sắt và 5 khối gỗ, bạn đi đến hang Hư Lăng tìm cho tôi nhé.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 37000 điểm\n" 
 BLK "    Tiềm năng: 640 điểm\n" 
 BLK "    Ngân lượng: 38000", who->get_save("gsbtieku"), who->get_save("gsbmutou"));
		else if (iKind == 11)
			result = sprintf(BLK "Mục tiêu nhiệm vụ:\n" 
 BLK "    Đoạt lấy Thẻ Tre trong tay Tiêu Trụ giao cho Lý Ẩn Sĩ\n" BLK "Thẻ Tre  %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Ẩn Sĩ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe nói Tiêu Trụ hiện đang ở tại đảo Đông Hải gần một đống rơm trong một thôn làng chài, hãy nhanh chóng tiêu diệt hắn lấy lại Thẻ Tre\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3500 điểm\n" 
 BLK "    Tiềm năng: 120 điểm\n" 
 BLK "    Ngân lượng: 3000", who->get_legend(40, 8) ? 1 : 0);
		else if (iKind == 12)
			result = sprintf(BLK "Mục tiêu nhiệm vụ:\n" 
 BLK "    Đi kênh Trịnh Quốc tìm Sừng Trâu Vàng giao cho Lý Ẩn Sĩ\n" BLK "Sừng Trâu Vàng  %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Ẩn Sĩ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lý Ẩn Sĩ nói muốn chế tạo pháp bảo cần nguyên liệu là Sừng Trâu Vàng\n" 
 BLK "    Nghe nói giết Khổ Dịch ở kênh Trịnh Quốc có thể lấy được Sừng Trâu Vàng, hãy nhanh chóng đi tiêu diệt để lấy Sừng Trâu Vàng\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 3500 điểm\n" 
 BLK "    Tiềm năng: 120 điểm\n" 
 BLK "    Ngân lượng: 3000", who->get_save("lysjinsnj"));
		else if (iKind == 20)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm sư phụ để tìm hiểu kỹ năng nghề nghiệp\n" 
 BLK "    Thăm hỏi Ngự Trù nước Chu %d/1\n" 
 BLK "    Thăm hỏi Cơ Quan Sư %d/1\n" 
 BLK "    Thăm hỏi May Mặc Sư %d/1\n" 
 BLK "    Thăm hỏi Dược Sư %d/1\n" 
 BLK "    Thăm hỏi Luyện Đơn Sư %d/1\n" 
 BLK "    Thăm hỏi Rèn Đúc Sư %d/1\n" 
 BLK "    Thăm hỏi Điêu Khắc Sư %d/1\n" 
 BLK "    Thăm hỏi Thái Dã Sư %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Vương Cơ Duyên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thăm hỏi các sư phụ kỹ năng nghề nghiệp.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 800\n" 
 BLK "    Tiềm năng: 50\n" 
 BLK "    Ngân lượng: 1500", who->get_save("baifang_js_0"), who->get_save("baifang_js_1"), who->get_save("baifang_js_2"), who->get_save("baifang_js_3"), who->get_save("baifang_js_4"), who->get_save("baifang_js_5"), who->get_save("baifang_js_6"), who->get_save("baifang_js_7"));
		else if (iKind == 21)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thăm hỏi Khổng Phu Tử, Công Thâu Ban, Thân Công Báo, Nguyệt Lão và Hồng Nương\n" 
 BLK "    Thăm hỏi Khổng Phu Tử %d/1\n" 
 BLK "    Thăm hỏi Công Thâu Ban %d/1\n" 
 BLK "    Thăm hỏi Thân Công Báo %d/1\n" 
 BLK "    Thăm hỏi Nguyệt Lão %d/1\n" 
 BLK "    Thăm hỏi Hồng Nương %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chu Vương Cơ Duyên\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ở nước Chu còn ẩn cư rất nhiều kỳ nhân dị sĩ, Khổng Phu Tử có thể giúp bái sư thu đồ, Công Thâu Ban có thể dùng tinh thạch cường hóa trang bị, Thân Công Báo có thể giúp tôi từ bỏ những kỹ năng sống không cần thiết, còn Nguyệt Lão và Hồng Nương có thể giúp tôi kết duyên với người thương, tôi nên đi thăm hỏi họ để hiểu rõ hơn.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 800\n" 
 BLK "    Tiềm năng: 50\n" 
 BLK "    Ngân lượng: 1500", who->get_save("baifang_ms_1"), who->get_save("baifang_ms_2"), who->get_save("baifang_ms_3"), who->get_save("baifang_ms_4"), who->get_save("baifang_ms_5"));
		else if (iKind == 102)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi doanh trại Thành Kiệu đánh bại tên đầu bếp xấu xa Lương Hưng\n" 
 BLK "    Tiêu diệt Lương Hưng %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đầu bếp nước Chu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đầu bếp nước Chu có một sư đệ tên Lương Hưng, thiên bẩm thông minh, được truyền thụ hầu hết chân truyền của sư phụ, nhưng tính cách xấu xa, cuối cùng đã đánh cắp bí kíp tổ truyền của sư môn mà sư phụ đã mất nhiều năm tâm huyết整理, đánh thương sư phụ và phản bội sư môn. Sư phụ vì tức giận và bị thương mà lâm bệnh nặng, nay sư phụ bệnh tật quấn thân sắp qua đời, nhưng đầu bếp nước Chu vì không phù hợp học võ nên không thể thay sư phụ báo thù.\n" 
 BLK "    Đầu bếp nước Chu thấy bạn có vẻ võ nghệ cao cường, nên nhờ bạn đến doanh trại Thành Kiệu nước Tần tiêu diệt Lương Hưng, báo thù cho sư phụ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 6800 điểm\n" 
 BLK "    Tiềm năng: 400 điểm\n" 
 BLK "    Ngân lượng: 9600", who->get_save("fb_002_001"));
		else if (iKind == 103)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp Công Thâu Ban tìm Bản đồ bí mật\n" 
 BLK "    Bản đồ bí mật phần trên %d/1\n" 
 BLK "    Bản đồ bí mật phần giữa %d/1\n" 
 BLK "    Bản đồ bí mật phần dưới %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Công Thâu Ban\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Kỹ nghệ thợ mộc gia truyền của Công Thâu Ban được tôn là đệ nhất đương thời, nhưng ông nghe nói trong lăng mộ Ly Sơn có con ngỗng gỗ được chế tạo bằng cơ quan có thể tự do bay lượn, không biết do ai chế tạo, ông rất muốn xem nhưng lại bận không thể đi, đồng thời lo lắng nơi đó quá nguy hiểm. Vì vậy, ông nhờ bạn giúp tìm Bản đồ bí mật.\n" 
 BLK "    Bản đồ bí mật được chia thành ba phần, phân bố trong lăng mộ, có thể ở trên người Tướng quân tượng hoặc thợ xây Minh, hoặc được đặt trong thư phòng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 16800 điểm\n" 
 BLK "    Tiềm năng: 650 điểm\n" 
 BLK "    Ngân lượng: 16800", who->get_save("fb_gsb_jgtsb"), who->get_save("fb_gsb_jgtzb"), who->get_save("fb_gsb_jgtxb"));
	}
	else if (iTask == TID_HANGUO)
	{
		if (iKind == 5)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20 con Thú Một Mắt\n" BLK "Thú Một Mắt %d/20\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính nước Hàn Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Gần đây có một đám Thú Một Mắt quấy rối gần cung đình, khiến gà chó không yên. Đi đến núi Thúy Hoa tiêu diệt 20 con Thú Một Mắt, sau khi hoàn thành báo cáo cho quan nội chính.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 1300 điểm\n" 
 BLK "    Tiềm năng: 70 điểm\n" 
 BLK "    Ngân lượng: 1200", who->get_save_2("nzdujiaosou"));
		else if (iKind == 19)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20 Đậu Binh (%d/20)\n" 
 BLK "    Tiêu diệt 20 Ác Ma Trong Lọ (%d/20) và báo cáo cho Hàn Tổng Quản\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Hàn Tổng Quản\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Theo tin tức từ quan tài chính nước Hàn Hàn Phi, tôi đã tìm được chủ sở hữu của Tàng Bảo Đồ là Hàn Tổng Quản. Nhưng Hàn Tổng Quản vẫn chưa tin tưởng vào thực lực của tôi, cách chứng minh sức mạnh là đến hang Linh Cốc tiêu diệt 20 Đậu Binh và 20 Ác Ma Trong Lọ. Nếu tôi có thể tiêu diệt những yêu quái này và trở về an toàn, Hàn Tổng Quản sẽ nói cho tôi biết việc ông ấy muốn giao phó. Tất nhiên, nếu tôi hoàn thành suôn sẻ, cuối cùng tôi sẽ nhận được Tàng Bảo Đồ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 34000 điểm\n" 
 BLK "    Tiềm năng: 510 điểm\n" 
 BLK "    Ngân lượng: 32000\n", who->get_save_2("hzgdoubing"), who->get_save_2("hzgguanzy"));
		else if (iKind == 22)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 20 Thi Đồng Giáp (%d/20)\n" 
 BLK "    Tiêu diệt 20 Bảo Vệ Người Chết (%d/20) rồi báo cáo cho quan nội chính nước Hàn Thân Bất Hại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính nước Hàn Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại Vương Hàn An sau khi đọc thư thỉnh mệnh của Lưu Phương Sĩ, nhận thấy tình hình nghiêm trọng. Ông đã phái quan nội chính Thân Bất Hại chiêu mộ nhân tài để bắt đầu tiêu diệt yêu quái ở hang Linh Cốc, giờ tôi cũng tham gia vào hàng ngũ tiêu diệt yêu quái ở hang Linh Cốc: đến tầng một hang Linh Cốc tiêu diệt 20 Thi Đồng Giáp và 20 Bảo Vệ Người Chết. Sau đó quay về báo cáo cho quan nội chính Thân Bất Hại, ông ấy sẽ cho tôi phần thưởng hậu hĩnh.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 34000 điểm\n" 
 BLK "    Tiềm năng: 510 điểm\n" 
 BLK "    Ngân lượng: 34000", who->get_save_2("hgnzgtongjs"), who->get_save_2("hgnzgswwl1"));
		else if (iKind == 30)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Cương Thi (%d/30)\n" 
 BLK "    Tiêu diệt 30 Dịch Quỷ (%d/30) rồi báo cáo cho Lý Phương Sĩ\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Lý Phương Sĩ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Hóa ra Đại Vương Chân Nhân đã sớm tiên đoán nước Hàn sẽ gặp kiếp nạn này, nên đã dạy Lý Phương Sĩ cách phá giải lời nguyền. Trong khi Lý Phương Sĩ thi pháp phá giải, tôi phải đến tầng ba hang Linh Cốc tiêu diệt 30 Cương Thi và 30 Dịch Quỷ, vốn là nguồn gốc của lời nguyền, để giải lời nguyền cho dòng sông, tôi phải lập tức lên đường đến tầng ba hang Linh Cốc tiêu diệt 30 Cương Thi và 30 Dịch Quỷ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 38000 điểm\n" 
 BLK "    Tiềm năng: 550 điểm\n" 
 BLK "    Ngân lượng: 37000\n", who->get_save_2("lfsjiangsi"), who->get_save_2("lfsyigui"));
		else if (iKind == 33)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 30 Ác Linh (%d/30)\n" 
 BLK "    Tiêu diệt 30 Bảo Vệ Người Chết (%d/30) rồi báo cáo cho quan nội chính nước Hàn Thân Bất Hại\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính nước Hàn Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quan nội chính Thân Bất Hại nói võ công của tôi cao cường, nếu tôi chịu giúp, mọi chuyện sẽ đơn giản hơn nhiều, ông ấy nói vậy, tôi chắc chắn sẽ giúp. Nhưng để tiêu diệt tên thổ phỉ đó, trước tiên phải loại bỏ tay sai của hắn. Vì vậy, tôi phải đến hang Linh Cốc tiêu diệt 30 Ác Linh và 30 Bảo Vệ Người Chết do tên thổ phỉ điều khiển. Sau đó quay về báo cáo cho ông ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 39000 điểm\n" 
 BLK "    Tiềm năng: 580 điểm\n" 
 BLK "    Ngân lượng: 39000\n", who->get_save_2("hgnzgeling"), who->get_save_2("hgnzgswwl"));
		else if (iKind == 41)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập hành, tỏi, gừng cần cho món cá nướng giao cho quan nội chính nước Hàn Thân Bất Hại\n" BLK "Hành %d/3\n" BLK "Gừng %d/1\n" BLK "Tỏi %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quan nội chính nước Hàn Thân Bất Hại\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đại Vương nước Hàn muốn ăn cá nướng, điều này làm quan nội chính nước Hàn bận rộn, khó khăn lắm mới tìm được một con cá thượng hạng ở Đông Hải, nhưng phát hiện còn cần ở Vạn Đạo tìm hành, tỏi, gừng thượng hạng làm gia vị mới có thể làm ra món cá nướng thượng hạng, giờ Vạn Đạo đầy rẫy thổ phỉ, tôi vẫn nên giúp ông ấy thu thập những nguyên liệu này về.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 26000 điểm\n" 
 BLK "    Tiềm năng: 440 điểm\n" 
 BLK "    Ngân lượng: 25000", who->get_save_2("hgnzgcong"), who->get_save_2("hgnzgjiang"), who->get_save_2("hgnzgdasuan"));
		else if (iKind == 42)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm gỗ hoàng lượng có thể rèn lưỡi câu giao cho sứ giả nước Hàn Nhiếp Chính\n" BLK "Hoàng lượng %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sứ giả nước Hàn Nhiếp Chính\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sứ giả nước Hàn Nhiếp Chính rất thích câu cá, nguyện vọng của ông là câu được một con cá chép hoàng lượng hiếm có, để câu được cá chép hoàng lượng cần dùng cần câu làm từ gỗ quế, mồi câu làm từ hương liệu gỗ quế, dây câu làm từ tơ bạc và lưỡi câu làm từ hoàng lượng, giờ ông chỉ thiếu hoàng lượng để làm lưỡi câu, tôi phải đến Vạn Đạo giúp ông tìm hoàng lượng.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 27000 điểm\n" 
 BLK "    Tiềm năng: 448 điểm\n" 
 BLK "    Ngân lượng: 25600", who->get_legend(TASK_22, 25) ? 1 : 0);
		else if (iKind == 43)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 Thủy Quỷ rồi báo cáo cho dân chúng nước Hàn Tử Doanh\n" BLK "Thủy Quỷ %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng nước Hàn Tử Doanh\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ở khu vực Vạn Đạo xuất hiện một đám thủy quỷ giả, chuyên kéo người xuống nước dìm chết rồi cướp tài sản, giờ đã có không ít người qua đường bị giết hại như vậy, để hành hiệp trượng nghĩa, tôi đến Vạn Đạo tiêu diệt 10 Thủy Quỷ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 25000 điểm\n" 
 BLK "    Tiềm năng: 430 điểm\n" 
 BLK "    Ngân lượng: 23000", who->get_save_2("hgbxsuigui"));
		else if (iKind == 44)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi Vạn Đạo tiêu diệt 10 Mật Thám, quay về báo cáo cho đại tướng quân nước Hàn Hàn Cử\n" BLK "Mật Thám %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Đại tướng quân nước Hàn Hàn Cử\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nghe đồn nước Tần muốn thống nhất lục quốc, mục tiêu đầu tiên chính là nước Hàn, gần đây ở khu vực Vạn Đạo xuất hiện một đám Mật Thám, nghe nói họ là do nước Tần phái đến để điều tra tình hình quân sự của nước Hàn. Tôi nhận ủy thác từ đại tướng quân Hàn Cử đến Vạn Đạo tiêu diệt 10 Mật Thám, sau khi hoàn thành nước Hàn sẽ thưởng hậu hĩnh cho tôi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 25000 điểm\n" 
 BLK "    Tiềm năng: 430 điểm\n" 
 BLK "    Ngân lượng: 23000", who->get_save_2("hgdjjmitan"));
		else if (iKind == 46)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 10 Tráng Đinh, quay về báo cáo cho võ sĩ nước Hàn\n" BLK "Tráng Đinh %d/10\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Võ sĩ nước Hàn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Cũng như mọi người ở đây, sự nghiệp quân đội của võ sĩ nước Hàn ở làng Hoa Lê bắt đầu từ việc bị bắt làm tráng đinh. Từ ngày anh ta rời khỏi làng, người vợ của anh ta đã trở thành góa phụ sống. Gần đây, có một đám tráng đinh ở kênh Trịnh Quốc nổi dậy, đại tướng quân ra lệnh cho anh ta tiêu diệt đám tráng đinh này. Nhưng anh ta thực sự không muốn tự tay giết họ, khiến những tráng đinh này phải xa cách vợ con mãi mãi, nhưng lệnh của đại tướng quân không thể trái, vì vậy võ sĩ nước Hàn này đã ủy thác cho tôi thay anh ta tiêu diệt 10 Tráng Đinh.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 20000 điểm\n" 
 BLK "    Tiềm năng: 290 điểm\n" 
 BLK "    Ngân lượng: 20000", who->get_save_2("hgwszuangding"));
		else if (iKind == 101)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Giúp dân chúng nước Hàn tìm anh trai\n" BLK "Ngọc bội %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Dân chúng nước Hàn Tử Doanh\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Anh trai của dân chúng nước Hàn nhờ người nhắn rằng anh ta bị nước Tần bắt làm khổ sai, đang xây lăng cho Đại Vương Tần, hy vọng có thể chuộc anh ta về, nhưng nơi đó nhiều nguy hiểm... Hãy giúp tìm tung tích hiện tại của anh trai anh ta. Anh ta có mang theo một ngọc bội làm tín vật, nếu anh ta đã chết, xin hãy mang tín vật về. Ngọc bội có thể ở trên người khổ sai hoặc giám công.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 16800 điểm\n" 
 BLK "    Tiềm năng: 500 điểm\n" 
 BLK "    Ngân lượng: 9600", who->get_legend(51, 8) ? 1 : 0);
	}
	else if (iTask == TID_DONGHAIDAO)
	{
		if (iKind == 1)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi tới Cô Trúc Tiểu Trúc tiêu diệt Cương Thi Vương, lấy được Cương Thi Phấn giao cho Mã Đồng\n" BLK "Cương Thi Phấn %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mã Đồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Đi tới Cô Trúc Tiểu Trúc (có thể đi qua từ Cầu Cửu Khúc) tìm Cương Thi Phấn, tôi phải đi ngay.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 45000 điểm\n" 
 BLK "    Tiềm năng: 655 điểm\n" 
 BLK "    Ngân lượng: 44000", who->get_legend(TASK_37, 8) ? 1 : 0);
		else if (iKind == 2)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Thu thập Bột Hành Hình, Gạo Nếp, Bảo Hòa Đan giao cho Mã Đồng\n" BLK "Bột Hành Hình %d/1\n" BLK "Gạo Nếp %d/8\n" BLK "Bảo Hòa Đan %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Mã Đồng\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Mã Đồng nói bệnh tình của Tiểu Đồ vẫn cần một vài vật phẩm phụ trợ để giải độc, phải đến Cầu Cửu Khúc tìm Bột Hành Hình, Gạo Nếp, Bảo Hòa Đan cho ông ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 210000 điểm\n" 
 BLK "    Tiềm năng: 2300 điểm\n" 
 BLK "    Ngân lượng: 210000\n" 
 BLK "    Vật phẩm: Giày cấp 100", who->get_save("mtxianxf"), who->get_save("mtnuomi"), who->get_save("mtbaohd"));
	}
	else if (iTask == TID_YUNMENZE)
	{
		if (iKind == 1)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm da hổ làm thuốc dẫn giao cho Quỷ Cốc Tử\n" BLK "Da hổ %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quỷ Cốc Tử\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quỷ Cốc Tử cuối cùng đã tìm được một đơn thuốc tiên cổ ghi lại căn bệnh tương tự, nên nói rằng thế tử trúng phải lời nguyền chứ không phải bệnh, những việc tương tự như thế này xảy ra quá thường xuyên trong gia đình Đại Vương, nhưng đó không phải điều ông muốn đánh giá, ông chỉ làm tròn bổn phận của một thầy thuốc. Phá giải lời nguyền cần nhiều dược liệu hiếm có, trong đó dược dẫn quan trọng nhất là da hổ chứa nhiều hồn khí trong trận Tru Tiên, loại da hổ này kết hợp khí cực âm của hồn khí và khí cực dương của hổ, là dược dẫn tốt nhất để phá giải lời nguyền này, ông bảo bạn đến trận Tru Tiên để lấy da hổ, cái này...\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 52000 điểm\n" 
 BLK "    Tiềm năng: 790 điểm\n" 
 BLK "    Ngân lượng: 52000", who->get_legend(TASK_45, 24) ? 1 : 0);
		else if (iKind == 2)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến hang Tử Vân tìm Bảo Đỉnh giao cho Quỷ Cốc Tử\n" BLK "Bảo Đỉnh %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quỷ Cốc Tử\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Quỷ Cốc Tử có nhiều loại bảo đỉnh để luyện thuốc, nhưng bảo đỉnh Thanh Vân dùng để luyện thuốc phá giải lời nguyền lại bị yêu tinh ở hang Tử Vân đánh cắp, gần đây ông có quá nhiều bệnh nhân và đệ tử nên không có thời gian để ý đến chúng, vì bạn hiện cần luyện loại thuốc này, hãy đến hang Tử Vân lấy lại bảo đỉnh Thanh Vân, ông không biết yêu tinh nào đang giữ, nhưng cứ hỏi chúng là đúng, những yêu tinh đó rất ích kỷ, sẽ không chia sẻ bảo đỉnh, nên chắc chắn chúng sẽ mang theo bên mình.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 52000 điểm\n" 
 BLK "    Tiềm năng: 790 điểm\n" 
 BLK "    Ngân lượng: 52000", who->get_legend(TASK_45, 27) ? 1 : 0);
	}
	else if (iTask == TID_NEWBIE_01)
	{
		if (iKind == 25)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 5 con Thỏ Hoang rồi báo cáo cho chủ tiệm thuốc Tân Thủ Thôn\n" BLK "Thỏ Hoang %d/5\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ tiệm thuốc nói rằng mấy hôm trước có một đám Thỏ Hoang đến phá phách, không chỉ làm đổ hết thuốc của ông mà còn ăn trộm một số dược liệu quý giá. Lúc đó, ông đang bận chữa trị cho một bệnh nhân nên không kịp dạy dỗ chúng. Sau đó, nhìn thấy cảnh tượng hỗn loạn, ông tức đến phát điên! Ông nói cần phải dạy cho lũ Thỏ Hoang một bài học để chúng biết kiềm chế, nên nhờ tôi xử lý việc này. Nếu tôi làm được, ông chắc chắn sẽ cho tôi Cỏ Linh Chi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 1800", who->get_save("ydlbxiaoyt"));
		else if (iKind == 28)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Hoàng Thạch Tán giao cho Trí Tuệ Lão Nhân\n" BLK "Hoàng Thạch Tán %d/1\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trí Tuệ Lão Nhân nói rằng theo suy đoán của ông, dân làng có lẽ đã trúng một loại độc gọi là Nhuyễn Cốt Tán, và nguồn độc đến từ giếng nước phía sau làng. Những người trúng độc đều uống nước từ giếng đó rồi mới xuất hiện triệu chứng. Để giải độc này cần phải có Hoàng Thạch Tán, và phải kết hợp với các dược liệu khác mới có hiệu quả. Thuốc sau khi điều chế không chỉ cho dân làng uống mà còn phải rắc vào giếng để giải độc. Trí Tuệ Lão Nhân bảo tôi đi tìm Hoàng Thạch Tán giao cho ông trước, rồi sẽ tính tiếp. Ông nói lũ Gà Núi ở khu vực này thường mang theo Hoàng Thạch Tán.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 1800", who->get_legend(41, 7) ? 1 : 0);
		else if (iKind == 30)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Ở ngoài Tân Thủ Thôn tiêu diệt Gà Núi để lấy Hoa Huệ giao cho Vệ Đội Trưởng\n" BLK "Hoa Huệ %d/3\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ Đội Trưởng nói rằng tuy ông là người thô kệch, nhưng rất chú trọng đến sự tinh tế trong cuộc sống. Ông thích trồng một ít hoa cỏ trong nhà để không gian trông sinh động hơn. Dù trong nhà đã có nhiều Lan, Măng Tây, Cúc, nhưng thứ ông yêu thích nhất vẫn là Hoa Huệ, mọc từ thung lũng, tượng trưng cho sự thuần khiết. Ông nói Gà Núi ngoài làng thường mang theo Hoa Huệ, nên nhờ tôi tìm vài bông cho ông.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 250 điểm\n" 
 BLK "    Tiềm năng: 10 điểm", who->get_save("wdzbaihh"));
		else if (iKind == 31)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 5 con Gà Núi, sau đó báo cáo cho Vệ Đội Trưởng\n" BLK "Gà Núi %d/5\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lũ Gà Núi ngoài làng vốn là những con vật đáng yêu, chúng tìm thức ăn ngoài hoang dã, khi gặp thợ săn lên núi, chúng thường vây quanh vì tin rằng con người sẽ không làm hại chúng. Nhưng giờ đây, mọi thứ đã thay đổi… Lũ Gà Núi này không còn đáng yêu, không còn hiền lành, chúng tấn công con người. Vệ Đội Trưởng nghi ngờ lũ Gà Núi bị yêu quái mê hoặc, bị điều khiển nên mới trở nên như vậy. Ông nhờ tôi đi tiêu diệt lũ Gà Núi này, sau đó báo cáo lại để ông cân nhắc bước tiếp theo.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 250 điểm\n" 
 BLK "    Tiềm năng: 15 điểm", who->get_save("wdzxiaosj"));
		else if (iKind == 32)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Ở ngoài làng tiêu diệt 3 con Tiểu Quái Vật rồi báo cáo cho Quản Khố (" HIR "Gà Núi, Thỏ Hoang, Bù Nhìn" BLK " đều được)\n" BLK "Tiểu Quái Vật %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản Khố\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Nhìn ngươi có vẻ ít tham gia chiến đấu, %s, ta đoán ngươi chắc chưa từng ra ngoài làng, cũng chưa thấy lũ " HIR "Gà Núi, Thỏ Hoang, Bù Nhìn" BLK " phiền phức kia. Ta nghĩ ngươi nên ra ngoài làng rèn luyện một chút, không chỉ giúp nâng cao năng lực bản thân mà còn mở rộng tầm mắt với những thứ chưa từng thấy. Thế này đi, ngươi ra " HIR "ngoài làng" BLK " tiêu diệt 3 con " HIR "Tiểu Quái Vật" BLK ", rồi quay lại báo cáo cho ta, ta sẽ thưởng cho ngươi! Quản Khố vừa nói với ta như vậy. Việc vừa rèn luyện bản thân vừa có thưởng, ai mà không muốn làm chứ!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 280 điểm\n" 
 BLK "    Tiềm năng: 15 điểm\n" 
 BLK "    Ngân lượng: 500", who->get_save("dplbxiaogw"), who->get_name());
		else if (iKind == 44)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến " HIR "U Cốc hoặc Thanh Khê" BLK " giúp chủ tiệm rượu tìm 3 cây Lúa Mạch\n" BLK "Lúa Mạch %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ tiệm rượu Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ tiệm rượu từng nghe nói ở khu vực " HIR "U Cốc hoặc Thanh Khê" BLK " có một loại " HIR "Ếch Vàng Đốm" BLK ", chúng mang theo thứ gọi là Lúa Mạch, là nguyên liệu tuyệt hảo để ủ rượu. Bà ấy rất muốn dùng Lúa Mạch này để ủ ra loại rượu thượng hạng, giúp việc buôn bán của tiệm rượu tốt hơn. Nếu ngươi mang về được 3 cây Lúa Mạch, bà ấy chắc chắn sẽ không bạc đãi ngươi.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 220 điểm\n" 
 BLK "    Tiềm năng: 10 điểm", who->get_save_2("baqiu_xiaomai"));
		else if (iKind == 45)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến " HIR "U Cốc" BLK " tiêu diệt 3 con " HIR "Kiến Nhỏ" BLK "\n" BLK "Kiến Nhỏ %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Tạp Hóa\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ Tiệm Tạp Hóa từ nhỏ đã thích ăn mật ong, ăn bao nhiêu cũng không đủ. Giờ tuy đã lớn tuổi, sở thích vẫn không thay đổi. Mấy hôm trước, một người bạn cũ từ Ba Khâu mang đến cho ông mười hũ mật ong, được ông cất giữ trong một ngôi nhà gỗ ở U Cốc. Nhưng ở U Cốc có rất nhiều Kiến Nhỏ hoạt động, ông luôn lo chúng sẽ ăn trộm mật ong. Ông nhờ tôi khi rảnh thì giúp ông tiêu diệt vài con " HIR "Kiến Nhỏ" BLK ", để ông yên tâm.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 150 điểm\n" 
 BLK "    Tiềm năng: 25 điểm\n" 
 BLK "    Ngân lượng: 800", who->get_save("xsc_mayi"));
		else if (iKind == 46)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 3 con " HIR "Thỏ Hoang" BLK "\n" BLK "Thỏ Hoang %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ tiệm rượu Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tuy tiệm rượu ở Tân Thủ Thôn không lớn, nhưng rượu ở đây nổi tiếng khắp nơi, nhiều khách từ xa đến thưởng thức, việc buôn bán rất phát đạt. Chủ tiệm rượu có một xưởng nhỏ ở Thanh Khê, rượu trong tiệm đều được ủ ở đó. Không ngờ mấy hôm trước, một đám Thỏ Hoang xông vào xưởng ăn trộm, làm xưởng tan hoang. Chủ tiệm rượu nhờ tôi dạy cho lũ " HIR "Thỏ Hoang" BLK " này một bài học, chúng thường xuất hiện ở " HIR "ngoài Tân Thủ Thôn và Thanh Khê" BLK ".\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 150 điểm\n" 
 BLK "    Tiềm năng: 20 điểm\n" 
 BLK "    Ngân lượng: 500\n" 
 BLK "    Vật phẩm: Rượu Gạo x5", who->get_save("jiudian_yetu"));
		else if (iKind == 47)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 3 con " HIR "Bù Nhìn" BLK "\n" BLK "Bù Nhìn %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ tiệm thuốc Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chuyện lạ có hàng năm, nhưng năm nay đặc biệt nhiều. Lũ Bù Nhìn ngoài Tân Thủ Thôn vốn chỉ là đồ trang trí do nông dân dựng lên để dọa chim sẻ, bảo vệ ruộng đồng, không ngờ giờ chúng lại sống dậy. Hôm qua, chú Lý ngoài làng đi làm ruộng còn bị một Bù Nhìn tấn công, làm trẹo lưng. Chủ tiệm thuốc thấy tôi có võ công, nhờ tôi tiêu diệt 3 con " HIR "Bù Nhìn" BLK " để trả thù cho chú Lý.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 150 điểm\n" 
 BLK "    Tiềm năng: 20 điểm\n" 
 BLK "    Ngân lượng: 500\n" 
 BLK "    Vật phẩm: Hành Quân Tán x5", who->get_save("yaodian_daocaoren"));
		else if (iKind == 48)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 1 con " HIR "Ếch Mẹ Con" BLK ", 1 con " HIR "Kiến Nâu Đỏ" BLK ", 1 con " HIR "Bù Nhìn Cầm Quạt" BLK "\n" BLK "Ếch Mẹ Con %d/1\n" BLK "Kiến Nâu Đỏ %d/1\n" BLK "Bù Nhìn Cầm Quạt %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ tiệm sửa chữa Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Phía bắc Tân Thủ Thôn, " HIR "Ba Khâu" BLK " là con đường bắt buộc để đến hồ Động Đình, thương nhân và khách qua lại tấp nập. Gần đây không biết vì sao, lũ " HIR "Ếch Mẹ Con và Kiến Nâu Đỏ" BLK " ở đó bắt đầu tấn công người đi đường. Một người bạn của chủ tiệm sửa chữa muốn đến thăm nhưng bị chặn ở hồ Động Đình, không qua được. Ông nhờ bạn đến Ba Khâu tiêu diệt vài con Ếch Mẹ Con, Kiến Nâu Đỏ và Bù Nhìn Cầm Quạt để giải quyết vấn đề cho thương nhân qua lại.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 250 điểm\n" 
 BLK "    Tiềm năng: 40 điểm\n" 
 BLK "    Ngân lượng: 600", who->get_save("xiuli_zimuwa"), who->get_save("xiuli_chy"), who->get_save("xiuli_cscr"));
		else if (iKind == 101)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Ra ngoài Tân Thủ Thôn tiêu diệt 5 Tiểu Quái Vật, sau đó đến gặp " HIR "Chủ Tiệm Vũ Khí" BLK " (" HIR "Gà Núi, Thỏ Hoang, Bù Nhìn" BLK " đều được)\n" BLK "Tiểu Quái Vật %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Vũ Khí Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Ngoài Tân Thủ Thôn có một số loài động vật rất kỳ lạ, chúng không thân thiện như gà, thỏ hay bù nhìn thông thường, chúng có thể tấn công con người. Tiêu diệt chúng là nhiệm vụ của chúng ta từ trước đến nay. Nếu ngươi tiêu diệt được lũ Tiểu Quái Vật này, chắc chắn sẽ nhận được nhiều phần thưởng! Chủ Tiệm Vũ Khí chắc chắn sẽ vui lòng cho ngươi một ít thứ, bảo ta sau khi tiêu diệt chúng thì đến gặp ông ấy.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 100 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 800\n" 
 BLK "    Vật phẩm: Trái Quýt x5", who->get_save("new_sj"));
		else if (iKind == 103)
		{
			if (objectp(item = present("Tàng Bảo Đồ", who, 1, MAX_CARRY)) && item->is_xunbao() == 1)
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến phía đông nhất ngoài Tân Thủ Thôn, tìm Tàng Bảo Đồ, giao cho chủ tiệm giáp trụ\n" BLK "Tàng Bảo Đồ 1/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Giáp Trụ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trước tiên, tôi phải tìm một tấm Tàng Bảo Đồ, nó có lẽ ở gần thác nước phía đông nhất của Tân Thủ Thôn. Ở đó còn có một lão Trần, tôi nghi lão Trần được cố ý bố trí để giám sát tôi, lòng có chút lo lắng, tôi phải đề phòng lão. Nghĩ lại, thật có chút kích thích! Sau khi tìm được Tàng Bảo Đồ, quay lại gặp chủ tiệm giáp trụ, ông ấy sẽ cho tôi manh mối tiếp theo!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 180 điểm\n" 
 BLK "    Tiềm năng: 40 điểm\n" 
 BLK "    Ngân lượng: 1000\n";
			else
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến phía đông nhất ngoài Tân Thủ Thôn, tìm Tàng Bảo Đồ, giao cho chủ tiệm giáp trụ\n" BLK "Tàng Bảo Đồ 0/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Giáp Trụ\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Trước tiên, tôi phải tìm một tấm Tàng Bảo Đồ, nó có lẽ ở gần thác nước phía đông nhất của Tân Thủ Thôn. Ở đó còn có một lão Trần, tôi nghi lão Trần được cố ý bố trí để giám sát tôi, lòng có chút lo lắng, tôi phải đề phòng lão. Nghĩ lại, thật có chút kích thích! Sau khi tìm được Tàng Bảo Đồ, quay lại gặp chủ tiệm giáp trụ, ông ấy sẽ cho tôi manh mối tiếp theo!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 180 điểm\n" 
 BLK "    Tiềm năng: 40 điểm\n" 
 BLK "    Ngân lượng: 1000\n";
		}
		else if (iKind == 104)
		{
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Sử dụng Tàng Bảo Đồ tìm ngọc bội gia tộc, giao cho chủ tiệm thuốc Tân Thủ Thôn\n" BLK "Ngọc Bội Gia Tộc %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Thuốc Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ tiệm giáp trụ bảo tôi cầm Tàng Bảo Đồ đi về phía nam, đến hòn đảo nổi bật nhất ở Thanh Khê, tìm kỹ trong bụi cỏ (88,62), đến đó là có thể đào được kho báu! Nhiệm vụ này sẽ có phần thưởng nhiều hơn so với việc tìm Tàng Bảo Đồ, nên tôi sẵn sàng nhận thử thách này. Sau khi tìm được kho báu, đến gặp chủ tiệm thuốc, ông ấy sẽ cho tôi thứ tôi muốn!\n" 
 BLK "    Sau khi hoàn thành nhiệm vụ, dùng alt+w mở giao diện thuộc tính nhân vật, sau đó sử dụng tín vật tân thủ để nhanh chóng trở về Tân Thủ Thôn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 260 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 500\n" 
 BLK "    Vật phẩm: Dây chuyền Tân Thủ", who->get_legend(48, 9) ? 1 : 0);
		}
		else if (iKind == 107)
		{
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến " HIR "Thanh Khê" BLK " tiêu diệt " HIR "Kiến Nhỏ" BLK " hoặc " HIR "Ong Nhỏ" BLK ", lấy Búa Sắt, giao cho chủ tiệm sửa chữa\n" BLK "Búa Sắt %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Chủ Tiệm Sửa Chữa Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Chủ tiệm tạp hóa đã hứa với chủ tiệm sửa chữa sẽ tìm cho ông một chiếc Búa Sắt. Theo thông tin ông nghe được, lũ " HIR "Kiến Nhỏ" BLK " và " HIR "Ong Nhỏ" BLK " ở Thanh Khê có mang theo Búa Sắt. Nhưng đối với tôi, sức mạnh của chúng có chút đáng gờm, nên đây là một thử thách lớn. Tôi thích thử thách!\n" 
 BLK "    Sau khi hoàn thành nhiệm vụ, dùng alt+w mở giao diện thuộc tính nhân vật, sau đó sử dụng tín vật tân thủ để nhanh chóng trở về Tân Thủ Thôn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 550 điểm\n" 
 BLK "    Tiềm năng: 50 điểm\n" 
 BLK "    Ngân lượng: 2500\n" 
 BLK "    Vật phẩm: Sửa chữa đặc biệt 1 lần", who->get_legend(48, 16) ? 1 : 0);
		}
		else if (iKind == 108)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tiêu diệt 8 Tiểu Quái Vật, báo cáo cho Vệ Đội Trưởng (" HIR "Ong Nhỏ, Kiến Nhỏ, Ếch Vàng Đốm" BLK " đều được)\n" BLK "Tiểu Quái Vật %d/8\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vệ Đội Trưởng Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Lũ động vật ở U Cốc vốn rất đáng yêu, chúng tìm thức ăn ngoài hoang dã, khi gặp thợ săn lên núi, chúng thường vây quanh vì tin rằng con người không làm hại chúng. Nhưng giờ đây, mọi thứ đã thay đổi… Lũ Ong Nhỏ này không còn đáng yêu, không còn hiền lành, chúng tấn công con người. Vệ Đội Trưởng nghi ngờ lũ Ong Nhỏ bị yêu quái mê hoặc, bị điều khiển nên mới trở nên như vậy. Ông nhờ tôi đi tiêu diệt lũ Ong Nhỏ, Kiến Nhỏ hoặc Ếch Vàng Đốm, sau đó báo cáo cho Vệ Đội Trưởng Tân Thủ Thôn để xem ông định xử lý ra sao.\n" 
 BLK "    Sau khi hoàn thành nhiệm vụ, dùng alt+w mở giao diện thuộc tính nhân vật, sau đó sử dụng tín vật tân thủ để nhanh chóng trở về Tân Thủ Thôn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 650 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 1000\n" 
 BLK "    Vật phẩm: Hành Quân Tán x5", who->get_save("new_chy"));
		else if (iKind == 110)
		{
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Tìm Hoàng Thạch Tán giao cho Công Đức Lão Nhân\n" BLK "Hoàng Thạch Tán %d/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Trí Tuệ Lão Nhân\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Công Đức Lão Nhân nói rằng theo suy đoán của ông, dân làng có lẽ đã trúng một loại độc gọi là Nhuyễn Cốt Tán, và nguồn độc đến từ giếng nước phía sau làng. Những người trúng độc đều uống nước từ giếng đó rồi mới xuất hiện triệu chứng. Để giải độc này cần phải có Hoàng Thạch Tán, và phải kết hợp với các dược liệu khác mới có hiệu quả. Thuốc sau khi điều chế không chỉ cho dân làng uống mà còn phải rắc vào giếng để giải độc. Công Đức Lão Nhân bảo tôi đi tìm Hoàng Thạch Tán giao cho ông trước, rồi sẽ tính tiếp. Ông nói lũ Ong Nhỏ, Kiến Nhỏ, Ếch Vàng Đốm ở khu vực U Cốc thường mang theo Hoàng Thạch Tán.\n" 
 BLK "    Sau khi hoàn thành nhiệm vụ, dùng alt+w mở giao diện thuộc tính nhân vật, sau đó sử dụng tín vật tân thủ để nhanh chóng trở về Tân Thủ Thôn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Công đức: 10 điểm\n" 
 BLK "    Ngân lượng: 1800", who->get_legend(48, 24) ? 1 : 0);
		}
		else if (iKind == 112)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến " HIR "Ba Khâu" BLK " tiêu diệt " HIR "Bù Nhìn Cầm Quạt, Kiến Nâu Đỏ hoặc Ếch Mẹ Con" BLK " để lấy Hoa Huệ giao cho Quản Khố\n" BLK "Hoa Huệ %d/3\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Quản Khố\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vệ Đội Trưởng nói rằng tuy ông là người thô kệch, nhưng rất chú trọng đến sự tinh tế trong cuộc sống. Ông thích trồng một ít hoa cỏ trong nhà để không gian trông sinh động hơn. Dù trong nhà đã có nhiều Lan, Măng Tây, Cúc, nhưng thứ ông yêu thích nhất vẫn là Hoa Huệ, tượng trưng cho sự thuần khiết. Quản Khố ở Tân Thủ Thôn luôn là người ông kính trọng nhất, nhân dịp nhà Quản Khố đang sửa sang, ông muốn tặng vài bông Hoa Huệ để trang trí. Nghe nói lũ Bù Nhìn Cầm Quạt, Kiến Nâu Đỏ hoặc Ếch Mẹ Con ở Ba Khâu có mang theo Hoa Huệ, hãy đi lấy về và giao cho Quản Khố.\n" 
 BLK "    Sau khi hoàn thành nhiệm vụ, dùng alt+w mở giao diện thuộc tính nhân vật, sau đó sử dụng tín vật tân thủ để nhanh chóng trở về Tân Thủ Thôn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 550 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Ngân lượng: 1000", who->get_save("wdzbaihh"));
		else if (iKind == 116)
			result = sprintf(BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến " HIR "Ba Khâu" BLK " tiêu diệt " HIR "Bù Nhìn Cầm Quạt, Kiến Nâu Đỏ hoặc Ếch Mẹ Con" BLK " để lấy Hỏa Diệm Thạch, giao cho Sứ Giả Môn Phái\n" BLK "Hỏa Diệm Thạch %d/5\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sứ Giả Môn Phái Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Tôi thực sự cần một ít Hành Quân Tán, chúng rất hữu ích cho khí huyết của tôi, đúng không? Quản Khố sẵn lòng cho tôi một ít Hành Quân Tán, nhưng ông yêu cầu tôi giúp Sứ Giả Môn Phái lấy 5 viên Hỏa Diệm Thạch. Chuyện này không làm khó được tôi! Chỉ cần đến Ba Khâu tiêu diệt lũ Bù Nhìn Cầm Quạt, Kiến Nâu Đỏ hoặc Ếch Mẹ Con phiền phức, tôi có thể tìm được Hỏa Diệm Thạch.\n" 
 BLK "    Sau khi hoàn thành nhiệm vụ, dùng alt+w mở giao diện thuộc tính nhân vật, sau đó sử dụng tín vật tân thủ để nhanh chóng trở về Tân Thủ Thôn!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 280 điểm\n" 
 BLK "    Tiềm năng: 30 điểm\n" 
 BLK "    Vật phẩm: Hành Quân Tán x10", who->get_save_2("huoyanshi"));
		else if (iKind == 117)
		{
			if (objectp(present("Vòng tay bị mất", who, 1, MAX_CARRY)))
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến " HIR "U Cốc" BLK " tìm Vòng Tay Bị Mất, giao vòng tay cho Sứ Giả Môn Phái\n" BLK "Vòng Tay 1/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sứ Giả Môn Phái Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thất quốc phân tranh, quần hùng tranh bá. Trong lúc chạy loạn thời chiến, cha mẹ không may qua đời, vòng tay mẹ truyền lại trước khi mất cũng bị thất lạc, quá khứ đau lòng không muốn nhớ lại! Làm sao tìm được chiếc vòng tay bị mất này! Tôi nghe nói hình như nó được thấy ở khu vực tây bắc U Cốc. Vì đó là di vật của mẹ anh ta, tôi sẽ giúp anh ta chuyện này! Sau khi tìm được vòng tay, hãy giao cho Sứ Giả Môn Phái trước, nghe nói ông ấy có tuyệt kỹ khử trùng, vòng tay lưu lạc bên ngoài lâu như vậy, nên nhờ ông khử trùng sạch sẽ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 20 điểm\n" 
 BLK "    Vật phẩm: Đai Lưng Tân Thủ\n";
			else
				result = BLK "Mục đích nhiệm vụ:\n" 
 BLK "    Đi đến " HIR "U Cốc" BLK " tìm Vòng Tay Bị Mất, giao vòng tay cho Sứ Giả Môn Phái\n" BLK "Vòng Tay 0/1\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Sứ Giả Môn Phái Tân Thủ Thôn\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Thất quốc phân tranh, quần hùng tranh bá. Trong lúc chạy loạn thời chiến, cha mẹ không may qua đời, vòng tay mẹ truyền lại trước khi mất cũng bị thất lạc, quá khứ đau lòng không muốn nhớ lại! Làm sao tìm được chiếc vòng tay bị mất này! Tôi nghe nói hình như nó được thấy ở khu vực tây bắc U Cốc. Vì đó là di vật của mẹ anh ta, tôi sẽ giúp anh ta chuyện này! Sau khi tìm được vòng tay, hãy giao cho Sứ Giả Môn Phái trước, nghe nói ông ấy có tuyệt kỹ khử trùng, vòng tay lưu lạc bên ngoài lâu như vậy, nên nhờ ông khử trùng sạch sẽ.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 20 điểm\n" 
 BLK "    Vật phẩm: Đai Lưng Tân Thủ\n";
		}
		else if (iKind == 118)
		{
			if (who->get_fam_name() == "")
				result = BLK "Mục đích nhiệm vụ:\n" HIR "    Sau khi đạt cấp 10" BLK ", bái sư trước, sau đó tìm Tiễn Lão Cửu nước Sở, giao Nhật Ký Thử Thách của Sứ Giả Môn Phái cho ông ta\n" BLK "Bái sư 0/1\n" BLK "Thăm Tiễn Lão Cửu nước Sở 0/1\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sứ Giả Môn Phái và Tiễn Lão Cửu nước Sở có ân oán nhiều năm, nay tôi mang thư khiêu chiến này giao cho Tiễn Lão Cửu để giải quyết ân oán. Trước khi đi, hãy bái sư học chút võ nghệ, nếu không bị ông ta bắt nạt mà tôi không có sức chống đỡ thì không hay!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 35 điểm\n" 
 BLK "    Ngân lượng: 1000\n";
			else
				result = BLK "Mục đích nhiệm vụ:\n" HIR "    Sau khi đạt cấp 10" BLK ", bái sư trước, sau đó tìm Tiễn Lão Cửu nước Sở, giao Nhật Ký Thử Thách của Sứ Giả Môn Phái cho ông ta\n" BLK "Bái sư 1/1\n" BLK "Thăm Tiễn Lão Cửu nước Sở 0/1\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Sứ Giả Môn Phái và Tiễn Lão Cửu nước Sở có ân oán nhiều năm, nay tôi mang thư khiêu chiến này giao cho Tiễn Lão Cửu để giải quyết ân oán. Trước khi đi, hãy bái sư học chút võ nghệ, nếu không bị ông ta bắt nạt mà tôi không có sức chống đỡ thì không hay!\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 35 điểm\n" 
 BLK "    Ngân lượng: 1000\n";
		}
		else if (iKind == 119)
		{
			result = BLK "Mục đích nhiệm vụ:\n" HIR "    Sau khi đạt cấp 10" BLK ", bái sư trước, sau đó thăm Vương Bộ Đầu nước Chu\n" BLK "Người hoàn thành nhiệm vụ:" HIR "Vương Bộ Đầu\n" BLK "Miêu tả nhiệm vụ:\n" 
 BLK "    Vương Bộ Đầu nước Chu không phải người thường, dù là đạo tặc nhỏ hay giang hồ đại đạo cũng không thể thoát khỏi tay ông. Nhưng gần đây, công việc của Vương Bộ Đầu quá nhiều, nhân thủ không đủ, nghe nói vì có phạm nhân trốn thoát. Đại Vương nước Chu treo thưởng bắt những kẻ này. Đã là lệnh của Đại Vương, phần thưởng chắc chắn không ít, tôi phải nhanh chóng đi xem có việc gì hay để nhận. Vương Bộ Đầu ở ngay cạnh trạm dịch trong thành nước Chu, trước khi đi hãy bái sư học chút võ nghệ, nếu không bị ông xem thường thì không tốt.\n" BLK "Phần thưởng nhiệm vụ:\n" 
 BLK "    Kinh nghiệm: 300 điểm\n" 
 BLK "    Tiềm năng: 35 điểm\n" 
 BLK "    Ngân lượng: 500\n";
		}
}
	return result;
}
