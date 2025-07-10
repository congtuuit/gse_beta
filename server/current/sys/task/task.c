
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <effect.h>
#include <time.h>
string send_task_intro(object who, int iFlag, int iTask, int iKind);

mapping mpTaskList = ([
	"Nhiệm Vụ Chỉ Dẫn":([
		1:({ TASK_NEWBIE_00,1,2,TID_NEWBIE_00,"Sứ Mệnh Đưa Thư" })
	]),

		"Nhiệm Vụ Sự Kiện" : ([
			1:({ TID_EVENTS,1,2,TID_EVENTS,"Thu thập hồn ma yêu tinh" })
		]),
			"Bá Vương" : ([
				1:({ TID_NEWITEMS,1,2,TID_NEWITEMS,"Trợ giúp" }),
					2 : ({ TID_NEWITEMS,3,4,TID_NEWITEMS,"Lục Bảo Tinh Thạch" }),
					3 : ({ TID_NEWITEMS,5,6,TID_NEWITEMS,"Tứ Linh Vệ Hồn" }),
					4 : ({ TID_NEWITEMS,7,8,TID_NEWITEMS,"Tiêu diệt Kinh Kha" }),
					5 : ({ TID_NEWITEMS,9,10,TID_NEWITEMS,"Thăm hỏi Hạng Vũ" }),
			]),
				"Tân Thủ Thôn" : ([
					3:({ TASK_NEWBIE_01,3,4,TID_NEWBIE_01,"Việc hợp tác" }),
						6 : ({ TASK_NEWBIE_01,10,11,TID_NEWBIE_01,"Thăm bệnh nhân" }),
						7 : ({ TASK_NEWBIE_01,12,13,TID_NEWBIE_01,"Tin nhắn của chim bồ câu" }),
						9 : ({ TASK_NEWBIE_01,17,18,TID_NEWBIE_01,"Mũi tên gãy" }),
						10 : ({ TASK_NEWBIE_01,19,20,TID_NEWBIE_01,"Ngưu Nhị cám ơn rất nhiều" }),
						11 : ({ TASK_NEWBIE_01,21,22,TID_NEWBIE_01,"Tiểu Nghê Đồ..." }),
						12 : ({ TASK_NEWBIE_01,1,2,TID_NEWBIE_01,"Sự ủy thác của trưởng thôn" }),
						13 : ({ TASK_NEWBIE_01,23,24,TID_NEWBIE_01,"Cơ hội tập luyện" }),
						17 : ({ TASK_NEWBIE_02,10,11,TID_NEWBIE_01,"Hãy nói chuyện với ông già thông thái." }),
						18 : ({ TASK_NEWBIE_02,12,13,TID_NEWBIE_01,"Bị mất vòng" }),
						23 : ({ TASK_37,13,14,TID_NEWBIE_01,"Sự biết ơn và phật ý của hướng dẫn trường" }),
						24 : ({ TASK_40,24,25,TID_NEWBIE_01,"Đau đầu (1)" }),
						26 : ({ TASK_40,28,29,TID_NEWBIE_01,"Đau đầu (3)" }),
						27 : ({ TASK_41,4,5,TID_NEWBIE_01,"Rất nhiều bệnh khác nhau (1)" }),
						29 : ({ TASK_41,9,10,TID_NEWBIE_01,"Rất nhiều bệnh khác nhau (3)" }),
						33 : ({ TASK_41,11,12,TID_NEWBIE_01,"Thùng vận chuyển" }),
						34 : ({ TASK_40,20,21,TID_NEWBIE_01,"cô đơn" }),
						35 : ({ TASK_40,22,23,TID_NEWBIE_01,"Nguồn thức ăn" }),
						102 : ({ TASK_48,4 ,5 ,TID_NEWBIE_01,"Việc hợp tác" }),
						103 : ({ TASK_48,6 ,7 ,TID_NEWBIE_01,"Kinh Nghiệm Tìm Báu Vật" }),
						105 : ({ TASK_48,11,12,TID_NEWBIE_01,"Thăm bệnh nhân" }),
						106 : ({ TASK_48,13,14,TID_NEWBIE_01,"Tin nhắn của chim bồ câu" }),
						109 : ({ TASK_48,21,22,TID_NEWBIE_01,"Rất nhiều bệnh khác nhau (1)" }),
						111 : ({ TASK_48,26,27,TID_NEWBIE_01,"Rất nhiều bệnh khác nhau(3)" }),
						113 : ({ TASK_49,1 ,2 ,TID_NEWBIE_01,"Đau đầu(1)" }),
						114 : ({ TASK_49,3 ,4 ,TID_NEWBIE_01,"Đau đầu(2)" }),
						115 : ({ TASK_49,4 ,5 ,TID_NEWBIE_01,"Đau đầu(3)" }),
						117 : ({ TASK_49,9 ,10,TID_NEWBIE_01,"Bị mất vòng" }),
						118 : ({ TASK_49,11,12,TID_NEWBIE_01,"Sự biết ơn và phật ý của hướng dẫn trường" }),
						119 : ({ TASK_2_00,10,11,TID_NEWBIE_01,"Công việc tốt của Vệ Đội Trưởng" }),
				]),
					"Chu Quốc": ([
						//1: ({TASK_NEWBIE_00,11,12,TID_ZHOUGUO,"Công việc tốt của cảnh sát Vương"}),
						//2: ({TASK_NEWBIE_00,13,14,TID_ZHOUGUO,"Đi mà nói chuyện với nước Vệ"}),
						3:({ TASK_NEWBIE_00,9,10,TID_ZHOUGUO,"Thăm chủ nhân" }),
							9 : ({ TASK_40,3,4,TID_ZHOUGUO,"Bị bao vây ở mọi phía(5)" }),
							10 : ({ TASK_40,5,6,TID_ZHOUGUO,"Tù Và Lập Bang" }),
							13 : ({ TASK_40,13,14,TID_ZHOUGUO,"Thỉnh Cầu Vua Giúp Đỡ" }),
							14 : ({ TASK_40,15,16,TID_ZHOUGUO,"Chế tạo Tù Và Đế Vương" }),
							15 : ({ TASK_49,13,14,TID_ZHOUGUO,"Một cái thăm dò về cái thiệt và cái thiệt" }),
							16 : ({ TASK_2_00,12,13,TID_ZHOUGUO,"Thăm chủ nhân" }),
							17 : ({ TASK_2_00,14,15,TID_ZHOUGUO,"Thăm hỏi Ngụy Vương" }),
							18 : ({ TASK_2_00,16,17,TID_ZHOUGUO,"Thăm hỏi Tả Khâu Minh" }),
							19 : ({ TASK_2_00,18,19,TID_ZHOUGUO,"Thăm Zhou Wang" }),
							22 : ({ TASK_2_00,26,27,TID_ZHOUGUO,"Thông điệp người coi nhà Chu" }),
					]),
						"Sở Quốc": ([
							9:({ TASK_NEWBIE_03,22,23,TID_CHUGUO,"Vá lại chuồng sau khi con cừu bị ăn trộm(1)" }),
								12 : ({ TASK_07,28,29,TID_CHUGUO,"Tờ Ghi Nhớ" }),
								31 : ({ TASK_24,15,16,TID_CHUGUO,"Trà Jasmine(4)" }),
								32 : ({ TASK_32,29,30,TID_CHUGUO,"Di sản của ông(2)" }),
								42 : ({ TASK_37,15,16,TID_CHUGUO,"Thu thập trang sức" }),
								43 : ({ TASK_37,17,18,TID_CHUGUO,"Trợ giúp của quản lý Hán" }),
								44 : ({ TASK_37,25,26,TID_CHUGUO,"Hãy gửi lời nhắn tới sứ giả của Tề" }),
								45 : ({ TASK_38,19,20,TID_CHUGUO,"Kiếm bị lãng quên" }),
								46 : ({ TASK_39,7,8,TID_CHUGUO,"Kết bạn đi" }),
						]),
							"Hàn Quốc": ([
								3:({ TASK_04,7,8,TID_HANGUO,"Những rắc rối của kiểm duyệt" }),
									4 : ({ TASK_04,9,10,TID_HANGUO,"Nhiệm vụ" }),
									6 : ({ TASK_04,13,14,TID_HANGUO,"Tự mật ghi lưu nhà" }),
									7 : ({ TASK_04,15,16,TID_HANGUO,"Quần áo màu nhiệm" }),
									8 : ({ TASK_04,17,18,TID_HANGUO,"Chuỗi lục ngọc" }),
									9 : ({ TASK_04,19,20,TID_HANGUO,"Tình yêu" }),
									10 : ({ TASK_04,21,22,TID_HANGUO,"Ý của thợ thủ" }),
									15 : ({ TASK_04,29,30,TID_HANGUO,"Chuyện khó khăn của các tướng lĩnh" }),
									16 : ({ TASK_25,4,5,TID_HANGUO,"Yêu cầu bản đồ kho báu" }),
									18 : ({ TASK_25,9,10,TID_HANGUO,"Tìm đến gốc rễ của mọi thứ" }),
									21 : ({ TASK_25,17,18,TID_HANGUO,"Khuyên bảo" }),
									24 : ({ TASK_25,25,26,TID_HANGUO,"Về Hán Vương" }),
									25 : ({ TASK_25,27,28,TID_HANGUO,"Liên minh với Chu" }),
									26 : ({ TASK_25,29,30,TID_HANGUO,"Suy nghĩ của quan chức nội thất" }),
									27 : ({ TASK_26,1,2,TID_HANGUO,"Xin giúp đỡ" }),
									28 : ({ TASK_26,3,4,TID_HANGUO,"Kiểm duyệt đề xuất" }),
									29 : ({ TASK_26,5,6,TID_HANGUO,"Chỉ đường đi" }),
									31 : ({ TASK_26,10,11,TID_HANGUO,"Thương nhân khóc" }),
									32 : ({ TASK_26,12,13,TID_HANGUO,"Nỗi lo của kiểm duyệt" }),
									35 : ({ TASK_26,20,21,TID_HANGUO,"Tìm nơi ẩn náu" }),
									36 : ({ TASK_26,22,23,TID_HANGUO,"Sự tử tế của nhân dân" }),
									37 : ({ TASK_26,24,25,TID_HANGUO,"Nhạc sĩ bất lực" }),
									40 : ({ TASK_26,29,30,TID_HANGUO,"Về Hán Vương" }),
									45 : ({ TASK_23,4,5,TID_HANGUO,"Linh hồn lang thang(1)" }),
									47 : ({ TASK_23,25,26,TID_HANGUO,"♪ Samurai love(2)" }),
									48 : ({ TASK_37,19,20,TID_HANGUO,"Lời mời của Cui Daguan" }),
									49 : ({ TASK_38,9,10,TID_HANGUO,"Tìm cách giúp đỡ người khác" }),
									50 : ({ TASK_38,13,14,TID_HANGUO,"Bí ẩn của kinh nghiệm sống" }),
							]),
								"Ngụy Quốc": ([
									5:({ TASK_07,4,9,TID_WEIGUO,"Đến Yến đại nhân" }),
										36 : ({ TASK_31,16,17,TID_WEIGUO,"Bí mật(1)" }),
										37 : ({ TASK_33,25,26,TID_WEIGUO,"yêu cầu tin tức" }),
										41 : ({ TASK_34,7,8,TID_WEIGUO,"Dân thường nước Ngụy" }),
										42 : ({ TASK_34,9,10,TID_WEIGUO,"yêu cầu thông tin" }),
										45 : ({ TASK_34,17,18,TID_WEIGUO,"Thành tích chính" }),
										46 : ({ TASK_34,19,20,TID_WEIGUO,"Hãy hỏi Vương Minh" }),
										47 : ({ TASK_34,21,22,TID_WEIGUO,"Con đường của hôn nhân 1" }),
										48 : ({ TASK_34,23,24,TID_WEIGUO,"Con đường của hôn nhân 2" }),
										51 : ({ TASK_35,1,2,TID_WEIGUO,"Con đường của hôn nhân 5" }),
										52 : ({ TASK_35,3,4,TID_WEIGUO,"Thăm dò" }),
										53 : ({ TASK_35,5,6,TID_WEIGUO,"Thăm dò" }),
										56 : ({ TASK_35,13,14,TID_WEIGUO,"Xóa bỏ điều kỳ diệu" }),
										57 : ({ TASK_35,15,16,TID_WEIGUO,"Tìm hiểu nguyên nhân" }),
										60 : ({ TASK_35,23,24,TID_WEIGUO,"Bản" }),
										61 : ({ TASK_35,25,26,TID_WEIGUO,"Báo cáo cho Ngụy vương" }),
										65 : ({ TASK_37,21,22,TID_WEIGUO,"Tiệc gia đình" }),
										66 : ({ TASK_37,23,24,TID_WEIGUO,"Ủy ban chết" }),
										67 : ({ TASK_38,21,22,TID_WEIGUO,"Đổi việc" }),
										68 : ({ TASK_39,5,6,TID_WEIGUO,"Một thợ thủ công giỏi" }),
								]),
									"Tề Quốc": ([
										1:({ TASK_09,19,20,TID_QIGUO,"Môi hở và răng lạnh(1)" }),
											2 : ({ TASK_09,21,22,TID_QIGUO,"Môi hở và răng lạnh(2)" }),
											4 : ({ TASK_09,26,27,TID_QIGUO,"Môi hở và răng lạnh(4)" }),
											8 : ({ TASK_10,1,2,TID_QIGUO,"Mang thông điệp đến Quan Vũ(3)" }),
											10 : ({ TASK_10,6,7,TID_QIGUO,"Mang tin nhắn cho ông Trịnh(2)" }),
											15 : ({ TASK_24,7,8,TID_QIGUO,"Trà Jasmine(1)" }),
											25 : ({ TASK_28,29,30,TID_QIGUO,"Hỏi tại sao" }),
											26 : ({ TASK_29,16,17,TID_QIGUO,"Hỏi về" }),
											28 : ({ TASK_29,21,22,TID_QIGUO,"Đến dưới cùng" }),
											30 : ({ TASK_29,26,27,TID_QIGUO,"Tham quan chung" }),
											31 : ({ TASK_30,1,2,TID_QIGUO,"Chữ Đại tướng" }),
											32 : ({ TASK_30,3,4,TID_QIGUO,"Thăm dân cư" }),
											35 : ({ TASK_30,8,9,TID_QIGUO,"Hỏi về lý do" }),
											36 : ({ TASK_30,10,11,TID_QIGUO,"phân biệt giữa sự thật và dối trá" }),
											39 : ({ TASK_30,18,19,TID_QIGUO,"Lục soát kẻ bắt nạt" }),
											40 : ({ TASK_30,20,21,TID_QIGUO,"Đi sâu vào dân gian" }),
											41 : ({ TASK_30,22,23,TID_QIGUO,"Người làm ăn" }),
											44 : ({ TASK_24,29,30,TID_QIGUO,"Trình diện cho vua nước Tề" }),
											45 : ({ TASK_31,1,2,TID_QIGUO,"Hỏi người bán hàng rong" }),
											48 : ({ TASK_31,9,10,TID_QIGUO,"Thông báo cho nhân viên nội vụ" }),
											49 : ({ TASK_31,11,12,TID_QIGUO,"Thông báo cho mọi người" }),
											61 : ({ TASK_36,29,30,TID_QIGUO,"Tiểu Đồ(2)" }),
											63 : ({ TASK_40,1,2,TID_QIGUO,"Bị bao vây ở mọi phía(3)" }),
											65 : ({ TASK_44,16,17,TID_QIGUO,"Tư vấn nhiệt tình(2)" }),
											71 : ({ TASK_45,13,14,TID_QIGUO,"Vinh quang tối cao(3)", }),
											72 : ({ TASK_37,27,28,TID_QIGUO,"Cây cuốc trồng trọt" }),
											73 : ({ TASK_37,29,30,TID_QIGUO,"Trao đổi kinh nghiệm" }),
											74 : ({ TASK_38,11,12,TID_QIGUO,"Cảm ơn" }),
											75 : ({ TASK_38,17,18,TID_QIGUO,"Hỏi về giá cả" }),
											76 : ({ TASK_38,23,24,TID_QIGUO,"Xin vui lòng" }),
											77 : ({ TASK_38,25,26,TID_QIGUO,"Thử thách" }),
									]),
										"Tần Quốc": ([
											4:({ TASK_11,4,5,TID_QINGUO,"Cung điện Tần(2)" }),
												6 : ({ TASK_11,9,10,TID_QINGUO,"Cung điện Tần(4)" }),
												8 : ({ TASK_10,29,30,TID_QINGUO,"Tình anh em" }),
												9 : ({ TASK_18,28,29,TID_QINGUO,"Chúc mừng" }),
												10 : ({ TASK_19,5,6,TID_QINGUO,"Quả bầu lớn(3)" }),
												12 : ({ TASK_18,19,20,TID_QINGUO,"Hiện sức mạnh đi(2)" }),
												13 : ({ TASK_18,20,21,TID_QINGUO,"Hiện sức mạnh đi(3)" }),
												22 : ({ TASK_19,22,23,TID_QINGUO,"Truy bắt đào phạm" }),
												23 : ({ TASK_20,19,20,TID_QINGUO,"Khám phá sự thật" }),
												27 : ({ TASK_21,1,2,TID_QINGUO,"Đất khô cằn" }),
												28 : ({ TASK_21,3,4,TID_QINGUO,"Hỏi thăm" }),
												30 : ({ TASK_21,8,9,TID_QINGUO,"Sửa chữa lăng mộ" }),
												32 : ({ TASK_21,13,14,TID_QINGUO,"Tìm hỗ trợ" }),
												33 : ({ TASK_21,15,16,TID_QINGUO,"Chuẩn bị làm sứ giả" }),
												35 : ({ TASK_21,20,21,TID_QINGUO,"Nhiệm vụ đưa thư" }),
												36 : ({ TASK_21,22,23,TID_QINGUO,"Thăm hỏi Triệu Vương" }),
												37 : ({ TASK_21,24,25,TID_QINGUO,"Quay về Tần Vương" }),
												38 : ({ TASK_21,26,27,TID_QINGUO,"Tần tướng quân bác bỏ lời đồn" }),
												40 : ({ TASK_22,1,2,TID_QINGUO,"Thông báo khiếu nại" }),
												41 : ({ TASK_22,3,4,TID_QINGUO,"Phân biệt giữa sự thật và dối trá" }),
												43 : ({ TASK_22,8,9,TID_QINGUO,"Tin đồn" }),
												46 : ({ TASK_22,16,17,TID_QINGUO,"Đại vương của nước Tần" }),
												51 : ({ TASK_20,13,14,TID_QINGUO,"Lễ hội đôi lần thứ 9(2)" }),
												52 : ({ TASK_20,14,15,TID_QINGUO,"Lễ hội đôi lần thứ 9(3)" }),
												54 : ({ TASK_19,1,2,TID_QINGUO,"Quả bầu lớn(1)" }),
												64 : ({ TASK_46,1,2,TID_QINGUO,"Huyền thoại linh hồn của thanh kiếm 1" }),
												66 : ({ TASK_46,6,7,TID_QINGUO,"Huyền thoại linh hồn của thanh kiếm 3" }),
												68 : ({ TASK_46,11,12,TID_QINGUO,"Huyền thoại linh hồn của thanh kiếm 5" }),
												69 : ({ TASK_46,13,14,TID_QINGUO,"Hỗn loạn 1" }),
												73 : ({ TASK_46,24,25,TID_QINGUO,"Hỗn loạn 5" }),
												74 : ({ TASK_46,26,27,TID_QINGUO,"Con đường y dược 1" }),
												76 : ({ TASK_47,1,2,TID_QINGUO,"Con đường y dược 3" }),
												78 : ({ TASK_47,6,7,TID_QINGUO,"Con đường y dược 5" }),
												79 : ({ TASK_47,8,9,TID_QINGUO,"Xua tan tin đồn 1" }),
												80 : ({ TASK_47,10,11,TID_QINGUO,"Xua tan tin đồn 2" }),
												82 : ({ TASK_47,15,16,TID_QINGUO,"Xua tan tin đồn 4" }),
												83 : ({ TASK_47,17,18,TID_QINGUO,"Xua tan tin đồn 5" }),
												84 : ({ TASK_47,19,20,TID_QINGUO,"Hãy hỏi kiếm 1" }),
												85 : ({ TASK_47,21,22,TID_QINGUO,"Hãy hỏi kiếm 2" }),
												88 : ({ TASK_47,29,30,TID_QINGUO,"Hãy hỏi kiếm 5" }),
												89 : ({ TASK_36,9,10,TID_QINGUO,"Viên ngọc hoàn hảo (4)" }),
												90 : ({ TASK_38,1,2,TID_QINGUO,"Nho tím" }),
												91 : ({ TASK_38,7,8,TID_QINGUO,"Sự ủy thác của quản lý Han" }),
												92 : ({ TASK_38,27,28,TID_QINGUO,"Đạo Phật" }),
												93 : ({ TASK_39,1,2,TID_QINGUO,"Việc vặt" }),
												94 : ({ TASK_39,3,4,TID_QINGUO,"Ủy thác" }),
										]),
											"Yên Quốc": ([
												17:({ TASK_11,14,15,TID_YANGUO,"Bất lực (1)" }),
													27 : ({ TASK_14,13,14,TID_YANGUO,"Hỗn Thiên Nghi(3)" }),
													30 : ({ TASK_15,7,8,TID_YANGUO,"Căn bệnh của Phu Nhân(1)" }),
													35 : ({ TASK_16,1,2,TID_YANGUO,"Hợp tác kinh doanh" }),
													38 : ({ TASK_27,14,15,TID_YANGUO,"Lỗ Vương rất thích vàng (3)" }),
													54 : ({ TASK_38,3,4,TID_YANGUO,"Ngọc trai đen đã mất" }),
											]),
												"Triệu Quốc": ([
													3:({ TASK_11,22,23,TID_ZHAOGUO,"Bất lực (4)", }),
														8 : ({ TASK_16,6,7,TID_ZHAOGUO,"Sứ giả của nước Tần", }),
														36 : ({ TASK_19,24,25,TID_ZHAOGUO,"Triệu Phú", }),
														38 : ({ TASK_19,29,30,TID_ZHAOGUO,"Thanh kiếm", }),
														42 : ({ TASK_27,10,11,TID_ZHAOGUO,"Yên vương là báu vật(1)", }),
														48 : ({ TASK_28,10,11,TID_ZHAOGUO,"Bí mật của hộp gỗ(2)", }),
														49 : ({ TASK_28,12,13,TID_ZHAOGUO,"Bí mật của hộp gỗ(3)", }),
														54 : ({ TASK_32,4,5,TID_ZHAOGUO,"Việc vặt(1)", }),
														56 : ({ TASK_32,9,10,TID_ZHAOGUO,"Sự rối loạn Khổng Tử", }),
														57 : ({ TASK_36,1,2,TID_ZHAOGUO,"Viên ngọc hoàn hảo (1)", }),
														58 : ({ TASK_39,23,24,TID_ZHAOGUO,"Bị bao vây ở mọi phía(1)", }),
														61 : ({ TASK_45,21,22,TID_ZHAOGUO,"Theo y tế(2)", }),
														64 : ({ TASK_38,5,6,TID_ZHAOGUO,"Xây dựng vũ kh", }),
														65 : ({ TASK_38,15,16,TID_ZHAOGUO,"Chào anh trai tôi", }),
														66 : ({ TASK_38,29,30,TID_ZHAOGUO,"Vừa vặn", }),
														67 : ({ TASK_39,9,10,TID_ZHAOGUO,"Ước", }),
														68 : ({ TASK_41,16,17,TID_ZHAOGUO,"Lý do yêu cầu", }),
														69 : ({ TASK_41,18,19,TID_ZHAOGUO,"Tìm nơi ở của hắn", }),
														72 : ({ TASK_41,26,27,TID_ZHAOGUO,"Tần vương Triệu vương", }),
														73 : ({ TASK_42,1,2,TID_ZHAOGUO,"Hỏi cung cấp thông tin", }),
														74 : ({ TASK_42,3,4,TID_ZHAOGUO,"Hỏi về kết quả", }),
														75 : ({ TASK_42,5,6,TID_ZHAOGUO,"Hỏi thăm về báo cáo chiến tranh", }),
														78 : ({ TASK_42,10,11,TID_ZHAOGUO,"Hỏi về lý do", }),
														82 : ({ TASK_42,21,22,TID_ZHAOGUO,"Trình diện Triệu Vương", }),
														83 : ({ TASK_42,23,24,TID_ZHAOGUO,"Thăm người", }),
														85 : ({ TASK_43,1,2,TID_ZHAOGUO,"Nói sự thật đi", }),
														87 : ({ TASK_43,3,4,TID_ZHAOGUO,"Hãy thực hiện chính phủ", }),
														88 : ({ TASK_43,5,6,TID_ZHAOGUO,"Thăm dò nguyên nhân", }),
														89 : ({ TASK_43,7,8,TID_ZHAOGUO,"Phỏng vấn nội gián", }),
														92 : ({ TASK_43,14,16,TID_ZHAOGUO,"Hoàn thành nhiệm vụ", }),
												]),
													"Mao Sơn": ([
														1:({ TASK_23,6,7,TID_MAOSHAN,"Linh hồn lang thang(2)", }),
															6 : ({ TASK_23,20,21,TID_MAOSHAN,"Linh hồn lang thang(7)", }),
													]),
														"Vân Mộng Cốc" : ([
															3:({ TASK_45,29,30,TID_YUNMENZE,"Theo y tế (5)", }),
														]),
]);

mapping mpTaskList1 = ([
	"Sở Quốc":([
		11:({ TASK_07,25,26,27,TID_CHUGUO,"Ba lông","Ba lông(Hoàn thành)" }),
			13 : ({ TASK_08,1,2,3,TID_CHUGUO,"Quần áo bảo vệ","Quần áo bảo vệ(Hoàn thành)" }),
			14 : ({ TASK_08,4,5,6,TID_CHUGUO,"Mảnh ghép thung lũng","Mảnh ghép thung lũng(Hoàn thành)" }),
			15 : ({ TASK_08,7,8,9,TID_CHUGUO,"Truy tìm kho báu đầm lầy","Truy tìm kho báu đầm lầy(Hoàn thành)" }),
			16 : ({ TASK_08,10,11,12,TID_CHUGUO,"Đầm lầy","Đầm lầy(Hoàn thành)" }),
			17 : ({ TASK_08,13,14,15,TID_CHUGUO,"Thiên thanh niên trên hồ","Thiên thanh niên trên hồ(Hoàn thành)" }),
			18 : ({ TASK_08,16,17,18,TID_CHUGUO,"Hào Quang Kim Long","Hào Quang Kim Long(Hoàn thành)" }),
			19 : ({ TASK_08,19,20,21,TID_CHUGUO,"Lạc lối","Lạc lối(Hoàn thành)" }),
			20 : ({ TASK_08,22,23,24,TID_CHUGUO,"Câu thần chú của Đường Cangwu","Câu thần chú của Đường Cangwu(Hoàn thành)" }),
			21 : ({ TASK_08,25,26,27,TID_CHUGUO,"Lửa ma trong dung nham","Lửa ma trong dung nham(Hoàn thành)" }),
			22 : ({ TASK_08,28,29,30,TID_CHUGUO,"Kho báu ở thung lũng","Kho báu ở thung lũng(Hoàn thành)" }),
			23 : ({ TASK_09,1,2,3,TID_CHUGUO,"Tiếng kêu dưới chân núi","Tiếng kêu dưới chân núi(Hoàn thành)" }),
			24 : ({ TASK_09,4,5,6,TID_CHUGUO,"Vụ án đang chờ xử lý ở làng","Vụ án đang chờ xử lý ở làng(Hoàn thành)" }),
			25 : ({ TASK_09,7,8,9,TID_CHUGUO,"Bí mật của Châu Phi","Bí mật của Châu Phi(Hoàn thành)" }),
			26 : ({ TASK_09,10,11,12,TID_CHUGUO,"Máu ở làng","Máu ở làng(Hoàn thành)" }),
			27 : ({ TASK_09,13,14,15,TID_CHUGUO,"Những gì còn lại","Những gì còn lại(Hoàn thành)" }),
			28 : ({ TASK_09,16,17,18,TID_CHUGUO,"Cháy rừng trên đường núi","Cháy rừng trên đường núi(Hoàn thành)" }),
			29 : ({ TASK_24,9,10,11,TID_CHUGUO,"Trà Jasmine(2)","Trà Jasmine(2)(Hoàn thành)" }),
			30 : ({ TASK_24,12,13,14,TID_CHUGUO,"Trà Jasmine(3)","Trà Jasmine(3)(Hoàn thành)" }),
			33 : ({ TASK_33,1,2,3,TID_CHUGUO,"Di sản của ông(3)","Di sản của ông(3)(Hoàn thành)" }),
			34 : ({ TASK_33,4,5,6,TID_CHUGUO,"Di sản của ông(4)","Di sản của ông(4)(Hoàn thành)" }),
			35 : ({ TASK_33,7,8,9,TID_CHUGUO,"Cơ thể bận rộn","Cơ thể bận rộn(Hoàn thành)" }),
			36 : ({ TASK_33,10,11,12,TID_CHUGUO,"Trà Quan Vũ","Trà Quan Vũ(Hoàn thành)" }),
			37 : ({ TASK_33,13,14,15,TID_CHUGUO,"Hoa hồng","Hoa hồng(Hoàn thành)" }),
			38 : ({ TASK_33,16,17,18,TID_CHUGUO,"Trừng phạt Lương Thiệu","Trừng phạt Lương Thiệu(Hoàn thành)" }),
			39 : ({ TASK_33,19,20,21,TID_CHUGUO,"Giữ khoảng cách","Giữ khoảng cách(Hoàn thành)" }),
			40 : ({ TASK_33,22,23,24,TID_CHUGUO,"Từ thực phẩm","Từ thực phẩm(Hoàn thành)" }),
			41 : ({ TASK_45,15,16,17,TID_CHUGUO,"Được mọi người ngưỡng mộ","Được mọi người ngưỡng mộ(Hoàn thành)" }),
	]),
		"Hàn Quốc": ([
			1:({ TASK_04,1,2,3,TID_HANGUO,"Kho bạc bị đánh cắp","Kho bạc bị đánh cắp(Hoàn thành)" }),
				2 : ({ TASK_04,4,5,6,TID_HANGUO,"Những rắc rối của Cán bộ Nội vụ","Những rắc rối của Cán bộ Nội vụ(Hoàn thành)" }),
				11 : ({ TASK_04,23,24,25,TID_HANGUO,"Trừ gian diệt ác","Trừ gian diệt ác(Hoàn thành)" }),
				12 : ({ TASK_04,26,27,28,TID_HANGUO,"Truy bắt tội phạm","Truy bắt tội phạm(Hoàn thành)" }),
				13 : ({ TASK_05,1,2,3,TID_HANGUO,"Giải cứu công tượng","Giải cứu công tượng(Hoàn thành)" }),
				14 : ({ TASK_05,4,5,6,TID_HANGUO,"Bộ luật hình sự","Bộ luật hình sự(Hoàn thành)" }),
				17 : ({ TASK_25,6,7,8,TID_HANGUO,"Xóa bỏ mối đe dọa","Xóa bỏ mối đe dọa(Hoàn thành)" }),
				19 : ({ TASK_25,11,12,13,TID_HANGUO,"Chứng minh bản thân","Chứng minh bản thân(Hoàn thành)" }),
				20 : ({ TASK_25,14,15,16,TID_HANGUO,"Tìm hiểu bí ẩn của kho báu","Tìm hiểu bí ẩn của kho báu(Hoàn thành)" }),
				22 : ({ TASK_25,19,20,21,TID_HANGUO,"Thử thách bản thân","Thử thách bản thân(Hoàn thành)" }),
				23 : ({ TASK_25,22,23,24,TID_HANGUO,"Loại bỏ những kẻ phản bội","Loại bỏ những kẻ phản bội(Hoàn thành)" }),
				30 : ({ TASK_26,7,8,9,TID_HANGUO,"Bài kiểm tra cuối cùng","Bài kiểm tra cuối cùng(Hoàn thành)" }),
				33 : ({ TASK_26,14,15,16,TID_HANGUO,"Kiểm tra sức mạnh","Kiểm tra sức mạnh(Hoàn thành)" }),
				34 : ({ TASK_26,17,18,19,TID_HANGUO,"Loại bỏ cái ác cho nhân dân","Loại bỏ cái ác cho nhân dân(Hoàn thành)" }),
				38 : ({ TASK_26,26,27,28,TID_HANGUO,"Tìm một cách","Tìm một cách(Hoàn thành)" }),
				39 : ({ TASK_27,1,2,3,TID_HANGUO,"Ngăn rò rỉ","Ngăn rò rỉ(Hoàn thành)" }),
				41 : ({ TASK_22,21,22,23,TID_HANGUO,"Gia vị nấu cá","Gia vị nấu cá(Hoàn thành)" }),
				42 : ({ TASK_22,24,25,26,TID_HANGUO,"Mồi câu vàng","Mồi câu vàng(Hoàn thành)" }),
				43 : ({ TASK_22,27,28,29,TID_HANGUO,"Ma da","Ma da(Hoàn thành)" }),
				44 : ({ TASK_23,1,2,3,TID_HANGUO,"Thảm họa rò rỉ","Thảm họa rò rỉ(Hoàn thành)" }),
				46 : ({ TASK_23,22,23,24,TID_HANGUO,"Tình yêu(1)","Tình yêu(1)(Hoàn thành)" }),
				101 : ({ TASK_2_01,7,8,9,TID_HANGUO,"Tìm kiếm họ hàng xa","Tìm kiếm họ hàng xa(Hoàn thành)" }),
		]),
			"Ngụy Quốc": ([
				1:({ TASK_06,22,23,24,TID_WEIGUO,"Sợi tóc","Sợi tóc(Hoàn thành)" }),
					2 : ({ TASK_06,25,26,27,TID_WEIGUO,"Bọn trộm","Bọn trộm(Hoàn thành)" }),
					3 : ({ TASK_06,28,29,30,TID_WEIGUO,"Trộm gà","Trộm gà(Hoàn thành)" }),
					4 : ({ TASK_07,1,2,3,TID_WEIGUO,"Rượu cho Lão Đinh","Rượu cho Lão Đinh(Hoàn thành)" }),
					6 : ({ TASK_07,6,7,8,TID_WEIGUO,"Hoa mẫu đơn","Hoa mẫu đơn(Hoàn thành)" }),
					7 : ({ TASK_07,10,11,12,TID_WEIGUO,"Giấc mơ","Giấc mơ(Hoàn thành)" }),
					8 : ({ TASK_07,13,14,15,TID_WEIGUO,"Thảm họa của Ngụy quản gia(1)","Thảm họa của Ngụy quản gia(1)(Hoàn thành)" }),
					9 : ({ TASK_07,16,17,18,TID_WEIGUO,"Thảm họa của Ngụy quản gia(2)","Thảm họa của Ngụy quản gia(2)(Hoàn thành)" }),
					10 : ({ TASK_07,19,20,21,TID_WEIGUO,"Thảm họa của Ngụy quản gia(3)","Thảm họa của Ngụy quản gia(3)(Hoàn thành)" }),
					11 : ({ TASK_05,10,11,12,TID_WEIGUO,"Đường mòn","Đường mòn(Hoàn thành)" }),
					12 : ({ TASK_05,13,14,15,TID_WEIGUO,"Huyền thoại bí ẩn","Huyền thoại bí ẩn(Hoàn thành)" }),
					13 : ({ TASK_05,7,8,9,TID_WEIGUO,"Đi vênh vang","Đi vênh vang(Hoàn thành)" }),
					14 : ({ TASK_05,16,17,18,TID_WEIGUO,"Tính khí anh hùng","Tính khí anh hùng(Hoàn thành)" }),
					15 : ({ TASK_05,19,20,21,TID_WEIGUO,"Giấc mơ thợ may","Giấc mơ thợ may(Hoàn thành)" }),
					16 : ({ TASK_05,22,23,24,TID_WEIGUO,"Kiếm Hồn","Kiếm Hồn(Hoàn thành)" }),
					17 : ({ TASK_05,25,26,27,TID_WEIGUO,"Quên lời thề","Quên lời thề(Hoàn thành)" }),
					18 : ({ TASK_05,28,29,30,TID_WEIGUO,"Tin đồn kho báu","Tin đồn kho báu(Hoàn thành)" }),
					19 : ({ TASK_06,1,2,3,TID_WEIGUO,"Linh hồn khóc","Linh hồn khóc(Hoàn thành)" }),
					20 : ({ TASK_06,4,5,6,TID_WEIGUO,"Tên cướp kiêu ngạo","Tên cướp kiêu ngạo(Hoàn thành)" }),
					21 : ({ TASK_06,7,8,9,TID_WEIGUO,"Giấc mơ anh hùng","Giấc mơ anh hùng(Hoàn thành)" }),
					22 : ({ TASK_06,10,11,12,TID_WEIGUO,"Giấc mơ xa","Giấc mơ xa(Hoàn thành)" }),
					23 : ({ TASK_06,13,14,15,TID_WEIGUO,"Huyền thoại về hươu khổng lồ","Huyền thoại về hươu khổng lồ(Hoàn thành)" }),
					24 : ({ TASK_06,16,17,18,TID_WEIGUO,"Tiếng vọng trong thung lũng","Tiếng vọng trong thung lũng(Hoàn thành)" }),
					25 : ({ TASK_06,19,20,21,TID_WEIGUO,"Sự báo oán của các vị thần","Sự báo oán của các vị thần(Hoàn thành)" }),
					26 : ({ TASK_07,22,23,24,TID_WEIGUO,"Bữa tối cầu kỳ","Bữa tối cầu kỳ(Hoàn thành)" }),
					27 : ({ TASK_19,3,4,5,TID_WEIGUO,"Quả bầu lớn(2)","Quả bầu lớn(2)(Hoàn thành)" }),
					29 : ({ TASK_24,1,2,3,TID_WEIGUO,"Tình yêu(4)","Tình yêu(4)(Hoàn thành)" }),
					30 : ({ TASK_28,23,24,25,TID_WEIGUO,"Ngọc ở mộ cổ","Ngọc ở mộ cổ(Hoàn thành)" }),
					31 : ({ TASK_29,4,5,6,TID_WEIGUO,"Cứu mọi người khỏi nguy hiểm","Cứu mọi người khỏi nguy hiểm(Hoàn thành)" }),
					32 : ({ TASK_29,7,8,9,TID_WEIGUO,"Sư tử đá","Sư tử đá(Hoàn thành)" }),
					33 : ({ TASK_29,10,11,12,TID_WEIGUO,"Điều kiện của bọn bắt cóc","Điều kiện của bọn bắt cóc(Hoàn thành)" }),
					34 : ({ TASK_29,13,14,15,TID_WEIGUO,"Điều kiện để làm bảo vệ","Điều kiện để làm bảo vệ(Hoàn thành)" }),
					35 : ({ TASK_31,13,14,15,TID_WEIGUO,"Truy nã","Truy nã(Hoàn thành)" }),
					38 : ({ TASK_33,27,28,29,TID_WEIGUO,"Bằng chứng sức mạnh","Bằng chứng sức mạnh(Hoàn thành)" }),
					39 : ({ TASK_34,1,2,3,TID_WEIGUO,"Chấp nhận yêu cầu","Chấp nhận yêu cầu(Hoàn thành)" }),
					40 : ({ TASK_34,4,5,6,TID_WEIGUO,"Kinh Nghiệm Tìm Báu Vật","Kinh Nghiệm Tìm Báu Vật (Hoàn thành)" }),
					43 : ({ TASK_34,11,12,13,TID_WEIGUO,"Chứng minh bản thân","Chứng minh bản thân(Hoàn thành)" }),
					44 : ({ TASK_34,14,15,16,TID_WEIGUO,"Loại bỏ tên dối trá","Loại bỏ tên dối trá(Hoàn thành)" }),
					49 : ({ TASK_34,25,26,27,TID_WEIGUO,"Con đường của hôn nhân 3","Con đường của hôn nhân 3(Hoàn thành)" }),
					50 : ({ TASK_34,28,29,30,TID_WEIGUO,"Con đường của hôn nhân 4","Con đường của hôn nhân 4(Hoàn thành)" }),
					54 : ({ TASK_35,7,8,9,TID_WEIGUO,"Thử kỹ năng của bạn","Thử kỹ năng của bạn(Hoàn thành)" }),
					55 : ({ TASK_35,10,11,12,TID_WEIGUO,"Đuổi theo bọn cướp","Đuổi theo bọn cướp(Hoàn thành)" }),
					58 : ({ TASK_35,17,18,19,TID_WEIGUO,"Dũng cảm đột nhập vào hang động","Dũng cảm đột nhập vào hang động(Hoàn thành)" }),
					59 : ({ TASK_35,20,21,22,TID_WEIGUO,"Giải quyết nguồn gốc của thảm họa","Giải quyết nguồn gốc của thảm họa(Hoàn thành)" }),
					62 : ({ TASK_44,4,5,6,TID_WEIGUO,"Giường đẹp(1)","Giường đẹp(1)(Hoàn thành)" }),
					63 : ({ TASK_44,7,8,9,TID_WEIGUO,"Giường đẹp(2)","Giường đẹp(2)(Hoàn thành)" }),
					64 : ({ TASK_44,10,11,12,TID_WEIGUO,"Giường đẹp(3)","Giường đẹp(3)(Hoàn thành)" }),
			]),
				"Tề Quốc": ([
					3:({ TASK_09,23,24,25,TID_QIGUO,"Môi hở và răng lạnh(3)","Môi hở và răng lạnh(3)(Hoàn thành)" }),
						5 : ({ TASK_09,28,29,30,TID_QIGUO,"Hình phạt cho gian lận","Hình phạt cho gian lận(Hoàn thành)" }),
						6 : ({ TASK_13,16,17,18,TID_QIGUO,"Gian Tế Sơn Nhung Tộc (1)","Gian Tế Sơn Nhung Tộc (1)(Hoàn thành)" }),
						7 : ({ TASK_13,19,20,21,TID_QIGUO,"Gởi quốc tịch(2)","Gởi quốc tịch(2)(Hoàn thành)" }),
						9 : ({ TASK_10,3,4,5,TID_QIGUO,"Yêu cầu rau quả(1)","Yêu cầu rau quả(1)(Hoàn thành)" }),
						11 : ({ TASK_10,8,9,10,TID_QIGUO,"Bị mất đồ","Bị mất đồ(Hoàn thành)" }),
						12 : ({ TASK_10,11,12,13,TID_QIGUO,"Kinh nghiệm kinh doanh","Kinh nghiệm kinh doanh(Hoàn thành)" }),
						14 : ({ TASK_24,4,5,6,TID_QIGUO,"Ác ma trong lọ","Ác ma trong lọ(Hoàn thành)" }),
						16 : ({ TASK_24,17,18,19,TID_QIGUO,"Tìm kiếm con dấu chính thức","Tìm kiếm con dấu chính thức(Hoàn thành)" }),
						17 : ({ TASK_24,20,21,22,TID_QIGUO,"Chết tiệt","Chết tiệt(Hoàn thành)" }),
						18 : ({ TASK_24,23,24,25,TID_QIGUO,"Chuẩn bị","Chuẩn bị(Hoàn thành)" }),
						19 : ({ TASK_24,26,27,28,TID_QIGUO,"Khám phá khủng khiếp","Khám phá khủng khiếp(Hoàn thành)" }),
						20 : ({ TASK_25,1,2,3,TID_QIGUO,"Đòn quyết định","Đòn quyết định(Hoàn thành)" }),
						21 : ({ TASK_27,4,5,6,TID_QIGUO,"Bảo vệ người chết","Bảo vệ người chết(Hoàn thành)" }),
						22 : ({ TASK_27,19,20,21,TID_QIGUO,"Tham quan hang động","Tham quan hang động(Hoàn thành)" }),
						23 : ({ TASK_27,22,23,24,TID_QIGUO,"Bảo vệ hối hận","Bảo vệ hối hận(Hoàn thành)" }),
						24 : ({ TASK_27,25,26,27,TID_QIGUO,"Chờ và xem","Chờ và xem(Hoàn thành)" }),
						27 : ({ TASK_29,18,19,20,TID_QIGUO,"Làm bài kiểm tra","Làm bài kiểm tra(Hoàn thành)" }),
						29 : ({ TASK_29,23,24,25,TID_QIGUO,"Tìm kiếm kho báu","Tìm kiếm kho báu(Hoàn thành)" }),
						33 : ({ TASK_29,28,29,30,TID_QIGUO,"Tự kiểm tra","Tự kiểm tra(Hoàn thành)" }),
						34 : ({ TASK_30,5,6,7,TID_QIGUO,"Mất và phục hồi","Mất và phục hồi(Hoàn thành)" }),
						37 : ({ TASK_30,12,13,14,TID_QIGUO,"Xác định đối thủ","Xác định đối thủ(Hoàn thành)" }),
						38 : ({ TASK_30,15,16,17,TID_QIGUO,"Diệt trừ cái ác","Diệt trừ cái ác(Hoàn thành)" }),
						42 : ({ TASK_30,24,25,26,TID_QIGUO,"Đơn độc trong mộ cổ","Đơn độc trong mộ cổ(Hoàn thành)" }),
						43 : ({ TASK_30,27,28,29,TID_QIGUO,"Tống khứ bọn cướp đi","Tống khứ bọn cướp đi(Hoàn thành)" }),
						46 : ({ TASK_31,3,4,5,TID_QIGUO,"Nghi ngờ","Nghi ngờ(Hoàn thành)" }),
						47 : ({ TASK_31,6,7,8,TID_QIGUO,"Thoát khỏi kẻ bắt nạt","Thoát khỏi kẻ bắt nạt(Hoàn thành)" }),
						50 : ({ TASK_35,27,28,29,TID_QIGUO,"Ác ma trong lọ Tiên trong nồi","Ác ma trong lọ Tiên trong nồi(Hoàn thành)" }),
						51 : ({ TASK_36,3,4,5,TID_QIGUO,"Viên ngọc hoàn hảo (2)","Viên ngọc hoàn hảo (2)(Hoàn thành)" }),
						52 : ({ TASK_36,6,7,8,TID_QIGUO,"Viên ngọc hoàn hảo (3)","Viên ngọc hoàn hảo (3)(Hoàn thành)" }),
						53 : ({ TASK_36,11,12,13,TID_QIGUO,"Không sợ","Không sợ(Hoàn thành)" }),
						54 : ({ TASK_36,14,15,16,TID_QIGUO,"Bệnh dịch","Bệnh dịch(Hoàn thành)" }),
						55 : ({ TASK_36,17,18,19,TID_QIGUO,"Niết bàn","Niết bàn(Hoàn thành)" }),
						56 : ({ TASK_36,20,21,22,TID_QIGUO,"Cuộc thám hiểm","Cuộc thám hiểm(Hoàn thành)" }),
						57 : ({ TASK_36,23,24,25,TID_QIGUO,"Kẻ phản bội","Kẻ phản bội(Hoàn thành)" }),
						58 : ({ TASK_36,26,27,28,TID_QIGUO,"Nổi loạn của Kỳ","Nổi loạn của Kỳ(Hoàn thành)" }),
						59 : ({ TASK_37,1,2,3,TID_QIGUO,"Đột phá hệ tầng Thiên Môn","Đột phá hệ tầng Thiên Môn(Hoàn thành)" }),
						60 : ({ TASK_37,4,5,6,TID_QIGUO,"Tiểu Đồ(1)","Tiểu Đồ(1)(Hoàn thành)" }),
						62 : ({ TASK_39,25,26,27,TID_QIGUO,"Bị bao vây ở mọi phía(2)","Bị bao vây ở mọi phía(2)(Hoàn thành)" }),
						64 : ({ TASK_44,13,14,15,TID_QIGUO,"Tư vấn nhiệt tình(1)","Tư vấn nhiệt tình(1)(Hoàn thành)" }),
						66 : ({ TASK_44,24,25,26,TID_QIGUO,"Ấm và lạnh(1)","Ấm và lạnh(1)(Hoàn thành)" }),
						67 : ({ TASK_44,27,28,29,TID_QIGUO,"Ấm và lạnh(2)","Ấm và lạnh(2)(Hoàn thành)" }),
						68 : ({ TASK_45,1,2,3,TID_QIGUO,"Ấm và lạnh(3)","Ấm và lạnh(3)(Hoàn thành)" }),
						69 : ({ TASK_45,7,8,9,TID_QIGUO,"Vinh quang tối cao(1)","Vinh quang tối cao(1)(Hoàn thành)" }),
						70 : ({ TASK_45,10,11,12,TID_QIGUO,"Vinh quang tối cao(2)","Vinh quang tối cao(2)(Hoàn thành)" }),
						103 : ({ TASK_2_00,7,8,9,TID_QIGUO,"Hồn ma","Hồn ma(Hoàn thành)" }),
				]),
					"Tần Quốc": ([
						1:({ TASK_10,20,21,22,TID_QINGUO,"Chạy trốn","Chạy trốn(Hoàn thành)" }),
							2 : ({ TASK_10,23,24,25,TID_QINGUO,"Cuộc nổi dậy của lao động khổ sai","Cuộc nổi dậy của lao động khổ sai(Hoàn thành)" }),
							3 : ({ TASK_11,1,2,3,TID_QINGUO,"Cung điện Tần(1)","Cung điện Tần(1)(Hoàn thành)" }),
							5 : ({ TASK_11,6,7,8,TID_QINGUO,"Cung điện Tần(3)","Cung điện Tần(3)(Hoàn thành)" }),
							7 : ({ TASK_11,11,12,13,TID_QINGUO,"Đá ma thuật","Đá ma thuật(Hoàn thành)" }),
							11 : ({ TASK_18,16,17,18,TID_QINGUO,"Hiện sức mạnh đi(1)","Hiện sức mạnh đi(1)(Hoàn thành)" }),
							14 : ({ TASK_18,22,23,24,TID_QINGUO,"Hiện sức mạnh đi(4)","Hiện sức mạnh đi(4)(Hoàn thành)" }),
							15 : ({ TASK_18,25,26,27,TID_QINGUO,"Hiện sức mạnh đi(5)","Hiện sức mạnh đi(5)(Hoàn thành)" }),
							16 : ({ TASK_10,14,15,16,TID_QINGUO,"Kế hoạch săn bắn","Kế hoạch săn bắn(Hoàn thành)" }),
							17 : ({ TASK_10,17,18,19,TID_QINGUO,"Tìm kiếm công thức nấu ăn","Tìm kiếm công thức nấu ăn(Hoàn thành)" }),
							18 : ({ TASK_19,7,8,9,TID_QINGUO,"Quả bầu lớn(4)","Quả bầu lớn(4)(Hoàn thành)" }),
							19 : ({ TASK_19,10,11,12,TID_QINGUO,"Quả bầu lớn(5)","Quả bầu lớn(5)(Hoàn thành)" }),
							20 : ({ TASK_19,13,14,15,TID_QINGUO,"Kẻ phản bội","Kẻ phản bội(Hoàn thành)" }),
							21 : ({ TASK_19,19,20,21,TID_QINGUO,"Truy bắt đào phạm","Truy bắt đào phạm(Hoàn thành)" }),
							24 : ({ TASK_20,21,22,23,TID_QINGUO,"Bản vẽ cung điện","Bản vẽ cung điện(Hoàn thành)" }),
							25 : ({ TASK_20,24,25,26,TID_QINGUO,"Gỗ gụ thiên niên kỷ","Gỗ gụ thiên niên kỷ(Hoàn thành)" }),
							26 : ({ TASK_20,27,28,29,TID_QINGUO,"Tránh đường!","Tránh đường!(Hoàn thành)" }),
							29 : ({ TASK_21,5,6,7,TID_QINGUO,"Khó xây dựng","Khó xây dựng(Hoàn thành)" }),
							31 : ({ TASK_21,10,11,12,TID_QINGUO,"Loại bỏ những kẻ bắt nạt","Loại bỏ những kẻ bắt nạt(Hoàn thành)" }),
							34 : ({ TASK_21,17,18,19,TID_QINGUO,"Khó khăn","Khó khăn(Hoàn thành)" }),
							39 : ({ TASK_21,28,29,30,TID_QINGUO,"Vu khống","Vu khống(Hoàn thành)" }),
							42 : ({ TASK_22,5,6,7,TID_QINGUO,"Sự thật được tiết lộ","Sự thật được tiết lộ(Hoàn thành)" }),
							44 : ({ TASK_22,10,11,12,TID_QINGUO,"Xác nhận tin đồn","Xác nhận tin đồn(Hoàn thành)" }),
							45 : ({ TASK_22,13,14,15,TID_QINGUO,"Hàm ý tội ác","Hàm ý tội ác(Hoàn thành)" }),
							47 : ({ TASK_22,18,19,20,TID_QINGUO,"Khó khăn khi viết","Khó khăn khi viết(Hoàn thành)" }),
							48 : ({ TASK_20,4,5,6,TID_QINGUO,"Sát nhân","Sát nhân(Hoàn thành)" }),
							49 : ({ TASK_20,7,8,9,TID_QINGUO,"Rượu vang","Rượu vang(Hoàn thành)" }),
							50 : ({ TASK_20,10,11,12,TID_QINGUO,"Lễ hội đôi lần thứ 9(1)","Lễ hội đôi lần thứ 9(1)(Hoàn thành)" }),
							53 : ({ TASK_20,16,17,18,TID_QINGUO,"Lễ hội đôi lần thứ 9(4)","Lễ hội đôi lần thứ 9(4)(Hoàn thành)" }),
							55 : ({ TASK_39,11,12,13,TID_QINGUO,"Kiểm soát số lượng","Kiểm soát số lượng(Hoàn thành)" }),
							56 : ({ TASK_39,14,15,16,TID_QINGUO,"Điểm mấu chốt(1)","Điểm mấu chốt(1)(Hoàn thành)" }),
							57 : ({ TASK_39,17,18,19,TID_QINGUO,"Điểm mấu chốt(2)","Điểm mấu chốt(2)(Hoàn thành)" }),
							58 : ({ TASK_39,20,21,22,TID_QINGUO,"Điểm mấu chốt(3)","Điểm mấu chốt(3)(Hoàn thành)" }),
							59 : ({ TASK_43,17,18,19,TID_QINGUO,"Sự giúp đỡ của bạn bè","Sự giúp đỡ của bạn bè(Hoàn thành)" }),
							60 : ({ TASK_43,23,24,25,TID_QINGUO,"Bóng tối trước bình minh","Bóng tối trước bình minh(Hoàn thành)" }),
							61 : ({ TASK_44,18,19,20,TID_QINGUO,"Tư vấn nhiệt tình(3)","Tư vấn nhiệt tình(3)(Hoàn thành)" }),
							62 : ({ TASK_44,21,22,23,TID_QINGUO,"Tư vấn nhiệt tình(4)","Tư vấn nhiệt tình(4)(Hoàn thành)" }),
							63 : ({ TASK_45,4,5,6,TID_QINGUO,"Đông cứng","Đông cứng(Hoàn thành)" }),
							65 : ({ TASK_46,3,4,5,TID_QINGUO,"Huyền thoại linh hồn của thanh kiếm 2","Huyền thoại linh hồn của thanh kiếm 2(Hoàn thành)" }),
							67 : ({ TASK_46,8,9,10,TID_QINGUO,"Huyền thoại linh hồn của thanh kiếm 4","Huyền thoại linh hồn của thanh kiếm 4(Hoàn thành)" }),
							70 : ({ TASK_46,15,16,17,TID_QINGUO,"Hỗn loạn 2","Hỗn loạn 2(Hoàn thành)" }),
							71 : ({ TASK_46,18,19,20,TID_QINGUO,"Hỗn loạn 3","Hỗn loạn 3(Hoàn thành)" }),
							72 : ({ TASK_46,21,22,23,TID_QINGUO,"Hỗn loạn 4","Hỗn loạn 4(Hoàn thành)" }),
							75 : ({ TASK_46,28,29,30,TID_QINGUO,"Con đường y dược2","Con đường y dược2(Hoàn thành)" }),
							77 : ({ TASK_47,3,4,5,TID_QINGUO,"Con đường y dược4","Con đường y dược4(Hoàn thành)" }),
							81 : ({ TASK_47,12,13,14,TID_QINGUO,"Xua tan tin đồn3","Xua tan tin đồn3(Hoàn thành)" }),
							86 : ({ TASK_47,23,24,25,TID_QINGUO,"Hãy hỏi kiếm 3","Hãy hỏi kiếm 3(Hoàn thành)" }),
							87 : ({ TASK_47,26,27,28,TID_QINGUO,"Hãy hỏi kiếm 4","Hãy hỏi kiếm 4(Hoàn thành)" }),
							101 : ({ TASK_2_00,1,2,3,TID_QINGUO,"Tiêu diệt lực lượng nổi loạn","Tiêu diệt lực lượng nổi loạn(Hoàn thành)" }),
							102 : ({ TASK_2_00,28,29,30,TID_QINGUO,"Phá hoại","Phá hoại(Hoàn thành)" }),
							103 : ({ TASK_2_01,1,2,3,TID_QINGUO,"Sự trở lại của linh hồn","Sự trở lại của linh hồn(Hoàn thành)" }),
					]),
						"Yên Quốc": ([
							1:({ TASK_12,1,2,3,TID_YANGUO,"Ngọn gió của...","Ngọn gió của...(Hoàn thành)" }),
								2 : ({ TASK_12,4,5,6,TID_YANGUO,"Tĩnh lặng như nước","Tĩnh lặng như nước(Hoàn thành)" }),
								3 : ({ TASK_12,7,8,9,TID_YANGUO,"Huyền thoại dòng sông","Huyền thoại dòng sông(Hoàn thành)" }),
								4 : ({ TASK_12,10,11,12,TID_YANGUO,"Dòng sông lớn","Dòng sông lớn(Hoàn thành)" }),
								5 : ({ TASK_12,13,14,15,TID_YANGUO,"Những rắc rối","Những rắc rối(Hoàn thành)" }),
								6 : ({ TASK_12,16,17,18,TID_YANGUO,"Giai thoại trong giấc mơ","Giai thoại trong giấc mơ(Hoàn thành)" }),
								7 : ({ TASK_12,19,20,21,TID_YANGUO,"Khóc ở nước Trịnh","Khóc ở nước Trịnh(Hoàn thành)" }),
								8 : ({ TASK_12,22,23,24,TID_YANGUO,"Thần sông","Thần sông(Hoàn thành)" }),
								9 : ({ TASK_12,25,26,27,TID_YANGUO,"Linh hồn của dòng sông","Linh hồn của dòng sông(Hoàn thành)" }),
								10 : ({ TASK_12,28,29,30,TID_YANGUO,"Các ý kiến ​​khác nhau","Các ý kiến ​​khác nhau(Hoàn thành)" }),
								11 : ({ TASK_13,1,2,3,TID_YANGUO,"Bận tâm","Bận tâm(Hoàn thành)" }),
								12 : ({ TASK_13,4,5,6,TID_YANGUO,"Truyền thuyết về lụa lạnh","Truyền thuyết về lụa lạnh(Hoàn thành)" }),
								13 : ({ TASK_13,7,8,9,TID_YANGUO,"Lời tiên tri khủng khiếp","Lời tiên tri khủng khiếp(Hoàn thành)" }),
								14 : ({ TASK_13,10,11,12,TID_YANGUO,"Huyền thoại về gương","Huyền thoại về gương(Hoàn thành)" }),
								15 : ({ TASK_13,13,14,15,TID_YANGUO,"Người lính vô song","Người lính vô song(Hoàn thành)" }),
								16 : ({ TASK_10,26,27,28,TID_YANGUO,"Ngàn năm","Ngàn năm(Hoàn thành)" }),
								18 : ({ TASK_11,24,25,26,TID_YANGUO,"Thử thách","Thử thách(Hoàn thành)" }),
								19 : ({ TASK_11,27,28,29,TID_YANGUO,"Viên đá","Viên đá(Hoàn thành)" }),
								20 : ({ TASK_13,22,23,24,TID_YANGUO,"Tượng bùn","Tượng bùn(Hoàn thành)" }),
								21 : ({ TASK_13,25,26,27,TID_YANGUO,"Sở thích","Sở thích(Hoàn thành)" }),
								22 : ({ TASK_13,28,29,30,TID_YANGUO,"Nguy hiểm tìm ẩn","Nguy hiểm tìm ẩn(Hoàn thành)" }),
								23 : ({ TASK_14,1,2,3,TID_YANGUO,"Trả thù","Trả thù(Hoàn thành)" }),
								24 : ({ TASK_14,4,5,6,TID_YANGUO,"Bảo thạch quý hiếm","Bảo thạch quý hiếm(Hoàn thành)" }),
								25 : ({ TASK_14,7,8,9,TID_YANGUO,"Hỗn Thiên Nghi(1)","Hỗn Thiên Nghi(1)(Hoàn thành)" }),
								26 : ({ TASK_14,10,11,12,TID_YANGUO,"Hỗn Thiên Nghi(2)","Hỗn Thiên Nghi(2)(Hoàn thành)" }),
								28 : ({ TASK_14,15,16,17,TID_YANGUO,"Đàn nhị","Đàn nhị(Hoàn thành)" }),
								29 : ({ TASK_14,18,19,20,TID_YANGUO,"Con gấu ngu ngốc","Con gấu ngu ngốc(Hoàn thành)" }),
								31 : ({ TASK_15,9,10,11,TID_YANGUO,"Căn bệnh của Phu Nhân(2)","Căn bệnh của Phu Nhân(2)(Hoàn thành)" }),
								32 : ({ TASK_15,12,13,14,TID_YANGUO,"Căn bệnh của Phu Nhân(3)","Căn bệnh của Phu Nhân(3)(Hoàn thành)" }),
								33 : ({ TASK_15,15,16,17,TID_YANGUO,"Cửa hàng trang sức","Cửa hàng trang sức(Hoàn thành)" }),
								34 : ({ TASK_15,18,19,20,TID_YANGUO,"Người giàu có","Người giàu có(Hoàn thành)" }),
								36 : ({ TASK_16,11,12,13,TID_YANGUO,"Với sự trừng phạt","Với sự trừng phạt(Hoàn thành)" }),
								37 : ({ TASK_27,12,13,14,TID_YANGUO,"Yên vương là báu vật(2)","Yên vương là báu vật(2)(Hoàn thành)" }),
								39 : ({ TASK_31,18,19,20,TID_YANGUO,"Quái vật","Quái vật(Hoàn thành)" }),
								39 : ({ TASK_31,18,19,20,TID_YANGUO,"Bí mật(2)","Bí mật(2)(Hoàn thành)" }),
								40 : ({ TASK_31,21,22,23,TID_YANGUO,"Bí mật(3)","Bí mật(3)(Hoàn thành)" }),
								41 : ({ TASK_31,24,25,26,TID_YANGUO,"Bí mật(4)","Bí mật(4)(Hoàn thành)" }),
								42 : ({ TASK_31,27,28,29,TID_YANGUO,"Hỗ trợ","Hỗ trợ(Hoàn thành)" }),
								43 : ({ TASK_32,1,2,3,TID_YANGUO,"Dao đơn","Dao đơn(Hoàn thành)" }),
								44 : ({ TASK_32,11,12,13,TID_YANGUO,"Xóa bỏ linh hồn","Xóa bỏ linh hồn(Hoàn thành)" }),
								45 : ({ TASK_32,14,15,16,TID_YANGUO,"Thu thập táo tàu","Thu thập táo tàu(Hoàn thành)" }),
								46 : ({ TASK_32,17,18,19,TID_YANGUO,"Sức mạnh của trụy lạc","Sức mạnh của trụy lạc(Hoàn thành)" }),
								47 : ({ TASK_32,20,21,22,TID_YANGUO,"Nguồn gốc của tội lỗi","Nguồn gốc của tội lỗi(Hoàn thành)" }),
								48 : ({ TASK_32,23,24,25,TID_YANGUO,"Giết nó","Giết nó(Hoàn thành)" }),
								49 : ({ TASK_32,26,27,28,TID_YANGUO,"Di sản của ông(1)","Di sản của ông(1)(Hoàn thành)" }),
								50 : ({ TASK_43,20,21,22,TID_YANGUO,"Nguồn cung cấp doanh trại","Nguồn cung cấp doanh trại(Hoàn thành)" }),
								51 : ({ TASK_44,1,2,3,TID_YANGUO,"Bóng tối bao trùm chúng ta","Bóng tối bao trùm chúng ta(Hoàn thành)" }),
								53 : ({ TASK_32,6,7,8,TID_YANGUO,"Việc vặt(2)","Việc vặt(2)(Hoàn thành)" }),
						]),
							"Triệu Quốc": ([
								1:({ TASK_11,16,17,18,TID_ZHAOGUO,"Bất lực (2)","Bất lực (2)(Hoàn thành)" }),
									2 : ({ TASK_11,19,20,21,TID_ZHAOGUO,"Bất lực (3)","Bất lực (3)(Hoàn thành)" }),
									4 : ({ TASK_15,21,22,23,TID_ZHAOGUO,"Niềm vui thơ ấu","Niềm vui thơ ấu(Hoàn thành)" }),
									5 : ({ TASK_15,24,25,26,TID_ZHAOGUO,"Sản xuất công cụ","Sản xuất công cụ(Hoàn thành)" }),
									6 : ({ TASK_15,27,28,29,TID_ZHAOGUO,"Trừng phạt cái ác","Trừng phạt cái ác(Hoàn thành)" }),
									7 : ({ TASK_16,3,4,5,TID_ZHAOGUO,"Chó đường phố","Chó đường phố(Hoàn thành)" }),
									9 : ({ TASK_16,8,9,10,TID_ZHAOGUO,"Thắt lưng buộc bụng","Thắt lưng buộc bụng(Hoàn thành)" }),
									10 : ({ TASK_14,21,22,23,TID_ZHAOGUO,"Nước mắt Vạn Lý Trường Thành","Nước mắt Vạn Lý Trường Thành(Hoàn thành)" }),
									11 : ({ TASK_14,24,25,26,TID_ZHAOGUO,"Những rắc rối của người hầu","Những rắc rối của người hầu(Hoàn thành)" }),
									12 : ({ TASK_14,27,28,29,TID_ZHAOGUO,"Vạn Lý Trường Thành","Vạn Lý Trường Thành(Hoàn thành)" }),
									13 : ({ TASK_15,1,2,3,TID_ZHAOGUO,"Bức tường vĩ đại","Bức tường vĩ đại(Hoàn thành)" }),
									14 : ({ TASK_15,4,5,6,TID_ZHAOGUO,"Rượu ngon","Rượu ngon(Hoàn thành)" }),
									15 : ({ TASK_16,14,15,16,TID_ZHAOGUO,"Khóc trên Vạn Lý Trường Thành","Khóc trên Vạn Lý Trường Thành(Hoàn thành)" }),
									16 : ({ TASK_16,17,18,19,TID_ZHAOGUO,"Ma quỷ đang đến","Ma quỷ đang đến(Hoàn thành)" }),
									17 : ({ TASK_16,20,21,22,TID_ZHAOGUO,"Thức ăn","Thức ăn(Hoàn thành)" }),
									18 : ({ TASK_16,23,24,25,TID_ZHAOGUO,"Truyền thuyết về quần áo thần","Truyền thuyết về quần áo thần(Hoàn thành)" }),
									19 : ({ TASK_16,26,27,28,TID_ZHAOGUO,"Một ngàn dặm đường đi bộ","Một ngàn dặm đường đi bộ(Hoàn thành)" }),
									20 : ({ TASK_17,1,2,3,TID_ZHAOGUO,"Hào quang trên bầu trời đêm","Hào quang trên bầu trời đêm(Hoàn thành)" }),
									21 : ({ TASK_17,4,5,6,TID_ZHAOGUO,"Âm thanh của bầu trời đêm","Âm thanh của bầu trời đêm(Hoàn thành)" }),
									22 : ({ TASK_17,7,8,9,TID_ZHAOGUO,"Vào nửa đêm","Vào nửa đêm(Hoàn thành)" }),
									23 : ({ TASK_17,10,11,12,TID_ZHAOGUO,"Khói trên đèn hiệu","Khói trên đèn hiệu(Hoàn thành)" }),
									24 : ({ TASK_17,13,14,15,TID_ZHAOGUO,"Ánh sáng kì lạ","Ánh sáng kì lạ(Hoàn thành)" }),
									25 : ({ TASK_17,16,17,18,TID_ZHAOGUO,"Than phiền cô đơn","Than phiền cô đơn(Hoàn thành)" }),
									26 : ({ TASK_17,19,20,21,TID_ZHAOGUO,"Cuộc phiêu lưu","Cuộc phiêu lưu(Hoàn thành)" }),
									27 : ({ TASK_17,22,23,24,TID_ZHAOGUO,"Huỳnh quang bí ẩn","Huỳnh quang bí ẩn(Hoàn thành)" }),
									28 : ({ TASK_17,25,26,27,TID_ZHAOGUO,"Cướp nhà","Cướp nhà(Hoàn thành)" }),
									29 : ({ TASK_17,28,29,30,TID_ZHAOGUO,"Thông điệp","Thông điệp(Hoàn thành)" }),
									30 : ({ TASK_18,1,2,3,TID_ZHAOGUO,"Sự đau khổ của quản gia","Sự đau khổ của quản gia(Hoàn thành)" }),
									31 : ({ TASK_18,4,5,6,TID_ZHAOGUO,"Phản đồ","Phản đồ(Hoàn thành)" }),
									32 : ({ TASK_18,7,8,9,TID_ZHAOGUO,"Báo động","Báo động(Hoàn thành)" }),
									33 : ({ TASK_18,10,11,12,TID_ZHAOGUO,"Thật đáng tiếc","Thật đáng tiếc(Hoàn thành)" }),
									34 : ({ TASK_18,13,14,15,TID_ZHAOGUO,"Pháo hoa trên Vạn Lý Trường Thành","Pháo hoa trên Vạn Lý Trường Thành(Hoàn thành)" }),
									35 : ({ TASK_19,16,17,18,TID_ZHAOGUO,"Rượu hảo hạng của Triệu","Rượu hảo hạng của Triệu(Hoàn thành)" }),
									37 : ({ TASK_19,26,27,28,TID_ZHAOGUO,"Món quà phù hợp","Món quà phù hợp(Hoàn thành)" }),
									39 : ({ TASK_20,1,2,3,TID_ZHAOGUO,"Duyệt","Duyệt(Hoàn thành)" }),
									40 : ({ TASK_23,27,28,29,TID_ZHAOGUO,"Tình yêu(3)","Tình yêu(3)(Hoàn thành)" }),
									41 : ({ TASK_27,7,8,9,TID_ZHAOGUO,"Bộ xương trong thảm sát","Bộ xương trong thảm sát(Hoàn thành)" }),
									43 : ({ TASK_27,16,17,18,TID_ZHAOGUO,"Yên Vương rất thích vàng(4)","Yên Vương rất thích vàng(4)(Hoàn thành)" }),
									44 : ({ TASK_27,28,29,30,TID_ZHAOGUO,"Kiến","Kiến(Hoàn thành)" }),
									45 : ({ TASK_28,1,2,3,TID_ZHAOGUO,"Điêu khắc","Điêu khắc(Hoàn thành)" }),
									46 : ({ TASK_28,4,5,6,TID_ZHAOGUO,"Sâu trong đồng cỏ","Sâu trong đồng cỏ(Hoàn thành)" }),
									47 : ({ TASK_28,7,8,9,TID_ZHAOGUO,"Bí mật của hộp gỗ(1)","Bí mật của hộp gỗ(1)(Hoàn thành)" }),
									50 : ({ TASK_28,17,18,19,TID_ZHAOGUO,"Không ngừng","Không ngừng(Hoàn thành)" }),
									51 : ({ TASK_28,20,21,22,TID_ZHAOGUO,"Trận chiến cuối cùng","Trận chiến cuối cùng(Hoàn thành)" }),
									52 : ({ TASK_28,26,27,28,TID_ZHAOGUO,"Bằng chứng sức mạnh","Bằng chứng sức mạnh(Hoàn thành)" }),
									53 : ({ TASK_29,1,2,3,TID_ZHAOGUO,"Hoạt động bí mật","Hoạt động bí mật(Hoàn thành)" }),
									59 : ({ TASK_43,26,27,28,TID_ZHAOGUO,"Biểu tượng quyền lực","Biểu tượng quyền lực(Hoàn thành)" }),
									60 : ({ TASK_45,18,19,20,TID_ZHAOGUO,"Theo y tế (1)","Theo y tế (1)(Hoàn thành)" }),
									70 : ({ TASK_41,20,21,22,TID_ZHAOGUO,"Kiểm tra sức mạnh","Kiểm tra sức mạnh(Hoàn thành)" }),
									71 : ({ TASK_41,23,24,25,TID_ZHAOGUO,"Cuộc phiêu lưu Thiên Môn","Cuộc phiêu lưu Thiên Môn(Hoàn thành)" }),
									76 : ({ TASK_41,28,29,30,TID_ZHAOGUO,"Đột nhập vào Thiên Quân","Đột nhập vào Thiên Quân(Hoàn thành)" }),
									77 : ({ TASK_42,7,8,9,TID_ZHAOGUO,"Tin tức chiến tranh","Tin tức chiến tranh(Hoàn thành)" }),
									79 : ({ TASK_42,12,13,14,TID_ZHAOGUO,"Thủ Thuật Nhỏ","Thủ Thuật Nhỏ (Hoàn thành)" }),
									80 : ({ TASK_42,15,16,17,TID_ZHAOGUO,"Giết sát thủ","Giết sát thủ(Hoàn thành)" }),
									81 : ({ TASK_42,18,19,20,TID_ZHAOGUO,"Tìm bản đồ","Tìm bản đồ(Hoàn thành)" }),
									84 : ({ TASK_42,25,26,27,TID_ZHAOGUO,"Loại bỏ cái ác cho nhân dân","Loại bỏ cái ác cho nhân dân(Hoàn thành)" }),
									86 : ({ TASK_42,28,29,30,TID_ZHAOGUO,"Kẻ biến thái","Kẻ biến thái(Hoàn thành)" }),
									90 : ({ TASK_43,9,10,11,TID_ZHAOGUO,"Xóa bỏ mối đe dọa","Xóa bỏ mối đe dọa(Hoàn thành)" }),
									91 : ({ TASK_43,12,13,14,TID_ZHAOGUO,"Tìm danh sách","Tìm danh sách(Hoàn thành)" }),
									101 : ({ TASK_2_01,10,11,12,TID_ZHAOGUO,"Thu thập các thành phần","Thu thập các thành phần(Hoàn thành)" }),

							]),
								"Mao Sơn": ([
									2:({ TASK_23,8,9,10,TID_MAOSHAN,"Linh hồn lang thang(3)","Linh hồn lang thang(3)(Hoàn thành)" }),
										3 : ({ TASK_23,11,12,13,TID_MAOSHAN,"Linh hồn lang thang(4)","Linh hồn lang thang(4)(Hoàn thành)" }),
										4 : ({ TASK_23,14,15,16,TID_MAOSHAN,"Linh hồn lang thang(5)","Linh hồn lang thang(5)(Hoàn thành)" }),
										5 : ({ TASK_23,17,18,19,TID_MAOSHAN,"Linh hồn lang thang(6)","Linh hồn lang thang(6)(Hoàn thành)" }),
								]),
									"Chu Quốc": ([
										7:({ TASK_28,14,15,16,TID_ZHOUGUO,"Bí mật của hộp gỗ(4)","Bí mật của hộp gỗ(4)(Hoàn thành)" }),
											8 : ({ TASK_39,28,29,30,TID_ZHOUGUO,"Bị bao vây ở mọi phía(4)","Bị bao vây ở mọi phía(4)(Hoàn thành)" }),
											11 : ({ TASK_40,7,8,9,TID_ZHOUGUO,"Thẻ Tre Bị Mất","Thẻ Tre Bị Mất (Hoàn thành)" }),
											12 : ({ TASK_40,10,11,12,TID_ZHOUGUO,"Sừng Trâu Vàng","Sừng Trâu Vàng (Hoàn thành)" }),
											20 : ({ TASK_2_00,20,21,22,TID_ZHOUGUO,"Thăm viếng công tượng kỹ năng sống","Thăm viếng công tượng kỹ năng sống(Hoàn thành)" }),
											21 : ({ TASK_2_00,23,24,25,TID_ZHOUGUO,"Thăm viếng Chu","Thăm viếng Chu(Hoàn thành)" }),
											102 : ({ TASK_2_00,4,5,6,TID_ZHOUGUO,"Tên đầu bếp xấu xa","Tên đầu bếp xấu xa(Hoàn thành)" }),
											103 : ({ TASK_2_01,4,5,6,TID_ZHOUGUO,"Bản đồ bí mật","Bản đồ bí mật(Hoàn thành)" }),
									]),
										"Đông Hải Đảo": ([
											1:({ TASK_37,7,8,9,TID_DONGHAIDAO,"Tiểu Đồ(3)","Tiểu Đồ(3)(Hoàn thành)" }),
												2 : ({ TASK_37,10,11,12,TID_DONGHAIDAO,"Tiểu Đồ(4)","Tiểu Đồ(4)(Hoàn thành)" }),
										]),
											"Tân Thủ Thôn" : ([
												25:({ TASK_40,26,27,28,TID_NEWBIE_01,"Đau đầu(2)","Đau đầu(2)(Hoàn thành)" }),
													28 : ({ TASK_41,6,7,8,TID_NEWBIE_01,"Rất nhiều bệnh khác nhau(2)","Rất nhiều bệnh khác nhau(2)(Hoàn thành)" }),
													30 : ({ TASK_41,13,14,15,TID_NEWBIE_01,"Trang trí nhà cửa","Trang trí nhà cửa(Hoàn thành)" }),
													31 : ({ TASK_41,1,2,3,TID_NEWBIE_01,"Niệm chú lên con người","Niệm chú lên con người(Hoàn thành)" }),
													32 : ({ TASK_40,17,18,19,TID_NEWBIE_01,"Rèn luyện bản thân","Rèn luyện bản thân(Hoàn thành)" }),
													44 : ({ TASK_NEWBIE_02,18,19,20,TID_NEWBIE_01,"Nguyên liệu thô để làm rượu","Nguyên liệu thô để làm rượu(Hoàn thành)" }),
													45 : ({ TASK_49,15,16,17,TID_NEWBIE_01,"Rắc rối do Kiến gây ra","Rắc rối do Kiến gây ra(Hoàn thành)" }),
													46 : ({ TASK_49,18,19,20,TID_NEWBIE_01,"Một con thỏ nhỏ","Một con thỏ nhỏ(Hoàn thành)" }),
													47 : ({ TASK_49,21,22,23,TID_NEWBIE_01,"Hãy loại bỏ Bù nhìn","Hãy loại bỏ Bù nhìn(Hoàn thành)" }),
													48 : ({ TASK_49,24,25,26,TID_NEWBIE_01,"Khó khăn","Khó khăn(Hoàn thành)" }),
													101 : ({ TASK_48,1,2,3,TID_NEWBIE_01,"Thủ Thuật Nhỏ","Thủ Thuật Nhỏ (Hoàn thành)" }),
													104 : ({ TASK_48,8,9,10,TID_NEWBIE_01,"Gia Tộc Ngọc Bội","Gia Tộc Ngọc Bội (Hoàn thành)" }),
													107 : ({ TASK_48,15,16,17,TID_NEWBIE_01,"Búa của chủ tiệm sửa chữa","Búa của chủ tiệm sửa chữa(Hoàn thành)" }),
													108 : ({ TASK_48,18,19,20,TID_NEWBIE_01,"Niệm chú lên con người","Niệm chú lên con người(Hoàn thành)" }),
													110 : ({ TASK_48,23,24,25,TID_NEWBIE_01,"Rất nhiều bệnh khác nhau(2)","Rất nhiều bệnh khác nhau(2)(Hoàn thành)" }),
													112 : ({ TASK_48,28,29,30,TID_NEWBIE_01,"Trang trí nhà cửa","Trang trí nhà cửa(Hoàn thành)" }),
													116 : ({ TASK_49,6 ,7 ,8 ,TID_NEWBIE_01,"Giao dịch","Giao dịch(Hoàn thành)" }),

											]),
												"Vân Mộng Cốc": ([
													1:({ TASK_45,23,24,25,TID_YUNMENZE,"Theo y tế (3)","Theo y tế (3)(Hoàn thành)" }),
														2 : ({ TASK_45,26,27,28,TID_YUNMENZE,"Theo y tế (4)","Theo y tế (4)(Hoàn thành)" }),
												]),
]);


mapping mpTaskDesc = ([]);

void SAVE_BINARY() { }

void create()
{
	object obj;
	string file = "/quest/taskdesc.c";
	if (obj = find_object(file))
	{
		obj->before_destruct();
		destruct(obj);
	}
	load_object(file);
	mpTaskDesc = file->get_taskdesc();
}

void kill_legend_npc(object me, object who)
{
	string name;
	int level, count;

	level = me->get_level();  name = who->get_name();

	if (me->get_legend(TASK_NEWBIE_00, 6) && !me->get_legend(TASK_NEWBIE_00, 7))
	{
		if (name == "Bù Nhìn")
		{
			me->add_save("newbie_5", 1);
			count = me->get_save("newbie_5");
			send_user(me, "%c%s", '!', sprintf("Nhiệm vụ Thủ Thuật Nhỏ hoàn thành %d/8", count));
			if (count >= 8)
			{
				me->delete_save("newbie_5");
				me->set_legend(TASK_NEWBIE_00, 7);
				send_user(me, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 2, "Thủ Thuật Nhỏ (Hoàn thành)");

			}
			else send_user(me, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 2, "Thủ Thuật Nhỏ");
			USER_TASK_D->send_task_intro(me, 2, TID_NEWBIE_01, 2);
			return;
		}
	}

}



void get_task_list(object who) {
	object npc, item;
	string id, * name1;
	int iFlag, i, size, * nId, j, count, iLegend;
	mixed* nTmp;
	int x;
	x = (time() - 4 * 24 * 3600 + 8 * 3600) / (7 * 24 * 3600);
	if (who->get_save_2("double_time.week") != x) {
		who->set_save_2("double_time.week", x);
		who->set_save_2("double_time.time", 0);
		who->set_save_2("double_time.time1", 0);
		who->set_save_2("double_time.time2", 0);
		who->set_save_2("double_time.time3", 0);
		who->set_save_2("double_time.freeze", 0);
	}

	if (who->get("tasklist") == 0) {
		who->set("tasklist", 1);
		send_user(who, "%c%c", 0x51, 0);
	}
	else {
		if (who->get_quest("escort.biaowang")) {
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ESCORT, 3, "");
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_ESCORT, "Nhiệm vụ áp tiêu");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ESCORT, 3, "Cuộc chiến của hộ tống Vương");
		}
		//		if ( who->get_save_2("51cuanye.time") )
		//		{
		//			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,1,"" );                  		
		//			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_WUYIHUODONG,"五一活动" );     
		//			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,1,"极限穿越" );                  		
		//		}	
		//		if ( who->get_save_2("51tiandao.accept") )
		//		{
		//			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,2,"" );                  		
		//			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_WUYIHUODONG,"五一活动" );     
		//			if ( who->get_save_2("51tiandao.amount") < 100 )
		//				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,2,"天道酬勤" );                  		
		//			else
		//				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,2,"天道酬勤(Hoàn thành)" );                  		
		//		}
		return;
	}
	//	if ( who->get_save_2("51cuanye.time") )
	//	{
	//		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_WUYIHUODONG,"五一活动" );     
	//		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,1,"极限穿越" );                  		
	//	}
	//	if ( who->get_save_2("51tiandao.accept") )
	//	{
	//		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_WUYIHUODONG,"五一活动" );     
	//		if ( who->get_save_2("51tiandao.amount") < 100 )
	//			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,2,"天道酬勤" );                  		
	//		else
	//			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,2,"天道酬勤(Hoàn thành)" );                  		
	//	}
	if ((i = who->get_save("dodolook")) && i < 4) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_DODOLOOK, "Tìm ngọc ấn");
		if (i == 1)
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DODOLOOK, 1, "Thăm Ngụy Quốc");
		else if (i == 2)
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DODOLOOK, 2, "Tìm ngọc ấn");
		else if (i == 3)
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DODOLOOK, 3, "Tìm ngọc ấn (Hoàn thành)");

	}
	if (who->get_save_2("dodolook_task.npcid")) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_YUANFEN, "Định mệnh xung đột");
		if (who->get_save_2("dodolook_task.finish"))
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_YUANFEN, 1, "Diệt trừ yêu quái!(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_YUANFEN, 1, "Diệt trừ yêu quái!");
	}
	if (stringp(who->get_save_2("dapang.name"))) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_DAPANG, "Nhiệm vụ lớn");
		if (who->get_save_2("dapang.count") < who->get_save_2("dapang.total"))
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DAPANG, 1, "Giết 20 " + who->get_save_2("dapang.name"));
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DAPANG, 1, "Giết 20 " + who->get_save_2("dapang.name") + "(Hoàn thành)");
	}
	if (gone_time(who->get_login_time()) + who->get_game_time() < who->get_double_time() || who->get_save_2("double_time.freeze") > 0) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi");
	}
	if (get_effect(who, EFFECT_MAGIC_CARD)) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 2, "Thời Gian Biến Thân");
	}
	if (who->get_save_2("insurance.timeover") > time()) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 3, "Thời Gian Bảo Hiểm");
	}
	if (who->get_save_2("refine.status") == 1) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_REFINE, "Nhiệm vụ Thu Yêu");
		if (who->get_save_2("refine.count") >= 450)
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_REFINE, 1, "Nhiệm vụ Hồ Lô Thu Yêu(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_REFINE, 1, "Nhiệm vụ Hồ Lô Thu Yêu");
	}
	if (who->get_save_2("cantuong.status") == 1) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_CANTUONG, "Nâng cấp Thần Binh");
		if (who->get_save_2("cantuong.count") >= 10000 &&
			who->get_save_2("cantuong.hv") >= 1 &&
			who->get_save_2("cantuong.agbd") >= 1 &&
			who->get_save_2("cantuong.uvdtq") >= 1 &&
			who->get_save_2("cantuong.ktl") >= 1)
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_CANTUONG, 1, "Tìm kiếm Thần Binh Phổ(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_CANTUONG, 1, "Tìm kiếm Thần Binh Phổ");
	}
	if (who->get_task("criminal.bonus") || (stringp(id = who->get_task("criminal")) &&
		(npc = find_char(id)) && npc->is_criminal())) {

		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_CRIMINAL, "Nhiệm vụ đào kho báu");
		if (who->get_task("criminal.bonus"))
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_CRIMINAL, 1, "Tiêu diệt Đào Phạm(Đã hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_CRIMINAL, 1, "Tiêu diệt Đào Phạm");
	}
	if (who->get_save_2("marrytask")) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_HONGNIANG, "Chuyện liên kết");
		if (who->get_save_2("marrytask.finish"))
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_HONGNIANG, 1, "Dạy bọn truyền thông bắt nạt một bài học  (Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_HONGNIANG, 1, "Dạy bọn truyền thông bắt nạt một bài học");
	}

	if (who->get_save_2("master_hide")) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_MASTER_HIDE, "Nhiệm Vụ Sư Môn");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_MASTER_HIDE, 1, "Nhiệm vụ Ẩn Tàng");
	}

	//ba vuong
	if (who->get_quest("hienvien.flag") == 101) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_NEWITEMS, "Bá Vương");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_NEWITEMS, 1, "Trợ giúp");
	}

	if (who->get_quest("hienvien.flag") == 101 && who->get_save_2("hienvien.task") >= 1) {
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_NEWITEMS, "Bá Vương");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_NEWITEMS, 1, "Trợ giúp (Hoàn thành)");
	}

	TASK_ROBBER_D->send_task_list(who);
	TASK_BANDITI_D->send_task_list(who);
	TASK_BANDITI_D->send_gold_task_list(who);
	TASK_THIEF_D->send_task_list(who);
	"/sys/party/valentine"->send_task_list(who);
	"/sys/party/qixi"->send_task_list(who);
	TASK_ESCORT_D->send_task_list(who);
	"/sys/sys/manager"->send_task_list(who);
	if (who->get_save_2("chain.type") > 0) {
		CHAIN_D->send_task_list(who, who->get_save_2("chain.type"));
	}
	if (who->get_fam_name()) {
		if (who->get_save_2("mastertask.type") > 0) {
			TASK_MASTER_D->send_task_list(who, who->get_save_2("mastertask.type"));
		}
		//		if (who->get_save_2("masterfight.status")>0)
		//                {		        
		//			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_MASTERFIGHT,"师门Thử thách任务" ); 
		//			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTERFIGHT,1,"Thử thách任务" ); 
		//		}
	}

	//以下为剧情任务
	name1 = keys(mpTaskList);
	for (i = 0, size = sizeof(name1); i < size; i++) {
		nId = keys(mpTaskList[name1[i]]);
		for (j = 0, count = sizeof(nId); j < count; j++) {

			nTmp = mpTaskList[name1[i]][nId[j]];
			if (who->get_legend(nTmp[0], nTmp[1]) && !who->get_legend(nTmp[0], nTmp[2])) {
				send_user(who, "%c%c%c%w%s", 0x51, 2, 1, nTmp[3], name1[i]);
				send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, nTmp[3], nId[j], nTmp[4]);
				iLegend++;
			}

		}
	}

	name1 = keys(mpTaskList1);
	for (i = 0, size = sizeof(name1); i < size; i++) {
		nId = keys(mpTaskList1[name1[i]]);
		for (j = 0, count = sizeof(nId); j < count; j++) {
			nTmp = mpTaskList1[name1[i]][nId[j]];
			if (who->get_legend(nTmp[0], nTmp[1]) && !who->get_legend(nTmp[0], nTmp[3])) {
				send_user(who, "%c%c%c%w%s", 0x51, 2, 1, nTmp[4], name1[i]);
				if (who->get_legend(nTmp[0], nTmp[2]))
					send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, nTmp[4], nId[j], nTmp[6]);
				else
					send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, nTmp[4], nId[j], nTmp[5]);
				iLegend++;
			}

		}
	}
	if (who->get_legend(TASK_NEWBIE_00, 3) && !who->get_legend(TASK_NEWBIE_00, 5)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (who->get_legend(TASK_NEWBIE_00, 4))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 1, "Lời dạy của Lão Nhân (Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 1, "Lời dạy của Lão Nhân");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_00, 6) && !who->get_legend(TASK_NEWBIE_00, 8)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (who->get_legend(TASK_NEWBIE_00, 7))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 2, "Thử tay đi(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 2, "Thử tay đi");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_01, 5) && !who->get_legend(TASK_NEWBIE_01, 6)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (!objectp(item = present("Tàng Bảo Đồ", who, 1, MAX_CARRY)) || item->is_xunbao() != 1)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 4, "Kinh Nghiệm Tìm Báu Vật");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 4, "Kinh Nghiệm Tìm Báu Vật (Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_01, 7) && (!who->get_legend(TASK_NEWBIE_01, 8) || !who->get_legend(TASK_NEWBIE_01, 9))) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 5, "Gia Tộc Ngọc Bội");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_01, 14) && (!who->get_legend(TASK_NEWBIE_01, 15) || !who->get_legend(TASK_NEWBIE_01, 16))) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (!who->get_legend(TASK_NEWBIE_01, 15))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 8, "Búa của chủ tiệm sửa chữa");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 8, "Búa của chủ tiệm sửa chữa(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_02, 1) && (!who->get_legend(TASK_NEWBIE_02, 2) || !who->get_legend(TASK_NEWBIE_02, 3))) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (!who->get_legend(TASK_NEWBIE_02, 2))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 14, "Giao dịch");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 14, "Giao dịch(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_02, 4) && (!who->get_legend(TASK_NEWBIE_02, 5) || !who->get_legend(TASK_NEWBIE_02, 6))) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (!who->get_legend(TASK_NEWBIE_02, 5))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 15, "Chim trĩ đáng ghét");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 15, "Chim trĩ đáng ghét(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_02, 7) && (!who->get_legend(TASK_NEWBIE_02, 8) || !who->get_legend(TASK_NEWBIE_02, 9))) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (!who->get_legend(TASK_NEWBIE_02, 8))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 16, "Gà gô!");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 16, "Gà gô!(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_00, 17) && !who->get_legend(TASK_NEWBIE_00, 19)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (who->get_legend(TASK_NEWBIE_00, 18))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 19, "Ủy ban hù dọa(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 19, "Ủy ban hù dọa");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_02, 14) && !who->get_legend(TASK_NEWBIE_02, 16)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (!who->get_legend(TASK_NEWBIE_02, 15))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 20, "Trừng phạt tướng quân xấu xa");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 20, "Trừng phạt tướng quân xấu xa(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_02, 17) && !who->get_legend(TASK_NEWBIE_02, 20)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		if (!who->get_legend(TASK_NEWBIE_02, 20))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 21, "Bạch lang");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 21, "Bạch lang(Hoàn thành)");
		iLegend++;
	}
	//if ( who->get_legend(TASK_NEWBIE_02, 28) && !who->get_legend(TASK_NEWBIE_02, 30) )
	//{
	//send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
	//if ( !who->get_legend(TASK_NEWBIE_02, 29) )
	//	send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,22,"正义之战" );
	//else
	//	send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,22,"正义之战(Hoàn thành)" );
	//iLegend++;
	//}
	//	if ( who->get_legend(TASK_NEWBIE_02, 18) && !who->get_legend(TASK_NEWBIE_02, 20) )
	//	{
	//		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_BAQIU,"巴丘" );
	//		if ( !who->get_legend(TASK_NEWBIE_02, 19) )
	//			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_BAQIU,1,"Nguyên liệu thô để làm rượu" );
	//		else
	//			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_BAQIU,1,"Nguyên liệu thô để làm rượu(Hoàn thành)" );
	//		iLegend++;
	//	}
	if (who->get_legend(TASK_NEWBIE_02, 22) && !who->get_legend(TASK_NEWBIE_02, 23)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_HUANJIAO, "Thung lũng sâu và tách biệt");
		send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_HUANJIAO, 1, "Cãi nhau giữa vợ chồng");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_02, 24) && !who->get_legend(TASK_NEWBIE_02, 25)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_YEWAI, "Thanh");
		if (who->get_save_2("xiaomao_fengmi") >= 3)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_YEWAI, 1, "Mật ong ngon(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_YEWAI, 1, "Mật ong ngon");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_02, 26) && !who->get_legend(TASK_NEWBIE_02, 27)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_YEWAI, "Thanh");
		if (who->get_save_2("xiaomifeng") >= 8)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_YEWAI, 2, "Con ong nhỏ chích người(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_YEWAI, 2, "Con ong nhỏ chích người");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 1) && !who->get_legend(TASK_NEWBIE_03, 2)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_CHUGUO, "Sở Quốc");
		if (!objectp(present("Hàng hóa của Tiền Lão Cửu", who, 1, MAX_CARRY)))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 1, "Thu hàng về");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 1, "Thu hàng về(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 3) && !who->get_legend(TASK_NEWBIE_03, 4)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_CHUGUO, "Sở Quốc");
		if (!objectp(item = present("珍珠项链", who, 1, MAX_CARRY)) || item->is_xianglian() != 1)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 2, "Món quà của người yêu");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 2, "Món quà của người yêu(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 5) && !who->get_legend(TASK_NEWBIE_03, 6)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_CHUGUO, "Sở Quốc");
		if (who->get_save_2("sijiaose") < 18)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 3, "Giết con rắn bốn chân");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 3, "Giết con rắn bốn chân(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 7) && !who->get_legend(TASK_NEWBIE_03, 8)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_CHUGUO, "Sở Quốc");
		if (who->get_save_2("xuantieshi") < 3)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 4, "Xây một thế giới run rẩy kiếm");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 4, "Xây một thế giới run rẩy kiếm(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 9) && !who->get_legend(TASK_NEWBIE_03, 10)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_CHUGUO, "Sở Quốc");
		if (!who->get_save_2("bandiangou"))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 5, "Máu chó đốm");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 5, "Máu chó đốm(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 11) && !who->get_legend(TASK_NEWBIE_03, 14)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_CHUGUO, "Sở Quốc");
		if (!who->get_legend(TASK_NEWBIE_03, 12))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 7, "Thiếu phán xét(1)");
		else if (who->get_legend(TASK_NEWBIE_03, 13))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 8, "Thiếu phán xét(2)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 15) && !who->get_legend(TASK_NEWBIE_03, 16)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_ZHOUGUO, "Chu Quốc");
		if (who->get_save_2("gongsumutou") >= 20)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 4, "Thiếu phán xét(3)(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 4, "Thiếu phán xét(3)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 17) && !who->get_legend(TASK_NEWBIE_03, 18)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_ZHOUGUO, "Chu Quốc");
		if (who->get_save_2("gongsupaozi"))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 5, "Thiếu phán xét(4)(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 5, "Thiếu phán xét(4)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 18) && !who->get_legend(TASK_NEWBIE_03, 19)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_ZHOUGUO, "Chu Quốc");
		send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 6, "Thiếu phán xét(5)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 20) && !who->get_legend(TASK_NEWBIE_03, 21)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_CHUGUO, "Sở Quốc");
		if (who->get_save_2("souweisoujiao") < 20)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 10, "Thần bảo vệ");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_CHUGUO, 10, "Thần bảo vệ(Hoàn thành)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 24) && !who->get_legend(TASK_NEWBIE_03, 25)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_DONGTINGHU, "Đông Hồ");
		if (who->get_save_2("zxganliang") >= 20)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_DONGTINGHU, 1, "Vá lại chuồng sau khi con cừu bị ăn trộm(2)(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_DONGTINGHU, 1, "Vá lại chuồng sau khi con cừu bị ăn trộm(2)");
		iLegend++;
	}
	if (who->get_legend(TASK_NEWBIE_03, 26) && !who->get_legend(TASK_NEWBIE_03, 28)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_DONGTINGHU, "Đông Hồ");
		if (who->get_legend(TASK_NEWBIE_03, 27))
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_DONGTINGHU, 2, "Vá lại chuồng sau khi con cừu bị ăn trộm(3)(Hoàn thành)");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_DONGTINGHU, 2, "Vá lại chuồng sau khi con cừu bị ăn trộm(3)");
		iLegend++;
	}
	if (who->get_legend(TASK_04, 11) && !who->get_legend(TASK_04, 12)) {
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_HANGUO, "Hàn Quốc");
		if (who->get_save_2("nzdujiaosou") < 20)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_HANGUO, 5, "Biến loạn triều đình");
		else
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_HANGUO, 5, "Biến loạn triều đình(Hoàn thành)");
		iLegend++;
	}
	who->set_save_2("task.story", iLegend);
	return;
}

string send_task_intro(object who, int iFlag, int iTask, int iKind) {
	int time, x, y, z, status, tasktype = 3, lefttime, task_jq;
	string result, id, name;
	object map, npc, me, item;
	mixed* mxTmp;
	string* npc_info;

	if (mapp(mpTaskDesc[iFlag]) && mapp(mpTaskDesc[iFlag][iTask]) && stringp(mpTaskDesc[iFlag][iTask][iKind])) {
		tasktype = 1;
		result = mpTaskDesc[iFlag][iTask][iKind];
	}
	if (stringp(result)) {
		if (tasktype == 1)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 3, iTask, iKind, result);
		else
			if (tasktype == 4) {
				if (lefttime < 0)
					send_user(who, "%c%c%c%w%w%s", 0x51, 1, 3, iTask, iKind, "Không còn thời gian nữa đâu");
				else
					send_user(who, "%c%c%c%w%w%d%s", 0x51, 1, 4, iTask, iKind, lefttime, result);
			}
			else
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 3, iTask, iKind, result);
		return result;
	}
	if (iFlag == 1 && iTask == TID_WUYIHUODONG) {
		if (iKind == 1) {
			result = sprintf(BLK "Mục đích nhiệm vụ:\n"
				BLK "    Tới phía đông bắc đảo Đông Bắc "
				HIR "Thử vượt biên\n"
				BLK "    Thời gian:"
				HIR " %d phút\n"
				BLK "Miêu tả nhiệm vụ:\n"
				BLK "    Bắt đầu t ừ đất n ước Tề, băng qua làng cá ở Đông Trung Quốc và đến đảo Đông. Bạn đang tìm kiếm một người tên là Thanh tra vượt biên Mọi người, hãy nhớ tìm một cầu thủ có tuổi cao cùng các bạn ở quán rượu I, nếu không, các bạn sẽ không thể cưỡng lại được cuộc tấn công của con quái vật ở đó.!\n"
				BLK "    Lấy cái này “Giấy chứng nhận”,Về phía đông bắc của Đảo Đông Thanh tra vượt biên,Bạn có thể nhận được phần thưởng mà anh ấy đã cho bạn!\n"
				BLK "    Bạn đến đích càng nhanh, bạn càng nhận được nhiều phần thưởng!\n"
				BLK "Phần thưởng:\n"
				BLK "    Huân chương lao động thời Chiến quốc", gone_time(who->get_save_2("51cuanye.time")) / 60);
		}
		else if (iKind == 2 || iKind == 3) {
			result = sprintf(BLK "Mục đích nhiệm vụ:\n"
				BLK "    Giết ma vật 100 trên tầng 5\n"
				BLK "  %d/100\n"
				BLK "Miêu tả nhiệm vụ:\n"
				BLK "   Không cần nỗ lực, không đạt được, chỉ cần bạn làm việc chăm chỉ, bạn sẽ gặt hái được nhiều quả giàu ,giữ cho chắc Đá Thử Nghiệm,Giết 100 quái vật cao hơn cấp độ 5 của bạn và bạn có thể quay lại Làng mới bắt đầu tìm người chỉ định sự kiện ngày 1 tháng 5 để nhận phần thưởng.\n"
				BLK "   Hãy nhớ rằng, nó phải là một con quái vật trong vòng 5 cấp độ cao hơn cấp độ của chính bạn.\n"
				BLK "Phần thưởng:\n"
				BLK "    Huân chương lao động thời Chiến quốc×3", who->get_save_2("51tiandao.amount"));
		}
	}
	else
		if (iFlag == 1 && iTask == TID_DODOLOOK) {
			if (iKind == 1)
				result = BLK "Mục đích nhiệm vụ:\n"
				BLK "    Nói chuyện với Ngụy Trung Nguyên \n"
				BLK "Miêu tả nhiệm vụ:\n"
				BLK "   Người ta nói có người đã nhìn thấy xác của dodoloky ở tiểu bang Ngụy. có lẽ đó là nước Vệ Vua Triệu đã bắt cô ta nếu như không t ìm được nó thì nên đến tìm nước Vệ mà hỏ!\n"
				BLK "Phần thưởng:\n"
				BLK "    Kinh nghiệm +:1000\n"
				BLK "    Tiềm năng +:50\n"
				BLK "    Ngân lượng:1000\n"
				BLK "    物品:行军散 5 个";
			else if (iKind == 2 || iKind == 3)
				result = BLK "Mục đích nhiệm vụ:\n"
				BLK "    Đi Chu Phương Thành thu hồi ấn ngọc tặng vua Ngụy Triệu\n"
				BLK "Miêu tả nhiệm vụ:\n"
				BLK "   Chấp nhận lời thách đấu của nước Vệ Chiêu Lỗ Vương Chiêu ngọc trai không còn nữa nếu như có thể giúp nước Vệ Chiêu tìm ngọc ngọc bích được Tần vương Triệu cho ngươi giữ vật.\n"
				BLK "Phần thưởng:\n"
				BLK "    Kinh nghiệm +:2000\n"
				BLK "    Tiềm năng +:50\n"
				BLK "    Ngân lượng:2000\n"
				BLK "    物品:行军散5个、正气散5个";
		}
		else
			if (iFlag == 1 && iTask == TID_YUANFEN && who->get_save_2("dodolook_task.npcid")) {
				if (!who->get_save_2("dodolook_task.finish")) {
					tasktype = 4;
					lefttime = 3600 - gone_time(who->get_save_2("dodolook_task.time"));
					if (lefttime <= 0)
						result = BLK "Nhiệm vụ thất bại";
					else
						result = sprintf(BLK "Mục đích nhiệm vụ:\n"
							BLK "    Diệt trừ yêu quái%s (0/1) \n"
							BLK "Thời gian còn lại %s phút\n"
							BLK "Miêu tả nhiệm vụ:\n"
							BLK "    gần %s Quốc (%d,%d)có một %s,它作祟不知将多少缠绵情侣之间的真爱一点点吞噬掉,你们的任务就是合力消灭他,为人世间的有缘人扫除天敌.任务Hoàn thành后告之dodolook一下!", who->get_save_2("dodolook_task.name"), "%d", who->get_save_2("dodolook_task.country"), who->get_save_2("dodolook_task.x"), who->get_save_2("dodolook_task.y"), who->get_save_2("dodolook_task.name"));
				}
				else
					result = sprintf(BLK "Mục đích nhiệm vụ:\n"
						BLK "    Diệt trừ yêu quái %s (1/1) \n"
						BLK "Miêu tả nhiệm vụ:\n"
						BLK "    gần %s Quốc (%d,%d)có một %s,它作祟不知将多少缠绵情侣之间的真爱一点点吞噬掉,你们的任务就是合力消灭他,为人世间的有缘人扫除天敌.任务Hoàn thành后告之dodolook一下!", who->get_save_2("dodolook_task.name"), who->get_save_2("dodolook_task.country"), who->get_save_2("dodolook_task.x"), who->get_save_2("dodolook_task.y"), who->get_save_2("dodolook_task.name"));

			}
			else
				if (iFlag == 1 && iTask == TID_DAPANG) {
					if (who->get_save_2("dapang.count") < who->get_save_2("dapang.total")) {
						tasktype = 4;
						lefttime = 1800 - gone_time(who->get_save_2("dapang.time"));
						if (lefttime <= 0)
							result = BLK "Nhiệm vụ thất bại";
						else
							result = sprintf(BLK "Mục đích nhiệm vụ:\n"
								BLK "    Giết 20 %s và nói Bàng đại Bàng\n"
								BLK "    %s %d/20\n"
								BLK "Miêu tả nhiệm vụ:\n"
								BLK "    如今天下世道纷乱不堪,Quái vật四出肆虐,此乃天理不容.为拯救苍生,你前Đi"
								HIR "Giết 20 %s"
								BLK ",只望以此来警示那些蠢蠢欲动的妖孽,Hoàn thành此使命还望告知大胖一声.据说"
								HIR "%s"
								BLK ".\n"
								BLK "Còn thừa %s phút\n"
								BLK "Phần thưởng:3000金 1000Kinh nghiệm + 200Tiềm năng +", name = who->get_save_2("dapang.name"), name, who->get_save_2("dapang.count"), name, who->get_save_2("dapang.where"), "%d");
					}
					else
						result = sprintf(BLK "Mục đích nhiệm vụ:\n"
							BLK "    Giết 20 %s và nói Bàng đại Bàng\n"
							BLK "    %s %d/20\n"
							BLK "Miêu tả nhiệm vụ:\n"
							BLK "    如今天下世道纷乱不堪,Quái vật四出肆虐,此乃天理不容.为拯救苍生,你前Đi"
							HIR "Giết 20 %s"
							BLK ",只望以此来警示那些蠢蠢欲动的妖孽,Hoàn thành此使命还望告知大胖一声.据说"
							HIR "%s"
							BLK ".\n"
							BLK "Phần thưởng:3000金 1000Kinh nghiệm + 200Tiềm năng +", name = who->get_save_2("dapang.name"), name, who->get_save_2("dapang.count"), name, who->get_save_2("dapang.where"));
				}
				else
					if (iFlag == 1 && iTask == TID_REFINE) {
						tasktype = 4;
						result = "/sys/user/refine"->send_task_intro(who);
					}
					else
						if (iFlag == 1 && iTask == TID_CANTUONG) {
							tasktype = 4;
							result = "/sys/user/cantuong"->send_task_intro(who);
						}
						else
							if (iFlag == 1 && iTask == 1) {
								if (iKind == 1) {
									tasktype = 4;
									if (who->get_save_2("double_time.freeze") > 0) {
										lefttime = 0;
										result = sprintf(BLK "Bạn đã đông cứng %d phút thời gian nhân đôi", who->get_save_2("double_time.freeze") / 60);
									}
									else {
										lefttime = who->get_double_time() - gone_time(who->get_login_time()) - who->get_game_time();
										result = BLK "Thời gian Kinh nghiệm gấp đôi của bạn còn %d phút";
									}
								}
								else if (iKind == 2) {
									tasktype = 4;
									lefttime = get_effect_3(who, EFFECT_MAGIC_CARD);
									result = BLK "Hiệu quả biến thân của bạn còn %d phút";
								}
								else if (iKind == 3 && (lefttime = who->get_save_2("insurance.timeover")) > time()) {
									mxTmp = localtime(lefttime);
									result = sprintf(BLK "Bảo hiểm sẽ hết hạn vào %d năm %d tháng %d ngày %d giờ", mxTmp[TIME_YEAR], mxTmp[TIME_MON] + 1, mxTmp[TIME_MDAY], mxTmp[TIME_HOUR]);
								}
							}
							else if (iFlag == 1 && iTask == TID_CRIMINAL && iKind == 1) {
								if (who->get_task("criminal.bonus")) {
									result = sprintf(BLK "Mục đích nhiệm vụ:\n"
										BLK "    Tiêu diệt Đào Phạm vừa tẩu thoát khỏi ngục\n"
										BLK "    Tiêu diệt %s: 1/1.\n"
										BLK "Miêu tả nhiệm vụ:\n"
										BLK "    Trước đó vài ngày có gió bão lớn, làm thiệt hại nhiều vách tường của nhà ngục, làm cho Đào phạm có cơ hội chạy trốn, nghe thám tử hồi báo "
										HIR "%s "
										BLK " đang núp ở "
										HIR "%s (%d,%d) "
										BLK ", nếu ngươi có thể giúp ta tiêu diệt đào phạm thì đại vương sẽ trọng thưởng\n"
										BLK "Phần thưởng: 1500 lượng\n",
										who->get_task("criminal.name"), who->get_task("criminal.name"), who->get_task("criminal.map"), who->get_task("criminal.x"), who->get_task("criminal.y"));
								}
								else if (stringp(id = who->get_task("criminal")) &&
									(npc = find_char(id)) && npc->is_criminal()) {
									tasktype = 4;
									lefttime = 1800 - gone_time(npc->get("birthday"));
									map = get_map_object(get_z(npc));
									name = map ? map->get_name() : "Bản đồ vô danh";
									result = sprintf(BLK "Mục đích nhiệm vụ:\n"
										BLK "    Tiêu diệt Đào Phạm vừa tẩu thoát khỏi ngục\n"
										BLK "    Tiêu diệt %s: 0/1 (Thời gian còn %s phút).\n"
										BLK "Miêu tả nhiệm vụ:\n"
										BLK "    Trước đó vài ngày có gió bão lớn, làm thiệt hại nhiều vách tường của nhà ngục, làm cho Đào phạm có cơ hội chạy trốn, nghe thám tử hồi báo "
										HIR "%s "
										BLK " đang núp ở "
										HIR "%s (%d,%d) "
										BLK ", nếu ngươi có thể giúp ta tiêu diệt đào phạm thì đại vương sẽ trọng thưởng\n"
										BLK "Phần thưởng: 1500 lượng\n",
										npc->get_name(), "%d", npc->get_name(), name, who->get_task("criminal.x"), who->get_task("criminal.y"));

								}
							}
							else if (iFlag == 1 && iTask == TID_ROBBER && iKind == 1) {
								if (who->get_task("robber.bonus")) {
									result = sprintf(BLK "Tiêu diệt %s (Lượt thứ %d)\n"
										BLK "Mục đích nhiệm vụ:\n"
										BLK "    Giúp Sư Gia tiêu diệt "
										HIR "%s"
										BLK ".\n"
										BLK "    Tiêu diệt %s: 1/1\n"
										BLK "Miêu tả nhiệm vụ:\n"
										BLK "    Gần đây có tên tội phạm "
										HIR "%s"
										BLK " ở "
										HIR "%s"
										BLK " làm đủ mọi chuyện ác, hung hăng ngang ngược\n"
										BLK "    Hiện tại Nha Môn phòng thủ không đủ, ngươi hãy đi tiêu diệt hắn giùm ta, ta sẽ trọng thưởng\n"
										BLK "phần thưởng nhiệm vụ:"
										HIR "500 lượng",
										who->get_task("robber.name"), who->get_task("robber#") + 1, who->get_task("robber.name"), who->get_task("robber.name"), who->get_task("robber.name"), who->get_task("robber.map"));
								}
								else if (stringp(id = who->get_task("robber")) &&
									(npc = find_char(id)) && npc->is_robber()) {
									tasktype = 4;
									lefttime = 3600 - gone_time(npc->get("birthday"));
									map = get_map_object(get_z(npc));
									name = map ? map->get_name() : "Bản đồ vô danh";
									result = sprintf(BLK "Tiêu diệt %s (Lượt thứ %d)\n"
										BLK "Mục đích nhiệm vụ:\n"
										BLK "    Giúp Sư Gia tiêu diệt "
										HIR "%s"
										BLK ".\n"
										BLK "    Tiêu diệt %s: 0/1 (Thời gian còn %s phút)\n"
										BLK "Miêu tả nhiệm vụ:\n"
										BLK "    Gần đây có tên tội phạm "
										HIR "%s"
										BLK " ở "
										HIR "%s"
										BLK " làm đủ mọi chuyện ác, hung hăng ngang ngược\n"
										BLK "    Hiện tại Nha Môn phòng thủ không đủ, ngươi hãy đi tiêu diệt hắn giùm ta, ta sẽ trọng thưởng\n"
										BLK "phần thưởng nhiệm vụ:"
										HIR "500 lượng",
										npc->get_name(), who->get_task("robber#") + 1, npc->get_name(), npc->get_name(),
										"%d", npc->get_name(), name);
								}
							}
							else if (iFlag == 1 && iTask == TID_BANDITI && iKind) {
								switch (iKind) {
								case 1:
									if (stringp(id = who->get_task("banditi")) &&
										(npc = find_char(id)) && npc->is_banditi()) // 30 phút
									{
										z = npc->get("xy.z");
										x = npc->get("xy.x");
										y = npc->get("xy.y");
										tasktype = 4;
										lefttime = 1800 - gone_time(npc->get("birthday"));
										map = get_map_object(get_z(npc));
										name = map ? map->get_name() : "Bản đồ vô danh";
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Tiêu diệt ở "
											HIR "%s(%d,%d)"
											BLK " vùng thường lui tới "
											HIR "%s"
											BLK ".\n"
											BLK "%s : 0/1  (Còn thừa %s phút).\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Nghe nói ở "
											HIR "%s(%d,%d)"
											BLK " vùng phụ cận có đạo tặc %s có ý định cướp bóc thôn ta, hy vọng đại hiệp ra tay trương trợ !",
											name, x, y, npc->get_name(), npc->get_name(), "%d", name, x, y, npc->get_name());
									}
									else if (who->get_task("banditi_bonus")) {
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Tiêu diệt ở "
											HIR "%s(%d,%d)"
											BLK " vùng thường lui tới "
											HIR "%s"
											BLK ".\n"
											BLK "%s : 1/1.\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Nghe nói ở "
											HIR "%s(%d,%d)"
											BLK " vùng phụ cận có đạo tặc "
											HIR "%s"
											BLK " có ý định cướp bóc thôn ta, hy vọng đại hiệp ra tay trương trợ !",
											who->get_task("banditi_map"), who->get_task("banditi_x"), who->get_task("banditi_y"), who->get_task("banditi_name"), who->get_task("banditi_name"), who->get_task("banditi_map"), who->get_task("banditi_x"), who->get_task("banditi_y"), who->get_task("banditi_name"));
									}
									break;
								case 2:
									if (stringp(id = who->get_task("warrior")) &&
										(npc = find_char(id)) && npc->is_warrior()) {
										z = npc->get("xy.z");
										x = npc->get("xy.x");
										y = npc->get("xy.y");
										tasktype = 4;
										lefttime = 600 - gone_time(npc->get("birthday"));
										map = get_map_object(get_z(npc));
										name = map ? map->get_name() : "Bản đồ vô danh";
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Tiêu diệt ở "
											HIR "%s(%d,%d)"
											BLK " vùng thường lui tới "
											HIR "%s"
											BLK ", lấy được Hoàng Kim Thánh Y.\n"
											BLK "    Hoàng Kim Thánh Y: 0/1  (Còn thừa %s phút).\n"
											BLK "Nhiệm vụ hoàn thành : Vệ Đội Trưởng ở Tân Thủ Thôn\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Vệ Đội Trưởng mỗi lần nằm mơ đều thấy mình hoá thành Hoàng Kim Thánh Đấu Sĩ, để hoàn thành giấc mộng hắn triệu tập quần hùng đi tìm giúp, nghe nói Hoàng Kim Thánh Y đang trong tay của một tên Đạo Tặc, nếu đánh bại hắn có thể có được Hoàng Kim Thánh Y",
											name, x, y, npc->get_name(), "%d");
									}
									else if (who->get_task("warrior_bonus")) {
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Tiêu diệt ở "
											HIR "%s(%d,%d)"
											BLK " vùng thường lui tới "
											HIR "%s"
											BLK ", lấy được Hoàng Kim Thánh Y.\n"
											BLK "    Hoàng Kim Thánh Y: 1/1\n"
											BLK "Nhiệm vụ hoàn thành : Vệ Đội Trưởng ở Tân Thủ Thôn\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Vệ Đội Trưởng mỗi lần nằm mơ đều thấy mình hoá thành Hoàng Kim Thánh Đấu Sĩ, để hoàn thành giấc mộng hắn triệu tập quần hùng đi tìm giúp, nghe nói Hoàng Kim Thánh Y đang trong tay của một tên Đạo Tặc, nếu đánh bại hắn có thể có được Hoàng Kim Thánh Y",
											who->get_task("warrior_map"), who->get_task("warrior_x"), who->get_task("warrior_y"), who->get_task("warrior_name"));
									}
									break;
								}

							}
							else if (iFlag == 1 && iTask == TID_THIEF && iKind) {
								if (iKind == who->get_quest("thief.bonus")) {
									switch (iKind) {
									case 1:
										x = who->get_quest("thief.x");
										y = who->get_quest("thief.y");
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Đến "
											HIR "%s"
											BLK " ở "
											HIR "%d,%d"
											BLK "vùng, đem "
											HIR "%s"
											BLK " giáo huấn(Lượt thứ %d )\n"
											BLK "Giáo huấn %s: 1/1\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Lão thôn trưởng đêm qua lại lại có một tên %s ăn trộm, tuy không mất gì nghiệm trọng, nhưng không thêt tha thứ\n"
											BLK "    %s ở tại %s (%d,%d) vùng thường lui tới, ngươi hãy đi giáo huấn %s một chút", id = who->get_quest("thief.map"), x, y, name = who->get_quest("thief.name"), who->get_quest("thief.count") + 1, name, name, name, id, x, y, name);
										break;
									case 4:
										x = who->get_quest("thief.x");
										y = who->get_quest("thief.y");
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Đuổi bắt đào phạm chạy trốn đến "
											HIR "%s(%d,%d)"
											BLK " vùng phụ cận "
											HIR "%s"
											BLK ", đem về Vật Phẩm bị mất(Lượt thứ %d )\n"
											BLK "Vật phẩm bị mất: 1/1\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Kẻ trộm %s đêm qua lại xuất hiện!Hắn đã cướp sạch những vật phẩm quý giá!Theo hồi báo cấp dưới nhìn thấy %s ở %s (%d,%d) vùng phụ cận.Nếu %s có thể giúp ta lấy lại vật phẩm bị mất ta sẽ trọng thưởng", id = who->get_quest("thief.map"), x, y, name = who->get_quest("thief.name"), who->get_quest("thief.count") + 1, name, name, id, x, y, NPC_RANK_D->get_respect_2(who));
										break;
									}
								}
								else if (iKind == who->get_quest("thief.flag")) {
									switch (iKind) {
									case 1: // 2. 失窃任务(人物)
										if (stringp(id = who->get_quest("thief.thief")) &&
											(npc = find_char(id)) && npc->is_thief()) // 30 phút
										{
											z = who->get_quest("thief.z");
											x = who->get_quest("thief.x");
											y = who->get_quest("thief.y");
											tasktype = 4;
											lefttime = 1800 - gone_time(who->get_quest("thief.time"));
											map = get_map_object(z);
											name = map ? map->get_name() : "Bản đồ vô danh";
											result = sprintf(BLK "Mục đích nhiệm vụ:\n"
												BLK "    Đến "
												HIR "%s"
												BLK " ở "
												HIR "%d,%d"
												BLK " vùng phụ cận, đem"
												HIR "%s"
												BLK " giáo huấn.Thời gian còn %s phút(Lượt thứ %d )\n"
												BLK "Giáo huấn %s: 0/1\n"
												BLK "Miêu tả nhiệm vụ:\n"
												BLK "    Lão thôn tưởng nói đêm qua lại xuất hiện 1 tên %s ăn trộm, tuy không mất gì đáng giá nhưng không thể tha thứ\n"
												BLK "    %s ở tại %s (%d,%d) vùng thường lui tới, ngươi hãy đi giáo huấn %s một chút", name, x, y, id = npc->get_name(), "%d", who->get_quest("thief.count") + 1, id, id, id, name, x, y, id);
										}
										break;

									case 2: // 1. 失窃任务(物品)
										lefttime = 1800 - gone_time(who->get_quest("thief.time"));
										if (lefttime < 0)
											lefttime = 1;
										tasktype = 4;
										z = who->get_quest("thief.z");
										x = who->get_quest("thief.x");
										y = who->get_quest("thief.y");
										map = get_map_object(z);
										name = map ? map->get_name() : "Bản đồ vô danh";
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Đến "
											HIR "%s"
											BLK " ở "
											HIR "%d,%d"
											BLK " vùng phụ cận, giúp Bát Cô tìm "
											HIR "%s"
											BLK ",Thời gian còn %s phút(Lượt thứ %d )\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Bát Cô ngồi tâm sự kể lể bị mất một vật quý\n"
											BLK "    Lần này Bát Cô bị mất %s,theo nàng miêu tả rớt tại %s (%d,%d) vùng phụ cận\n"
											BLK "    Như thế nào ？%s có muốn giúp ta tìm lại vật phẩm này không ？", name, x, y, id = who->get_quest("thief.thief"), "%d", who->get_quest("thief.count") + 1, id, name, x, y, NPC_RANK_D->get_respect_2(who));
										break;

									case 3: // 5. 寻物任务
									  //			                if( ( time = 1800 - gone_time( who->get_quest("thief.time") ) ) > 0 )    // 15 phút
									  //			                {
										result = sprintf(BLK "Mục tiêu nhiệm vụ:\n"
											BLK " Giúp Vương Bộ Đầu mua "
											HIR " %s "
											BLK ". (Lượt thứ %d )\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK " %s , ta vốn muốn mua về %s , nhưng vì công vụ trói buộc bản thân không thể tự do đi mua được , ngươi có thể giúp ta một tay không?\n", id = who->get_quest("thief.thief"), who->get_quest("thief.count") + 1, who->get_name(), id);
										//			                }
										break;

									case 4: // 3. 失窃任务(人物)
										if (stringp(id = who->get_quest("thief.thief")) &&
											(npc = find_char(id)) && npc->is_thief()) // 15 phút
										{
											z = who->get_quest("thief.z");
											x = who->get_quest("thief.x");
											y = who->get_quest("thief.y");
											tasktype = 4;
											lefttime = 1800 - gone_time(who->get_quest("thief.time"));
											map = get_map_object(z);
											name = map ? map->get_name() : "Bản đồ vô danh";
											result = sprintf(BLK "Mục đích nhiệm vụ:\n"
												BLK "    Đuổi bắt Đào phạm đến "
												HIR "%s(%d,%d)"
												BLK " vùng phụ cận "
												HIR "%s"
												BLK ", đem vật phẩm quý giá trở về .Thời gian còn %s phút(Lượt thứ %d )\n"
												BLK "Vật Phẩm bị mất:0/1\n"
												BLK "Miêu tả nhiệm vụ:\n"
												BLK "    Kẻ trộm %s đêm qua lại xuất hiện!Hắn đã cướp sạch những vật phẩm quý giá!Theo cấp dưới báo nhìn thấy %s ở %s (%d,%d).Nếu %s có thể giúp ta tìm lại vật phẩm bị mất, ta sẽ trọng thưởng", id = map->get_name(), x, y, name = npc->get_name(), "%d", who->get_quest("thief.count") + 1, name, name, id, x, y, NPC_RANK_D->get_respect_2(who));
										}
										break;
									}
								}
							}
							else if (iFlag == 1 && iTask == TID_VALENTINE && iKind) {
								if (iKind == who->get_quest("valentine.flag")) {
									switch (iKind) {
									case 1:
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Tìm sư phụ Đường Môn Hạt giống bí ẩn\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    14/2 là một ngày rất kỳ diệu. Một chàng trai tình yêu có thể có hoa hồng với nhiều ý nghĩa khác nhau nhờ sự chân thành và sức mạnh của mình. bạn có thể tới chỗ ông Đường lấy bông hồng huyền thoại.Hạt giống bí ẩn吧!Nhân tiện, giúp t ôi mang gói hàng này đến cho ông Đường.!\n"
											BLK "Phần thưởng:Kinh nghiệm +500");
										break;
									case 2:
										lefttime = 1800 - gone_time(who->get_quest("valentine.time"));
										if (lefttime < 0)
											lefttime = 1;
										tasktype = 4;
										x = who->get_quest("valentine.x");
										y = who->get_quest("valentine.y");
										z = who->get_quest("valentine.z");

										map = get_map_object(z);
										name = map ? map->get_name() : "Bản đồ vô danh";
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Đến %s Quốc(%d,%d) Giết thằng chỉ điểm rồi lấy đi Hạt giống bí ẩn,Còn lại giờ làm việc %s phút.\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Cái gói cô mang tới đã được ông Đường chấp nhận, nhưng cái túi hạt bí ẩn duy nhất đã bị đánh cắp vài ngày trước. có vẻ như tên trộm đã ăn cắp hạt giống đang ở đây %s (%d,%d) Nếu cậu có thể lấy lại được hạt giống, nó sẽ là của cậu!\n"
											BLK "Phần thưởng:Kinh nghiệm +500 Tiềm năng +10", name, x, y, "%d", name, x, y);
										break;
									case 3:
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Hãy đưa hạt giống bí ẩn cho Nguyệt Lão và hỏi ổng về hoa, và hỏi về hoa.\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Không dễ lấy được hạt giống bí ẩn đâu. mau đưa nó cho Nguyệt Lão\n"
											BLK "Phần thưởng:Kinh nghiệm +500");
										break;
									case 4:
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Hỏi Ông già thông minh trong làng về việc hoa của hạt giống.\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Viện công an nói rằng một lão già thông minh trong làng non có thể biết đủ thứ và biết rõ thế giới. Có lẽ ông ấy biết cách làm cho hạt nở.\n"
											BLK "Phần thưởng:Kinh nghiệm +500 Tiềm năng +10");
										break;
									case 5:
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "	  Đi tìm Vong Tình Bà Bà ở Đào Nguyên Thôn\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    14/2 là một ngày kỳ diệu. một chàng trai tình yêu có thể có hoa hồng với nhiều ý nghĩa khác nhau nhờ sự chân thành và sức mạnh của mình. Có vẻ như bạn cũng là một cô gái chân thành. Vậy, hãy tới ở Đào Nguyên Thôn và tìm mẹ vợ cô ấy. Cô ấy sẽ chỉ cho bạn cách kiếm chocolate!\n"
											BLK "Phần thưởng:Kinh nghiệm +500");
										break;
									case 6:
										lefttime = 1800 - gone_time(who->get_quest("valentine.time"));
										if (lefttime < 0)
											lefttime = 1;
										tasktype = 4;
										x = who->get_quest("valentine.x");
										y = who->get_quest("valentine.y");
										z = who->get_quest("valentine.z");

										map = get_map_object(z);
										name = map ? map->get_name() : "Bản đồ vô danh";
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Đi %s Quốc (%d,%d)Tìm Vong Tình Bà Bà Son Đỏ, Lược, trâm, giờ còn lại việc %s phút.\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Than thở,Tôi nghĩ mẹ vợ tôi cũng là một cô gái thiên thần,Valentine s ẽ đến, cô ấy cũng muốn ăn diện, anh đi đi %s Quốc (%d,%d),Đi ra ngoài thành phố tìm bọn quậy đó, có thể chúng mặc áo hồng, tổ hợp và kẹp tóc để các cô gái thích.\n"
											BLK "Phần thưởng:Kinh nghiệm +500 Tiềm năng +10", name, x, y, "%d", name, x, y);
										break;
									case 7:
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "   Lấy Đậu Socola Hãy trao nó cho Hồng Nương.\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Điều quan trọng nhất của ngày Valentine là các chàng trai tặng hoa cho các cô gái và các cô gái tặng anh trai chocolate Đậu Socola,Người mai mối phải biết cách Đậu Socola Hãy hỏi cô ấy!\n"
											BLK "Phần thưởng:Kinh nghiệm +500");
										break;
									case 8:
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Hỏi "
											HIR "Yêu tinh Socola"
											NOR " cách làm chocolate.\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Hồng gniang nói rằng có một vực sâu nằm ở phía Tây Bắc bên ngoài làng non. có một cô tiên sô cô la sống cạnh vách đá. cô ấy sẽ biết cách làm sô cô la!\n"
											BLK "Phần thưởng:Kinh nghiệm +500 Tiềm năng +10");
										break;
									}
								}

							}
							else if (iFlag == 1 && iTask == TID_QIXI && iKind) {
								if (iKind == who->get_save_2("qixi.flag")) {
									switch (iKind) {
										/*				case 1:
										result = sprintf(BLK"Mục đích nhiệm vụ:\n"BLK"    领取号码牌,与有缘人一起Đi找月老\n" BLK"Miêu tả nhiệm vụ:\n"BLK"    上天给了牛郎织女一次机会,只要抓住这次机会,那么他们以后就不用再隔河相望了,他们需要一对有缘人的帮助,所以,只要找到与我的"HIR "号码牌"BLK"相同号码的有缘人,我们就能给他们帮助了,因此,我决定赶快找到我的有缘人,然后再Đi向"HIR "月老"BLK"打听一下情况.\n"BLK"Phần thưởng:\n"BLK"    Kinh nghiệm + 2000");
										break;*/
									case 3:
										if (who->get_gender() == 1)
											result = sprintf(BLK "Mục đích nhiệm vụ:\n"
												BLK "    Tìm ra nơi ở của Mẫu Hậu\n"
												BLK "Miêu tả nhiệm vụ:\n"
												BLK "    Hóa ra chăn bò và cô gái thợ dệt Thiên Hà bị chia cắt vì Thái hậu, nhưng để giúp họ, trước tiên bạn phải tìm được Thái hậu. Nghe nói có một yêu thích"
												HIR "Lang thang"
												BLK "Những người trong nhóm đã nhìn thấy Thái hậu và tôi không biết đó có phải là sự thật không. Tôi sẽ hỏi Đi trước. Trước tiên, tôi sẽ hỏi các thành viên trong nhóm"
												HIR "Đã đến"
												BLK ",Có thể kết hợp thông tin nhanh chóng lấy được manh mối mới.\n"
												BLK "Phần thưởng:\n"
												BLK "    Ngân lượng 500\n"
												BLK "    Kinh nghiệm + 50");
										else
											result = sprintf(BLK "Mục đích nhiệm vụ:\n"
												BLK "    Tìm ra nơi ở của Mẫu Hậu\n"
												BLK "Miêu tả nhiệm vụ:\n"
												BLK "    Hóa ra chăn bò và cô gái thợ dệt Thiên Hà bị chia cắt vì Thái hậu, nhưng để giúp họ, trước tiên bạn phải tìm được Thái hậu. Nghe nói có một yêu thích"
												HIR "Lang thang"
												BLK "Những người trong nhóm đã nhìn thấy Thái hậu và tôi không biết đó có phải là sự thật không. Tôi sẽ hỏi Đi trước. Trước tiên, tôi sẽ hỏi các thành viên trong nhóm"
												HIR "Đã đến"
												BLK ",Có thể kết hợp thông tin nhanh chóng lấy được manh mối mới.\n"
												BLK "Phần thưởng:\n"
												BLK "    Ngân lượng 500\n"
												BLK "    Kinh nghiệm + 50");
										break;
										/*				case 5:
										if (who->get_gender() == 1)
										result = sprintf(BLK"Mục đích nhiệm vụ:\n"BLK"    找寻王母娘娘\n" BLK"Miêu tả nhiệm vụ:\n"BLK"    据服装店老板说,有一个十分喜欢"HIR "云游"BLK"的人无意间提到曾经见过王母娘娘,看来只要找到这个人就能知晓王母娘娘的下落了.最好问一下"HIR "同伴"BLK"有没有线索\n"BLK"Phần thưởng:\n"BLK"    Ngân lượng 5000\n"BLK"    Kinh nghiệm + 3000");
										else
										result = sprintf(BLK"Mục đích nhiệm vụ:\n"BLK"    找寻王母娘娘\n" BLK"Miêu tả nhiệm vụ:\n"BLK"    据服装店老板说,有一个卖珍稀品的"HIR "商人"BLK"无意间提到曾经见过王母娘娘,看来只要找到这个人就能知晓王母娘娘的下落了.最好问一下"HIR "同伴"BLK"有没有线索\n"BLK"Phần thưởng:\n"BLK"    Ngân lượng 5000\n"BLK"    Kinh nghiệm + 3000");
										break;
										case 7:
										result = sprintf(BLK"Mục đích nhiệm vụ:\n"BLK"    找寻王母娘娘\n" BLK"Miêu tả nhiệm vụ:\n"BLK"    据云游商人说,王母娘娘曾经现身昆仑"HIR "瑶池"BLK".以昆仑浓厚的灵气,王母娘娘一定会在那里多呆一段时间的.现在赶过Đi,说不定就能找到王母娘娘.\n"BLK"Phần thưởng:\n"BLK"    Ngân lượng 5000\n"BLK"    Kinh nghiệm + 3000");
										break;*/
									case 9:
										lefttime = 1800 - gone_time(who->get_save_2("qixi.time"));
										//					if ( lefttime < 0 )
										//						lefttime = 1;
										tasktype = 4;
										x = who->get_save_2("qixi.x");
										y = who->get_save_2("qixi.y");
										z = who->get_save_2("qixi.z");

										map = get_map_object(z);
										name = map ? map->get_name() : "Bản đồ vô danh";
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "   Đánh bại yêu quái và lấy tiên dược, Thời gian còn lại %s phút.\n"
											BLK "    Chất(0/1)\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Khi tôi tìm thấy thương nhân của Vân Nam, Thái hậu đã không có ở đó, thương nhân của Vân Lăng nói rằng chỉ cần thu thập được một viên tiên dược cho hắn, hắn sẽ cho biết nơi ở của Thái hậu. Người ta nói rằng %s Quốc (%d,%d) Có thần dược này,Tại sao bạn không đi một chuyến đi, cô gái nói rằng thuốc tiên có một linh thú mạnh mẽ,Sau đó, tôi đầu tiên hãy sẵn sàng đi.\n"
											BLK "Phần thưởng:\n"
											BLK "    Ngân lượng 500\n"
											BLK "    Kinh nghiệm + 50", "%d", name, x, y);
										break;
									case 10:
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "   Đánh bại yêu quái và lấy tiên dược.\n"
											BLK "    Chất(1/1)\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Đã Hoàn thành, Quay lại Đi Tìm một thương gia lang thang!");
										break;
									case 12:
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "    Đưa lọ thần dược do Thái hậu trao cho bò cái và cô gái dệt\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Sau muôn vàn khó khăn, cuối cùng tôi cũng chọn được thuốc tiên mà Thái hậu cần, và Thái hậu đã cho chúng tôi thuốc tiên. Bà ấy nói rằng miễn là được choALT+G)"
											HIR "Cô gái chăn bò và thợ dệt"
											BLK ",Họ sẽ có thể sống hạnh phúc bên nhau trong tương lai, ừm! Tôi tin rằng họ đã chờ đợi, tôi sẽ cho họ Đi càng sớm càng tốt.\n"
											BLK "Phần thưởng:\n"
											BLK "    Ngân lượng 50000\n"
											BLK "    Kinh nghiệm + 50000\n"
											BLK "    Tình yêu mạnh hơn vàng");
										break;
									}
								}

							}
							else if (iFlag == 1 && iTask == TID_ESCORT && iKind && iKind == who->get_quest("escort.flag")) {

								if (iKind == 1) // 1. Nhiệm vụ áp tiêu(物品)
								{
									tasktype = 4;
									lefttime = 2400 - gone_time(who->get_quest("escort.time")); // 40 phút

									result = sprintf(BLK "Mục đích nhiệm vụ:\n"
										BLK "    Vận chuyển Vật phẩm quý giá đến %s giao cho %s (Còn thừa %s phút)\n"
										BLK "Miêu tả nhiệm vụ:\n"
										BLK "    Trước đó vài ngày có người uỷ thác ta đem rương bạc tới "
										HIR "%s Quốc "
										BLK " giao cho "
										HIR "%s "
										BLK ", ta thật sự không rảnh rổi, ngươi hãy đi đi !\n", name = who->get_quest("escort.city"), id = who->get_quest("escort.name"), "%d", name, id);
								}
								else if (iKind == 2) // 2. Nhiệm vụ áp tiêu(人物)
								{
									tasktype = 4;
									lefttime = 2400 - gone_time(who->get_quest("escort.time"));

									result = sprintf(BLK "Mục đích nhiệm vụ:\n"
										BLK "    Hộ tống %s đến "
										HIR "%s"
										BLK " (Còn thừa %s phút)\n"
										BLK "Miêu tả nhiệm vụ:\n"
										BLK "    Vị đại nhân này là "
										HIR "%s "
										BLK " thân hữu, hắn hy vọng có thể nhìn thấy thân hữu, nhưng do đường xá xa xôi và hiểm ác, mà hắn thì không biết võ công, cho nên ngươi hãy hộ tống hắn đi "
										HIR "%s Quốc (%d,%d) ở %s"
										BLK ".\n", who->get_quest("escort.npcname"), name = who->get_quest("escort.name"), "%d", name, who->get_quest("escort.city"), who->get_quest("escort.x"), who->get_quest("escort.y"), name);
								}
								else if (iKind == 3) {
									lefttime = gone_time(who->get_quest("escort.time"));
									npc_info = who->get_quest("escort.npcinfo");
									if (!arrayp(npc_info)) {
										result = BLK "Nhiệm vụ thất bại! Xin hãy bỏ nhiệm vụ!";
									}
									else
										result = sprintf(BLK "Mục đích nhiệm vụ:\n"
											BLK "   Hộ tống %s đến Địa điểm %s\n"
											BLK "Thời gian:"
											HIR " %d 分 %d 秒\n"
											BLK "Hoàn thành:%s\n"
											BLK "Miêu tả nhiệm vụ:\n"
											BLK "    Hoan nghênh bạn tham gia Cuộc thi Vua phi tiêu trong Cúp Siêu nhân này. Đây là cuộc thi về tốc độ và may mắn, cuộc thi của trí tuệ và công nghệ. Giải thưởng lớn đang vẫy gọi bạn và niềm vinh dự đang bay lơ lửng trên đầu bạn! Là đúng là vua phi tiêu thời Chiến quốc, chỉ tôi biết sau khi thử.\n"
											BLK "    Đầu phi tiêu cũ của Yuchi cho phép bạn gửi siêu nhân vua phi tiêu càng sớm càng tốt %s 的 %s(%s)处,Hoàn thành Thời gian càng ngắn, bạn càng nhận được nhiều phần thưởng. Hãy nhanh chân Đi nào!\n"
											BLK "Phần thưởng:\n"
											BLK "    trong 3phút Hoàn thành Phần thưởng 55000 vàng\n"
											BLK "    trong 3phút 4phút Hoàn thành Phần thưởng 45000 vàng\n"
											BLK "    trong 4phút Hoàn thành Phần thưởng 30000 vàng\n", npc_info[0], npc_info[1], lefttime / 60, lefttime % 60, npc_info[0], npc_info[0], npc_info[1], npc_info[2]);
								}
							}
							else
								if (iFlag == 1 && who->get_save_2("marrytask") && iTask == TID_HONGNIANG && iKind == 1) {
									tasktype = 4;
									lefttime = 3600 - gone_time(who->get_save_2("marrytask.time"));
									result = sprintf(BLK "Mục đích nhiệm vụ:\n    "
										BLK "Hãy giúp Hồng Nương %s (Thời gian còn lại %s phút)\n"
										BLK "Miêu tả nhiệm vụ:\n    "
										BLK "%s Quốc (%d,%d)có một %s,Yêu cầu “Người mai mối tốt nhất thế giới”.Anh ta bị giới hạn mai mối trong vòng ba ngày Rời khỏi.Chu Quả, nếu thấy người mai mối ba ngày nữa vẫn nói chuyện về bà mối, sẽ mang người đến đập biển hiệu của bà mối, bạn Đi sẽ dạy cho hắn một bài học, kẻo hắn lộng hành!\n"
										BLK "Phần thưởng:  Khoá đồng tâm", who->get_save_2("marrytask.name"), "%d", who->get_save_2("marrytask.country"), who->get_save_2("marrytask.x1"), who->get_save_2("marrytask.y1"), who->get_save_2("marrytask.name"));
								}
								else
									if (iFlag == 1 && who->get_save_2("master_hide") && iTask == TID_MASTER_HIDE && iKind == 1) {
										tasktype = 4;
										lefttime = 2400 - gone_time(who->get_save_2("master_hide.time"));
										result = sprintf(BLK "Nhiệm vụ:\n    "
											BLK "Tiêu diệt %s (Thời gian còn %s phút)\n"
											BLK "Nhiệm vụ miêu tả:\n    "
											BLK "Gần đây Tây Vực phái đến một Người tự xưng là Thiên Hạ Vô Địch %s, thật là kiêu ngạo, hắn còn dám đến Bổn môn khiêu khích đòi gây chiến, nếu không tiêu diệt hắn thì sẽ khiến thiên hạ chê cười.Sư phụ lệnh ngươi đến %s Quốc (%d,%d) tiêu diệt hắn rồi báo cho Sư phụ biết !\n"
											BLK "Phần thưởng nhiệm vụ:\n"
											BLK "    Ngân lượng:1500000 \n"
											BLK "    Kinh nghiệm:%d \n"
											BLK "    Tiềm năng:%d\n", who->get_save_2("master_hide.name"), "%d", who->get_save_2("master_hide.name"), who->get_save_2("master_hide.country"), who->get_save_2("master_hide.x1"), who->get_save_2("master_hide.y1"), who->get_save_2("master_hide.exp"), who->get_save_2("master_hide.potential"));
									}
									else
										if (iFlag == 1 && who->get_fam_name() && iTask == TID_MASTER && iKind > 0 && iKind == who->get_save_2("mastertask.type")) {
											TASK_MASTER_D->send_task_intro(who);
										}
										else
											if (iFlag == 1 && iTask == TID_CHAIN) {
												CHAIN_D->send_task_intro(who);
											}
											else
												if (iFlag == 2 && iTask == TID_ZHOUGUO && iKind == 15) {
													tasktype = 4;
													task_jq = 2;
													lefttime = 2400 - gone_time(who->get_quest("escort.time"));
													result = sprintf(BLK "Mục đích nhiệm vụ:\n"
														BLK "   Gửi phi tiêu bạc đến Ma Dahan ở làng Lệ Hoa bên ngoài thành phố, Hàn Quốc(Còn lại %s phút)\n"
														BLK "Hoàn thành nhiệm vụ:\n"
														HIR "    Han Quoc Ma Dahan ở làng Lệ Hoa bên ngoài thành phố\n"
														BLK "Miêu tả nhiệm vụ:\n"
														BLK "    Người đứng đầu phi tiêu cũ của Yuchi có thể mang lại cho bạn cơ hội kiếm tiền, nhưng trong những ngày gần đây, có một số con chuột bất tài và đạo đức đã lừa rất nhiều phi tiêu từ anh ta dưới biểu ngữ giúp đỡ anh ta. Vì vậy, trong tương lai , bất cứ ai muốn chơi phi tiêu tại Yuchi Lao Biaotou sẽ phải vượt qua bài kiểm tra của mình trước.\n"
														BLK "    Đầu tiên bạn vận chuyển phi tiêu bạc đến Ma Dahan ở làng Lệ Hoa bên ngoài Hán Thành. Lần này anh ta sẽ không thu tiền đặt cọc của bạn, nhưng bạn phải nhớ rằng bạn không được sử dụng trạm hoặc đạo cụ và phép thuật trong quá trình vận chuyển phi tiêu. Nếu không, nhiệm vụ của bạn sẽ thất bại!\n"
														BLK "Phần thưởng:\n"
														BLK "    Ngân lượng:60000", "%d");
												}
												else
													if (iFlag == 2 && iTask == TID_NEWBIE_00 && iKind) {
														tasktype = 1;
														result = sprintf(BLK "Mục tiêu nhiệm vụ:\n"
															BLK " Mỗi đại hiệp đến Tân Thủ Thôn đều đến báo với Thần Tiên Gia Gia. Thần Tiên Gia Gia chính là cổng vào của Tân Thủ Thôn. Sau khi từ Thiên Đàn xuống, đi dọc theo con đường nhỏ đá xanh đi thẳng là có thể đến.\n"
															BLK "Người hoàn thành nhiệm vụ: \n"
															BLK " Thần Tiên Gia Gia ở Tân Thủ Thôn \n"
															BLK "Miêu tả nhiệm vụ:\n"
															BLK " Hoan nghênh ngươi đã đến Chiến Quốc, đây là Tân Thủ Thôn, mỗi đại hiệp đến thôn này đều phải báo cho Thần Tiên Gia Gia biết, Thần Tiên Gia Gia chính là cổng vào của Tân Thủ Thôn. Sau khi từ Thiên Đàn xuống, đi dọc theo con đường nhỏ đá xanh đi thẳng là có thể đến.\n"
															BLK "Phần thưởng nhiệm vụ:\n"
															BLK " Kinh nghiệm: 20\n"
															BLK " Tiềm năng: 20\n"
															BLK "500 lượng\n"
															BLK "Nửa tiếng gấp đôi Kinh nghiệm\n ");
													}
													else
														if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 1) {
															tasktype = 1;
															if (!who->get_legend(TASK_NEWBIE_00, 4))
																result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																	BLK "   Yêu cầu một thanh kiếm gỗ từ chủ cửa hàng vũ khí\n"
																	BLK "Kiếm gỗ 0/1\n"
																	BLK "Miêu tả nhiệm vụ:\n"
																	BLK "    Tôi mới đến ngôi làng này và tôi chưa quen với môi trường của làng mới, ông nội Bất tử bảo tôi đi theo con đường mòn đá xanh bên cạnh và đi thẳng lên, sau khi đi qua tiệm cầm đồ, tôi đến cửa hàng vũ khí, chờ tìm Chủ cửa hàng vũ khí, Ông ấy sẽ cho tôi những thứ tôi muốn, nếu ông cần, xin hãy đưa những thứ này cho Ông nội Bất tử, ông ấy đang rất vội.!\n"
																	BLK "Lựa chọn phần thưởng: Dao gỗ mới bắt đầu、Gậy dài, giáo tre\n");
															if (who->get_legend(TASK_NEWBIE_00, 4) && !who->get_legend(TASK_NEWBIE_00, 5))
																result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																	BLK "    Yêu cầu một thanh kiếm gỗ từ chủ cửa hàng vũ khí\n"
																	BLK "Kiếm gỗ 1/1\n"
																	BLK "Miêu tả nhiệm vụ:\n"
																	BLK "    Tôi mới đến ngôi làng này và tôi chưa quen với môi trường của làng mới, ông nội Bất tử bảo tôi đi theo con đường mòn đá xanh bên cạnh và đi thẳng lên, sau khi đi qua tiệm cầm đồ, tôi đến cửa hàng vũ khí, chờ tìm Chủ cửa hàng vũ khí, Ông ấy sẽ cho tôi những thứ tôi muốn, nếu ông cần, xin hãy đưa những thứ này cho Ông nội Bất tử, ông ấy đang rất vội.!\n"
																	BLK "Lựa chọn phần thưởng: dao gỗ mới bắt đầu, thanh gỗ dài, giáo tre\n");
														}
														else
															if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 2) {
																tasktype = 1;
																if (who->get_legend(TASK_NEWBIE_00, 3))
																	result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																		BLK "    Đi Giết 5 Con gà nhỏ "
																		HIR "Chim trĩ bé nhỏ"
																		BLK "Lùi"
																		HIR "Người chủ tiệm vũ khí"
																		BLK "báo cáo\n"
																		BLK "    Con gà nhỏ 5/5\n"
																		BLK "Hoàn thành nhiệm vụ:\n"
																		BLK "    Chủ cửa hàng vũ khí\n"
																		BLK "Miêu tả nhiệm vụ:\n"
																		BLK "    Bên ngoài ngôi làng mới sinh này, có một số loài động vật rất kỳ lạ, chúng không thân thiện như gà, thỏ và bù nhìn thông thường. Chúng sẽ tấn công mọi người. Loại bỏ những con quái vật này là những gì chúng tôi đang làm. Bây giờ, Nếu tôi có thể loại bỏ 5 gà nhỏ, tôi chắc chắn sẽ nhận được rất nhiều phần thưởng!\n"
																		BLK "    Anh ta nói rằng chủ cửa hàng vũ khí sẽ vui lòng cho tôi một thứ gì đó và bảo tôi hãy tìm chủ cửa hàng vũ khí sau khi giết Đi.\n"
																		BLK "Phần thưởng:\n"
																		BLK "    Kinh nghiệm +:350点\n"
																		BLK "    Tiềm năng +:30点\n"
																		BLK "    Ngân lượng:800\n"
																		BLK "    物品:Trái quýt×5\n");
																else
																	result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																		BLK "     Đi Giết 5 Con gà nhỏ "
																		HIR "小山鸡"
																		BLK "后向"
																		HIR "武器店老板"
																		BLK "汇报\n"
																		BLK "    Con gà nhỏ %d/5\n"
																		BLK "Hoàn thành nhiệm vụ:\n"
																		BLK "    Chủ cửa hàng vũ khí\n"
																		BLK "Miêu tả nhiệm vụ:\n"
																		BLK "    在这个新手村外,分布着一些很奇怪的动物,他们不像普通的小鸡、小兔、稻草人一样的友善,他们会攻击人,除掉这些怪物是我们一直以来在做的事情.现在,如果我能够除掉5只小山鸡,一定会拿到很多的奖励!\n"
																		BLK "    他说武器店老板会很乐意给我一些东西的,叫我杀完后Đi找武器店老板.\n"
																		BLK "Phần thưởng:\n"
																		BLK "    Kinh nghiệm +:350点\n"
																		BLK "    Tiềm năng +:30点\n"
																		BLK "    Ngân lượng:800\n"
																		BLK "    物品:Trái quýt×5\n", who->get_save_2("new_sj"));
															}
															else
																if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 4) {
																	tasktype = 1;
																	if (who->get_legend(TASK_NEWBIE_01, 5)) {
																		if (!objectp(item = present("Tàng Bảo Đồ", who, 1, MAX_CARRY)) || item->is_xunbao() != 1)
																			result = BLK "Mục đích nhiệm vụ:\n"
																			BLK "    Tìm bản đồ kho báu ở viễn đông bên ngoài Tân Thủ Thôn.\n"
																			BLK "Tàng Bảo Đồ  0/1\n"
																			BLK "Miêu tả nhiệm vụ:\n"
																			BLK "    Trước hết, tôi muốn tìm một bản đồ kho báu, nó phải ở ngay bên cạnh thác nước ở phía đông của làng Xinshou, có cả Old Man Chen ở đó nữa, tôi nghi ngờ rằng Old Man Chen đã cố tình sắp xếp để theo dõi tôi. trái tim hơi lạnh. Tôi phải cẩn thận. Anh ấy. Hãy nghĩ về điều đó, nó thực sự thú vị! Khi tôi tìm thấy bản đồ kho báu, tôi quay trở lại với chủ cửa hàng áo giáp, và anh ta sẽ cho tôi biết manh mối tiếp theo!\n"
																			BLK "Phần thưởng:\n"
																			BLK "    120点Kinh nghiệm +\n"
																			BLK "    10点Tiềm năng +";
																		else
																			result = BLK "Mục đích nhiệm vụ:\n"
																			BLK "    Tìm bản đồ kho báu ở viễn đông bên ngoài Tân Thủ Thôn.\n"
																			BLK "Tàng Bảo Đồ  1/1\n"
																			BLK "Miêu tả nhiệm vụ:\n"
																			BLK "    首先我要找到一张藏宝图,它应该就在新手村最东边的瀑布旁,那儿还有个陈老头,我怀疑陈老头是故意安排在那监视我的,心里有点寒寒的,我得提防着他.想想,还真有点刺激!等我找到藏宝图后,回到防具店老板那里,他会告诉我下一条线索!\n"
																			BLK "Phần thưởng:\n"
																			BLK "    120点Kinh nghiệm +\n"
																			BLK "    10点Tiềm năng +";

																	}
																}
																else
																	if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 5) {
																		tasktype = 1;
																		if (who->get_legend(TASK_NEWBIE_01, 7) && !who->get_legend(TASK_NEWBIE_01, 8))
																			result = BLK "Mục đích nhiệm vụ:\n"
																			BLK "    Sử dụng bản đồ kho báu để tìm mặt dây chuyền ngọc bích của gia đình\n"
																			BLK "Ngọc đình  0/1\n"
																			BLK "Miêu tả nhiệm vụ:\n"
																			BLK "    Chủ tiệm áo giáp bảo tôi đi về phía nam với bản đồ kho báu trên tay, tìm trên hòn đảo mà Thành nổi bật nhất, nó nằm trong đám cỏ (88, 62), nếu tìm được thì bạn. có thể đào kho báu! Nhiệm vụ này tốt hơn Sẽ có nhiều phần thưởng hơn khi tìm thấy bản đồ kho báu, vì vậy tôi sẵn sàng chấp nhận thử thách này. Sau khi tìm được kho báu, Đi tìm chủ hiệu thuốc và ông ấy sẽ cho tôi thứ gì muốn!\n"
																			BLK "Phần thưởng:\n"
																			BLK "    200点Kinh nghiệm +\n"
																			BLK "    40点Tiềm năng +\n"
																			BLK "    1000金\n"
																			BLK "    行军散×10";
																		else if (who->get_legend(TASK_NEWBIE_01, 7) && who->get_legend(TASK_NEWBIE_01, 8))
																			result = BLK "Mục đích nhiệm vụ:\n"
																			BLK "   Sử dụng bản đồ kho báu để tìm mặt dây chuyền ngọc bích của gia đình\n"
																			BLK "Ngọc đình  1/1\n"
																			BLK "Miêu tả nhiệm vụ:\n"
																			BLK "    防具店老板叫我拿着手上的藏宝图一直向南走,到Thanh最突出那个岛上好好找找,就在草丛里(88,62),找到那里,就可以挖宝了!这个任务比找到藏宝图的奖励会更多,所以,我愿意接受这个Thử thách.等我找到宝物后,Đi找药店老板,他会给我想要的东西!\n"
																			BLK "Phần thưởng:\n"
																			BLK "    200点Kinh nghiệm +\n"
																			BLK "    40点Tiềm năng +\n"
																			BLK "    1000金\n"
																			BLK "    行军散×10";
																	}
																	else
																		if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 8) {
																			tasktype = 1;
																			if (who->get_legend(TASK_NEWBIE_01, 14) && !who->get_legend(TASK_NEWBIE_01, 16))
																				result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																					BLK "    Giết con thỏ nhỏ bên ngoài làng Đi mới, lấy cái búa và đưa cho chủ tiệm sửa chữa\n"
																					BLK "Cây búa: %d/1\n"
																					BLK "Miêu tả nhiệm vụ:\n"
																					BLK "    杂货店老板答应了修理店老板,给他找到一把铁锤,据他打听来的消息,分布在新手村外、幽谷、Thanh的小野兔身上带着铁锤,但是对于我来说,他们的力量有点强大,所以这对我来说可是个大的Thử thách,我喜欢Thử thách!\n"
																					BLK "Phần thưởng:\n"
																					BLK "    300Kinh nghiệm +\n"
																					BLK "    50点Tiềm năng +\n"
																					BLK "    2500金\n"
																					BLK "    5正气散", who->get_legend(TASK_NEWBIE_01, 15) ? 1 : 0);
																		}
																		else
																			if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 14) {
																				tasktype = 1;
																				if (who->get_legend(TASK_NEWBIE_02, 1) && (!who->get_legend(TASK_NEWBIE_02, 2) || !who->get_legend(TASK_NEWBIE_02, 3)))
																					result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																						BLK "   Giết con thỏ bên ngoài làng Đi mới, lấy viên đá lửa và đưa viên đá lửa cho chủ tiệm cầm đồ\n"
																						BLK "Đá lửa:%d/5\n"
																						BLK "Miêu tả nhiệm vụ:\n"
																						BLK "    刚从仙灵岛来到这儿,还真需要一些行军散,这些都是对我的气血非常有用的.对吗？既然当铺老板很愿意给我一些行军散,虽然他叫我帮他弄5个Hỏa Thạch来,但是这些都难不倒我!只要Đi新手村外杀掉那些讨厌的野兔,就可能会有Hỏa Thạch了.\n"
																						BLK "Phần thưởng:行军散10包,Kinh nghiệm +100点", who->get_save_2("huoyanshi"));
																			}
																			else
																				if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 15) {
																					tasktype = 1;
																					if (who->get_legend(TASK_NEWBIE_02, 4) && (!who->get_legend(TASK_NEWBIE_02, 5) || !who->get_legend(TASK_NEWBIE_02, 6)))
																						result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																							BLK "    Giết 10 con gà nhỏ\n"
																							BLK "Con gà nhỏ %d/10\n"
																							BLK "Miêu tả nhiệm vụ:\n"
																							BLK "    村外的那些山鸡太可恶了,昨天居然跑到村子里的店铺偷吃!武器店老板气坏了,叫我Đi帮他杀死那帮盗贼.他叫我顺着这条路一直走,只要出了这个村子,我就能见到那些可恶的山鸡了.只要我能杀死10只小山鸡,他会给我很多奖励哦!\n"
																							BLK "Phần thưởng:Kinh nghiệm +110点,Tiềm năng +10点,600金,长木剑、布拳套(二选一)", who->get_save_2("newbie_sanji"));
																				}
																				else
																					if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 16) {
																						tasktype = 1;
																						result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																							BLK "    给Gà gô!Tìm nguồn cấp dữ liệu yêu thích\n"
																							BLK "Thức ăn cho gà %d/1\n"
																							BLK "Hoàn thành nhiệm vụ:Làng mới Gà gô!\n"
																							BLK "Miêu tả nhiệm vụ:\n"
																							BLK "    Gà gô!十分兴奋地在我面前拍打着翅膀,好像是期待着我给它某些东西一样.是肚子饿了吗？\n"
																							BLK "    也许我该到村外转转,说不定能找到小鸡喜欢的饲料也说不定.听说"
																							HIR "Đi往巴丘路上的刘大叔"
																							BLK "就有Gà gô!爱吃的饲料.\n"
																							BLK "Phần thưởng:100点Kinh nghiệm +\n"
																							BLK "          5个Trái quýt", who->get_legend(TASK_NEWBIE_02, 8) ? 1 : 0);

																					}
																					else
																						if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 19) {
																							tasktype = 1;
																							result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																								BLK "    Giúp bù nhìn kỳ lạ tìm một viên đá thần có thể thay thế đầu của anh ta.\n"
																								BLK "Đá Tinh Linh:%d/1\n"
																								BLK "Hoàn thành nhiệm vụ:Làng mới"
																								HIR "Bù nhìn kỳ lạ\n"
																								BLK "Miêu tả nhiệm vụ:\n"
																								BLK "    稻草人整个身体除了一堆稻草外就只有布片和木杆.因此常常遭到那些该死的乌鸦嘲笑没大脑.稻草人虽然十分生气,但却不得不承认这是事实.如果它也像人类一样有一个大脑的话,那些乌鸦也不敢再嘲笑它了.\n"
																								BLK "    稻草人曾经听说"
																								HIR "Thanh的丁大叔"
																								BLK "在长白天池中取到了不少的Đá Tinh Linh,如果用将那些Đá Tinh Linh作为其脑袋的话应该相当不错.可惜稻草人没有脚,不能自己亲自Đi.如果我能帮它的忙,稻草人会十分感激我.\n"
																								BLK "Phần thưởng:180点Kinh nghiệm +\n"
																								BLK "          30点Tiềm năng +", who->get_legend(TASK_NEWBIE_00, 18) ? 1 : 0);
																						}
																						else
																							if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 20) {
																								tasktype = 1;
																								result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																									BLK "    Giết Tướng ác Hồ Thanh\n"
																									BLK "Tướng ác %d/1\n"
																									BLK "Miêu tả nhiệm vụ:\n"
																									BLK "    老村长果然是尽心尽力,这恶将胡仗着自己家有钱有势,勾结地方官府,欺压百姓,至今Với sự trừng phạt.我要替天行道,杀死恶将胡.恶将胡就在Thanh的Thanh北野,最东边的地方.\n"
																									BLK "Phần thưởng:550点Kinh nghiệm +、60点Tiềm năng +、2600金、10个Trái quýt", who->get_legend(TASK_NEWBIE_02, 15) ? 1 : 0);
																							}
																							else
																								if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 21) {
																									tasktype = 1;
																									if (!who->get_legend(TASK_NEWBIE_02, 20))
																										result = BLK "Mục đích nhiệm vụ:\n"
																										BLK "    Mang rượu ‘Bạch lang‘ nổi tiếng thế giới đến Old Man Chen\n"
																										BLK "Bạch lang 0/1\n"
																										BLK "Miêu tả nhiệm vụ:\n"
																										BLK "    据说有一壶天下名酒‘Bạch lang’就收藏在李老汉的家中.陈老头多次登门讨酒,但都遭到了拒绝.也许我能帮上陈老头的忙,将酒讨回来.\n"
																										BLK "    李老汉就在村子的正北方,在Đi往巴丘的路上很容易就能找到.\n"
																										BLK "Phần thưởng:200Kinh nghiệm +,3000金,5张回城符";
																									else
																										result = BLK "Mục đích nhiệm vụ:\n"
																										BLK "    Mang rượu ‘Bạch lang‘ nổi tiếng thế giới đến Old Man Chen\n"
																										BLK "Bạch lang 1/1\n"
																										BLK "Miêu tả nhiệm vụ:\n"
																										BLK "    据说有一壶天下名酒‘Bạch lang’就收藏在李老汉的家中.陈老头多次登门讨酒,但都遭到了拒绝.也许我能帮上陈老头的忙,将酒讨回来.\n"
																										BLK "    李老汉就在村子的正北方,在Đi往巴丘的路上很容易就能找到.\n"
																										BLK "Phần thưởng:200Kinh nghiệm +,3000金,5张回城符";
																								}
																								else
																									if (iFlag == 2 && iTask == TID_NEWBIE_01 && iKind == 22) {
																										tasktype = 1;
																										if (!who->get_legend(TASK_NEWBIE_02, 29))
																											result = BLK "Mục đích nhiệm vụ:\n"
																											BLK "    Loại bỏ những kẻ bắt nạt ,然后回黄大叔处复命.\n"
																											BLK "Hạt bồ đà điểu 0/1\n"
																											BLK "Miêu tả nhiệm vụ:\n"
																											BLK "    那黄大叔居然是一个密探,真了不起,他找到了恶霸李麻子,但是身份特殊,自己不能露脸,所以请我帮这个忙,我也算是个正义之士,就帮了他这个忙吧!恶霸李麻子在新手村外的蝴蝶岗,地方不大,很容易就找得到,到时候黄大叔还会给我丰厚的报酬!\n"
																											BLK "Phần thưởng:600点Kinh nghiệm +,50点Tiềm năng +,1500金";
																										else
																											result = BLK "Mục đích nhiệm vụ:\n"
																											BLK "    消灭恶霸李麻子,然后回黄大叔处复命.\n"
																											BLK "Hạt bồ đà điểu 1/1\n"
																											BLK "Miêu tả nhiệm vụ:\n"
																											BLK "    那黄大叔居然是一个密探,真了不起,他找到了恶霸李麻子,但是身份特殊,自己不能露脸,所以请我帮这个忙,我也算是个正义之士,就帮了他这个忙吧!恶霸李麻子在新手村外的蝴蝶岗,地方不大,很容易就找得到,到时候黄大叔还会给我丰厚的报酬!\n"
																											BLK "Phần thưởng:600点Kinh nghiệm +,50点Tiềm năng +,1500金";
																									}
																									else
																										if (iFlag == 2 && iTask == TID_NEWBIE_01) {
																											tasktype = 1;
																											result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																										}
	//        else
	//        if ( iFlag==2 && iTask == TID_BAQIU && iKind==1 )
	//        {
	//        	tasktype = 1;
	//		if ( !who->get_legend(TASK_NEWBIE_02, 19) )
	//	        	result = sprintf(BLK"Mục đích nhiệm vụ:\n"BLK"    帮李老汉寻找5根小麦,藉此交换他手中的名酒“Bạch lang”\n"BLK"小麦 %d/5\n"BLK"Miêu tả nhiệm vụ:\n"BLK"    在苦苦的哀求下,顽固的李老汉终于同意交出他珍藏的名酒“Bạch lang”.但是他所提出的条件便是用巴丘附近的子母蛙拥有的小麦来交换.也许我该到巴丘一带看看,说不定会有所收获.\n"BLK"Phần thưởng:220点Kinh nghiệm +,10点Tiềm năng +,名酒Bạch lang",who->get_save_2("baqiu_xiaomai"));
	//	        else
	//	        	result = BLK"Mục đích nhiệm vụ:\n"BLK"    帮李老汉寻找5根小麦,藉此交换他手中的名酒“Bạch lang”\n"BLK"小麦 5/5\n"BLK"Miêu tả nhiệm vụ:\n"BLK"    在苦苦的哀求下,顽固的李老汉终于同意交出他珍藏的名酒“Bạch lang”.但是他所提出的条件便是用巴丘附近的子母蛙拥有的小麦来交换.也许我该到巴丘一带看看,说不定会有所收获.\n"BLK"Phần thưởng:220点Kinh nghiệm +,10点Tiềm năng +,名酒Bạch lang";
	//        }
																										else
																											if (iFlag == 2 && iTask == TID_HUANJIAO && iKind == 1) {
																												tasktype = 1;
																												result = BLK "Mục đích nhiệm vụ:\n"
																													BLK "    找到孟大伯,并劝他回家\n"
																													BLK "Miêu tả nhiệm vụ:\n"
																													BLK "    孟氏和孟大伯为搬家的问题吵了一架,孟大伯早上出门后一直没回来,现在也到了该吃饭的时候了,孟大伯肯定一个人在外面抽闷烟,不想回家.唉,夫妻间哪能没有一点矛盾呢,我Đi劝劝他,让他早点回来吧.\n"
																													BLK "Phần thưởng:150点Kinh nghiệm +,20点Tiềm năng +";
																											}
																											else
																												if (iFlag == 2 && iTask == TID_YEWAI && iKind == 1) {
																													tasktype = 1;
																													result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																														BLK "    找到3罐蜜糖交给李小毛\n"
																														BLK "蜜糖:%d/3\n"
																														BLK "Hoàn thành nhiệm vụ:"
																														HIR "Thanh的李小毛\n"
																														BLK "Miêu tả nhiệm vụ:\n"
																														BLK "    小朋友都这么可爱,喜欢吃甜甜的东西,我小时候也是一样哦,蜂蜜真的好甜哦,既然他从来没吃过,那我就帮他Đi找几罐吧."
																														HIR "Thanh和幽谷"
																														BLK "附近的"
																														HIR "蜜蜂"
																														BLK "都会随身带些蜜糖在身上,应该很容易就能取得.\n"
																														BLK "Phần thưởng:380点Kinh nghiệm +\n"
																														BLK "          20点Tiềm năng +\n"
																														BLK "          8只Trái quýt", who->get_save_2("xiaomao_fengmi"));
																												}
																												else
																													if (iFlag == 2 && iTask == TID_YEWAI && iKind == 2) {
																														tasktype = 1;
																														result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																															BLK "    消灭8只小蜜蜂\n"
																															BLK "小蜜蜂 %d/8\n"
																															BLK "Miêu tả nhiệm vụ:\n"
																															BLK "    蹊跷……整个Thanh弥漫着一种神秘的气氛……那些平日和善的小蜜蜂突然成群结队的攻击周围的行人、百姓,他们的毒性与攻击力似乎提升了不少,在他们背后是不是有神秘的组织操纵着,还是他们已经被迷惑了心智？当务之急还是得消灭他们,不然会造成更大的伤亡.看来孔老头应该知道点内幕.\n"
																															BLK "Phần thưởng:370点Kinh nghiệm +,30点Tiềm năng +,2000金,5包辟毒散", who->get_save_2("xiaomifeng"));
																													}
																													else
																														if (iFlag == 2 && iTask == TID_CHUGUO) {
																															tasktype = 1;
																															result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																														}
																														else
																															if (iFlag == 2 && iTask == TID_ZHOUGUO) {
																																tasktype = 1;
																																result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																															}
																															else
																																if (iFlag == 2 && iTask == TID_DONGTINGHU && iKind == 1) {
																																	tasktype = 1;
																																	result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																																		BLK "    给庄辛找到20包干粮\n"
																																		BLK "干粮 %d/20\n"
																																		BLK "Hoàn thành nhiệm vụ:"
																																		HIR "庄辛"
																																		BLK "Miêu tả nhiệm vụ:\n"
																																		BLK "    庄辛劝说楚王考烈王不再重用身边四臣,而被楚王考烈王驳回,便与楚王考烈王达成协议,暂迁至赵 Quốc 居住,但一路上风餐露宿,需要充饥的干粮,听说上庸关的刀兵、剑兵囤储了一批.\n"
																																		BLK "Phần thưởng:Kinh nghiệm +900点,Tiềm năng +40点,1000金", who->get_save_2("zxganliang"));
																																}
																																else
																																	if (iFlag == 2 && iTask == TID_DONGTINGHU && iKind == 2) {
																																		tasktype = 1;
																																		result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																																			BLK "    杀掉%s\n"
																																			BLK "Hoàn thành nhiệm vụ:"
																																			HIR "Tướng quân Hạng Vũ\n"
																																			BLK "Miêu tả nhiệm vụ:\n"
																																			BLK "    庄辛劝说楚王考烈王不再重用身边四臣,而被楚王考烈王驳回,便与楚王考烈王达成协议,暂迁至赵 Quốc 居住,庄辛本想近日内即起程,结果大王省悟,令庄辛杀掉只知奢侈淫乐的%s,庄辛委托我Đi做此事,看来我得尽快替他办好!那%s就在%s.杀死他后报告给楚 Quốc 大将军就是了!大王一定会按功行赏的.\n"
																																			BLK "Phần thưởng:Kinh nghiệm +900点,Tiềm năng +100点,1800金,10级武器", name = who->get_save_2("zxkillnpc"), name, name, who->get_save_2("zxkillnpc1"));
																																	}
																																	else
																																		if (iFlag == 2 && iTask == TID_HANGUO) {
																																			tasktype = 1;
																																			result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																																		}
																																		else
																																			if (iFlag == 2 && iTask == TID_WEIGUO) {
																																				tasktype = 1;
																																				result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																																			}
																																			else
																																				if (iFlag == 1 && iTask == TID_ORG) {
																																					tasktype = 2;
																																					result = "/sys/sys/manager"->get_task_str(who, iKind);
																																				}
																																				else
																																					if (iFlag == 2 && iTask == TID_QIGUO) {
																																						tasktype = 1;
																																						result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																																					}
																																					else
																																						if (iFlag == 2 && iTask == TID_QINGUO) {
																																							tasktype = 1;
																																							result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																																						}
																																						else
																																							if (iFlag == 2 && iTask == TID_YANGUO) {
																																								tasktype = 1;
																																								result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																																							}
																																							else
																																								if (iFlag == 2 && iTask == TID_ZHAOGUO) {
																																									tasktype = 1;
																																									result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																																								}
																																								else
																																									if (iFlag == 2 && iTask == TID_DONGHAIDAO) {
																																										tasktype = 1;
																																										result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																																									}
																																									else
																																										if (iFlag == 2 && iTask == TID_YUNMENZE) {
																																											tasktype = 1;
																																											result = "quest/taskdesc"->get_task_str(who, iTask, iKind);
																																										}
																																										else
																																											if (iFlag == 2 && iTask == TID_MAOSHAN) {
																																												tasktype = 1;
																																												if (iKind == 2)
																																													result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																																														BLK "    Đến góc 2 và tìm cái gương,Đưa nó cho Mao\n"
																																														BLK "Gương %d/1\n"
																																														BLK "Miêu tả nhiệm vụ:\n"
																																														BLK "    Hàn Vương'an đã tham gia vào một trò lừa ác đã bị Mao Sơn cấm trong nhiều năm---Linh hồn lang thang之术.普天之下只有茅山的茅真人才可以解这种邪术.茅真人要作法解开这邪术还需要一件已经遗失多时的镜子,这镜子就在弯道2附近.我得赶快Đi把这面镜子找回来,如果韩王安梦中Linh hồn lang thang的次数达到二十一次的话,韩王安的生命也就完结了,所以我已经没有什么时间了. \n    路途凶险,我最好是结伴而行.\n"
																																														BLK "Phần thưởng:Kinh nghiệm +16000 Tiềm năng +260 Ngân lượng17000", who->get_legend(TASK_23, 9) ? 1 : 0);
																																												else if (iKind == 5)
																																													result = sprintf(BLK "Mục đích nhiệm vụ:\n"
																																														BLK "    Giết 20 và quay lại để trả lời Mao bất tử\n"
																																														BLK "Yêu nghiệt! %d/20\n"
																																														BLK "Miêu tả nhiệm vụ:\n"
																																														BLK "    Cuối cùng cũng giết được Ma Ning, mặc dù nó bị nứt. Linh hồn lang thang之术,但是还必须把韩王安之前丢失的20个灵魂吸回来,韩王安才可以得教.韩王安的灵魂被封在灵谷洞最底层的恶灵身上.杀掉那20个恶灵,让茅真人用之前我找回来的镜子把韩王安的灵魂吸回来.\n"
																																														BLK "Phần thưởng:Kinh nghiệm +17000 Tiềm năng +280 Ngân lượng19000", who->get_save_2("mzreling"));

																																											}
																																											else
																																												if (iFlag == 2 && iTask == TID_EVENTS && iKind) {
																																													tasktype = 1;
																																													result = sprintf(BLK "Mục tiêu nhiệm vụ:\n"
																																														BLK "Tiêu diệt 100 quái vật để thu thập linh hồn của chúng. Quái vật phải có cấp độ ít nhất nhỏ hơn nhân vật 10 cấp. Sau đó quay lại Sứ Giả Halloween để nhận thưởng.\n"
																																														BLK "Miêu tả nhiệm vụ: \n"
																																														BLK " Đã tiêu diệt "
																																														HIR "%d / 100 %s"
																																														NOR " \n"
																																														BLK "NPC trả nhiệm vụ: Sứ Giả Halloween\n"
																																														BLK "Phần thưởng nhiệm vụ:\n"
																																														BLK " Túi quà Bí Ngô\n"
																																														BLK "\n ", who->get_save_2("halloween.task"), who->get_save_2("halloween.task") >= 100 ? "(Hoàn thành)" : "");
																																												}
																																												else
																																													if (iFlag == 1 && iTask == TID_NEWITEMS && iKind) {
																																														switch (iKind) {
																																														case 0:
																																															result = sprintf(BLK "Mục:\n"
																																																BLK "Hãy giúp ta tìm Mảnh Ngọc Thất Truyền mang về cho ta\n"
																																																BLK "Miêu tả nhiệm vụ: \n"
																																																BLK "Đến khu vực luyện cấp, tiêu diệt bọn yêu tinh để thu lấy Mảnh Ngọc Thất Truyền."
																																																NOR "\n"
																																																BLK "NPC trả nhiệm vụ: Chiến Quốc Tổng Quản\n"
																																																BLK "Phần thưởng nhiệm vụ:\n"
																																																BLK "Hảo hữu: +1\n"
																																																BLK "\n %s", who->get_save_2("hienvien.task") >= 1 ? "(Hoàn thành)" : "");
																																															break;
																																														case 1:
																																															result = sprintf(BLK "Mục tiêu nhiệm vụ:\n"
																																																BLK "Hãy giúp ta tìm Mảnh Ngọc Thất Truyền mang về cho ta\n"
																																																BLK "Miêu tả nhiệm vụ: \n"
																																																BLK "Đến khu vực luyện cấp, tiêu diệt bọn yêu tinh để thu lấy Mảnh Ngọc Thất Truyền."
																																																NOR "\n"
																																																BLK "NPC trả nhiệm vụ: Chiến Quốc Tổng Quản\n"
																																																BLK "Phần thưởng nhiệm vụ:\n"
																																																BLK "Hảo hữu: +1\n"
																																																BLK "\n %s", who->get_save_2("hienvien.task") >= 1 ? "(Hoàn thành)" : "");
																																															break;
																																														}

																																													}
	if (stringp(result)) {
		if (tasktype == 1)
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 3, iTask, iKind, result);
		else
			if (tasktype == 4) //有Thời gian的
			{
				if (task_jq == 2) {
					if (lefttime < 0)
						send_user(who, "%c%c%c%w%w%s", 0x51, 2, 3, iTask, iKind, "Không còn thời gian nữa đâu");
					else
						send_user(who, "%c%c%c%w%w%d%s", 0x51, 2, 4, iTask, iKind, lefttime, result);
				}
				else {
					if (lefttime < 0)
						send_user(who, "%c%c%c%w%w%s", 0x51, 1, 3, iTask, iKind, "Không còn thời gian nữa đâu");
					else
						send_user(who, "%c%c%c%w%w%d%s", 0x51, 1, 4, iTask, iKind, lefttime, result);
				}
			}
			else
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 3, iTask, iKind, result);
	}
	return result;
}

void get_task_intro(object who, string arg) {
	int iFlag, iTask, iKind;

	if (sscanf(arg, "%d %d %d", iFlag, iTask, iKind) != 3)
		return;
	send_task_intro(who, iFlag, iTask, iKind);
}
void task_giveup(object who, string arg) {
	int iType, iTask, iKind;
	object npc, item;

	if (sscanf(arg, "%d %d %d", iType, iTask, iKind) != 3)
		return;
	if (iType == 1 && iTask == TID_WUYIHUODONG) {
		if (iKind == 1) {
			if (item = present("Giấy chứng nhận", who, 1, MAX_CARRY)) {
				item->remove_from_user();
				destruct(item);
			}
			who->delete_save_2("51cuanye.time");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_WUYIHUODONG, 1, "");
		}
		else if (iKind == 2) {
			if (item = present("Đá Thử Nghiệm", who, 1, MAX_CARRY)) {
				item->remove_from_user();
				destruct(item);
			}
			who->delete_save_2("51tiandao.accept");
			who->delete_save_2("51tiandao.amount");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_WUYIHUODONG, 2, "");
		}
	}
	else if (iType == 1 && iTask == TID_YUANFEN) {
		"npc/party/dodolook"->task_giveup(who);
	}
	else if (iType == 1 && iTask == TID_DAPANG) {
		who->delete_save_2("dapang");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DAPANG, 1, "");
	}
	else if (iType == 1 && iTask == TID_BANDITI && iKind == 1) {
		TASK_BANDITI_D->task_giveup(who, iKind);
	}
	else if (iType == 1 && iTask == TID_BANDITI && iKind == 2) {
		TASK_BANDITI_D->gold_task_giveup(who, iKind);
	}
	else if (iType == 1 && iTask == TID_THIEF) {
		TASK_THIEF_D->task_giveup(who, iKind);
	}
	else if (iType == 1 && iTask == TID_VALENTINE) {
		"/sys/party/valentine"->task_giveup(who, iKind);
	}
	else if (iType == 1 && iTask == TID_QIXI) {
		"/sys/party/qixi"->task_giveup(who, iKind);
	}
	else if (iType == 1 && iTask == TID_REFINE) {
		"/sys/user/refine"->task_giveup(who);
	}
	else if (iType == 1 && iTask == TID_CANTUONG) {
		"/sys/user/cantuong"->task_giveup(who);
	}
	else if (iType == 1 && iTask == TID_ORG) {
		"/sys/sys/manager"->task_giveup(who, iKind);
	}
	else if (iType == 1 && iTask == TID_CRIMINAL && iKind == 1) {
		"npc/00/8006"->task_giveup(who, iKind);
	}
	else if (iType == 1 && iTask == TID_ROBBER && iKind == 1) {
		TASK_ROBBER_D->task_giveup(who, iKind);
	}
	else if (iType == 1 && iTask == TID_MASTER) {
		TASK_MASTER_D->task_giveup(who);
	}
	else if (iType == 1 && iTask == TID_CHAIN) {
		CHAIN_D->task_giveup(who);
	}
	else if (iType == 1 && iTask == TID_ESCORT) {
		TASK_ESCORT_D->task_giveup(who);
	}
	else if (iType == 2)
		TASK_LEGEND_D->task_giveup(who, iType, iTask, iKind);
	else if (iType == 1 && iTask == TID_MASTERFIGHT && iKind == 1) {
		who->delete_save_2("masterfight");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_MASTERFIGHT, 1, "");
	}
	else if (iType == 1 && who->get_save_2("marrytask") && !who->get_save_2("marrytask.finish") && iTask == TID_HONGNIANG && iKind == 1) {
		if (objectp(npc = find_char(who->get_save_2("marrytask.target"))) && npc->is_marry_task()) {
			npc->remove_from_scene();
			destruct(npc);
		}
		who->delete_save_2("marrytask");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_HONGNIANG, 1, "");
	}
	else if (iType == 1 && who->get_save_2("master_hide") && iTask == TID_MASTER_HIDE && iKind == 1) {
		"sys/task/master"->master_hide_giveup(who, npc);
	}
}