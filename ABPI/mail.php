<?php
$name = $_POST['name'];
$email = $_POST['email'];
$message = $_POST['message'];
$subject = $_POST['subject'];

if ($name === ''){
print json_encode(array('message' => 'Name cannot be empty', 'code' => 0));
exit();
}
if ($email === ''){
print json_encode(array('message' => 'Email cannot be empty', 'code' => 0));
exit();
} else {
if (!filter_var($email, FILTER_VALIDATE_EMAIL)){
print json_encode(array('message' => 'Email format invalid.', 'code' => 0));
exit();
}
}



if ($subject === ''){
print json_encode(array('message' => 'subject cannot be empty', 'code' => 0));
exit();
}

if ($message === ''){
print json_encode(array('message' => 'Message cannot be empty', 'code' => 0));
exit();
}

$content="From: $name \nEmail: $email \nMessage: $message";
$recipient = "satyam.honorplay@gmail.com";
$mailheader = "From: $email \r\n";
mail($recipient, $subject, $content, $mailheader) or die("Error!");
header('location: index.html');
exit();
?>