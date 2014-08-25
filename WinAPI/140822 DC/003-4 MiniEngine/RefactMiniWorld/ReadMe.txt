수정 / 변경사항
개선 사항
- World Class 및 WorldRendere Class로 Refactoring
- 원을 Object화 하여 추가, 이동, 삭제 처리과정 추가 (이제 다수의 원을 추가 삭제 이동 처리 가능)
- Rendering과 World Class를 이원화하여, World Class에서만 Object 및 World Map 관리를 하도록 수정
- 차후 Object Class 다분화시 확장성 개선
개악 사항(수정해야할 것)
- 원 추가나 이동시 범위 밖으로 나가지 않게 수정해야 할것 (이전 버전에선 처리해줬으나 리팩토링중 과정 생략)
