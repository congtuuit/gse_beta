#include <ansi.h>
#include <task.h>

// Mảng: Thông tin gợi ý tiêu chuẩn -- [tùy ý]
mapping TipsTable = ([0:({
                            "Nút chức năng",
                            "Phía dưới bên phải của game là các nút chức năng, nếu bạn lần đầu vào game, tôi khuyên bạn nên click vào các biểu tượng nhỏ của các nút chức năng trước, xem có những chức năng gì.",
                        }),
                      1:({
                            "Nhận nhiệm vụ",
                            "Bạn có thể nhận nhiệm vụ từ các NPC có dấu chấm hỏi màu vàng trên đầu, sau đó click vào biểu tượng hình cuộn giấy ở góc dưới bên phải màn hình để mở giao diện nhiệm vụ, xem thông tin nhiệm vụ của bạn.",
                        }),
                      2:({
                            "Hoàn thành nhiệm vụ",
                            "Khi bạn hoàn thành một nhiệm vụ nào đó, bạn có thể click vào biểu tượng hình cuộn giấy ở góc dưới bên phải màn hình để mở giao diện nhiệm vụ, và theo hướng dẫn của giao diện nhiệm vụ để tìm người hoàn thành nhiệm vụ nhận phần thưởng.",
                        }),
                      3:({
                            "Chat",
                            "Bạn có thể nhập thông tin muốn nói với người khác vào thanh chat ở góc dưới bên trái, sau đó nhấn Enter để gửi; nút bên cạnh thanh chat có thể chuyển đổi kênh gửi thông tin của bạn.",
                        }),
                      4:({
                            "Khu vực hoạt động cho người mới",
                            "Ngoài làng mới, phía đông nam của làng mới là Thanh Khê, còn phía tây là U Cốc; những nơi này đều là khu vực hoạt động chính của người mới, khá phù hợp để người mới đánh quái luyện cấp.",
                        }),
                      5:({
                            "Trang bị vật phẩm",
                            "Bạn có thể mở túi đồ và dùng chuột phải click vào vật phẩm có thể trang bị để trang bị vật phẩm đó.",
                            "Mạnh Tử",
                            "Nếu bạn muốn tìm một người chơi làm sư phụ, có thể đến làng mới tìm Mạnh Tử (136,144), ông ấy sẽ giúp bạn gửi thông tin tìm sư phụ miễn phí đến toàn thế giới.",
                        }),
                      6:({
                            "Tổ đội",
                            "Click vào nút tổ đội ở góc dưới bên phải, chuột của bạn sẽ biến thành cờ đỏ nhỏ, dùng cờ đỏ nhỏ này click vào người chơi khác, bạn có thể mời họ vào tổ đội.",
                        }),
                      7:({
                            "Bắt thú cưng",
                            "Sau khi mua Càn Khôn Thừng ở cửa hàng tạp hóa, bạn có thể sử dụng kỹ năng bắt thú cưng trong kỹ năng cơ bản để biến quái vật ngoài đồng thành thú cưng của bạn.",
                        }),
                      8:({
                            "Đội trưởng vệ binh",
                            "Ở đội trưởng vệ binh làng mới bạn có thể nhận nhiệm vụ hỗ trợ trị an làng, nhiệm vụ hỗ trợ trị an làng là nhiệm vụ có thể nhận vô hạn. Hoàn thành nhiều lần nhiệm vụ này sẽ nhận được phần thưởng khá tốt.",
                        }),
                      9:({
                            "Nhiệm vụ cấp 10 của nước Sở",
                            "Lên thêm một cấp nữa bạn sẽ đạt cấp 10, nhưng tôi khuyên bạn sau khi đạt cấp 10 nên đến nước Sở đi dạo, ở đó còn có rất nhiều nhiệm vụ đang chờ bạn nhận!",
                            "Tìm sư phụ",
                            "Muốn hiểu nhanh hơn về Đại Thoại Chiến Quốc? Tôi khuyên bạn tìm Mạnh Tử (136,144) ở làng mới giúp bạn tìm một người chơi làm sư phụ, điều này sẽ rất có ích cho việc hiểu game của bạn!",
                        }),
                     10:({
                            "Nơi tụ tập người chơi - Nước Chu",
                            "Bạn cấp 10 đã có thể sử dụng trạm dịch, từ trạm dịch làng mới đến nước Chu chỉ cần 1 lượng vàng, tôi khuyên bạn cấp 10 nên đến nơi tụ tập người chơi của Đại Thoại Chiến Quốc - nước Chu đi tham quan một chuyến.",
                            "Gia nhập môn phái",
                            "Chúc mừng bạn đạt cấp 10, từ bây giờ bạn có thể chọn một môn phái mình thích để gia nhập, mau đến tìm người tuyển mộ môn phái ở làng mới và nước Sở tìm hiểu nhé!",
                        }),
                     11:({
                            "Khu vực luyện cấp từ 10-15",
                            "Thành Sở Phương, Ải Thượng Dung, núi Hoa Sơn, Đào Hoa Nguyên, đỉnh Triều Dương là khu vực hoạt động chính của người chơi cấp 10, khá phù hợp để bạn hiện tại đánh quái luyện cấp ở những nơi này.",
                        }),
                     12:({
                            "Nhiệm vụ sư môn",
                            "Ở sư phụ môn phái của bạn có thể nhận nhiệm vụ sư môn, hoàn thành 10 vòng nhiệm vụ sư môn bạn có thể nhận được phần thưởng kinh nghiệm rất phong phú, tôi khuyên bạn nên hoàn thành 20 vòng mỗi ngày.",
                        }),
                     13:({
                            "Vương Bổ Đầu",
                            "Ở Vương Bổ Đầu nước Chu bạn có thể nhận một số nhiệm vụ tuần hoàn, nghe nói nhiệm vụ của ông ấy còn có thể kiếm được khá nhiều tiền, qua xem thử!",
                        }),
                     14:({
                            "Kỹ năng sinh hoạt",
                            "Bây giờ bạn nên học một số kỹ năng sinh hoạt, đến các thành trong các nước tìm các sư phụ kỹ năng sinh hoạt, bạn có thể học kỹ năng sinh hoạt tương ứng ở họ.",
                            "Bí quyết bái sư",
                            "Mạnh Tử (136,144) ở làng mới hiểu sâu về đạo thầy trò, bây giờ bạn có thể chủ động trò chuyện với người chơi khác, để họ nhận bạn làm đồ đệ. Khi trò chuyện hãy chú ý lịch sự với người khác.",
                        }),
                     15:({
                            "Nhiệm vụ cấp 15 của nước Hàn",
                            "Bạn cấp 15 bây giờ có thể thử đến nước Hàn, ở nước Hàn bạn sẽ thấy rất nhiều dân cư có dấu chấm hỏi màu vàng trên đầu đang chờ bạn.",
                        }),
                     16:({
                            "Khu vực luyện cấp từ 15-20",
                            "Nghe nói núi Thủ Dương, núi Thúy Hoa, Ải Hàm Cốc, những nơi này khá phù hợp để bạn luyện cấp đánh quái ở cấp độ 15-20, bây giờ có thể đi xem!",
                        }),
                     17:({
                            "Nâng cao năng lực",
                            "Ngoài việc nâng cấp, bạn còn có thể nâng cao năng lực thông qua trang bị, trang bị càng mạnh càng cho bạn năng lực càng mạnh.",
                        }),
                     18:({
                            "Mua trang bị",
                            "Nếu bạn cảm thấy trang bị không đủ dùng, bạn có thể đến các cửa hàng trong các nước mua trang bị tương ứng với môn phái của mình, tất nhiên bạn cũng có thể đến khu vực bày hàng của nước Chu tìm xem có trang bị phù hợp với bạn ở các sạp của người chơi khác.",
                        }),
                     19:({
                            "Bái sư",
                            "Vẫn chưa tìm được sư phụ? Đừng sợ thất bại, hãy thử nhiều lần cầu sư với các người chơi cấp cao khác! Chỉ cần đến Mạnh Tử (136,144) ở làng mới, bạn có thể kết giao quan hệ thầy trò!",
                        }),
                     20:({
                            "Nhiệm vụ cấp 20 của nước Hàn và nước Ngụy",
                            "Bây giờ bạn đã cấp 20! Bạn có thể đến nước Hàn và nước Ngụy nhận nhiệm vụ cấp 20.",
                        }),
                     21:({
                            "Khu vực luyện cấp từ 20-25",
                            "Với thực lực hiện tại của bạn, Ải Hổ Lao, sông Vô Định, bờ sông Vô Định, Tương Lăng, đường Mã Lăng, trang Bạch Mã, hồ Mã Đạp là nơi luyện cấp phù hợp nhất với bạn.",
                        }),
                     23:({
                            "Bày hàng bán",
                            "Khi bạn có vật phẩm thừa, bạn có thể đến khu vực bày hàng của nước Chu bày một sạp bán những thứ này cho người chơi khác, bán đồ qua bày hàng cũng là một cách để có thêm tiền.",
                        }),
                     24:({
                            "Vốn liếng bái sư",
                            "Bạn cấp 24 tìm sư phụ đã không còn là việc khó! Chỉ cần chủ động tìm kiếm, chắc chắn có thể nhanh chóng tìm được sư phụ của bạn. Sau đó cùng họ đến Mạnh Tử (136,144) ở làng mới kết thành quan hệ thầy trò!",
                        }),
                     25:({
                            "Kết giao nhiều bạn bè",
                            "Ở cấp độ này bạn nên kết giao nhiều bạn bè, để sau này cùng tiến lùi, đối mặt với nhiều nhiệm vụ khó khăn hơn.",
                        }),
                     26:({
                            "Khu vực luyện cấp từ 25-30",
                            "Ải Kỳ, Tấn Dương, Ải Nhạn Môn, Trường Bình, Cự Lộc, núi Thái Hành, Mục Dã, Quế Lăng, Bình Nguyên, sông Dịch, Trác Lộc là nơi luyện cấp đánh quái phù hợp nhất với cấp độ của bạn.",
                        }),
                     28:({
                            "Bái người chơi làm sư",
                            "Khi cấp của bạn vượt quá 30, bạn không thể bái người chơi khác làm sư nữa, vì vậy nếu bây giờ bạn vẫn chưa bái người chơi khác làm sư, hãy mau tìm một sư phụ!",
                        }),
                     29:({
                            "Sư gia",
                            "Ở nước Chu có một sư gia tên Từ Phúc, ông ấy phụ trách theo dõi và truy bắt tất cả các vụ án của nha môn nước Chu. Tôi khuyên bạn sau cấp 30 nhất định phải đến nước Chu tìm ông ấy.",
                        }),
                     30:({
                            "Nhiệm vụ cấp 30 của nước Sở",
                            "Bạn cấp 30 đã lâu không về nước Sở xem rồi phải không? Mau về xem đi! Ở đó bây giờ lại có nhiệm vụ phù hợp với bạn!",
                            "Vận tiêu",
                            "Muốn kiếm tiền? Nếu muốn có thể tìm Lão Tiêu Đầu Úy Trì của Trấn Uy Tiêu Cục nước Chu vận tiêu, nhưng vận tiêu sẽ có một số rủi ro, mau đến nước Chu tìm Lão Tiêu Đầu Úy Trì hỏi thử!",
                        }),
                     31:({
                            "Khu vực luyện cấp từ 30-35",
                            "Chân núi Đại Biệt, núi Đại Biệt, núi Vu Sơn, hồ Bà Dương những nơi này đều là nơi lý tưởng nhất để bạn hiện tại nâng cấp. Hãy đi nhiều những nơi này!",
                        }),
                     35:({
                            "Nhiệm vụ cấp 35 của nước Tề",
                            "Nước Tề nằm ở phía đông nhất là một quốc gia xinh đẹp, dân cư ở đó bây giờ đang chờ bạn cấp 35 đến giúp họ.",
                        }),
                     36:({
                            "Khu vực luyện cấp từ 35-40",
                            "Núi Thái Sơn, chân núi Thái Sơn, hồ Thái Hồ, Xích Bích đều là khu vực phù hợp để bạn hiện tại thường xuyên hoạt động.",
                            "Gương phong yêu",
                            "Ở nước Chu có một người tên Tả Khâu Minh, ông ấy có thể mở cho bạn một cảnh luyện cấp đặc biệt độc quyền. Bạn có rảnh thì nên đến nước Chu tìm ông ấy tìm hiểu.",
                        }),
                     40:({
                            "Nhiệm vụ cấp 40 của nước Tần và nước Yên",
                            "Nước Tần và nước Yên là hai quốc gia xa xôi, bạn cấp 40 nên đến hai quốc gia này đi dạo, rất nhiều nhiệm vụ đang chờ bạn!",
                            "Thu đồ đệ",
                            "Khi cấp của bạn đạt 40 trở lên, bạn có thể tìm một người chơi dưới cấp 30 đến Khổng Phu Tử ở nước Chu kết thành quan hệ thầy trò.",
                        }),
                     41:({
                            "Khu vực luyện cấp từ 40-45",
                            "Bạn cấp 40 có làng chài Đông Hải, bờ biển Đông Hải, bãi biển, đảo Đông Hải những nơi này đang chờ bạn khám phá. Nghe nói còn có người thấy một con chó kỳ lạ ở một bãi biển nào đó!",
                        }),
                     45:({
                            "Nhiệm vụ cấp 45 của nước Yên",
                            "Nhanh vậy đã đạt cấp 45? Hãy đến nước Yên xem nhiều! Ở đó có rất nhiều nhiệm vụ phù hợp với bạn hiện tại.",
                        }),
                     46:({
                            "Khu vực luyện cấp từ 45-50",
                            "Nếu bạn đang tìm quái vật phù hợp để luyện cấp, kênh Trịnh Quốc gần nước Tần là nơi đáng để bạn đến.",
                        }),
                     50:({
                            "Nhiệm vụ cấp 50 của nước Yên và nước Triệu",
                            "Bạn cấp 50 đã có thể đảm đương một mặt! Hãy đến nước Yên và nước Triệu hai quốc gia lân cận xem, ở đó rất nhiều dân cư đang chờ bạn giúp đỡ.",
                        }),
                     51:({
                            "Khu vực luyện cấp từ 50-55",
                            "Núi Trường Bạch, đỉnh Ngọc Trụ, đỉnh Bạch Vân, hồ Trường Bạch Thiên Trì ở phía đông bắc là nơi bắt buộc phải đến cho người chơi cấp 50 đi du lịch, đánh quái luyện cấp. Hôm nay bạn đã đi chưa?",
                        }),
                     55:({
                            "Nhiệm vụ cấp 55 của nước Triệu",
                            "Năm xưa Triệu Vũ Linh Vương thực hiện 'Hồ phục kỵ xạ' khiến người nước Triệu ai cũng giỏi đánh trận, tôi khuyên bạn cấp 55 đến nước Triệu thăm dân cư nước Triệu, ở đó lại có rất nhiều nhiệm vụ có thể nhận.",
                        }),
                     56:({
                            "Khu vực luyện cấp từ 55-60",
                            "Vạn Lý Trường Thành nước Yên không biết bạn đã đi chưa? Nơi đó với thực lực hiện tại của bạn rất phù hợp để luyện cấp.",
                        }),
                     60:({
                            "Nhiệm vụ cấp 60 của nước Tần",
                            "Từ sau biến pháp Thương Ưởng, nước Tần không ngừng lớn mạnh, bây giờ đã trở thành quốc gia mạnh nhất trong bảy nước. Tôi khuyên bạn đến nước Tần đi một chuyến, có rất nhiều nhiệm vụ đang chờ bạn nhận!",
                        }),
                     61:({
                            "Khu vực luyện cấp từ 60-65",
                            "Vạn Lý Trường Thành nước Triệu là trường thành do nước Triệu xây... gì? Bạn nói đây là lời thừa! Hừm, tôi sẽ không nói cho bạn biết nơi luyện cấp tốt nhất hiện tại là Vạn Lý Trường Thành nước Triệu!",
                        }),
                     65:({
                            "Nhiệm vụ cấp 65 của nước Tần",
                            "Nghe nói với thực lực như bạn hiện tại, ở lại nước Tần còn có thể nhận rất nhiều nhiệm vụ, bạn mau về nước Tần xem!",
                        }),
                     66:({
                            "Khu vực luyện cấp từ 65-70",
                            "Vệ binh Vạn Lý Trường Thành nước Tần mạnh không biết bạn đã từng lĩnh giáo chưa? Nhưng với thực lực hiện tại của bạn, đã đủ để đối kháng với vệ binh Vạn Lý Trường Thành nước Tần! Vạn Lý Trường Thành nước Tần ở phía bắc nước Tần.",
                        }),
                     70:({
                            "Nhiệm vụ cấp 70 của nước Hàn",
                            "Trong bảy nước, nước Hàn được coi là một quốc gia tương đối yếu. Bây giờ người nước Hàn rất cần người cấp 70 giúp đỡ, bây giờ bạn chính là người cấp 70! Mau đến nước Hàn xem!",
                        }),
                     71:({
                            "Khu vực luyện cấp từ 70-75",
                            "Từ nước Hàn đi bộ đến trang viên Đường Phủ phải đi qua một đoạn đường vòng, bạn biết không? Nơi đó có rất nhiều mật thám, thủy tặc cấp 70 xuất hiện.",
                        }),
                     75:({
                            "Khám phá Chiến Quốc",
                            "Bây giờ bạn đã có một thực lực nhất định, có thể đi khám phá những nơi sâu hơn, nhiều hang động ngầm phù hợp với thực lực hiện tại của bạn để khám phá. Sự vô hạn thú vị của Chiến Quốc đang chờ bạn!",
                        }),
]);

mapping GTipsTable = ([1:({
                             "Đại Thoại Chiến Quốc",
                             "Chào mừng đến với Đại Thoại Chiến Quốc, tôi là trợ thủ nhỏ Chiến Quốc, tôi sẽ cung cấp cho bạn các thông tin hướng dẫn đơn giản trong quá trình chơi game. Click chuột phải vào tôi có thể đặt lại thông tin hướng dẫn của tôi.",
                         }),
                       2:({
                             "Nhận nhiệm vụ",
                             "Trong game, các NPC có nhiệm vụ cốt truyện có thể nhận sẽ có một dấu chấm hỏi màu vàng trên đầu làm dấu hiệu.",
                         }),
                       3:({
                             "Thời gian kinh nghiệm gấp đôi",
                             "Mỗi tuần đều có thể tìm ông tiên nhận 4 giờ thời gian kinh nghiệm gấp đôi. Trong thời gian kinh nghiệm gấp đôi, kinh nghiệm nhận được khi đánh bại quái vật sẽ tăng gấp đôi.",
                         }),
                       4:({
                             "Sử dụng tiệm cầm đồ",
                             "Bạn có thể miễn phí cất giữ vật phẩm và tiền tạm thời không dùng trong túi đồ vào tiệm cầm đồ, khi cần thì lấy ra.",
                         }),
                       5:({
                             "Mua vật phẩm",
                             "Click vào vật phẩm trong cửa hàng, chọn số lượng rồi click xác nhận, bạn có thể mua vật phẩm. Tất nhiên bạn cũng có thể kéo thả vật phẩm trong túi đồ vào thanh cửa hàng để bán lấy tiền.",
                         }),
                       6:({
                             "Sửa chữa vật phẩm",
                             "Nếu trang bị của bạn bị giảm độ bền, bạn có thể đến chủ tiệm sửa chữa trả một số tiền để sửa trang bị.",
                         }),
                       7:({
                             "Giám định vật phẩm",
                             "Bạn có thể đưa trang bị chưa giám định đến chủ tiệm sửa chữa để giám định, nhưng phải trả một ít tiền.",
                         }),
                       8:({
                             "Trang bị vật phẩm",
                             "Bạn có thể mở túi đồ và dùng chuột phải click vào vật phẩm có thể trang bị để trang bị vật phẩm đó.",
                         }),
                       9:({
                             "Sử dụng thuốc",
                             "Mở túi đồ click chuột phải vào thuốc tương ứng, bạn có thể sử dụng thuốc đó.",
                         }),
                      10:({
                             "Sử dụng rượu thức ăn",
                             "Nếu trong túi đồ của bạn có thức ăn và rượu, bạn có thể sử dụng rượu thức ăn này để hồi phục khí huyết và pháp lực. Nhưng khi ăn uống bạn không thể thực hiện bất kỳ động tác nào khác ngoài di chuyển.",
                         }),
                      11:({
                             "Thanh phím tắt",
                             "Bạn có thể đặt kỹ năng, vật phẩm thường dùng vào thanh phím tắt ở góc dưới bên trái màn hình, sau đó click vào phím tắt tương ứng (F1 đến F10) để sử dụng.",
                         }),
                      12:({
                             "Chiến đấu",
                             "Đưa chuột đến quái vật click chuột trái, bạn có thể tấn công quái vật, đồng thời bản thân vào trạng thái chiến đấu.",
                         }),
                      13:({
                             "Chết",
                             "Sau khi nhân vật của bạn chết, bạn có thể chọn hồi sinh ngay tại điểm hồi sinh hoặc chờ người chơi khác biết phép hồi sinh cứu viện, người chơi sau cấp 15 tự động hồi sinh sẽ mất một số tiền mặt và kinh nghiệm.",
                         }),
                      14:({
                             "Nhặt vật phẩm",
                             "Sau khi đánh bại quái vật, quái vật có thể rơi một số vật phẩm, đưa chuột đến vật phẩm rơi trên đất, sau đó click chuột trái để nhặt vật phẩm đó. Và cất vào ba lô của bạn.",
                         }),
                      15:({
                             "Thú cưng",
                             "Bạn có thể nhấn ALT+R mở giao diện thuộc tính thú cưng chọn thú cưng tham chiến, để thú cưng hỗ trợ bạn chiến đấu.",
                         }),
                      16:({
                             "Nhân vật nhiệm vụ",
                             "Nếu có thể đánh bại nhân vật nhiệm vụ, bạn có thể nhận được một số phần thưởng kinh nghiệm và tiềm năng.",
                         }),
                      17:({
                             "Vật phẩm nhiệm vụ",
                             "Đưa vật phẩm nhiệm vụ cho đội trưởng vệ binh làng mới, có thể đổi lấy phần thưởng khá phong phú.",
                         }),
                      18:({
                             "Võ đài",
                             "Võ sư của Trấn Uy Tiêu Cục có thể đưa bạn đến võ đài, trong võ đài bạn có thể tùy ý đấu với người chơi khác mà không lo chết sẽ bị phạt.",
                         }),
                      19:({
                             "Lên cấp thủ công",
                             "Khi kinh nghiệm tích lũy đủ để lên cấp, nhấn ALT+W mở giao diện thuộc tính nhân vật, và click nút lên cấp ở dưới giao diện để lên cấp.",
                         }),
                      20:({
                             "Phân phối điểm",
                             "Mở giao diện thuộc tính nhân vật có thể phân phối điểm chưa phân phối của bạn.",
                         }),
                      21:({
                             "Xem bản đồ",
                             "Phím tắt ALT+D có thể cho bạn xem bản đồ khu vực của cảnh hiện tại, ALT+M có thể xem bản đồ thế giới.",
                         }),
                      22:({
                             "Thêm bạn bè",
                             "Nếu bạn hòa thuận với người chơi khác, có thể click vào biểu tượng hình bắt tay của nút chức năng ở góc dưới bên phải, thêm người chơi đó làm bạn bè.",
                         }),
                      23:({
                             "Bày hàng",
                             "Trong khu vực bày hàng, bạn có thể sử dụng kỹ năng bày hàng trong kỹ năng cơ bản để tự lập một sạp, bán một số thứ không thường dùng cho người chơi khác.",
                         }),
                      24:({
                             "Trang bị ràng buộc",
                             "Một số trang bị sau khi nhặt hoặc trang bị sẽ ràng buộc trên người, trang bị đã ràng buộc không thể giao dịch với người chơi khác.",
                         }),
                      25:({
                             "Gia nhập quốc gia",
                             "Thất hùng Chiến Quốc là bảy nước Tề, Hàn, Triệu, Ngụy, Tần, Sở, Yên. Bạn có thể chọn một quốc gia mình thích, sau đó đến quan hộ tịch của quốc gia đó chọn gia nhập quốc gia đó.",
                         }),
                      26:({
                             "Gia nhập bang hội",
                             "Sau khi gia nhập quốc gia, bạn có thể đăng ký gia nhập một bang hội ở tổng quản bang hội của quốc gia mình, gia nhập bang hội là con đường tắt để kết giao nhiều bạn bè hơn.",
                         }),
                      27:({
                             "Kỹ năng sư môn",
                             "Bạn có thể click vào biểu tượng hình sách ở góc dưới bên phải mở giao diện kỹ năng, sau đó kéo kỹ năng của bạn vào thanh phím tắt để sử dụng.",
                         }),
                      28:({
                             "Sử dụng kỹ năng sinh hoạt",
                             "Sau khi học kỹ năng sinh hoạt, bạn có thể click vào biểu tượng hình sách ở góc dưới bên phải mở giao diện kỹ năng, click kỹ năng sinh hoạt ở kỹ năng phụ trợ để sản xuất. Nhưng sản xuất cần tiêu hao nguyên liệu đặc định.",
                         }),
                      29:({
                             "Điểm công đức",
                             "Khi cấp của bạn đạt 50 trở lên, bạn dẫn một người chơi dưới cấp 30 lên cấp có thể nhận được một số giá trị công đức, giá trị công đức có thể đổi lấy phần thưởng khá tốt ở lão nhân công đức.",
                         }),
                      30:({
                             "Trang bị xuất sắc",
                             "Màu sắc tên một số trang bị sẽ rực rỡ hơn trang bị thông thường, thường những trang bị này thuộc tính đều tốt hơn trang bị trắng thông thường khá nhiều.",
                         }),
                      31:({
                             "Tinh luyện trang bị",
                             "Khi bạn có được tinh thạch, bạn có thể đặt tinh thạch cùng trang bị tương ứng để tinh luyện, điều này có thể khiến trang bị của bạn uy lực tăng mạnh.",
                         }),
                      32:({
                             "Hôn nhân",
                             "Nếu có một người chơi khác giới tình cảm tương thông với bạn, có thể thử bày tỏ tình cảm với đối phương, trong game kết thành vợ chồng với cô ấy (anh ấy). Nguyệt lão và Hồng Nương ở đài Thước sẽ làm chứng cho hai bạn.",
                         }),
                      33:({
                             "BOSS thế giới",
                             "BOSS thế giới là một loại quái vật rất mạnh. Nếu bạn tự tin vào khả năng của mình, có thể tuyển mộ nhiều bạn bè để cùng thử thách hắn. Đánh bại hắn sẽ nhận được phần thưởng rất phong phú.",
                         }),
                      34:({
                             "Sử dụng tín vật",
                             "Click vào tín vật môn phái hoặc sử dụng kỹ năng sử dụng tín vật trong kỹ năng cơ bản, có thể đưa bạn truyền về làng mới hoặc môn phái của bạn.",
                         }),
                      35:({
                             "Tiềm năng",
                             "Tiêu diệt quái vật ngoài việc nhận kinh nghiệm, còn có thể nhận tiềm năng. Tiềm năng là một loại tiêu hao khi tu luyện kỹ năng sau này, kỹ năng càng cao cấp tiêu hao tiềm năng càng nhiều.",
                         }),
                      36:({
                             "Lên cấp",
                             "Sau khi cấp tăng lên năng lực nhân vật sẽ tăng tương ứng, đồng thời sẽ nhận được phần thưởng bốn điểm thuộc tính. Trong giao diện thuộc tính nhân vật có thể tự do phân phối điểm vào năm thuộc tính cơ bản.",
                         }),
                      37:({
                             "Làng mới",
                             "Đây là làng mới, là nơi tụ tập của người mới, cũng là quê hương nơi vô số dũng sĩ trưởng thành. Thăm hỏi dân làng ở đây, lắng nghe câu chuyện của họ, sẽ hiểu được nhiều điều hơn về thế giới này.",
                         }),
                      38:({
                             "Cửa hàng",
                             "Cửa hàng cơ bản có tiệm vũ khí, tiệm phòng cụ, tiệm tạp hóa và tiệm thuốc, còn có tiệm cầm đồ dùng làm kho. Những cửa hàng này là nơi chính để người chơi tương tác giao dịch với NPC.",
                         }),
                      39:({
                             "Tiệm vũ khí",
                             "Bạn có thể mua đao, thương, kiếm, gậy, quyền thao, ám khí các loại vũ khí khác nhau ở tiệm vũ khí. Đồng thời bạn cũng có thể bán vật phẩm không dùng trên người cho chủ tiệm vũ khí.",
                         }),
                      40:({
                             "Tiệm phòng cụ",
                             "Tiệm phòng cụ có thể mua các loại đồ dùng phòng cụ. Đồng thời bạn cũng có thể bán vật phẩm không dùng trên người cho chủ tiệm phòng cụ.",
                         }),
                      41:({
                             "Tiệm tạp hóa",
                             "Bạn có thể mua các đồ dùng cần thiết ở tiệm tạp hóa, ví dụ như phù về thành, phù bay v.v. Bạn cũng có thể bán vật phẩm không dùng trên người cho chủ tiệm tạp hóa để đổi lấy một số tiền.",
                         }),
                      42:({
                             "Tiệm thuốc",
                             "Ở chủ tiệm thuốc bạn có thể mua các loại thuốc hồi phục khí huyết và pháp lực, ra ngoài chắc chắn không thể thiếu mang nhiều thuốc phòng thân.",
                         }),
                      43:({
                             "Rời khỏi đội",
                             "Bạn đã gia nhập một đội, nếu muốn rời khỏi đội, click chuột phải vào avatar của mình ở góc trên bên trái giao diện game, trong menu hiện ra chọn rời đội là được.",
                         }),
                      44:({
                             "Gửi thông tin vật phẩm",
                             "Giữ phím Shift rồi click vào một vật phẩm bạn có, có thể gửi thông tin vật phẩm đó vào thanh chat, để người khác thấy.",
                         }),
                      45:({
                             "Người chơi trong thanh chat",
                             "Giữ phím Shift rồi click vào bất kỳ tên người chơi nào trong thanh chat, có thể mở menu chuột phải tương tác với người chơi này.",
                         }),
                      46:({
                             "Công cụ kỹ năng sinh hoạt",
                             "Ngoài rượu thức ăn, 7 kỹ năng sinh hoạt khác đều cần công cụ tương ứng, công cụ sơ cấp kỹ năng sinh hoạt có thể mua ở chủ tiệm tạp hóa của quốc gia tương ứng với kỹ năng sinh hoạt.",
                         }),
                      47:({
                             "Hồi phục khí huyết",
                             "Nếu khí huyết của bạn giảm xuống 0, bạn sẽ chết. Bạn có thể sử dụng thuốc và rượu thức ăn để hồi phục khí huyết đã giảm.",
                         }),
                      48:({
                             "Đối thoại",
                             "Dùng chuột trái click vào một NPC, có thể mở đối thoại với NPC đó.",
                         }),
                      49:({
                             "Nút chức năng",
                             "Góc dưới bên phải của game là các nút chức năng của game, nếu bạn lần đầu vào game, tôi khuyên bạn nên click vào các biểu tượng nhỏ của các nút chức năng trước, xem có những chức năng gì.",
                         }),
                      50:({
                             "Thanh chat",
                             "Góc dưới bên trái của game là thanh chat, có thể nhập thông tin vào thanh chat, tôi khuyên bạn nên thử click vào các nút trên thanh chat trước, làm quen với chức năng chat.",
                         }),
                      51:({
                             "Cửa hàng trang sức",
                             "Chủ cửa hàng trang sức là thương nhân bán giày và thắt lưng, giống thương nhân thông thường, bạn cũng có thể bán vật phẩm không dùng trên người cho chủ cửa hàng trang sức.",
                         }),
                      52:({
                             "Tiệm sửa chữa",
                             "Chủ tiệm sửa chữa là chuyên gia vũ khí trang bị, ông ấy không chỉ có thể giúp bạn sửa trang bị bị hỏng, nếu bạn có trang bị chưa giám định cũng có thể đưa cho ông ấy giúp bạn giám định.",
                         }),
                      53:({
                             "Chủ quán rượu",
                             "Ở chủ quán rượu, bạn không chỉ có thể mua nhiều rượu thức ăn, nhiều nguyên liệu cần thiết cho kỹ năng sinh hoạt đều cần mua từ đây.",
                         }),
                      54:({
                             "Kênh trả phí",
                             "Sử dụng kênh công chúng và kênh tin đồn cần trả một số phí. Sử dụng một lần kênh công chúng cần trả 200 vàng, sử dụng một lần kênh tin đồn cần trả 1000 vàng.",
                         }),
]);

// Hàm: Hiển thị thông tin gợi ý (tiêu chuẩn)
void send_level_tips(object me, int level)
{
        string *info, result;
        info = TipsTable[level];
        if (sizeof(info) < 2)
                return;
        result = sprintf("%-20s%s", info[0], info[1]);
        send_user(me, "%c%w%s", 0x63, level * 2 + 1002, result);
        if (sizeof(info) == 4)
        {
                result = sprintf("%-20s%s", info[2], info[3]);
                send_user(me, "%c%w%s", 0x63, level * 2 + 1 + 1002, result);
        }
}

// Hàm: Hiển thị thông tin gợi ý (tiêu chuẩn)
void send_level_tips2(object me, int level)
{
        string *info, result;
        info = TipsTable[level];
        while (sizeof(info) < 2 && level >= 0)
        {
                level--;
                info = TipsTable[level];
        }
        result = sprintf("%-20s%s", info[0], info[1]);
        send_user(me, "%c%w%s", 0x63, 1000, result);
        if (sizeof(info) == 4)
        {
                result = sprintf("%-20s%s", info[2], info[3]);
                send_user(me, "%c%w%s", 0x63, 1001, result);
        }
}

void send_help_tips(object me, int type)
{
        int *status;
        int i, locate, pos;
        string *info, result;
        status = me->get_save("tipstatus");
        if (!status)
                status = ({});
        // Kiểm tra đã gửi chưa
        locate = type / 30;
        pos = type % 30;
        if (sizeof(status) >= locate + 1)
        {
                if ((status[locate] & (1 << pos)) != 0)
                        return;
                status[locate] = status[locate] | (1 << pos);
        }
        else
        {
                while (sizeof(status) < locate + 1)
                        status += ({0});
                status[locate] = status[locate] | (1 << pos);
        }
        me->set_save("tipstatus", status);
        info = GTipsTable[type];
        if (sizeof(info) < 2)
                return;
        result = sprintf("%-20s%s", info[0], info[1]);
        send_user(me, "%c%w%s", 0x63, type + 10, result);
        //        send_user( me, "%c%s", ';', result );
        //        tell_user(me, info[1]);
}