      case '1':
        if(ledState == LOW){
          digitalWrite(LED_BUILTIN,HIGH);
          HM10.println("LED가 켜졌습니다.\n");
        }
        else
        {
          HM10.println("이미 LED가 켜졌습니다.\n");
        }
        break;
