<?php
error_reporting(0);
if (isset($_GET['debug']) && $_GET['debug'] === 'true') {
    highlight_file(__FILE__);
    exit();
}
if (!isset($_COOKIE['username'])) {
    header('Location: index.php');
}
$user = base64_decode($_COOKIE['username']);
if ($user === 'admin') {
    include('../safe.php');
    $flag = $safe_flag;
} else {
    $flag = "Hello <u>".htmlspecialchars($user)."</u>, you're not admin, no flag for you!";
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Paradiso</title>
    <link rel="stylesheet" href="main.css">
</head>
<body>
<div class="container">
    <div class="card flag-card">
        <h3>Flag storage box</h3>
        <h4><?php echo $flag; ?></h4>
        <!-- flag.php?debug=true -->
    </div>
</div>

</body>
</html>