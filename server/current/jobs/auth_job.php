<?php
$filename = '../log/auth.dat';

$fp = fopen($filename, 'c+');
if (!$fp) exit("Không thể mở file.\n");

if (!flock($fp, LOCK_EX)) {
    fclose($fp);
    exit("Không thể khóa file.\n");
}

// Đọc nội dung rồi xóa ngay
rewind($fp);
$content = stream_get_contents($fp);
ftruncate($fp, 0); // Xóa hết file
flock($fp, LOCK_UN);
fclose($fp); // Đóng file ngay sau khi lấy nội dung

// Xử lý từng dòng
$lines = array_filter(array_map('trim', explode("\n", $content)));

foreach ($lines as $line) {
    if (strpos($line, 'GET ') !== 0) continue;

    $url = trim(substr($line, 4));

    $parsed = parse_url($url);
    parse_str($parsed['query'] ?? '', $query);

    if (!isset($query['u'])) continue;

    $username = $query['u'];
    $outfile = "../log/auth/" . $username . '.dat';

    $context = stream_context_create(['http' => ['method' => 'GET', 'timeout' => 5]]);
    $response = @file_get_contents($url, false, $context);
    $body = $response === false ? 'fail:0:0:0' : trim($response);

    file_put_contents($outfile, $body . "\n", FILE_APPEND | LOCK_EX);
}
