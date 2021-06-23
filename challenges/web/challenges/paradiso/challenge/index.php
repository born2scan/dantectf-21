<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Paradiso</title>
    <link rel="stylesheet" href="main.css">
</head>
<body>
<div class="container">
    <div class="card">
        <form action="login.php" method="POST">
            <div class="label">Username</div>
            <input type="text" name="username" id="username" class="form-control"/>
            <div class="label">Password</div>
            <input type="password" name="password" id="password" class="form-control"/>
            <input type="submit" value="Login"/>
            <?php if(isset($_GET['error'])) : ?> <div class="error"> <?php echo htmlspecialchars($_GET['error']); ?></div> <?php endif; ?>
        </form>
    </div>
</div>
<!--TODO remove user guest:guest in production -->
</body>
</html>